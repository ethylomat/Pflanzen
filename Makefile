TARGET = baum
LIBS = -lncurses
CC = g++
CFLAGS = -g -Wall -std=c++11

.PHONY: default all clean run $(TARGET)

default: $(TARGET)
all: default

SOURCES = Bäume/main.cpp Bäume/Tree.cpp Bäume/Terminal.cpp Bäume/Game.cpp Bäume/Node.cpp Bäume/Word.cpp Bäume/Sun.cpp Bäume/helper.cpp
HEADERS = Bäume/Terminal.h Bäume/Tree.h Bäume/Vec2D.h Bäume/Game.h Bäume/Node.h Bäume/Word.h Bäume/Sun.h Bäume/helper.h

$(TARGET):
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)
	
clean:
	-rm -f $(TARGET)
	
