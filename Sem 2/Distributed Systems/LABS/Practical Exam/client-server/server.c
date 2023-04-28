#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    char *ip = "127.0.0.1";
    int port = 5000;

    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
        perror("Socket error......\n");

        printf("\n");
        exit(1);
    }

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    n = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (n < 0)
    {
        perror("Bind error......");

        printf("\n");
        exit(1);
    }

    listen(server_sock, 5);
    printf("Serever running......\n");

    printf("\n");

    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
    printf("Client Connected......\n");

    printf("\n");

    while (1)
    {
        bzero(buffer, 1024);
        recv(client_sock, buffer, sizeof(buffer), 0);
        printf("Message from client is : %s\n", buffer);
        printf("\n");

        if ((strncmp(buffer, "load", 4)) == 0)
        {
        	FILE *file;
        	char *load;

            	system("mpstat| grep -w \"all\"| awk '{o = 100-$NF; {print o} }' >> data1.txt");
            	
            	file = fopen("data1.txt");
		    if (file == NULL)
		    {
		        printf("file can't be opened......\n");
		        printf("\n");
		    }

		    fgets(load, 10, file);
		    fclose(file);
            	
            	
            	
	            send(client_sock, load, strlen(load), 0);
        }
    }

    return 0;
}
