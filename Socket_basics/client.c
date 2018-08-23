#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	// while(1){
		//Creation of socket
		int client_socket;
		char hello[256] = "Hello from the client side!";
		client_socket = socket(AF_INET, SOCK_STREAM, 0);

		struct sockaddr_in server_address;
		server_address.sin_family = AF_INET; //Type of address
		server_address.sin_port = htons(8080); //Port we're working on
		server_address.sin_addr.s_addr = INADDR_ANY;

		//Connect to network
		int connect_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
		if(connect_status == -1){
			printf("Connection failed.\n");
			return 0;
		}
		printf("Enter the message for server:\n");
		fgets(hello, 256, stdin);
		send(client_socket, hello, sizeof(hello), 0);
		//Socket listener
		char server_res[256];
		recv(client_socket, &server_res, sizeof(server_res), 0); //Recieve response
		printf("The server sent the data: %s\n", server_res);

		//Close socket
		close(client_socket);
		// int c, d;
		// for (c = 1; c <= 32767; c++)
		//    for (d = 1; d <= 32767; d++){
		//    }
	// }
	return 0;
}