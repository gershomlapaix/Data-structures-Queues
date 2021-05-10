#include <iostream>
using namespace std;
int circularQueue[20];
int front = -1, rear = -1, size = 7;

void enqueue(int value) {

  if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
    cout << "Queue is full. \n";
    return;
  }
  if (front == -1) {
    front = 0;
    rear = 0;
  } else {
    if (rear == size - 1)
      rear = 0;
    else
      rear = rear + 1;
  }
  circularQueue[rear] = value;
}

void dequeue() {
  if (front == -1) {
    cout << "Queue is empty\n";
    return;
  }
  cout<<"\n\n\t------------------------\n";
  cout << "\tDeleted element is : " << circularQueue[front] << endl;
  cout<<"\t------------------------\n";
  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    if (front == size - 1)
      front = 0;
    else
      front = front + 1;
  }
}

void display() {
  int f = front, r = rear;
  if (front == -1) {
    cout << "Queue is empty." << endl;
    return;
  }
  if (f <= r) {
    while (f <= r) {
      cout << circularQueue[f] << " ";
      f++;
    }
  } else {
    while (f <= size - 1) {
      cout << circularQueue[f] << " ";
      f++;
    }
    f = 0;
    while (f <= r) {
      cout << circularQueue[f] << " ";
      f++;
    }
  }
  cout << endl;
}

int main() {
  int choice{}, val{}, numberOfElements{};
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

      for (int i{}; i < numberOfElements; i++) {
        cout << "value " << i + 1 << " : ";
        cin >> val;
        enqueue(val);
      }
      break;

    case 2:
      cout << "\t________________________________\n\n";
      cout << "\tData in the queue: ";
      display();
      cout << "\t________________________________\n";
      cout << "\n\n";
      break;

    case 3:
      dequeue();      
      cout << "\n\n";
      break;

    default:
      cout << "\nBye Bye !!!\n\n";
    }
  }

  while (choice != 0);
  return 0;
}
