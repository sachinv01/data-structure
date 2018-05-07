#include<iostream>

using namespace std;

struct bstnode
{
    int data;
    bstnode* left;
    bstnode* right;
};

bstnode* Getnewnode(int data)
{
    bstnode* newnode = new bstnode;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

bstnode* Insert(bstnode* root , int data)
{
    if(root == NULL)
    {
        root = Getnewnode(data);
    }
    else if(data<=root->data)
    {
        root->left = Insert(root->left,data);
    }
    else if(data>=root->data)
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

bool Search(bstnode* root,int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(data == root->data)
    {
        return true;
    }
    else if(data<=root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}

int findmin(bstnode* root)
{
    if(root==NULL)
    {
        cout<<"ERROR: THE TREE IS EMPTY "<<endl;
        return -1;
    }
    else if(root->left == NULL)
    {
        return root->data;
    }
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return findmin(root->left);
}

int findmax(bstnode* root)
{
    if(root == NULL)
    {
        cout<<"ERROR: THE TREE IS EMPTY"<<endl;
        return -1;
    }
    else if(root->right == NULL)
    {
        return root->data;
    }
    return findmax(root->right);
}

int findheight(bstnode* root)
{
    if(root == NULL)
    {
        return -1;
    }
    return max(findheight(root->right),findheight(root->left))+1;

}

int main()
{
    bstnode* d;
    bstnode* root = NULL;
    int n,x,y;
    cout<<"enter how many numbers you wanna enter in the tree: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the number: "<<endl;
        cin>>x;
        root = Insert(root,x);\
        d = root;
    }
    cout<<"enter the number u wanna search in this tree: "<<endl;
    cin>>y;
    if(Search(root,y) == true)
    {
        cout<<"FOUND!!!"<<endl;
    }
    else
    {
        cout<<"NOT FOUND :( "<<endl;
    }
    findmin(d);
    findmin(d);
    cout<<findheight(root);
}



