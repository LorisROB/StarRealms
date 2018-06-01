CC=g++ 
CCFLAGS= -O3 #Option d'optimisation du programme
LIBFLAGS= -lSDL -lSDL_gfx -lSDL_image -lSDL_ttf
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
EXEC= exec

all: $(EXEC)

$(EXEC): $(OBJ)
		$(CC) $^ -o $@	$(LIBFLAGS)

%.o: %.cpp
		$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
		g++ -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC)


