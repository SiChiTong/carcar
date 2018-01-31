#include "server.h"
#include "thread.h"

using namespace std;
int main(){ 
	
#if 0
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
	
	recieve_data=RecieveMsgFormSer(socket_id,recieve_buff,sizeof(recieve_buff),&their_addr); //recieve dev info
	if (recieve_data != -1){

		memcpy(recieve_dev_info_, recieve_buff, recieve_data);

		cout << "ipAddr:" << recieve_dev_info_->ipAddr << "\n";
		cout << "gwAddr:" << recieve_dev_info_->gwAddr << "\n";
		cout << "macAddr:" << recieve_dev_info_->macAddr << "\n";
		cout << "devId:" << recieve_dev_info_->devId << "\n";
	}
	else{
	
		cout<<"recieve data failed !!!\n";
	}
	#if 0
	RecieveMsgFormSer(socket_id,recieve_dev_info,sizeof(recieve_dev_info),&their_addr);	
	cout<<"recieve_dev_info:"<<recieve_dev_info<<"\n";
	#endif
	//closesocket(sockClient);
	system("pause");
	
#endif
	
	pthread_t send_th,recie_th;
	int ret_sed,ret_reci;
	void* retval;
	
	SEND_REV_MSG_* send_msg(new SEND_REV_MSG_());
	SEND_REV_MSG_* recie_msg(new SEND_REV_MSG_());
	
	struct sockaddr_in their_addr;
	int socket_id;
	int port=PORT;
		
	CreateSocket(&their_addr,port,socket_id );	//initial sock
	
	memcpy(send_msg->their_addr,&their_addr,
			sizeof(sockaddr_in));
			
	memcpy(recie_msg->their_addr,&their_addr,
			sizeof(sockaddr_in));
			
	send_msg->socket_id=socket_id;
	recie_msg->socket_id=socket_id;
		
	strcpy(send_msg->find_dev,(char*)IP_FOUND);
				
	ret_sed=pthread_create(&send_th,NULL,
							SendMsgThread,(void*)send_msg);
	if(ret_sed!=0){
		std::cout<<"ret_sed failed!!\n";
		return -1;				
	}
	
	ret_reci=pthread_create(&recie_th,NULL,
							RecieveThread,(void*)recie_msg);
	if(ret_reci!=0){
		std::cout<<"ret_reci failed!!\n";
		return -1;				
	}
	
	pthread_join(send_th,&retval);
	pthread_join(recie_th,&retval);
	
	delete recie_msg;
	delete send_msg;
	
}  








