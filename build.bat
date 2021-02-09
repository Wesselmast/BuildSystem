@echo off
g++ -c src/print.cpp -o int/print.o
g++ -c src/file.cpp  -o int/file.o
g++ -c src/flags.cpp -o int/flags.o
g++ -c src/main.cpp  -o int/main.o
g++ -o bin/wcompile.exe int/print.o int/file.o int/flags.o int/main.o 
