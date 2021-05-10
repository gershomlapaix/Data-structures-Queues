#include <iostream>
using namespace std;

const int n = 20;
int Q[n], Pr[n];
int f = -1, r = -1;

bool overflow() {
  bool isFull{false};
  if ((f == 0) && (r == n - 1)) {
    isFull = true;
  }

  return isFull;
}

bool underflow() {
  bool isEmpty{false};
  if (f == -1) {
    isEmpty = true;
  }
  return isEmpty;
}

void enqueue(int data, int p) {
  int i{};
  if (overflow()) {
    cout << "The  queue is now full....\n";
    return;
  } else { // if the queue is empty
    if (f == -1) {
      f = r = 0;
      Q[r] = data;
      Pr[r] = p;
    } else if (r == n - 1) // if there there is some elemets in Queue
    {
      for (i = f; i <= r; i++) {
        Q[i - f] = Q[i];
        Pr[i - f] = Pr[i];
        r = r - f;
        f = 0;
        for (i = r; i > f; i--) {
          if (p > Pr[i]) {
            Q[i + 1] = Q[i];
            Pr[i + 1] = Pr[i];
          } else
            break;
          Q[i + 1] = data;
          Pr[i + 1] = p;
          r++;
        }
      }
    } else {
      for (i = r; i >= f; i--) {
        if (p > Pr[i]) {
          Q[i + 1] = Q[i];
          Pr[i + 1] = Pr[i];
        } else
          break;
      }
      Q[i + 1] = data;
      Pr[i + 1] = p;
      r++;
    }
  }
}

void dequeue() {
  if (underflow()) {
    cout << "No data in the queue. You need to insert some\n";
  }

  else {
    cout << "\n\t--------------------------------------------\n";
    cout << "\tDeleted element is:: " << Q[f] << " it's priority is:: " << Pr[f]
         << endl;
    cout << "\n\t--------------------------------------------\n";
    if (f == r)
      f = r = -1;
    else
      f++;
  }
}

void display() {
  for (int i{f}; i <= r; i++) {
    cout << "\tElem:: " << Q[i] << ", prior:: " << Pr[i] << endl;
  }
}

int main() {
  int opt, n = 4, i = 0, data, p, numberOfElements;

  cout << "\n\t\tOPERATE PRIORITY QUEUE\n\t\t-------------------------\n\n";
  cout << "\n\t1. Enqueue some data\n\t2. Display queue data\n\t3. Dequeue "
          "some data\n";

  do {

    cout << "\n\t(Type 0 to terminate).  Your option: ";
    cin >> opt;

    switch (opt) {
    case 1:
      cout << "\n\tEnter the number of elements you want to insert:: ";
      cin >> numberOfElements;

      cout << "Enter the values: ";
      while (i < numberOfElements) {
        cin >> Q[i] >> Pr[i];
        enqueue(Q[i], Pr[i]);
        i++;
      }
      break;

    case 2:
      cout << "\n\t_____________________\n\n";
      display();
      cout << "\t_____________________\n";
      cout << "\n\n";
      break;

    case 3:
      dequeue();
      break;

    default:
      cout << "Bye bye!!\n\n";
      break;
    }
  } while (opt != 0);
  return 0;
}