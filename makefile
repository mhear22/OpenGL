CC=clang
SRC=Engine/Source/
OBJ=$(SRC)*.cpp
CFLG= -std=c++11
LIBS=

ifeq ($(UNAME),Darwin)
LIBS= -framework OpenGL -I/usr/include
endif

ifeq ($(UNAME),Windows)
LIBS= -I /usr/include -lXmu -lglut -lGL -lGLU -lm -lGLEW -lglfw3 -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -ldl
endif


all: Main
	
Main:
	$(CC) $(OBJ) $(LIBS) $(CFLG)
	
clean:
	rm a.out