# Guess-My-Number

## Project Description
This project is about improving my abilities as a C++ developer by creating small mini games from scratch. 
With more games being added throughout development.

## TODO
- GussMyNumber: 
	-- Improve readablity of on screen prompts / output.
	
- X&Os: 
	-- Add ability to play against bot.

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