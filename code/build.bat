@echo off

mkdir ..\build
call pushd ..\build

call cl /Zi ..\code\win32_handmade.cpp User32.lib Gdi32.lib



call popd
