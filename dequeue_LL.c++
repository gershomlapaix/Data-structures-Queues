#include <cstdlib>
#include <iostream>
#include <iterator>
using namespace std;

struct Node {
  int data;
  Node *next, *prev;
};

struct Deque {

  Node *rear = NULL;
  Node *front = NULL;

  void insert_front(int data);
  void insert_end(int data);
  void delete_front();
  void delete_rear();
  void display();
  bool overflow();
  bool underflow();
};

bool Deque::underflow() {
  if (front == NULL) {
    return true;
  } else {
    return false;
  }
}

void Deque::insert_front(int data) {
  Node *newNode = new Node;
  newNode->data = data;
  if (front == NULL) {
    rear = front = newNode;
  } else {
    newNode->next = front;
    front->prev = newNode;
    front = newNode;
  }
}

void Deque::insert_end(int data) {
  Node *newNode = new Node;
  newNode->data = data;

  if (rear == NULL) {
    front = rear = newNode;
  } else {
    newNode->prev = rear;
    rear->next = newNode;
    rear = newNode;
  }
}

void Deque::delete_front() {
  if (underflow()) {
    cout << "\nNO MORE ELEMENTS IN QUEUE.YOU NEED TO INSERT SOME..\n";
  } else {
    Node *temp = front;
    front = front->next;

    if (front == NULL) {
      rear = NULL;
    } else {
      front->prev = NULL;
    }
    free(temp);
  }
}

void Deque::delete_rear() {
  if (underflow()) {
    cout << "\nNO MORE ELEMENTS IN QUEUE.YOU NEED TO INSERT SOME..\n";
  } else {
    Node *temp = rear;
    rear = rear->prev;

    if (rear == NULL) {
      front == NULL;
    } else {
      rear->next = NULL;
    }

    free(temp);
  }
}

void Deque::display() {
  Node *temp = front;

  if (underflow()) {
    cout << "\nNO MORE ELEMENTS IN QUEUE.YOU NEED TO INSERT SOME..\n";
    return;
  }

  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int main() {
  Deque dq;
  int numberOfElements{}, data{}, choice{};

  cout << "\n\t\t_________OPERATE DEQUEUE_________\n\n";
  cout << "\t1. Insert at the front.\n\t2. Insert at the rear.\n\t3. Display "
          "the "
          "data in Queue.\n\t4. Delete from front.\n\t5. Delete from "
          "rear.\n\t0. Exit\n\n";

  do {
    cout << "\n\t(Terminate by 0). What is your choice? ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "\n\tEnter the number of elements you want to insert:: ";
      cin >> numberOfElements;

      cout << "\n\tEnter the elements: ";
      for (int i{}; i < numberOfElements; ++i) {
        cin >> data;
        dq.insert_front(data);
      }
      break;

    case 2: {
      cout << "\n\tEnter the number of elements you want to insert:: ";
      cin >> numberOfElements;

      cout << "\n\tEnter the elements: ";
      for (int i{}; i < numberOfElements; ++i) {
        cin >> data;
        dq.insert_end(data);
      }

    case 3:
      cout << "\t________________________________\n\n";
      cout << "\tData in the queue: ";
      dq.display();
      cout << "\n\n\t________________________________\n";
      cout << "\n\n";
      break;

    case 4:
      dq.delete_front();
      break;

    case 5:
      dq.delete_rear();
      break;

    default:
      cout << "\nBye Bye !!!\n\n";
    }
    }
  } while (choice != 0);

  return 0;
}