engine=src/Core/Engine.cpp
textureManager=src/Graphics/TextureManager.cpp	
files=src/main.cpp $(engine) $(textureManager)
libs=-lmingw32 -lSDL2main -lSDL2 -lSDL_image

all: build

build:
	g++ -o ./out/main -Wall -g  ${files} ${libs}

run:
	./out/main.exe