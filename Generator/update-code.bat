set thisDir=%~dp0
set vspath=C:\Program Files (x86)\Microsoft Visual Studio 12.0\
cd "%vspath%"
call "%vspath%Common7\Tools\VsDevCmd.bat"

msbuild "%thisDir%Generator.sln" /Target:Rebuild /p:Configuration=Release

"%thisDir%Generator.Console\bin\Release\Generator.Console.exe" --command gen-xml --source "%thisDir%Data\greis-manual.txt" --target "%thisDir%Output"

MSTest "/testcontainer:%thisDir%Generator.Tests\bin\Release\Generator.Tests.dll" 