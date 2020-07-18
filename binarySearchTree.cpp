#include<iostream>
#include<stdio.h>
#include<vector>


struct Node{ // defined node
    int val;
    Node* left; // left node
    Node* right;
};

Node* createNode(int value) // creates a node
{
    Node* newNode = new Node;
    newNode->val = value;
    newNode->right=newNode->left=NULL; // initialize node left and right as nulls
    return newNode;
}

void insertNode(Node* &root,int val) // if value is smaller than the node value we put, move to the left otherwise move to the right
{
    if(root==NULL)
    {
        root=createNode(val);
    }
    else if(root->val>val)
    {
        insertNode(root->left,val);
    }
    else {insertNode(root->right,val);
    }

}

void display(Node* root) // display the values
{
    if(root!=NULL)
    {
        display(root->left);
        std::cout << root->val << ",";
        display(root->right);
    }

}
int main( )
{
    Node* root = NULL;
    int n, num, rootNum;
    std::cout << "what is your root number" << std::endl;
    std::cin >> rootNum;
    std::cout << "how many numbers in the binary search tree?" << std::endl;
    std::cin>>n;
    root = createNode(rootNum);
    std::cout << "Please list the numbers and press enter after each number." << std::endl;
    for(int i = 0; i < n; i++)
        {std::cin >> num;
        insertNode(root,num);}
    //root = createNode(n);
    display(root);
    //std::cout << root->val << std::endl;
}

