/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "queue.h"
#include "utility.h"
#include "hostd.h"

// Put macros or constants here using #define
#define MEMORY 1024

// Put global environment variables here



// Define functions declared in hostd.h here

int main(int argc, char *argv[])
{
    // ==================== YOUR CODE HERE ==================== //
    
    // Load the dispatchlist
    FILE *fp;
    char buffer[1024];
    char delim[2]=",";
    const char *token;
    int c,counter;

    printf("opening file \"dispatch list\"");
    fp = fopen("dispatchlist","r");
    
    while((c = fgetc(fp)!=EOF)){
        counter = 0;
        //fill buffer with one line
        while(c!='\n'){
            buffer[counter] = c;
        }
        //split buffer into its 8 components
        //arrivalTime,priority,processorTime,mbytes,printers,scanners,modems,cds
        token = strtok(buffer,delim);
        //allocate memory for one process structure
        process * newProcess;
        newProcess = malloc(sizeof(newProcess));
        
        for(int i =0;i<8;i++){
            printf("token at %i is %s\n",i,token);
            switch(i){
                case 0:newProcess->arrivalTime = atoi(token);break;
                case 1:newProcess->priority = atoi(token);break;
                case 2:newProcess->processorTime = atoi(token);break;
                case 3:newProcess->mbytes = atoi(token);break;
                case 4:newProcess->printers = atoi(token);break;
                case 5:newProcess->scanners = atoi(token);break;
                case 6:newProcess->modems = atoi(token) ;break;
                case 7:newProcess->cds = atoi(token);break;
            }
            token =strtok(NULL,delim);
        }


        //clear buffer for next line
        buffer[0]='\0';
    }
    printf("closing file\n");
    fclose(fp);



    // Add each process structure instance to the job dispatch list queue

    // Iterate through each item in the job dispatch list, add each process
    // to the appropriate queues

    // Allocate the resources for each process before it's executed

    // Execute the process binary using fork and exec

    // Perform the appropriate signal handling / resource allocation and de-alloaction

    // Repeat until all processes have been executed, all queues are empty
     
    return EXIT_SUCCESS;
}
