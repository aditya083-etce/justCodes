#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;

    Node(int data){
        data = data;
        prev = NULL;
    }
};

Node* tail = NULL;

void multiply(int mul)
{
    Node* curr = tail;
    Node* previous = curr;

    int carry = 0;
    while (curr)
    {
        int temp = curr->data * mul + carry;
        curr->data = temp % 10;
        carry = temp / 10;
        previous = curr;
        curr = curr->prev;
    }

    while(carry) {
        Node* newnode = new Node(carry%10);
        previous->prev = newnode;
        carry /= 10;
        previous = previous->prev;
    }
}

void print_fact(Node* tail) {
    if (tail == NULL) return;
    print_fact(tail);
    cout << tail->data;
}

// void print_fact() {
//     Node* curr = head;
//     while (curr != NULL){
//         cout << curr->data;
//         curr = curr->next;
//     }
// }


void fact(int N)
{
    Node* newnode = new Node(1);

    tail = newnode;

    for(int i = 2; i <= N; i++)
    {
        multiply(i);
    }

    print_fact(tail);
}

int main(){

    int N;
    cin>>N;
    fact(N);

    return 0;
}

void solve(int A)
{
    string ans="1";
    int carry=0;
    for (int x=2;x<=A;x++)
    {
      carry=0;
      int n=ans.size();
        for (int i=0;i<n;i++)
        {
            int curr=ans[i]-'0';
            int res=curr*x+carry;
            ans[i]=res%10+'0';
            carry=res/10;
        }
        while (carry)
        {
            ans+=carry%10+'0';
            carry/=10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}