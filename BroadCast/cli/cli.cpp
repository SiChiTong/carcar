#include "client.h"
#include <unistd.h>

int main(int argc,char** argv){  
 
	int sockListen;
	int port(PORT);
	char reci_msg[1024];
	int reci_msg_len=1024;
	struct sockaddr_in remote_addr;
	
	char send_buff[2000];
	
	DEV_FIND_T tem_para;
	sprintf(tem_para.ipAddr,"0.0.0.0");
	memcpy(send_buff,&tem_para,sizeof(tem_para));
	
	CreatBindSocket(sockListen,port );
	while(true){
		RecieveMsgFormSer(sockListen,reci_msg,reci_msg_len,&remote_addr);
		if(strstr(reci_msg,(char*)IP_FOUND)){
			//printf("remote ip:%s port: %d",inet_ntoa(local_addr.sin_addr),inet_ntoa(local_addr.sin_port));
			printf ("send msg\n");
			SendMsgToCli(sockListen,send_buff,sizeof(tem_para)+1,remote_addr);  
		}
		usleep(10000);
	}
} 