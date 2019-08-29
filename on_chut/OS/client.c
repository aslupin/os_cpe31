// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8888 

int main(int argc, char const *argv[]) 
{ 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	char *hello = "Hello from client"; 
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
	//if(inet_pton(AF_INET, "10.2.42.208", &serv_addr.sin_addr)<=0)
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	}
	// SHOW NEW SOCKET 
	valread = read( sock , buffer, 1024); 
	printf("%s\n",buffer ); 

	// ACTION WITH SERVER
	while(1){
		char res[1024] = "";
		char req[1024] = "";
		printf("input your req : ");
		scanf(" %s", req);
		send(sock , req , strlen(req) , 0 ); 
		valread = read( sock , res, 1024); 
		printf("from server : %s\n",res );
	}
	 
		//valread = read( sock , buffer, 1024); 
	//printf("%s\n",buffer ); 
	return 0; 
} 

