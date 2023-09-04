#include <iostream>
using namespace std;

#define MAX 10

class Deque {
  int arr[MAX];  // Array to store the elements of the deque
  int front;     // Index of the front element
  int rear;      // Index of the rear element
  int size;      // Maximum size of the deque

public:
  Deque(int size) {
    front = -1;   // Initialize front as -1 (empty deque)
    rear = 0;     // Initialize rear as 0
    this->size = size;  // Set the maximum size of the deque
  }

  void insertfront(int key);  // Insert an element at the front of the deque
  void insertrear(int key);   // Insert an element at the rear of the deque
  void deletefront();         // Delete the front element of the deque
  void deleterear();          // Delete the rear element of the deque
  bool isFull();              // Check if the deque is full
  bool isEmpty();             // Check if the deque is empty
  int getFront();             // Get the front element of the deque
  int getRear();              // Get the rear element of the deque
};

// Check if the deque is full
bool Deque::isFull() {
  return ((front == 0 && rear == size - 1) || front == rear + 1);
}

// Check if the deque is empty
bool Deque::isEmpty() {
  return (front == -1);
}

// Insert an element at the front of the deque
void Deque::insertfront(int key) {
  if (isFull()) {
    cout << "Overflow\n" << endl;  // Display overflow message if the deque is full
    return;
  }

  if (front == -1) {
    front = 0;   // If deque is empty, set front and rear to 0
    rear = 0;
  } else if (front == 0)
    front = size - 1;   // If front is at the first index, wrap around to the last index
  else
    front = front - 1;  // Move front to the previous index

  arr[front] = key;  // Insert the new element at the front
}

// Insert an element at the rear of the deque
void Deque::insertrear(int key) {
  if (isFull()) {
    cout << "Overflow\n" << endl;  // Display overflow message if the deque is full
    return;
  }

  if (front == -1) {
    front = 0;   // If deque is empty, set front and rear to 0
    rear = 0;
  } else if (rear == size - 1)
    rear = 0;    // If rear is at the last index, wrap around to the first index
  else
    rear = rear + 1;  // Move rear to the next index

  arr[rear] = key;  // Insert the new element at the rear
}

// Delete the front element of the deque
void Deque::deletefront() {
  if (isEmpty()) {
    cout << "Queue Underflow\n" << endl;  // Display underflow message if the deque is empty
    return;
  }

  if (front == rear) {
    front = -1;  // If there is only one element, set front and rear to -1 (empty deque)
    rear = -1;
  } else if (front == size - 1)
    front = 0;   // If front is at the last index, wrap around to the first index
  else
    front = front + 1;  // Move front to the next index
}

// Delete the rear element of the deque
void Deque::deleterear() {
  if (isEmpty()) {
    cout << "Underflow\n" << endl;  // Display underflow message if the deque is empty
    return;
  }

  if (front == rear) {
    front = -1;  // If there is only one element, set front and rear to -1 (empty deque)
    rear = -1;
  } else if (rear == 0)
    rear = size - 1;  // If rear is at the first index, wrap around to the last index
  else
    rear = rear - 1;  // Move rear to the previous index
}

// Get the front element of the deque
int Deque::getFront() {
  if (isEmpty()) {
    cout << "Underflow\n" << endl;  // Display underflow message if the deque is empty
    return -1;
  }
  return arr[front];  // Return the value of the front element
}

// Get the rear element of the deque
int Deque::getRear() {
  if (isEmpty() || rear < 0) {
    cout << "Underflow\n" << endl;  // Display underflow message if the deque is empty
    return -1;
  }
  return arr[rear];  // Return the value of the rear element
}

int main() {
  Deque dq(4);  // Create a deque of maximum size 4

  cout << "insert element at rear end \n";
  dq.insertrear(5);
  dq.insertrear(11);

  cout << "rear element: " << dq.getRear() << endl;

  dq.deleterear();
  cout << "after deletion of the rear element, the new rear element: " << dq.getRear() << endl;

  cout << "insert element at front end \n";

  dq.insertfront(8);

  cout << "front element: " << dq.getFront() << endl;

  dq.deletefront();

  cout << "after deletion of front element new front element: " << dq.getFront() << endl;
}

// // Deque implementation in C++

// #include <iostream>
// using namespace std;

// #define MAX 10

// class Deque {
//   int arr[MAX];
//   int front;
//   int rear;
//   int size;

//    public:
//   Deque(int size) {
//     front = -1;
//     rear = 0;
//     this->size = size;
//   }

//   void insertfront(int key);
//   void insertrear(int key);
//   void deletefront();
//   void deleterear();
//   bool isFull();
//   bool isEmpty();
//   int getFront();
//   int getRear();
// };

// bool Deque::isFull() {
//   return ((front == 0 && rear == size - 1) ||
//       front == rear + 1);
// }

// bool Deque::isEmpty() {
//   return (front == -1);
// }

// void Deque::insertfront(int key) {
//   if (isFull()) {
//     cout << "Overflow\n"
//        << endl;
//     return;
//   }

//   if (front == -1) {
//     front = 0;
//     rear = 0;
//   }

//   else if (front == 0)
//     front = size - 1;

//   else
//     front = front - 1;

//   arr[front] = key;
// }

// void Deque ::insertrear(int key) {
//   if (isFull()) {
//     cout << " Overflow\n " << endl;
//     return;
//   }

//   if (front == -1) {
//     front = 0;
//     rear = 0;
//   }

//   else if (rear == size - 1)
//     rear = 0;

//   else
//     rear = rear + 1;

//   arr[rear] = key;
// }

// void Deque ::deletefront() {
//   if (isEmpty()) {
//     cout << "Queue Underflow\n"
//        << endl;
//     return;
//   }

//   if (front == rear) {
//     front = -1;
//     rear = -1;
//   } else if (front == size - 1)
//     front = 0;

//   else
//     front = front + 1;
// }

// void Deque::deleterear() {
//   if (isEmpty()) {
//     cout << " Underflow\n"
//        << endl;
//     return;
//   }

//   if (front == rear) {
//     front = -1;
//     rear = -1;
//   } else if (rear == 0)
//     rear = size - 1;
//   else
//     rear = rear - 1;
// }

// int Deque::getFront() {
//   if (isEmpty()) {
//     cout << " Underflow\n"
//        << endl;
//     return -1;
//   }
//   return arr[front];
// }

// int Deque::getRear() {
//   if (isEmpty() || rear < 0) {
//     cout << " Underflow\n"
//        << endl;
//     return -1;
//   }
//   return arr[rear];
// }

// int main() {
//   Deque dq(4);

//   cout << "insert element at rear end \n";
//   dq.insertrear(5);
//   dq.insertrear(11);

//   cout << "rear element: "
//      << dq.getRear() << endl;

//   dq.deleterear();
//   cout << "after deletion of the rear element, the new rear element: " << dq.getRear() << endl;

//   cout << "insert element at front end \n";

//   dq.insertfront(8);

//   cout << "front element: " << dq.getFront() << endl;

//   dq.deletefront();

//   cout << "after deletion of front element new front element: " << dq.getFront() << endl;
// }


// // Deque or Double Ended Queue is a type of queue in which insertion and removal of elements can either be performed from the front or the rear. Thus, it does not follow FIFO rule (First In First Out).