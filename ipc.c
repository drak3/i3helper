#include "ipc.h"

#include <string.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <sys/un.h>
#include <unistd.h>

#define BUF_SIZE 4096

void i3h_test_ipc(char* socket_path) 
{
    int sock, connected;
    struct sockaddr_un address;
    i3_ipc_header_t ipc_header;
    ssize_t sent, received;
    char buf[BUF_SIZE];

    if(strlen(socket_path) + 1 > sizeof(address.sun_path)) {
	printf("Path of socket too long!\n");
	return;
    }

    address.sun_family = AF_LOCAL;
    strncpy(address.sun_path, socket_path, sizeof(address.sun_path));

    sock = socket(AF_UNIX, SOCK_STREAM, 0);  
    if(sock < 0) {
	printf("Could not create socket\n");
	return;
    }
    printf("Successfully created socket\n");
    
    connected = connect(sock, (struct sockaddr *) &address, sizeof(address));

    if(connected == 0) {
	printf("Connected!\n");
    } else {
	printf("Could not connect to socket at \"%s\"\n", address.sun_path);
    }

    strcpy(ipc_header.magic, I3_IPC_MAGIC);
    ipc_header.size = 0;
    ipc_header.type = I3_IPC_MESSAGE_TYPE_GET_VERSION;

    sent = send(sock, &ipc_header, sizeof(ipc_header), 0);

    if(sent < 0) {
	printf("Could not sent message\n");
	return;
    }

    received = recv(sock, buf, BUF_SIZE, 0);

    if(received == 0) {
	printf("Client died\n");
	return;
    } else if(received < 0) {
	printf("Error while receiving\n");
	return;
    } else {
	i3_ipc_header_t response_head = *( (i3_ipc_header_t*) buf);
	char *payload = buf + sizeof(i3_ipc_header_t);
	buf[received] = '\0';
	printf("Received:\n \ttype: %d\n\tlength:%d\n", response_head.type, response_head.size); 
	printf("Received Payload:\n%s", payload);
    }
    
    close(sock);


}
