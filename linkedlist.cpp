#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* getnewnode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

node* Insert(node* head, int data)
{
    if(head == NULL)
    {
        head = getnewnode(data);
        return head;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = getnewnode(data);
    return head;
}

void print(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    node* head = NULL;
    head = Insert(head,1);
    head = Insert(head,2);
    head = Insert(head,3);
    head = Insert(head,4);
    head = Insert(head,5);
    print(head);
}

