#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis/hiredis.h>
#include <iostream>
#include <unistd.h>
using namespace std;

redisContext* intialConnecRedis(){
	   
    redisContext *c;
    const char *hostname = "127.0.0.1";
    int port = 6379;

    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, timeout);
    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }
	return c;	
}

int updateDevTTL(redisContext *c,char* key){
	
	redisReply *reply;
	reply = (redisReply *)redisCommand(c,"expire %s 20",key);
    printf("return: %s\n", reply->str);
    freeReplyObject(reply);
	return 0;	
	
}

int updateDevStatus(redisContext *c,char* key,char* feild,char* values)
{
	redisReply *reply;
	char command[50];
	sprintf(command,"hset %s %s %s",key,feild,values);
	reply = (redisReply *)redisCommand(c,command);
    printf("return: %s\n", reply->str);
    freeReplyObject(reply);
	return 0;
	
}

int readDevStatus(redisContext *c,char* key,char* feild)
{
	redisReply *reply;
	char command[50];
	sprintf(command,"hget %s %s",key,feild);
	reply = (redisReply *)redisCommand(c,command);
    printf("return: %s\n", reply->str);
    freeReplyObject(reply);
	return 0;
	
}
int main(int argc, char **argv) {

	redisContext *connecRedis=intialConnecRedis();
	
	while(1){
	updateDevStatus(connecRedis,"id","status","1");
	
	updateDevTTL(connecRedis,"id");
	
	sleep(5);
	
	readDevStatus(connecRedis,"id","status");

    
	}
    /* Disconnects and frees the context */
	redisFree(connecRedis);
	

    return 0;
}