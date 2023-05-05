@echo off

call pushd ..\..\build\win32_handmade\ 

call cl /Zi w:\build\win32_handmade\win32_handmade.cpp

call popd