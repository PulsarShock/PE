#include "PainterEngine_Application.h"
#include "PX_Object.h"
#include "PX_Texture.h"
#include "PX_Typedef.h"
#include "PainterEngine_Startup.h"
PX_Application App;
px_texture texture;

typedef struct {
	px_point2D velocity;
	px_point2D cursor;
	px_int rotation_speed;
	px_int rotation;
} PX_Star;

px_void star_update(PX_Object *obj, px_uint elapsed)
{
	px_point2D force;
	PX_Star *ss = obj->pObject;

	force.x = ss->cursor.x - obj->x;
	force.y = ss->cursor.y - obj->y;

	px_point2D v_inc;
	v_inc.x = force.x * elapsed / 1000.f;
	v_inc.y = force.y * elapsed / 1000.f;

	ss->velocity.x += v_inc.x;
	ss->velocity.y += v_inc.y;

	ss->velocity.x -= ss->velocity.x * 0.5f * elapsed / 1000.f;
	ss->velocity.y -= ss->velocity.y * 0.5f * elapsed / 1000.f;

	obj->x += ss->velocity.x * elapsed / 1000.f;
	obj->y += ss->velocity.y * elapsed / 1000.f;

	ss->rotation += (ss->rotation_speed * elapsed / 100) % 360;
}

px_void star_render(px_surface *psurface, PX_Object *obj, px_uint elapsed)
{
	PX_Star *ss = obj->pObject;
	PX_TextureRenderRotation(psurface, &texture, obj->x, obj->y, PX_ALIGN_CENTER, PX_NULL, ss->rotation);
	
}

px_void PX_StarOnMouseMove(PX_Object *obj, PX_Object_Event e, px_void *ptr)
{
	PX_Star *ss = obj->pObject;
	ss->cursor.x = PX_Object_Event_GetCursorX(e);
	ss->cursor.y = PX_Object_Event_GetCursorY(e);
}

PX_Object *pObj = PX_NULL;

px_bool PX_ApplicationInitialize(PX_Application *pApp,px_int screen_width,px_int screen_height)
{
	PX_ApplicationInitializeDefault(&pApp->runtime, screen_width, screen_height);
	PX_LoadTextureFromFile(&pApp->runtime.mp_game, &texture, "star.traw");
	
	PX_Star s;
	s.rotation = 0;
	s.rotation_speed = 20;
	pObj = PX_ObjectCreateEx(&pApp->runtime.mp_game, PX_NULL, 0, 0, 0, 0, 0, 0, 0, star_update, star_render, PX_NULL, &s, sizeof(PX_Star));
	PX_ObjectRegisterEvent(pObj, PX_OBJECT_EVENT_CURSORMOVE, PX_StarOnMouseMove, PX_NULL);

	return PX_TRUE;
}

px_void PX_ApplicationUpdate(PX_Application *pApp,px_dword elapsed)
{
	star_update(pObj, elapsed);
}

px_void PX_ApplicationRender(PX_Application *pApp,px_dword elapsed)
{
	px_surface *pRenderSurface=&pApp->runtime.RenderSurface;
	PX_RuntimeRenderClear(&pApp->runtime,PX_COLOR_WHITE);
	PX_ObjectRender(pRenderSurface, pObj, elapsed);
}

px_void PX_ApplicationPostEvent(PX_Application *pApp,PX_Object_Event e)
{
	PX_ApplicationEventDefault(&pApp->runtime, e);
	PX_ObjectPostEvent(pObj, e);
	
}

