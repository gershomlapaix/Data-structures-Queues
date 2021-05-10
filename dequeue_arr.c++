#include <iostream>
using namespace std;

struct Deque {
  int *arr, arrSize, rear, front;

  Deque(int size) {
    front = rear = -1;
    arrSize = size;
    arr = new int[size];
  }

  void insert_front(int data);
  void insert_end(int data);
  void delete_front();
  void delete_rear();
  void display();
  bool overflow();
  bool underflow();
};

bool Deque::overflow() {
  bool condResult{false};
  if ((front == 0 && rear == arrSize - 1) || (front == rear + 1)) {
    condResult = true;
  }
  return condResult;
}

bool Deque::underflow() {
  bool condResult{false};
  if (front == -1) {
    condResult = true;
  }
  return condResult;
}

void Deque::insert_front(int data) {
  if (overflow()) {
    cout << "The queue is full!!";
    return;
  } else {
    if (front == -1) {
      front = 0;
      rear = 0;
      arr[front] = data;
    } else if (front == 0) {
      front = arrSize - 1;
      arr[front] = data;
    } else {
      arr[--front] = data;
    }
  }
}

void Deque::insert_end(int data) {
  if (overflow()) {
    cout << "The queue is full!!";
    return;
  } else {
    if (front == -1) {
      front = 0;
      rear = 0;
      arr[front] = data;
    } else if (rear == arrSize - 1) {
      rear = 0;
      arr[rear] = data;
    } else {
      arr[++rear] = data;
    }
  }
}

void Deque::delete_front() {
  if (underflow()) {
    cout << "NO more elements in queue. You need to insert some.\n";
    return;
  } else {
    if (front == rear) {
      front = rear = -1;
    } else {
      if (front == arrSize - 1)
        front = 0;
      else
        front = front + 1;
    }
  }
}

void Deque::delete_rear() {
  if (underflow()) {
    cout << "NO more elements in queue. You need to insert some.\n";
    return;
  } else {
    if (front == rear) {
      front = rear = -1;
    } else {
      if (rear == 0)
        rear = arrSize - 1;
      else
        rear--;
    }
  }
}

void Deque::display() {
  if (underflow())
    cout << "No elements in the queue.You need to insert some!!\n";

  if (rear >= front) {
    for (int i{front}; i <= rear; i++) {
      cout << arr[i] << " ";
    }
  } else {
    for (int i{front}; i < arrSize; i++)
      cout << arr[i] << " ";

    for (int i = 0; i <= rear; i++)
      cout << arr[i] << " ";
  }
}

int main() {

  int choice{}, data{}, numberOfElements;
  Deque deq(10);

  cout << "\n\t\t_________OPERATE DEQUEUE_________\n\n";
  cout << "\t1. Insert at the front.\n\t2. Insert at the rear.\n\t3. Display "
          "the "
          "data in Queue.\n\t4. Delete from front.\n\t5. Delete from "
          "rear.\n\t0. Exit\n\n";

  do {
    cout << "\n\t\tEnter your choice(terminate by 0) : ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "\n\tEnter the number of elements you want to insert:: ";
      cin >> numberOfElements;

      cout << "\n\tEnter the data: ";
      for (int i = 0; i < numberOfElements; ++i) {
        cin >> data;
        deq.insert_front(data);
      }
      break;

    case 2:
      cout << "\n\tEnter the number of elements you want to insert:: ";
      cin >> numberOfElements;

      cout << "\n\tEnter the data: ";
      for (int i{}; i < numberOfElements; ++i) {
        cin >> data;
        deq.insert_end(data);
      }
      break;

    case 3:
      cout << "\n\t\t\t------------------------\n";
      cout << "\t\t\tData in queue: ";
      deq.display();
      cout << "\n\t\t\t------------------------\n";
      break;

    case 4:
      deq.delete_front();
      break;

    case 5:
      deq.delete_rear();
      break;

    default:
      cout << "Bye bye!!\n\n";
    }
  } while (choice != 0);
  return 0;
}