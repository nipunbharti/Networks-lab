#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	FILE *html_data;
	html_data = fopen("index.html", "r");

	char response_data[1024];
	fgets(response_data, 1024, html_data);

	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n"; //Client header response
	strcat(http_header, response_data);
	printf("%s\n", http_header);

	//Create a server socket
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);

	//Address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8001);
	server_address.sin_addr.s_addr = INADDR_ANY;
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	//Listener for connections
    listen(server_socket, 5);

    int client_socket;
    while(1){
    	client_socket = accept(server_socket, NULL, NULL);
    	if(client_socket >= 0){
	        printf("HIT!\n");
	    }
	    send(client_socket, http_header, sizeof(http_header), 0);
	    close(client_socket);
    }
	return 0;
}