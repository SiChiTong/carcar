#include "client.h"
int main(int argc,char** argv){  
 
	int sockListen;
	int port(4001);
	char reci_msg[1024];
	int reci_msg_len=1024;
	struct sockaddr_in remote_addr;
	
	CreatBindSocket(sockListen,port );
	RecieveMsgFormSer(sockListen,reci_msg,reci_msg_len,&remote_addr);
	//printf("remote ip:%s port: %d",inet_ntoa(local_addr.sin_addr),inet_ntoa(local_addr.sin_port));
	SendMsgToCli(sockListen,reci_msg,reci_msg_len,remote_addr);    
} 