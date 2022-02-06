// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int n, Node *head){
        // code here
        Node* dummy_odd=new Node(-1);
        Node* dummy_even=new Node(-1);
        Node* yo=dummy_odd;
        Node* ans=dummy_even;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data%2==0){
                dummy_even->next=temp;
                dummy_even=temp;
                temp=temp->next;
                dummy_even->next=NULL;
            }
            else{
                dummy_odd->next=temp;
                dummy_odd=temp;
                temp=temp->next;
                dummy_odd->next=NULL;
            }
        }
        dummy_even->next=yo->next;
        return ans->next;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends