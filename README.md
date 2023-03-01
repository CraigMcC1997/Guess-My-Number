# Guess-My-Number
A repo for a new small, personal project. This will begin as a simple single file project which using the console window for output and the user must guess a number which has been randomly chosen between 1-100
  
- try clearing the screen each time to stop the terminal getting spammed and hard to read
- try making input/ output more clear to differentiate, currently all mashed together
- allow the player to add their own range, or add 3 levels, 0-100, 0-1,000, 0-10,000 with differening score boards

## TODO


## Linking
Properties -> VC++ Directories -> Include Directories:
+ ..\Dev\SDL2-2.26.3\include;

Properties -> VC++ Directories -> Library Directories:
+ ..\Dev\SDL2-2.26.3\lib\x64;

Properties -> Linker -> General:
+ ..\Dev\SDL2-2.26.3\lib\x64;

Properties -> Linker -> Input:
+ SDL2.lib;SDL2main.lib;

note: add "sdl2.dll" into Mini-Games/

## Testing
see TestingREADME.md for more information