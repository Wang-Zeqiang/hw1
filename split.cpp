/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

Node* Find_Tail(Node* in);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  if(in == nullptr){return;}

  Node* curr_ptr = in;
  int curr_val = curr_ptr->value;
  // move in-list 1 forward before change the curr next to NULL
  in = in->next; 
  curr_ptr->next = nullptr; // change node from in-list to odds/evens

  if(curr_val % 2 == 0){
    if(evens == nullptr){
      evens = curr_ptr;
    }
    else{
      Node* tail = Find_Tail(evens);
      tail->next = curr_ptr;
    }
  }
  else{
    if(odds == nullptr){
      odds = curr_ptr;
    }
    else{
      Node* tail = Find_Tail(odds);
      tail->next = curr_ptr;
    }
  }

  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
Node* Find_Tail(Node* in){
  if(in->next == nullptr){
    return in;
  }
  in = in->next;
  return Find_Tail(in);
}