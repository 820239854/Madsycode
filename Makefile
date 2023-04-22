engine=src/Core/Engine.cpp
files=src/main.cpp $(engine)
libs=-lmingw32 -lSDL2main -lSDL2

all: build

build:
	g++ -o ./out/main -Wall -g  ${files} ${libs}

run:
	./out/main.exe