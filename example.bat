@echo off

set out=application
set defines=USE_OPENGL DEBUG

call bin\wcompile.exe %out% %defines% 
