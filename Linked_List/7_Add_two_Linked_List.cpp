#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


int carry;
class Solution
{
    Node* reverse(Node *head)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
void addBack(Node *&head, Node *&last, int data){
   
   Node *newNode=new Node(data);
//   newNode->data=data;
   newNode->next=NULL;
   
   if(last==NULL){
       head=newNode;
   }
   else{
       last->next=newNode;
   }
   last=newNode;
   
}
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
       Node *head1=reverse(first);
      Node *head2=reverse(second);
      Node *res;
      Node *last=NULL; // Last node of new list
      int total,carry=0;
      // One of them not NULL
      while(head1|| head2){
          
          int a=(head1)?(head1->data):(0); // If NULL contri is 0
          int b=(head2)?(head2->data):(0);
          
          total=(a+b+carry);
          carry=(total/10);
          total=total%10;
          
          // Add this to back of new list
          addBack(res,last,total);
          
          if(head1){
              head1=head1->next;
          }
          
          if(head2){
               head2=head2->next;
          }
      }
      if(carry!=0){
          addBack(res,last,carry);
      }
      res = reverse(res);
      return res;
    }
};