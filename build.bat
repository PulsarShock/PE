echo Y | rmdir /s build && mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make -j 4
cd ..
.\output\PE.exe