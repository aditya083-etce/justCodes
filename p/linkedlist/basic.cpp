#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next; 
    ListNode(int v) {
        val = v;
        next = NULL;
    }
};

void viewlist(ListNode* head) {
    ListNode* curr = head;
    while(curr) {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "NULL"<<endl;
}

int main() {
    ListNode *head = new ListNode(-1);
    ListNode* curr = head;
    int n; cin >> n;
    for(int i = 0; i<n; i++) {
        int data; cin >> data;
        ListNode* newnode = new ListNode(data);
        curr->next = newnode;
        curr = newnode;
    }
    head = head->next;
    viewlist(head);
    
    return 0;
}
