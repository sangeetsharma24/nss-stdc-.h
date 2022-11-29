#include<iostream>
using namespace std;

//BST NODE CLASS
class Node
{
    public:
    int data;
    Node*left;
    Node*right;

//CONSTRUCTOR
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};



class bst{

Node *root;

public:
//INSERTION INTO BST


Node* bstinsert(Node*node,int data)
{
    if(node==NULL)
    {
        return new Node(data);
    }

    if (data<node->data)
    {
        node->left= bstinsert(node->left,data);
    }
    else
    {
        node->right= bstinsert(node->right,data);
    }

    return node;
}

void insert(int data)
{
    root = bstinsert(root,data);
}

//constructor
bst(){
    root = NULL;
}

bst(int a)
{
    root = NULL;
    insert(a);
}
//TRAVERSALS
void bstpreorder(Node*root)
{
    //base case
    if(root==NULL)
    {return;}

    cout<<root->data<<" ";
    bstpreorder(root->left);
    bstpreorder(root->right);
}

void bstinorder(Node*root)
{
    //base case
    if(root==NULL)
    {return;}

    bstinorder(root->left);
    cout<<root->data<<" ";
    bstinorder(root->right);
}

void bstpostorder(Node*root)
{
    //base case
    if(root==NULL)
    {return;}

    bstpostorder(root->left);
    bstpostorder(root->right);
    cout<<root->data<<" ";
}

void preorder()
{
    bstpreorder(root);
}

void postrder(){
    bstpostorder(root);
}

void inorder()
{
    bstinorder(root);
}

//FINDING MINIMUM NODE
int minNode()
{
    Node*current=root;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current->data;
}

//FINDING MAXIMUM NODE
int maxNode()
{
    Node*current=root;
    while(current && current->right!=NULL)
    {
        current=current->right;
    }
    return current->data;
}


//SEARCHING 
bool bstsearch(Node*root, int key)
{
    if(!root){
        return false;
    }
    else if(root->data<key)
    {
        return bstsearch(root->right,key);
    }
    else if(root->data>key)
    {
        return bstsearch(root->left,key);
    }

    return true;
}

bool search(int key)
{
    return bstsearch(root, key);
}


//LEVEL ORDER
void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(Node* node)
{
    if (node == NULL)
        return 0;
    else {
       
        int lheight = height(node->left);
        int rheight = height(node->right);
 
       
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}
 
void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
void levelOrder()
{
    printLevelOrder(root);
}

//DELETION IN BST

Node*minNodee(Node*node)
{
    Node*current=node;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
  
    
    if (key < root->data)
        root->left = deleteNode(root->left, key);
  
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
  
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
        
        // node has only one child or no child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
  
        // node with two children
        Node* temp = minNodee(root->right);
  
        // Copy the inorder successor's content to this node
        root->data = temp->data;
  
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void remove(int key)
{
    deleteNode(root, key);
}
};



int main()
{

    bst t(8);
    t.insert(3);
    t.insert(1);
    t.insert(6);
    t.insert(7);
    t.insert(10);
    t.insert(14);
    t.insert(4);
    cout<<"Inorder is:"<<endl;
    t.inorder();
    cout<<endl<<"Preorder is:"<<endl;
    t.preorder();
    cout<<t.minNode();
    cout<<endl<<"Levelorder is:"<<endl;
    t.levelOrder();
    cout<<endl<<"Deleting 6"<<endl;
    t.remove(6);
    cout<<"New inorder is:"<<endl;
    t.inorder();
    cout<<endl<<"Levelorder is:"<<endl;
    t.levelOrder();
    cout<<endl<<t.search(14);
    return 0;
}