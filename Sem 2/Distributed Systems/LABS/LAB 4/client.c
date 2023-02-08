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
        printf("Enter message to send a server (exit for quit, load for get load) : \n");
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

    receive:
        bzero(buffer, 1024);
        recv(sock, buffer, sizeof(buffer), 0);
        printf("Message from server is : %s\n", buffer);
        printf("\n");

        if ((strncmp(buffer, "exit", 4)) == 0)
        {
            close(sock);
            printf("Server disconnected......\n");
            printf("#######################################################\n");
            printf("\n");
            exit(0);
        }

        if ((strncmp(buffer, "load", 4)) == 0)
        {
            bzero(buffer, 1024);
            system("mpstat| grep -w \"all\"| awk '{o = 100-$NF; {print o} }' >> load.txt");
            FILE *file;
            char load[10];
            float cpu_load;
            file = fopen("load.txt", "r");
            if (file == NULL)
            {
                printf("file can't be opened......\n");
                printf("#######################################################\n");
                printf("\n");
            }

            fgets(load, 10, file);
            fclose(file);
            cpu_load = atof(load);
            if (cpu_load > 70)
            {
                strcpy(buffer, "Client is overload\n");
            }
            else if (30 > cpu_load && 70 < cpu_load)
            {
                strcpy(buffer, "Client is moderately loaded\n");
            }
            else
            {
                strcpy(buffer, "Client is lightly loaded\n");
            }

            printf("Your message sended to server is : \n");
            printf("%s", buffer);
            printf("\n\n");
            send(sock, buffer, strlen(buffer), 0);
            goto receive;
        }
    }

    return 0;
}