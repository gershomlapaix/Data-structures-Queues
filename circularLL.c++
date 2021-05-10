#include <cstdlib>
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

struct Que {
  struct Node *front, *rear;
};

bool underflow(Que *q) {
  bool condSuccess{false};
  if (q->front == NULL)
    condSuccess = true;

  return condSuccess;
}

void enQueue(Que *q, int value) {
  Node *newNode = new Node;
  newNode->data = value;
  if (underflow(q)) { // if he queue is empty
    q->front = newNode;
  } else {
    q->rear->next = newNode;
  }

  q->rear = newNode;
  q->rear->next = q->front;
}

int deQueue(Que *q) {
  Node *temp = new Node;
  int value{};

  if (underflow(q)) {
    cout << "No data found";
  }

  if (q->rear == q->front) {
    value = q->front->data;
    q->front = NULL;
    q->rear = NULL;
    free(temp);
  } else {
    value = q->front->data;
    q->front = q->front->next;
    q->rear->next = q->front;
    free(temp);
  }

  return value;
}

void display(Que *q) {
  if (underflow(q)) {
    cout << "No values in linked  queue.\n";
    return;
  }

  Node *looper = q->front;
  while (looper->next != q->front) {
    cout << looper->data << " ";
    looper = looper->next;
  }
  cout << looper->data << " ";
}

int main() {
  int val{}, choice{}, numberOfElements{};
  Que *q = new Que;
  q->front = q->rear = NULL;

  cout << "\n\t\t_________OPERATE CIRCULAR QUEUE_________\n\n";
  cout << "\t1. Insert at the front.\n\t2. Remove from the rear.\n\t3. Display "
          "the data.\n\t0. Exit\n\n";

  do {
    cout << "Enter your choice(terminate by 0): ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "\n\tEnter the number of elements you want to insert:: ";
      cin >> numberOfElements;

      cout << "\n\tEnter the values of queue::\n";
      for (int i{}; i < numberOfElements; i++) {
        cout << "value " << i + 1 << " : ";
        cin >> val;
        enQueue(q, val);
      }
      break;

    case 2:
      cout << "\t________________________________\n\n";
      cout << "\tData in the queue: ";
      display(q);
      cout << "\n\t________________________________\n";
      cout << "\n\n";
      break;

    case 3:
      deQueue(q);
      cout << "\t________________________________\n\n";
      cout << "\tData in the queue: ";
      display(q);
      cout << "\n\n\t________________________________\n";
      cout << "\n\n";
      break;

    default:
      cout << "\nBye Bye !!!\n\n";
    }

  } while (choice != 0);

  return 0;
}