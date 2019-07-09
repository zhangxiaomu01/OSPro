/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
//Great tutorial from http://www.linuxhowtos.org/C_C++/socket.htm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int g_bufferSize = 256;

void error(char* msg){
    perror(msg);
    exit(1);
}

void GenerateUpperCaseFunc(char* msg){
    int len = strlen(msg);
    for(int i = 0; i < len; ++i){
        if(msg[i] >= 'a' && msg[i] <= 'z'){
            msg[i] = msg[i] - 32;
        }
    }
}

void HandleClientEventFunc(int acSockfd){
    //Server will read the characters from the socket connection to this buffer
    char msgBuffer[g_bufferSize];
    //n - return value for the read() and write() calls / contains the number of characters read or written.
    int n;

    /*
    Note that we would only go to this point when client successfully connected to the server! We first initialize the buffer with 0s, then read from the socket.
    Note we use acSockfd, instead of the sockfd. read() will block until there is something for it to read in the socket, i.e. after the client has executed a
    write().
     */
    __bzero(msgBuffer, g_bufferSize);
    //The read() function will read the total number of characters in the socket or g_bufferSize - 1 in this case.
    n =read(acSockfd, msgBuffer, g_bufferSize-1);
    if(n < 0)
        error("Error: Reading from the socket : server!");
    printf("Here is the original message: %s \n", msgBuffer);
    
    GenerateUpperCaseFunc(msgBuffer);

    //Once a connection has been successfully connected, both ends can both read and write to the connection. Naturally, everything written by the client will 
    //be read by the server, everything written by the server will be read by the client. The last argument is the size of the message.
    n = write(acSockfd, msgBuffer, g_bufferSize);

    if(n == -1)
        error("Error: server cannot write to socket!");
}

void setServer(int argc, char *argv[]){
    //sockfd / acSockfd - file descriptors for socket. sockfd will be used in socket() call, and acSockfd will be used in accept()
    int sockfd, acSockfd;

    //portID - ID for port number on which the server accepts connection
    //clientLen - stores the size of the address of the client. This is needed for the accept system call.
    
    int portId, clientLen;

    int pid; //defines the process id number

    //sockaddr_in contains an internet address. Check the definition for more info.
    struct sockaddr_in servAddr, clientAddr;

    //Check whether the user input is valid. The user should pass in the port number on which the server will accept connections as an argument.
    if(argc < 2){
        fprintf(stderr, "Error, no port ID provided!\n");
        exit(1);
    }

    //Create a new socket.
    /*
    - First argument is address domain. Two possible address domains: 1. Unix domain for two processes share a common file system (AF_UNIX); 
    2. Internet domain for any two hosts on the internet (AF_INET). (Other options can serve for specialized purposes.)
    - Second argument is type of the socket. Two choices are here: 1. A stream socket in which characters are read in a continuous stream as if from
    a file or pipe (SOCK_STREAM); 2. A datagram socket in which the messages are read in chunks (SOCK_DGRAM). 
    - Third argument is the protocal. If set to 0, the operating system will choose the most appropriate protocal. TCP for stream sockets, UDP for 
    datagram sockets.
    The socket() system call returns an entry into the file descriptor table (i.e. a small integer). This value is used for subsequent reference to 
    this socket. Return -1 if it fails.
     */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        error("Error: socket cannot be created!");
    }

    //set servAddr buffer to 0. 
    __bzero((char*) &servAddr, sizeof(servAddr));

    //get the port number. atoi() converts a string to integer.
    portId = atoi(argv[1]);

    //Set the code for the address family. Should be AF_INET in our case.
    servAddr.sin_family = AF_INET;  

    //Set the port ID. Note we need to convert the portID to network byte order using function htons(). This function converts the port ID in host byte 
    //order to network byte order.
    servAddr.sin_port = htons(portId);

    //IP address of the host. For server code, this will always be the IP address of the machine on which the server is running. INADDR_ANY gets this address.
    servAddr.sin_addr.s_addr = INADDR_ANY;    

    /*
    bind() system call binds a socket to an address, in this case the address of current host and port number on which the server will run. It takes 3 arguments:
    - 1. socket file descriptor, the address to which is bound, and the size of the address to which it is bound!
    - 2. a pointer to a structure of type sockaddr, we need to cast the sockaddr_in type to pass in as an argument.
    This function call can fail for a number of reasons, most obvious one is that the socket is already in use on this machine.
     */
    if(bind(sockfd, (struct sockaddr*)(&servAddr), sizeof(servAddr)) < 0)
        error("Error: server binding fails!");
    
    /*
    listen() system call allows the process to listen on the socket for connections! The second argument specifies the size of the backlog queue - the maximum
    number of connections that can be waiting while the process is handling a particular connection! If the first argument is a valid socket, this call 
    cannot fail. Therefore, the code does not check for error.
     */
    listen(sockfd, 5);
    clientLen = sizeof(clientAddr); 

    while(1){
        /*
        The accept() system call causes the process to block until a client connects to the server. Thus it wakes up the process when a connection from a client
        has been successfully established. It returns a new file descriptor, and all communication on this connection should be done using the new file descriptor.
        The second argument is a reference pointer to the address of the client on the other end of the connection, the third argument is the size of this structure.
        */
        acSockfd = accept(sockfd, (struct sockaddr*)(&clientAddr), &clientLen);
        if(acSockfd == -1)
            error("Error: accept process fails.\n");
        
        //create a new process.
        pid = fork();
        if(pid == -1)
            error("Error: process cannot be created!\n");
        
        if(pid == 0){
            close(sockfd);
            HandleClientEventFunc(acSockfd);
            exit(0);
        }
        else close(acSockfd); //main thread will close acSockfd
    }
}

int main(int argc, char *argv[])
{
    setServer(argc, argv);
    return 0;
}
