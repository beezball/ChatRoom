#include <iostream>
#include <string>
#include <string.h>
#include <string>
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <netdb.h> //hostent
#include <sys/types.h>

#ifndef CLIENT_H
#define CLIENT_H



#define UDP 			0
#define TCP 			1
#define MAXLENGTH 		4096


using namespace std;

/*
Client that makes and sustains a connection until closed
Works with IPv4 and IPv6
Supports UDP
*/

class Client {
private:
	int sock;
	int mode; //0 for TCP, 1 for UDP
	string addr; //hostname or IP address
	struct sockaddr_in connInfo;

	//helper functions
	

public:
	Client(int mode);
	bool makeConnection(string addr, string portNum);
	string recvData(int len);
	bool sendData(string toSend); //false if send fails
	void closeConnection(); //closes socket and cleans up 
};








#endif