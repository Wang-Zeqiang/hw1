/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstddef>
using namespace std;

void print(Node* head);
void empty(Node* head);

int main(int argc, char* argv[])
{
  Node* head = new Node(0, nullptr);;
  Node* temp = head;
  for(int i = 1; i < 15; i++){
    temp->next = new Node(i, nullptr);
    temp = temp->next;
  }
  Node* odds = nullptr;
  Node* evens = nullptr;
  split(head, odds, evens);

  print(odds);
  print(evens);  
  empty(odds);
  empty(evens);
  empty(head);
  
}

void print(Node* head){
  Node* temp = head;
  while(temp != nullptr){
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

void empty(Node* head){
  Node * currElement = head;

	while(currElement != nullptr)
	{
		Node * nextElement = currElement->next;

		delete currElement;

		currElement = nextElement;
	}
}
