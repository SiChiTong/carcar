#include "client.h"

int CreatBindSocket(int& sockListen,int port ){
	 
    if((sockListen = socket(AF_INET, SOCK_DGRAM, 0)) == -1){  
        printf("socket fail\n");  
        return -1;  
    }  
    int set = 1;  
    setsockopt(sockListen, SOL_SOCKET, SO_REUSEADDR, &set, sizeof(int));  
    struct sockaddr_in local_addr;  
    memset(&local_addr, 0, sizeof(struct sockaddr_in));  
    local_addr.sin_family = AF_INET;  
    local_addr.sin_port = htons(port);  
    local_addr.sin_addr.s_addr = INADDR_ANY;  
    // 必须绑定，否则无法监听  
    if(bind(sockListen, (struct sockaddr *)&local_addr, sizeof(struct sockaddr)) == -1){  
        printf("bind fail\n");  
        return -1;  
    }
	return 0;
	
}

int RecieveMsgFormSer(int sockListen,char* reci_msg,int reci_msg_len,
					  struct sockaddr_in* remote_addr){
						  
	int recvbytes;  
    socklen_t addrLen = sizeof(struct sockaddr_in);  
    if((recvbytes = recvfrom(sockListen, reci_msg, reci_msg_len, 0,  
        (struct sockaddr *)remote_addr, &addrLen)) != -1){  
        reci_msg[recvbytes] = '\0';  
        printf("receive a broadCast messgse:%s\n", reci_msg);  
    }else{  
        printf("recvfrom fail\n");  
    }  
    //close(sockListen);
	return 0;
						  						  						  
}

int SendMsgToCli(int sockfd,char* reci_buf,size_t reci_buf_len,struct sockaddr_in clientaddr){
	
    int clientlen = sizeof(clientaddr);
	int n = sendto(sockfd, reci_buf, reci_buf_len, 0, 
	       (struct sockaddr *) &clientaddr, clientlen);	
		
	if (n < 0){ 
		printf("ERROR in sendto");
		return -1;
	}
	return 0;
}













