#include "server.h"
using namespace std;
int main(){ 
 
    char find_dev[30];
	char recieve_dev_info[100];
	char recieve_buff[2000];  
	int recieve_data;
	
	DEV_FIND_T* recieve_dev_info_=(DEV_FIND_T*)malloc(sizeof(DEV_FIND_T));
	struct sockaddr_in their_addr;
	int port=PORT;
	int socket_id;
	//int reci_msg_len(128);
	
	strcpy(find_dev,(char*)IP_FOUND);
	
    CreateSocket(&their_addr,port,socket_id );	//initial sock
	
    SendData(&their_addr,socket_id,find_dev,sizeof(find_dev)); //send msg
	while(true){
	
		recieve_data=RecieveMsgFormSer(socket_id,recieve_buff,sizeof(recieve_buff),&their_addr); //recieve dev info
		if(-1!=recieve_data){
			memcpy(recieve_dev_info_,recieve_buff,recieve_data);
	
			cout<<"ipAddr:"<<recieve_dev_info_->ipAddr<<"\n";
			cout<<"gwAddr:"<<recieve_dev_info_->gwAddr<<"\n";
			cout<<"macAddr:"<<recieve_dev_info_->macAddr<<"\n";
			cout<<"devId:"<<recieve_dev_info_->devId<<"\n";
		}
	}
	
	#if 0
	RecieveMsgFormSer(socket_id,recieve_dev_info,sizeof(recieve_dev_info),&their_addr);	
	cout<<"recieve_dev_info:"<<recieve_dev_info<<"\n";
	#endif
}  

