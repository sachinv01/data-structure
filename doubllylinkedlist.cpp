#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};
node* head;

node* getnewnode(int x)
{
    node* newnode = new node();
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertathead(int x)
{
   node* newnode = getnewnode(x);
   if(head == NULL)
   {
       head = newnode;
       return;
   }
   head->prev = newnode;
   newnode->next = head;
   head = newnode;
}

void print()
{
        node* temp = head;
        cout<<"forward";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
}


int main()
{
    head = NULL;
    int n,x;
    cout<<"enter the length of the list"<<endl;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cout<<"enter the number"<<endl;
        cin>>x;
        insertathead(x);
    }
    print();
}
