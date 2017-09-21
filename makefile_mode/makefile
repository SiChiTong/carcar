TAEGET=out
CFLAGS= -Wall
INCLUDE=-I/usr/include/
CC=gcc
OBJS=$(patsubst %.c,%.o,$(wildcard ./*.c))
all:$(TAEGET)

$(TAEGET):$(OBJS)
	$(CC) -o $@ $^ 

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

.PHONY:clean
clean:
	rm -rf ./*.o
	rm -rf ./$(TAEGET)


