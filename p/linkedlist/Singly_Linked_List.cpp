#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;
int len = 0;

// Insertion
void insertAtHead(int data) {

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = head;
    head = newNode;

    if(len == 0) {

        tail = newNode;
    }

    len++;
}

void insertAtTail(int data) {

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    
    if(len == 0) {

        head = tail = newNode;
    } else {

        tail->next = newNode;
        tail = newNode;
    }

    len++;
}

// pos valid range is [1, len + 1].
void insertAtPos(int data, int pos) {

    if(pos > len + 1) {

        cout << "Invalid position" << endl;

        return;
    }
    
    if(pos == 1) {
        
        insertAtHead(data);
    } else if(pos == len + 1) {

        insertAtTail(data);
    } else {

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        Node* current = head;

        for(int i = 1; i <= pos - 2; i++) {

            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        len++;
    }
}

// Deletion
void deleteHead() {

    if(len == 0) {

        return;
    }

    Node* temp = head->next;

    delete head;

    head = temp;

    if(len == 1) {

        tail = NULL;
    }

    len--;
}

void deleteTail() {

    if(len == 0) {

        return;
    } else if(len == 1) {

        delete tail;

        head = tail = NULL;
    } else {

        Node* current = head;

        for(int i = 1; i <= len - 2; i++) {

            current = current->next;
        }

        delete tail;

        current->next = NULL;
        tail = current;
    }

    len--;
}

// pos valid range is [1, len].
void deleteAtPos(int pos) {

    if(len == 0) {

        return;
    }

    if(pos == 1) {

        deleteHead();
    } else if(pos == len) {

        deleteTail();
    } else {

        Node* current = head;

        for(int i = 1; i <= pos - 2; i++) {

            current = current->next;
        }

        Node* temp = current->next->next;

        delete current->next;

        current->next = temp;
    
        len--;
    }
}

void print() {

    Node* current = head;

    while(current != NULL) {

        cout << current->data << "->";

        current = current->next;
    }
}


class Node {

    int data;
    Node* next;

    Node(){
        next = NULL;
    }
};

int main() {
     
    Node *newnode = new Node;
    Node *newnode = new Node();
    return 0;
}