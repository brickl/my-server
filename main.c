#include <stdlib.h>
#include <stdio.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include "server.h"

int main(int argc, char* argv[]) {	
	
	run_server();
	return 0;
}
