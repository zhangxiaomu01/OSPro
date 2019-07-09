#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define g_bufferSize 256

void error(char* msg){
    perror(msg);
    exit(1);
}

void setupClient(int argc, char* argv[]){
    //similar to server, we do not need to have acSockfd
    int sockfd, portID, n;
    //store server address
    struct sockaddr_in servAddr;
    /* 
    This defines a host computer on the internet. The members of this structure are:
    - h_name: official name of the host
    - h_aliases: a zero terminated array of alternate names for the host
    - h_addrtype: the type of address being returned; in our case, should be AF_INET
    - h_length: the length, in bytes, of the address
    - h_addr_list: A pointer to a list of netwark addresses for the named host. Host addresses are returned in
                   network byte order.
    - h_addr is an alias for the first address in the array of network addresses.
     */
    struct hostent *server;

    //Check server.c for detail
    char msgBuffer[g_bufferSize];
    if(argc < 3){
        fprintf(stderr, "Usage %s hostname port", argv[0]);
        exit(0);
    }
    portID = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
        error("Error: initialize socket fails.");
    
    //Get the server by its name. Takes such a name as an argument and returns a pointer to 
    //a hostent containing information about that host. *h_addr contains the IP address.
    //If the server is NULL, then the system cannot locate the host with this name!
    server = gethostbyname(argv[1]);
    if(server == NULL){
        fprintf(stderr, "Error: no such host exists!");
        exit(0);
    }

    __bzero((char*) &servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    //Copy the address from server to servAddr
    bcopy((char*)server->h_addr_list[0], (char*) &servAddr.sin_addr.s_addr, server->h_length);
    servAddr.sin_port = htons(portID);

    //The connection function is called by the client to establish a connection to the server.
    //3 arguments: socket file descriptor / address of the host / size of the address
    //returns 0 if success, -1 otherwise
    //Client needs to know the port number of the server, but it does not need to know the port number of its own
    if(connect(sockfd, &servAddr, sizeof(servAddr)) < 0)
        error("Error: connecting is impossible for now!");
    
    printf("Please enter the message: ");
    __bzero(msgBuffer, g_bufferSize);
    fgets(msgBuffer, g_bufferSize-1, stdin);
    n = write(sockfd, msgBuffer, strlen(msgBuffer));
    if(n < 0)
        error("Error: writing message to buffer fails!");
    bzero(msgBuffer, g_bufferSize);
    n = read(sockfd, msgBuffer, g_bufferSize-1);
    if(n < 0)
        error("Error: reading message to buffer fails!");
    
    printf("Test: %s \n", msgBuffer);
}

int main(int argc, char *argv[])
{
    setupClient(argc, argv);
    return 0;
}
