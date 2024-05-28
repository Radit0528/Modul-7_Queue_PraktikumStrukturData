#include <iostream>

using namespace std;

struct Node {
  string nama_2311102013;
  long long int nim_2311102013;
  Node* next;
};

Node* front = NULL; 
Node* back = NULL; 

bool isEmpty() {
  return front == NULL;
}

void enqueueAntrian(string nama, long long int NIM) {
  Node* newNode = new Node; 
  newNode->nama_2311102013 = nama;
  newNode->nim_2311102013 = NIM;
  newNode->next = NULL; 

  if (isEmpty()) { 
    front = newNode;
    back = newNode;
  } else { 
    back->next = newNode;
    back = newNode;
  }
}

void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Antrian Kosong!" << endl;
    return;
  }

  Node* temp = front; 
  front = front->next; 
  delete temp; 

  if (front == NULL) { 
    back = NULL;
  }
}

int countQueue() {
  int count = 0;
  Node* current = front;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

void clearQueue() {
  while (!isEmpty()) {
    dequeueAntrian();
  }
}

void viewQueue() {
  if (isEmpty()) {
    cout << "Antrian kosong!" << endl;
    return;
  }

  cout << "Data antrian mahasiswa:" << endl;
  Node* current = front;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->nama_2311102013 << " (" << current->nim_2311102013 << ")" << endl;
    i++;
    current = current->next;
  }
}

int main() {

  enqueueAntrian("Raditya", 2311102013);
  enqueueAntrian("Wisnu", 231112913);
  enqueueAntrian("Rananta", 2311102813);
  enqueueAntrian("Putra", 2311102513);
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  clearQueue();
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  return 0;
}
