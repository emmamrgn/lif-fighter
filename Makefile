all : bin/SDL bin/txt

bin/SDL: obj/main_sdl2.o obj/sdlSF.o obj/Field.o obj/Game.o obj/Fighter.o obj/Hitbox.o obj/ResourceManager.o obj/Animation.o obj/CharacterState.o obj/AnimationData.o obj/Menu.o obj/Image.o
	g++ -ggdb -o $@ $^ -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

obj/main_sdl2.o : src/SDL/main_sdl2.cpp src/SDL/sdlSF.h 
	g++ -ggdb -c -Wall $< -o $@ 

obj/sdlSF.o : src/SDL/sdlSF.cpp src/SDL/sdlSF.h src/core/Game.h src/core/Field.h src/core/Fighter.h src/SDL/ResourceManager.h src/SDL/Animation.h src/core/CharacterState.h src/SDL/AnimationData.h src/SDL/Menu.h src/SDL/Image.h
	g++ -ggdb -c -Wall $< -o $@ 

bin/txt : obj/main_text.o obj/winTXT.o obj/txtSF.o obj/Field.o obj/Game.o obj/Fighter.o obj/Hitbox.o obj/CharacterState.o
	g++ -ggdb -o $@ $^

obj/main_text.o : src/txt/main_text.cpp src/txt/winTXT.h src/txt/txtSF.h src/core/Game.h src/core/Field.h src/core/Fighter.h 
	g++ -ggdb -c -Wall $< -o $@

obj/winTXT.o : src/txt/winTXT.cpp src/txt/winTXT.h src/core/Game.h src/core/Field.h src/core/Fighter.h
	g++ -ggdb -c -Wall $< -o $@

obj/txtSF.o : src/txt/txtSF.cpp src/txt/txtSF.h src/core/Game.h src/core/Field.h src/core/Fighter.h src/core/Hitbox.h
	g++ -ggdb -c -Wall $< -o $@

obj/Game.o : src/core/Game.cpp src/core/Field.h src/core/Game.h src/core/Fighter.h
	g++ -ggdb -c -Wall $< -o $@

obj/Fighter.o : src/core/Fighter.cpp src/core/Fighter.h src/core/Hitbox.h
	g++ -ggdb -c -Wall $< -o $@

obj/Field.o : src/core/Field.cpp src/core/Field.h
	g++ -ggdb -c -Wall  $< -o $@

obj/Collisions.o : src/core/Collisions.cpp src/core/Collisions.h src/core/Hitbox.h
	g++ -ggdb -c -Wall  $< -o $@

obj/Hitbox.o : src/core/Hitbox.cpp src/core/Hitbox.h
	g++ -ggdb -c -Wall  $< -o $@

obj/Animation.o : src/SDL/Animation.cpp src/SDL/Animation.h src/SDL/ResourceManager.h 
	g++ -ggdb -c -Wall  $< -o $@

obj/ResourceManager.o : src/SDL/ResourceManager.cpp src/SDL/ResourceManager.h 
	g++ -ggdb -c -Wall  $< -o $@	

obj/CharacterState.o : src/core/CharacterState.cpp src/core/CharacterState.h 
	g++ -ggdb -c -Wall  $< -o $@

obj/AnimationData.o : src/SDL/AnimationData.cpp src/SDL/AnimationData.h 
	g++ -ggdb -c -Wall  $< -o $@

obj/Menu.o : src/SDL/Menu.cpp src/SDL/Menu.h
	g++ -ggdb -c -Wall  $< -o $@ -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

obj/Image.o : src/SDL/Image.cpp src/SDL/Image.h
	g++ -ggdb -c -Wall  $< -o $@ 

clean : 
	rm -f -r obj/* bin/* 