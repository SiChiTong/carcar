#ifndef SERVER_H
#define SERVER_H

#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<sys/types.h>  
#include<sys/socket.h>  
#include<sys/wait.h>  
#include<netinet/in.h>  
#include<arpa/inet.h>  
#include<errno.h> 
#include <fstream>
#include <unistd.h>
#include <fcntl.h> 

#define PORT 8898//8668             // 端口号
#define IP_FOUND "HHWW_FOUND"       // IP发现命令
#define NET_ADDRSIZE 20		        // "192.168.188.168" 给20个bytes;"00:AB:BB:CC:BA:00" 共18个字节

typedef  struct  _DevFind_ 
{ 
    int             realChannelNum;            //本设备可用通道数
    int             serverType;                //设备类型, 0,dvs; 1,ipc; 2,nvr 
    int             portNo;                    //监听端口 
    int             netType;                   //网络类型 
    char            hostName[32];              //设备名 
    char            macAddr[NET_ADDRSIZE];     //MAC地址 
    char            ipAddr[NET_ADDRSIZE];      //IP地址 
    char            netMask[NET_ADDRSIZE];     //网络掩码 
    char            gwAddr[NET_ADDRSIZE];      //网关地址 
    char            versionNo[32];             //版本号 
    unsigned int    portOffset;                //端口偏移 
    char            firstDns[NET_ADDRSIZE];    //主DNS 
    char            secondDns[NET_ADDRSIZE];   //备用DNS 
    unsigned short  dnsGetFlag;                //dns 自动获得标志,0: 自动获得, 1: 手动获得 
    unsigned short  webPort;                   //web 端口配置 
    char            dhcpFlag;
    char            unused[3];
    char            deviceType[32];            //产品型号 
    char            devId[52];                 // 产品Id
    char            devCode[32];               //  产品序列号
} DEV_FIND_T;


int CreateSocket(struct sockaddr_in* theirAddr,int& port,int& socket_id );
int SendData(struct sockaddr_in* theirAddr,int socket_id,char* mag,int msg_size);
int RecieveMsgFormSer(int sockListen,char* reci_msg,int reci_msg_len,
					  struct sockaddr_in* remote_addr);

#endif