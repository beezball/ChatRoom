#include "Client.h"



Client::Client(int mode)
{
	this -> mode = mode;
	this -> sock = -1;
}


bool Client::makeConnection(string addr, string portNum) //pseudoconnection for UDP
{

	int status;
	struct addrinfo hints, *result;
	bzero(&hints, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	
	hints.ai_socktype = (mode == UDP) ? SOCK_DGRAM : SOCK_STREAM;

	if(status = getaddrinfo(addr.c_str(), portNum.c_str(),
									 &hints, &result) != 0)
	{
		fprintf(stderr, "%s\n", gai_strerror(error));
		exit(1);
	}

	connInfo = *(result -> ai_addr);

	freeaddrinfo(result);

	if ((sock = socket(connInfo.ai_family,connInfo.ai_socktype,
					 connInfo.ai_protocol)) == -1) //the based way to do it
	{
		perror("Error on Socket Create");
		return false;
	}

	//if UDP, will allow use of send and recv
	if(connect(sock, connInfo.ai_addr, connInfo.ai_addrlen) == -1)
	{
		perror("Error on Socket Connect")
		return false;
	}

	return true;
}