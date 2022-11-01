#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;
int len = 0;

// Insertion
void insertAtHead(int data) {

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(len == 0) {

        head = tail = newNode;
    } else {

        newNode->next = head;
        head->prev = newNode;

        head = newNode;
    }

    len++;
}

void insertAtTail(int data) {

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(len == 0) {

        head = tail = newNode;
    } else {

        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;
    }

    len++;
}

// pos valid range is [1, len + 1].
void insertAtPos(int data, int pos) {

    if(pos == 1) {

        insertAtHead(data);

        return;
    } else if(pos == len + 1) {

        insertAtTail(data);

        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    Node* current = head;

    for(int i = 1; i <= pos - 2; i++) {

        current = current->next;
    }

    newNode->next = current->next;

    current->next = newNode;

    newNode->prev = current;

    newNode->next->prev = newNode;

    len++;
}

// Deletion
void deleteHead() {

    if(len == 0) {

        cout << "Already empty";

        return;
    }

    Node* temp = head;

    head = head->next;

    if(head != NULL) {

        head->prev = NULL;
    }

    delete temp;

    len--;
}

void deleteTail() {

    if(len == 0) {

        cout << "Already empty";

        return;
    }

    Node* temp = tail;

    tail = tail->prev;

    if(tail != NULL) {

        tail->next = NULL;
    }

    delete temp;

    len--;
}

// pos valid range is [1, len].
void deleteAtPos(int pos) {

    if(pos == 1) {

        deleteHead();

        return;
    } else if(pos == len) {

        deleteTail();

        return;
    }

    Node* current = head;

    for(int i = 1; i <= pos - 1; i++) {

        current = current->next;
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;

    len--;
}

void print() {

    Node* current = head;

    while(current != NULL) {

        cout << current->data << "->";

        current = current->next;
    }
}

int main() {
     
    return 0;
}