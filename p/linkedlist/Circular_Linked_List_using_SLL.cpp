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

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {

        head = tail = newNode;
        head->next = head;
    } else {

        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }

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
    tail->next = head;

    delete temp;

    len--;
}


void print1() {

    Node *current = head;

    if(current != NULL) {

        cout << current->data << " ";
        
        current = current->next;
    }

    while(current != head) {

        cout << current->data << " ";

        current = current->next;
    }
}

void print2() {

    Node *current = head;

    if(current != NULL) {

        do {

            cout << current->data << " ";

            current = current->next;
            
        } while(current != head);
    }
}

int main() {

    insertAtHead(1);

    insertAtHead(2);

    insertAtHead(3);

    insertAtHead(4);

    print1();
     
    return 0;
}