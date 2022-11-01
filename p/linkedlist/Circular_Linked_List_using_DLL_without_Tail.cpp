#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
int len = 0;

// Insertion
void insertAtHead(int data) {

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(head == NULL) {

        head = newNode;
        head->next = head->prev = head;
    } else {

        head->prev->next = newNode;
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev = newNode;

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
    temp->prev->next = head;
    head->prev = temp->prev;

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