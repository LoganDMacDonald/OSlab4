/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2018, Members of Group
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "utility.h"


// Define your FIFO queue functions here, these will most likely be the
// push and pop functions that you declared in your header file



 node *push(node *head, process proc)
 {
     //Start at the head of the list
      node * visiting = head;

      //Go to the last node
      if (visiting != NULL);
      while (visiting->next != NULL)
      { visiting = visiting->next; }

    //Create a new node, and attach it to the list
      node * new_node;
      new_node = malloc(sizeof(node));
      new_node->proc = proc;
      visiting->next = new_node;

    //Return the new node to the caller
      return new_node;
}



 node *pop(node *head)
 {
     //Get the head of the list
    node * visiting = head;

    //Set the head to the child of the head
    if (visiting != NULL)
        head = visiting->next;

    //Return the old head
    return visiting;
 }