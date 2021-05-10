#include <iostream>
using namespace std;

struct Node {
  int data, p;
  Node *next;
};

struct Node *f = NULL;
struct Ndde *r = NULL;

void enqueue(int d, int pr) {
  Node *temp = new Node;
  Node *new_node = new Node;

  new_node->data = d;
  new_node->p = pr;

  if (f == NULL) {
    new_node->next = f;
    f = new_node;
  } else {
    temp = f;
    while ((temp->next != NULL) && (temp->next->p) <= pr)
      temp = temp->next;

    new_node->next = temp->next;
    temp->next = new_node;
  }
}

void display() {
  Node *temp = f;
  while (temp != NULL) {
    cout << "\tElem:: " << temp->data << ", prior:: " << temp->p << endl;
    temp = temp->next;
  }
}

void dequeue() {
  Node *temp = new Node;
  if (f == NULL) {
    cout << "The queue is empty....\n";
    return;
  }

  else {
    temp = f;
    f = f->next;
    cout << "\n\t----------------------------------------";
    cout << "\n\tDeleted elem is:: " << temp->data
         << " It's prior is:: " << temp->p;
    cout << "\n\t----------------------------------------\n";
    free(temp);
  }
}

int main() {

  int qdata{}, qprior{}, choice{}, numberOfElements{};

  cout << "\n\t\t_________OPERATE PRIORITY QUEUE_________\n\n";
  cout << "\t1. Insert elements.\n\t2. Display.\n\t3. Delete highest prior elements\n\t0. Exit\n\n";
  do {
    cout << "\n\t(Type 0 to terminate).  Your option: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "\n\tEnter the number of elements you want to insert:: ";
      cin >> numberOfElements;

      cout << "\n\tInput the queue data and priority: ";
      for (int i{}; i < numberOfElements; i++) {
        cin >> qdata >> qprior;
        enqueue(qdata, qprior);
      }
      break;

    case 2:
      cout << "\t_____________________\n\n";
      display();
      cout << "\t_____________________\n";
      cout << "\n\n";
      break;

    case 3:
      dequeue();
      break;

    default:
      cout << "\nBye bye!!!!!!\n\n";
      break;
    }

  } while (choice != 0);

  return 0;
}