SDLFLAGS = $(shell sdl2-config --libs --cflags)
INCLUDES = $(-I${workspaceFolder}/src/)
ADDITIONALLIBS = -lSDL2_ttf -lSDL2_image -lSDL2_mixer
SRCDIR = src
SRCS := $(shell find $(SRCDIR) -name '*.cpp')

game:
	mkdir -p build
	g++ $(SRCS) -o build/main $(SDLFLAGS) $(ADDITIONALLIBS) -framework OpenGL -std=c++14 -g
	./build/main

git:
	git add .
	git commit -m "$m"
	git push -u origin master

info:
	cd src; git ls-files | xargs wc -l; cd ..