#include <stdio.h>
#include <errno.h>
#include<string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include <pthread.h>

#define USB_CONNECTED 4 

int Pipe[2]; // pipe[0] TX pipe[1] RX
char string[10];

void* lasvegas(void *vargp)
{
    int a = 0;
    read(Pipe[0], string, 10); // bloquear
    printf("%s\r\n",string);

    while(USB_CONNECTED != a)
    {
        usleep(1000000);
        printf("viva las vegas\n");
        a++;
    }
    return NULL;
}

void* bar(void *vargp)
{
    int a = 0;
    
    while(USB_CONNECTED != a)
    {
        usleep(1000000);
        printf("cosas shadys\n");
        a++;
    }
    write(Pipe[1], "Deslock", strlen("Deslock"));
    return NULL;
}



 
int main(int argc, char const *argv[])
{
    pthread_t thread_id;
    pthread_t thread_id2;
    printf("Before Thread\n");
   
    if (pipe(Pipe) == -1){
        perror("Filed to create pipe");
        exit(1);
    }


    pthread_create(&thread_id, NULL, lasvegas, NULL);    
    pthread_create(&thread_id2, NULL, bar, NULL);


    
    pthread_join(thread_id, NULL); // esperar a que el thread termine
    pthread_join(thread_id2, NULL);
    printf("After Thread\n");
    return 0;


    return 0;
}
