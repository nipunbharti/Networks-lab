#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	//Creation of socket
	int net_socket;
	net_socket = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket_fd: %d\n", net_socket);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET; //Type of address
	server_address.sin_port = htons(8080); //Port we're working on
	server_address.sin_addr.s_addr = INADDR_ANY;

	//Connect to network
	int connect_status = connect(net_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if(connect_status == -1){
		printf("Connection failed.\n");
		return 0;
	}
	//Socket listener
	char server_res[256];
	recv(net_socket, &server_res, sizeof(server_res), 0); //Recieve response
	printf("The server sent the data: %s\n", server_res);

	//Close socket
	close(net_socket);
	return 0;
}