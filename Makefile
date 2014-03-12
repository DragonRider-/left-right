all:
	g++ *.cpp \
	-lSDL2 -lSDL2_image -lSDL2_mixer \
	-Wall -Wextra -pedantic \
	-o left-right.exec
run: all
	./left-right.exec
