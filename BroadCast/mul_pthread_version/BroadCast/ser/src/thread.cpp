#include "thread.h"
using namespace std;
void* SendMsgThread(void* arg){
	
	SEND_REV_MSG_* buf=(SEND_REV_MSG_*)arg;
	
	struct sockaddr_in* their_addr=buf->their_addr;
	int socket_id=buf->socket_id;
	char find_dev[30];
	strcpy(find_dev,buf->find_dev);
	int ret;
	while(true){
	
		ret=SendData(their_addr,socket_id,find_dev,sizeof(find_dev)); //send msg
		std::cout<<"SendData :"<<"ret\n";
		usleep(3000000);
	}
	//return (void*)ret;
		
}

void* RecieveThread(void* arg){
	
	SEND_REV_MSG_* buf=(SEND_REV_MSG_*)arg;	
	struct sockaddr_in* their_addr=buf->their_addr;
	int socket_id=buf->socket_id;
	char* recieve_buf_=buf->recieve_buf;
	
	DEV_FIND_T* recieve_dev_info_=(DEV_FIND_T*)malloc(sizeof(DEV_FIND_T));
	char rec_buf[1000];
	int recieve_data;
	
	while(true){
		std::cout<<"recieve data!!\n";
		recieve_data=RecieveMsgFormSer(socket_id,rec_buf,
									sizeof(rec_buf),their_addr); //recieve dev info
		if(-1!=recieve_data){
		
			memcpy(recieve_buf_,rec_buf,recieve_data);
			memcpy(recieve_dev_info_,rec_buf,recieve_data);
			
			cout << "ipAddr:" << recieve_dev_info_->ipAddr << "\n";
			cout << "gwAddr:" << recieve_dev_info_->gwAddr << "\n";
			cout << "macAddr:" << recieve_dev_info_->macAddr << "\n";
			cout << "devId:" << recieve_dev_info_->devId << "\n";	
							
		}
	}
		
}

