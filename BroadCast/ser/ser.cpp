#include "server.h"
int main(){ 
 
    char msg[128] = "I am broadCast message from server!"; 
	struct sockaddr_in their_addr;
	int port=4001;
	int socket_id;
	int reci_msg_len(128);
	
    CreateSocket(&their_addr,port,socket_id );	
    SendData(&their_addr,socket_id,msg,sizeof(msg));
	RecieveMsgFormSer(socket_id,msg,reci_msg_len,&their_addr);       
}  

