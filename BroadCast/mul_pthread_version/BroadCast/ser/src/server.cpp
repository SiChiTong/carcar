#include "server.h"

int CreateSocket(struct sockaddr_in* theirAddr,int& port,int& socket_id ){
  	
#ifdef __WIN32
	const char optval = 1;
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	// setup socket api  
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return -1;
	}

	if (LOBYTE(wsaData.wVersion) != 2 ||
		HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		return -1;
	}

	//create socket 
	socket_id = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET == socket_id)
	{
		err = WSAGetLastError();
		printf(" error! error code is %d/n", err);
		return -1;
	}
	bool bOpt = true;
	//设置该套接字为广播类型  
	setsockopt(socket_id, SOL_SOCKET, SO_BROADCAST, (char*)&bOpt, sizeof(bOpt));
	
	// config server ip
	theirAddr->sin_family = AF_INET;
	theirAddr->sin_port = htons(port);
	theirAddr->sin_addr.s_addr = INADDR_BROADCAST;

#else
	if ((socket_id = socket(PF_INET, SOCK_DGRAM, 0)) == -1){
		printf("socket fail\n");
		return -1;  
	}
	int optval = 1;//这个值一定要设置，否则可能导致sendto()失败 
    setsockopt(socket_id, SOL_SOCKET, SO_BROADCAST | SO_REUSEADDR, &optval, sizeof(int));   
    theirAddr->sin_family = AF_INET;  
	theirAddr->sin_port = htons(port);
    theirAddr->sin_addr.s_addr = inet_addr("255.255.255.255");  
   
#endif

	return 0;
}

int SendData(struct sockaddr_in* theirAddr,int socket_id,char* msg,int msg_size){
	
	ssize_t sendBytes;
	if((sendBytes = sendto(socket_id, msg, msg_size, 0,  
            (struct sockaddr *)theirAddr, sizeof(struct sockaddr))) == -1){  
        printf("sendto fail, errno=%d\n", errno);  
        return -1;  
    }  
    printf("msg=%s, msgLen=%zu, sendBytes=%zd\n", msg, strlen(msg), sendBytes);  
    //close(socket_id);  
    return 0;  
	
}

int RecieveMsgFormSer(int sockListen,char* reci_msg,int reci_msg_len,
					  struct sockaddr_in* remote_addr){
						  
	int recvbytes;  
    socklen_t addrLen = sizeof(struct sockaddr_in);  
    if((recvbytes = recvfrom(sockListen, reci_msg, reci_msg_len, 0,  
        (struct sockaddr *)remote_addr, &addrLen)) != -1){  
        //reci_msg[recvbytes] = '\0';  
        //printf("receive messgse::%s\n", reci_msg);  
    }else{  
        printf("recvfrom fail\n"); 
		return -1;
    }  
    //close(sockListen);
	return recvbytes;
						  						  						  
}







