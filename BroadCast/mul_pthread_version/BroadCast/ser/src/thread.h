#ifndef THREAD_H
#define THREAD_H

#include "server.h"
#include<pthread.h>
#include <stdio.h>      
#include <stdlib.h>
typedef struct SEND_REV_MSG{
		
	char find_dev[30];     //发送缓存
	short find_dev_len;    //发送缓存大小
	int recieve_buff_len;  //接收缓存大小
	int socket_id;         //套接字
	struct sockaddr_in* their_addr=(struct sockaddr_in *)malloc(sizeof(struct sockaddr_in *)); //对端地址信息
	char recieve_buf[2000];       //接收缓存	
		
}SEND_REV_MSG_;

void* SendMsgThread(void* arg);
void* RecieveThread(void* arg);

#endif

