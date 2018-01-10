TARGET=out
INCLUDE=-I/usr/local/include
LIBRARY= -lpthread
CFLAGS= -g -Wall -std=c++11
CC=g++
OJB=$(patsubst %c,%.o,$(wildcard ./*.c))
OJB=$(patsubst %cpp,%.o,$(wildcard ./*.cpp))

all:$(TARGET)
$(TARGET):$(OJB)
	$(CC) -o $@ $^ $(LIBRARY)

	
.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)
	
.cpp.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

.PHONY:clean_obj 
.PHONY:clean

clean_obj:
	clean -rf $(OJB) 
clean:
	clean -rf $(TARGET)
	
	

