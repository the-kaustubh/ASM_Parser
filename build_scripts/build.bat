@echo off
cd .. 
gcc -m32 -DWIN parse.c -o gparse32.exe
gcc -DWIN parse.c -o gparse.exe
tcc -DWIN parse.c -o tparse.exe
cd build_scripts
@echo on