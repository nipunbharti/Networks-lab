/*
	Client for file transferring through TCP
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	//Create a socket
	int client_socket = socket(AF_INET, SOCK_STREAM, 0);

	//Specify the server address and port
	struct sockaddr_in client_address;
	bzero(&client_address, sizeof(client_address));
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(8080);
	client_address.sin_addr.s_addr = INADDR_ANY;

	//Connect to the IP
	int connect_status = connect(client_socket, (struct sockaddr *) &client_address, sizeof(client_address));

	//Error checking
	if(connect_status < 0){
		int errno;
		perror("Error");
	}
	char buffer[100];

	FILE *file;
	file = fopen("one.txt", "r");
	fgets(buffer, sizeof(buffer), file);

	//Write to server
	write(client_socket, buffer, sizeof(buffer));
	printf("File sent successfully!\n");

	close(client_socket);
	return 0;
}