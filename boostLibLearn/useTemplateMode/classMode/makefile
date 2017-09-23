TAEGET=out
CFLAGS= -Wall
INCLUDE=-I/usr/include/
CC=g++
OBJS=$(patsubst %.c,%.o,$(wildcard ./*.c))
OBJS=$(patsubst %.cpp,%.o,$(wildcard ./*.cpp))

all:$(TAEGET) clean_object

$(TAEGET):$(OBJS)
	$(CC) -o $@ $^ 

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

.cpp.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

.PHONY:clean_object
.PHONY:clean
clean:
	rm -rf ./$(TAEGET)
	rm -rf ./*.o
clean_object:
	rm -rf ./*.o

