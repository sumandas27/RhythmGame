SDLFLAGS = $(shell sdl2-config --libs --cflags)
ADDITIONALLIBS = -lSDL2_ttf -lSDL2_image -lSDL2_mixer
SRCDIR = src
SRCS := $(shell find $(SRCDIR) -name '*.cpp')

game:
	mkdir -p build
	g++ $(SRCS) -o build/main $(SDLFLAGS) $(ADDITIONALLIBS) -framework OpenGL -std=c++14 -g
	./build/main

cloc:
	git clone --depth 1 https://github.com/sumandas27/RhythmGame.git
	cloc RhythmGame --fullpath --not-match-f="(Makefile)" --exclude-ext=json,plist
	rm -rf RhythmGame