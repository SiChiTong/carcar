#ifndef CLIENT_H
#define CLIENT_H

#include<stdlib.h>  
#include<stdio.h>  
#include<string.h>  
#include<sys/types.h>  
#include<netinet/in.h>  
#include<netdb.h>  
#include<sys/socket.h>  
#include<sys/wait.h>  
#include<arpa/inet.h> 
#include <fstream>
#include <unistd.h>
#include <fcntl.h>

int CreatBindSocket(int& sockListen,int port );
int RecieveMsgFormSer(int sockListen,char* reci_msg,int reci_msg_len,struct sockaddr_in* local_addr);
int SendMsgToCli(int sockfd,char* reci_buf,size_t reci_buf_len,struct sockaddr_in clientaddr);

#endif