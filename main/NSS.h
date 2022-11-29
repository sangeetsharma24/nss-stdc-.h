#include<iostream>
#include<climits>
using namespace std;

template<class T> 

struct node{
    T data;
    node* next;
    node(T a)
    {
        data = a;
        next = NULL;
    }
};



template <class T>

class vector
{
    public:
    T *arr;
    int size;
    int cap;
    vector()
    {
        cap=1;
        arr=new T[cap];
        size=0;
    }
    vector(int n)
    {
        size = n;
        cap = n;
    }
    vector(int a, T b)
    {
        size = a;
        cap = a;
        for(int i = 0; i<a; i++)
        {
            arr[i] = b;
        }
    }
    void push_back(T x)
    {
        if(size<cap)
        {
            arr[size]=x;
            size++;
            return;
        }
        else if(size==cap)
        {
            cap=2*cap;
            T *temp=new T[cap];
            for(int i=0;i<size;i++)
            {
                temp[i]=arr[i];
            }
            delete []arr;
            arr=temp;
            arr[size]=x;
            size++;
        }
    }
    int length()
    {
        return size;
    }
    void print()
    {
        for(int i=0;i<size;i++)
        {
            cout<<" "<<arr[i];
        }
    }




    /*
    v<int> v;
    v.push_back(2);
    v[0];
    */
    T operator[](T i)
    {
        return arr[i];
    }
   
    void pop_back()
    {
        size--;
    }
   
    void insert(int a, T b)
    {
        push_back(b);
        T temp = arr[size-1];
        for(int i = size-1; i>a; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[a] = b;
    }
   
    void emplace(int a, T b)
    {
        push_back(b);
        T temp = arr[size-1];
        for(int i = size-1; i>a-1; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[a-1] = b;
    }
   
    int partition(int s, int e)
    {
         int pivot = 0;
       for(int i = 1; i<size; i++)
       {
         
           if(arr[i]<arr[0])
           {
               pivot++;
           }
       }
       swap(arr[0],arr[pivot]);
    }
   
    void quicksort(int s, int e)
    {
        if(s<=e){
        int p = partition(s,e);
        quicksort(s,p-1);
        quicksort(p+1,e);
        }
    }
   
    void sort()
    {
        for(int i = 0; i<size-1; i++)
        {
            if(arr[i]<arr[i+1])
                continue;
            else
                {
                for(int i = size; i>0; i--)
                {
                    if(arr[i]>arr[i-1])
                    {
                        continue;
                    }
                    else
                    {
                        quicksort();
                        return;
                    }
                }
                }
        }
    }
   
   
};











template<class T> 

struct list{
    node<T>* root;
    list(T a)
    {
        root = new node<T>(a);
    }
    void insert(int x)
    {
        node<T>* curr = root;
        while(curr->next) curr = curr->next;
        curr -> next = new node<T>(x);
    }
    void print()
    {
        node<T>* curr = root;
        while(curr)
        {
            cout<<curr->data<<" ";
            curr = curr->next;
        }
    }
};

// code for queue data structure


int max(int a, int b)
{
    if(a>b) return a;
    else return b;
}
template<class T> 

struct queue{
    node<T> *f, *r;
    queue()
    {
        f = r = NULL;
    }

    void enqueue(T x)
    {
        node<T>* temp = new node<T>(x);

        if(r == NULL){
            f = r = temp; 
            return;
        }

        r -> next = temp;
        r = temp;
        return;
    }

    void push(T x)
    {
        node<T>* temp = new node<T>(x);

        if(r == NULL){
            f = r = temp; 
            return;
        }

        r -> next = temp;
        r = temp;
        return;
    }

    T dequeue()
    {
        T temp = f->data;
        node<T>* ntemp = f;
        if(f != r){
        f = f->next;
        delete ntemp;
        return temp;
        }else{
            delete ntemp;
            f = r = NULL;
            return temp;
        }
    }
  
    T pop()
    {
        T temp = f->data;
        node<T>* ntemp = f;
        if(f != r){
        f = f->next;
        delete ntemp;
        return temp;
        }else{
            delete ntemp;
            f = r = NULL;
            return temp;
        }
    }

    T front()
    {
        if(f)
        {
            return f->data;
        }else{
            cout<<"Queue is empty";
        }
    }

    bool empty()
    {
        if(f) return false;
        else return true;
    }
};

// code for stack data structure

template<class T>

struct stack{
    node<T>* top;
    stack()
    {
        top = NULL;
    }

    void push(T x)
    {
        node<T> *temp = new node<T>(x);
        if(!top)
        {
            top = temp;
            return;
        }else{
            temp->next = top;
            top = temp;
            return;
        }
    }

    T pop()
    {
        if(!top)
        {
            cout<<"stack underflow";
            return INT_MIN;
        }
        T ans = top->data;
        if(top->next)
        {
            node<T>* temp = top;
            top = top->next;
            delete temp;
            return ans;
        }else{
            node<T>* temp = top;
            top = NULL;
            delete temp;
            return ans;
        }
    }

    T peek()
    {
        return top->data;
    }
};



/*


--------------------------------GRAPH DATA STRUCTURE STARTED---------------------------


*/

//undirected graph

class ungraph{
    int n;  //no of nodes
    int **Alist;
    int **Amatrix;

    public:

    // constructor
    ungraph(int a)
    {
        n = a;
        Alist = new int *[n];
        for(int i = 0; i<n; i++)
        {
            *(Alist+i) = new int[n];
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
                Alist[i][j] = INT_MIN;
        }

        Amatrix = new int *[n];
        for(int i = 0; i<n; i++)
        {
            Amatrix[i] = new int [n];
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                Amatrix[i][j] = 0;
            }
        }
    } 

    //add edge          ----  taking into consideration that smaller vertex should be written first to perfectly perform bfs and dfs.

    void addedge(int a, int b)
    {
        //transformation in adjacency matrix
        Amatrix[a][b] = 1;
        Amatrix[b][a] = 1;

        //transformation in adjacency list
        int z = 0;
        while(Alist[b][z] != INT_MIN)
        {
            z++;
        }
        Alist[b][z] = a;
        for(int i = 0; i<n-1; i++)
        {
            for(int j = i+1; j<n; j++){
                int temp = Alist[b][i];
                if(Alist[b][i] > Alist[b][j])
                {
                    Alist[b][i] =  Alist[b][j];
                    Alist[b][j] = temp;
                }
            }
        }


        z = 0;
        while(Alist[a][z] != INT_MIN)
        {
            z++;
        }
        Alist[a][z] = b;
        for(int i = 0; i<n-1; i++)
        {
            for(int j = i+1; j<n; j++){
                int temp = Alist[a][i];
                if(Alist[a][i] > Alist[a][j])
                {
                    Alist[a][i] =  Alist[a][j];
                    Alist[a][j] = temp;
                }
            }
        }
        return;
    }

    // to print adjacency matrix

    void printAmatrix()
    {
        int a[n+1][n+1];
        a[0][0] = INT_MIN;
        for(int i = 1; i<n+1; i++)
        {
            a[0][i] = i-1;
            a[i][0] = i-1;
        }
        for(int i = 1; i<n+1; i++)
        {
            for(int j = 1; j<n+1; j++)
            {
                a[i][j] = Amatrix[i-1][j-1];
            }
        }

        for(int i = 0; i<n+1; i++)
        {
            for(int j = 0; j<n+1; j++)
            {
                if(i == 0 && j == 0)
                {
                    cout<<"  ";
                }else{
                    cout<<a[i][j]<<" ";
                }
                
            }
            cout<<endl;
        }
    }

    // to print adjacency list

    void printAlist()
    {
        for(int i = 0; i<n; i++)
        {
            cout<<i<<" -> ";
            for(int j = 0; j<n; j++)
            {
                if(Alist[i][j] != INT_MIN)
                {
                    cout<<Alist[i][j]<<" ";
                }
                
            }
            cout<<endl;
        }
    }

    // code for bfs traversal

    void tbfs(int s, bool visited[])
    {
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            for(int v = 0; v<n; v++)
            {
                int t = Alist[u][v];
                if(t != INT_MIN){
                if(visited[t] == false)
                {
                    visited[t] = true;
                    q.push(t);
                }
                }
            }
        }
    }

    void bfs(int s)
    {
        bool visited[n];
        for(int i = 0; i<n; i++)
        {
            visited[i] = false;
        }
        tbfs(s, visited);
        for(int i = 0; i<n; i++)
        {
            if(visited[i] == false)
            {
                tbfs(i, visited);
            }
        }
    }

    // code for dfs traversal

    void tdfs(int s, bool visited[])
    {
        cout<<s<<" ";
        visited[s] = true;
        int i = 0;
        while(i<n)
        {
            int t = Alist[s][i];
            if(t != INT_MIN){
            if(visited[t] == false)
            {
                visited[t] = true;
                tdfs(t, visited);
            }
            }
            i++;
        }
    }
    
    void dfs(int s)
     {
        bool visited[n];
        for(int i = 0; i<n; i++)
        {
            visited[i] = false;
        }
        tdfs(s, visited);
        for(int i = 0; i<n; i++)
        {
            if(visited[i] == false)
            {
                tdfs(i, visited);
            }
        }
     }

};

//directed graph

class diagraph{

    int n;  //no of nodes 
    int **Alist;
    int **Amatrix;

    public:

    // constructor
    diagraph(int a)
    {
        n = a;
        Alist = new int *[n];
        for(int i = 0; i<n; i++)
        {
            *(Alist+i) = new int[n];
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
                Alist[i][j] = INT_MIN;
        }

        Amatrix = new int *[n];
        for(int i = 0; i<n; i++)
        {
            Amatrix[i] = new int [n];
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                Amatrix[i][j] = 0;
            }
        }
    } 

    //add edge          ----  taking into consideration that smaller vertex should be written first to perfectly perform bfs and dfs.

    void addedge(int a, int b)
    {
        //transformation in adjacency matrix
        Amatrix[a][b] = 1;

        //transformation in adjacency list
        int z = 0;
        while(Alist[a][z] != INT_MIN)
        {
            z++;
        }
        Alist[a][z] = b;
        for(int i = 0; i<n-1; i++)
        {
            for(int j = i+1; j<n; j++){
                int temp = Alist[a][i];
                if(Alist[a][i] > Alist[a][j])
                {
                    Alist[a][i] =  Alist[a][j];
                    Alist[a][j] = temp;
                }
            }
        }

    }

    // to print adjacency matrix

    void printAmatrix()
    {
        int a[n+1][n+1];
        a[0][0] = INT_MIN;
        for(int i = 1; i<n+1; i++)
        {
            a[0][i] = i-1;
            a[i][0] = i-1;
        }
        for(int i = 1; i<n+1; i++)
        {
            for(int j = 1; j<n+1; j++)
            {
                a[i][j] = Amatrix[i-1][j-1];
            }
        }

        for(int i = 0; i<n+1; i++)
        {
            for(int j = 0; j<n+1; j++)
            {
                if(i == 0 && j == 0)
                {
                    cout<<"  ";
                }else{
                    cout<<a[i][j]<<" ";
                }
                
            }
            cout<<endl;
        }
    }


    // to print adjacency list

    void printAlist()
    {
        for(int i = 0; i<n; i++)
        {
            cout<<i<<" -> ";
            for(int j = 0; j<n; j++)
            {
                if(Alist[i][j] != INT_MIN)
                {
                    cout<<Alist[i][j]<<" ";
                }
                
            }
            cout<<endl;
        }
    }

    // code for bfs traversal

    void tbfs(int s, bool visited[])
    {
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            for(int v = 0; v<n; v++)
            {
                int t = Alist[u][v];
                if(t != INT_MIN){
                if(visited[t] == false)
                {
                    visited[t] = true;
                    q.push(t);
                }
                }
            }
        }
    }

    void bfs(int s)
    {
        bool visited[n];
        for(int i = 0; i<n; i++)
        {
            visited[i] = false;
        }
        tbfs(s, visited);
        for(int i = 0; i<n; i++)
        {
            if(visited[i] == false)
            {
                tbfs(i, visited);
            }
        }
    }

    // code for dfs traversal

    void tdfs(int s, bool visited[])
    {
        cout<<s<<" ";
        visited[s] = true;
        int i = 0;
        while(i<n)
        {
            int t = Alist[s][i];
            if(t != INT_MIN){
            if(visited[t] == false)
            {
                visited[t] = true;
                tdfs(t, visited);
            }
            }
            i++;
        }
    }
    
    void dfs(int s)
     {
        bool visited[n];
        for(int i = 0; i<n; i++)
        {
            visited[i] = false;
        }
        tdfs(s, visited);
        for(int i = 0; i<n; i++)
        {
            if(visited[i] == false)
            {
                tdfs(i, visited);
            }
        }
     }
};

/*
----------------------graph end----------------------------
*/

/*
---------------Basic Binary Tree----------------
*/
template<class T>
struct Node
{
T key;
Node *left;
Node *right;
int height;

Node(T x)
{
    key = x;
    left = right = NULL;
    height = 0;
}
};

template<class T>
int height(Node<T>* a)
{
    if(!a)
    {
        return 0;
    }
    return max(height(a->left), height(a->right)) + 1;
}

/*
------------------------ Basic Binary Search TREE -----------------------------
*/

class bst{

Node<int>* root;

public:
//INSERTION INTO BST


Node<int>* bstinsert(Node<int>* node,int data)
{
    if(node==NULL)
    {
        return new Node<int>(data);
    }

    if (data<node->key)
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
void bstpreorder(Node<int>*root)
{
    //base case
    if(root==NULL)
    {return;}

    cout<<root->key<<" ";
    bstpreorder(root->left);
    bstpreorder(root->right);
}

void bstinorder(Node<int>*root)
{
    //base case
    if(root==NULL)
    {return;}

    bstinorder(root->left);
    cout<<root->key<<" ";
    bstinorder(root->right);
}

void bstpostorder(Node<int>*root)
{
    //base case
    if(root==NULL)
    {return;}

    bstpostorder(root->left);
    bstpostorder(root->right);
    cout<<root->key<<" ";
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
    Node<int>*current=root;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current->key;
}

//FINDING MAXIMUM NODE
int maxNode()
{
    Node<int>*current=root;
    while(current && current->right!=NULL)
    {
        current=current->right;
    }
    return current->key;
}


//SEARCHING 
bool bstsearch(Node<int>*root, int key)
{
    if(!root){
        return false;
    }
    else if(root->key<key)
    {
        return bstsearch(root->right,key);
    }
    else if(root->key>key)
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
void printCurrentLevel(Node<int>* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(Node<int>* node)
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
 
void printLevelOrder(Node<int>* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
void levelorder()
{
    printLevelOrder(root);
}

//DELETION IN BST

Node<int>*minNodee(Node<int>*node)
{
    Node<int>* current=node;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}

Node<int>* deleteNode(Node<int>* root, int key)
{
    // base case
    if (root == NULL)
        return root;
  
    
    if (key < root->key)
        root->left = deleteNode(root->left, key);
  
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
  
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
        
        // node has only one child or no child
        else if (root->left == NULL) {
            Node<int>* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node<int>* temp = root->left;
            free(root);
            return temp;
        }
  
        // node with two children
        Node<int>* temp = minNodee(root->right);
  
        // Copy the inorder successor's content to this node
        root->key = temp->key;
  
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void remove(int key)
{
    deleteNode(root, key);
}
};

/*
------------------------ AVL TREE -----------------------------
*/

template<class T>
class anode{
    public:
    T key;
    anode *left;
    anode *right;
    anode(T x)
    {
        key=x;
        left=NULL;
        right=NULL;
    }
};

class avl{
  anode<int>* root;
  public:
  avl(){
      root = NULL;
  }
  avl(int a)
  {
      anode<int>* temp = new anode<int>(a);
      root = temp;
  }
   
int getheight(anode<int>* root)
{
    if(root==NULL)
    {return -1;}
    int lh=getheight(root->left);
    int rh=getheight(root->right);
    return (max(lh,rh))+1;
}
   
int height()
{
    return getheight(root);
}

void pre(anode<int>*root)
{
    if(root!=NULL)
    {cout<<" "<<root->key;
        pre(root->left);
        pre(root->right);
    }
}
void in(anode<int>*root)
{
    if(root!=NULL)
     {   in(root->left);
    cout<<" "<<root->key;
        in(root->right);
    }
}

void post(anode<int>*root)
{
    if(root!=NULL)
     {   post(root->left);
        post(root->right);
    cout<<" "<<root->key;
    }
}

void inorder(){
    in(root);
}

void preorder()
{
    pre(root);
}

void postorder()
{
    post(root);
}

int getbf(anode<int>*root)
{
    if(root==NULL)
    {return -1;}
    int lh=getheight(root->left);
    int rh=getheight(root->right);
    return (lh-rh);
}
anode<int>*rightrotate(anode<int>*root)
{
    anode<int>*b=root->left;
    anode<int>*t2=b->right;
    b->right=root;
    root->left=t2;
    return b;//as its the new root
}
anode<int>*leftrotate(anode<int>*a)
{
    anode<int>*b=a->right;
    anode<int>*t2=b->left;
    b->left=a;
    a->right=t2;
    return b;
}



anode<int>* insertsub(anode<int>* root,int x)
{
    if(root==NULL)
    {
        return new anode<int>(x);
    }
    else if(x>root->key)
    {
        root->right=insertsub(root->right,x);
    }
    else if(x<root->key)
    {
        root->left=insertsub(root->left,x);
    }
    else{return root;}
    int bf=getbf(root);//bf=lh-rh bf to be calculated after inserting the node at all ancestors here due to recursion that is done
    if(bf>1&&x<root->left->key)//main node=root as ublanced LL
    {
        root=rightrotate(root);
        return root;
    }
    else if(bf<-1&&x>root->right->key)//RR left right must exist due to such value of bf
    {
        root=leftrotate(root);
        return root;
    }
    else if(bf>1&&x>root->left->key)//LR
    {
        root->left=leftrotate(root->left);
        root=rightrotate(root);
        return root;
    }
    else if(bf<-1&&x<root->right->key)
    {root->right=rightrotate(root->right);
        root=leftrotate(root);
        return root;
    }
    return root;//after 1 balencing all nodes get balanced and due to recursion only the bootomost unbalanced node gets balanced
}

anode<int>* getsucc(anode<int>*root)
{
    anode<int>*curr=root->right;
    while(curr->left!=NULL)
    {curr=curr->left;}
    return curr;
}
anode<int>* del(anode<int>* root,int x)
{
    if(root==NULL)
    {return NULL;}
    if(x>root->key)
    {root->right=del(root->right,x);
    }
    else if(x<root->key)
    {root->left=del(root->left,x);
    }
    else//x==root->i so delete root
    {
     if(root->left==NULL)//no child or right child only
     {anode<int>*temp=root->right;
     delete root;
     root=temp;
     
     }
     else if(root->right==NULL)//left child only
     {anode<int>* temp=root->left;
     delete root;
     root=temp;
   
        }
        else{//both child
                anode<int>*temp=getsucc(root);
            root->key=temp->key;
            root->right=del(root->right,temp->key);
           
        }
    }
    int bf=getbf(root);//bf=lh-rh
    if(bf>1&&getbf(root->left)>=0)//LL
    {
        root=rightrotate(root);
    }
    else if(bf>1&& getbf(root->left)<0)//LR
    {
        root->left=leftrotate(root->left);
        root=leftrotate(root);
    }
    else if(bf<-1&&getbf(root->right)<=0)//RR
    {
        root=leftrotate(root);
    }
    else if(bf<-1&&getbf(root->right)>0)//RL
    {
        root->right=rightrotate(root->right);
        root=leftrotate(root);
    }
    return root;
}

void insert(int x){
    root = insertsub(root,x);
}

void remove(int x)
{
    root = del(root, x);
}
};