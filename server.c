#include "server.h"

void run_server(void) {
	int create_socket, new_socket;
	socklen_t addrlen;
	int bufsize = 1024;
	char *buffer = malloc(bufsize);
	struct sockaddr_in address;
	
	if((create_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Error: socket could not be created.\n");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(15000);

	if(bind(create_socket, (struct sockaddr *) &address, sizeof(address)) != 0) {
		perror("server: bind");
		exit(EXIT_FAILURE);
	}

	if(listen(create_socket, 10) < 0) {
			perror("server: listen");
			exit(EXIT_FAILURE);
	}


	while(1) {
		

		printf("Finished listening.\n");

		if((new_socket = accept(create_socket, (struct sockaddr *) &address, &addrlen)) < 0) {
			perror("server: accept");
			exit(EXIT_FAILURE);
		}


		printf("Finished accepting.\n");

		if(new_socket > 0) {
			printf("Client is connected.\n");
		}

		recv(new_socket, buffer, bufsize, 0);
		printf("%s\n", buffer);
		write(new_socket, "hello world.\n", 13);
		close(new_socket);
	}

	close(create_socket);
}
