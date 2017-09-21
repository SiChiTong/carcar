TAEGET=out
CFLAGS= -Wall
INCLUDE=-I/usr/include/
CC=gcc
OBJS=$(patsubst %.c,%.o,$(wildcard ./*.c))

all:$(TAEGET) clean_object

$(TAEGET):$(OBJS)
	$(CC) -o $@ $^ 

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

.PHONY:clean_object
.PHONY:clean
clean:
	rm -rf ./$(TAEGET)
clean_object:
	rm -rf ./*.o

