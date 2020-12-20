echo.
echo.
echo.
echo COPYING DLLS 
echo.
echo.
echo.



copy /Y %1\lib\SDL2.dll %1\%2\%3\SDL2.dll
copy /Y %1\lib\glew-2.1.0\bin\Release\x64\glew32.dll %1\%2\%3\glew32.dll


echo.
echo.
echo.
echo COPYING DONE
echo.
echo.
echo.
EXIT 0