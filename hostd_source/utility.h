/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#ifndef UTILITY_H_
#define UTILITY_H_

// The amount of available memory
#define MEMORY 1024

// Resources structure containing integers for each resource constraint and an
// array of 1024 for the memory
typedef struct reso{
    int printer;
    int scanner;
    int cd;
    int modem;
    int memory[MEMORY];
 } resources;


// Processes structure containing all of the process details parsed from the 
// input file, should also include the memory address (an index) which indicates
// where in the resources memory array its memory was allocated
 typedef struct proc{
     //arrivalTime,priority,processorTime,mbytes,printers,scanners,modems,cds
    int arrivalTime;
    int priority;
    int processorTime; 
    int mbytes;
    int printers;
    int scanners;
    int modems;
    int cds;
    int memIndex;

 } process;



// Include your relevant functions declarations here they must start with the 
// extern keyword such as in the following examples:

// Function to allocate a contiguous chunk of memory in your resources structure
// memory array, always make sure you leave the last 64 values (64 MB) free, should
// return the index where the memory was allocated at
extern int alloc_mem(resources res, int size);

// Function to free the allocated contiguous chunk of memory in your resources
// structure memory array, should take the resource struct, start index, and 
// size (amount of memory allocated) as arguments
extern int free_mem(resources res, int index, int size);

// Function to parse the file and initialize each process structure and add
// it to your job dispatch list queue (linked list)
extern void load_dispatch(char *dispatch_file, node *queue);


#endif /* UTILITY_H_ */