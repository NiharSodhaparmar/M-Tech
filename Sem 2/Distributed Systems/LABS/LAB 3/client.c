#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    char *ip = "127.0.0.1";
    int port = 5000;

    int sock;
    struct sockaddr_in addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (n < 0)
    {
        perror("Socket error......");
        printf("#######################################################\n");
        printf("\n");

        exit(1);
    }
    printf("TCP server socket created......\n");

    memset(&addr, '\0', sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = port;
    addr.sin_addr.s_addr = inet_addr(ip);

    connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    printf("Server connected......\n");
    printf("#######################################################\n");
    printf("\n");

    while (1)
    {

        bzero(buffer, 1024);
        printf("Enter message to send a server (exit for quit) : \n");
        scanf("%[^\n]%*c", buffer);

        printf("Your message sended to server is : \n");
        printf("%s", buffer);
        printf("\n\n");

        send(sock, buffer, strlen(buffer), 0);

        if ((strncmp(buffer, "exit", 4)) == 0)
        {
            close(sock);
            printf("Server disconnected......\n");
            printf("#######################################################\n");
            printf("\n");
            exit(0);
        }
    }

    return 0;
}