// LAB 12 - LINKED LISTS
#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

typedef Node * Node_Ptr;


void write_list(Node_Ptr head);


int main()
{
  Node_Ptr head = NULL, temp;

  cout << "empty list" << endl;
  //write_list(head);
  cout << endl << endl;

  head = new Node;
  head->data = 30;
  head->next = NULL;

  cout << "singleton list" << endl;
  write_list(head);
  cout << endl << endl;

  temp = new Node;
  temp->data = 20;
  temp->next = head;
  head = temp;

  temp = new Node;
  temp->data = 10;
  temp->next = head;
  head = temp;

  cout << "list" << endl;
//  write_list(head);
  cout << endl << endl;

  return 0;
}


void write_list(Node_Ptr head)
{
}
