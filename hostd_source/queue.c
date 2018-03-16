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

// Define your FIFO queue functions here, these will most likely be the
// push and pop functions that you declared in your header file



 node_t *push(node_t *head, proc process)
 {
     //Start at the head of the list
      node_t * visiting = head;

      //Go to the last node
      if (visiting != NULL);
      while (visiting->next != NULL)
      { visiting = visiting->next; }

    //Create a new node, and attach it to the list
      node_t * new_node;
      new_node = malloc(sizeof(node_t));
      new_node->process = process;
      visiting->next = new_node;

    //Return the new node to the caller
      return new_node;
}



 node_t *pop(node_t *head)
 {
     //Get the head of the list
    node_t * visiting = head;

    //Set the head to the child of the head
    if (visiting != NULL)
        head = visiting->next;

    //Return the old head
    return visiting;
 }
