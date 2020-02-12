#include <stdio.h>
#include <unistd.h>
#include <thread> 
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
//This file demonstrates Parent process having a child process
//each one makes a thread which use a pipe as internal comunication
//
// FOR COMPILE THIS FILE ENTER THE NEXT g++ COMMAND
//g++ -o Exec Family.cpp -pthread
#define MSGSIZE 11
using namespace std;
int fd[2];
int nbytes;

void tx() 
{
    int counter =0;
    char buffer [MSGSIZE];
    memset(buffer,0,sizeof(buffer));
    /* Closes up input side of pipe */
    close(fd[0]);
    while(counter<10)
    {
        sprintf (buffer, "hellow %d\r\n", counter);
        printf("TX: %s\r\n",buffer);
        write(fd[1], buffer,MSGSIZE);
        sleep(1);
        counter++;
    }
    /* Send "string" through the output side of pipe */
}

void rx()
{
    int counter = 0;
    char readbuffer[MSGSIZE];
    memset(readbuffer,0,sizeof(readbuffer));
    /* Parent process closes up output side of pipe */
    close(fd[1]);
    while(counter < 10)
    {
        nbytes = read(fd[0], readbuffer, MSGSIZE);
        printf("RX: %s\r\n", readbuffer);
        counter++;
    }
    /* Read in a string from the pipe */
}


int main(int argc, char **argv)
{
    int counter = 0;
    if (pipe(fd) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if(pid == 0)
    {
        thread first (tx);     // spawn new thread that calls foo()
        first.join();                // pauses until first finishes
            /* Child process closes up input side of pipe */
    }
    else
    {
        thread second (rx);  // spawn new thread that calls bar(0)
        second.join();               // pauses until second finishes
    }
    
    return 0;
}