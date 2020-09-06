#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr){}
};
int LCA[MAXN][10];
int level[MAXN];
Node* refer[MAXN];

void dfs(Node* root, int p = -1, int l = 0) {
    if(root == nullptr) return;

    int currNodeData = root -> data;
    refer[currNodeData] = root;
    LCA[currNodeData][0] = p;
    level[currNodeData] = l;
    dfs(root -> left, currNodeData, l + 1);
    dfs(root -> right, currNodeData, l + 1);
}


void initialize(Node* root) {
    for(int i = 0; i < MAXN; ++i) {
        for(int j = 0; j < 10; ++j) {
            LCA[i][j] = -1;
        }
        level[i] = -1;
    }
    dfs(root);
    for(int j = 1; j < 10; ++j) {
        for(int i = 0; i < MAXN; ++i) {
            if(LCA[i][j - 1] != -1) {
                int par = LCA[i][j - 1];
                LCA[i][j] = LCA[par][j - 1];
            }
        }
    }
}
Node * lca(Node* root,int a,int b) {
    initialize(root);
    int la = level[a];
    int lb = level[b];
    if(la == lb) {
        if(la == -1) return nullptr;

    }
    else if(la == -1 && lb != -1) {
        return refer[b];
    }
    else if(la != -1 && lb == -1) {
        return refer[a];
    }
    if(level[a] >  level[b]) swap(a, b);

    int d = level[b] - level[a];

    while(d > 0) {
        int i = log2(d);
        b = LCA[b][i];
        d -= (1 << i);
    }
    if(a == b) return refer[a];

    for(int i = 9; i >= 0; --i) {
        if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i])) {
            a = LCA[a][i], b = LCA[b][i];
        }
    }
    return refer[LCA[a][0]];
}

// Utility function to create a new Tree Node
Node* newNode(int val){
    Node* temp = new Node(val);
    return temp;
}


// Function to Build Tree
Node* buildTree(string str){
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root){
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        cout<<lca(root,a,b)->data<<endl;
    }
    return 0;
}