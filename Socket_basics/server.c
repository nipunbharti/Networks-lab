#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    char server_msg[256] = "Hello from the server side!";
    char buffer[1024] = {0};
    //Creation of socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //Bind the socket to an IP
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    //Listener for connections
    listen(server_socket, 5);

    int client_socket;
    while(1){
        client_socket = accept(server_socket, NULL, NULL); //Null holds the address the sockets are coming from
        int valread = read(client_socket, buffer, 1024);
        printf("Message from client: %s\n", buffer);
        //Send data
        send(client_socket, buffer, sizeof(buffer), 0);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}