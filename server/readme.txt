gcc -Wall -o server_epoll server_epoll.c

gcc -Wall -o client client.c

execute program:
./client 127.0.0.1 8888

./server_epoll 8888
