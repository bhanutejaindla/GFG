//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Back-end complete function Template for C++
class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    
    int verticalWidth(Node* root) {
        // code here
        if(!root) return 0;
        pair<int,Node*>p;
        priority_queue<pair<int,Node*>>pq;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        pq.push({0,root});
        while(!q.empty())
        {
            auto v=q.front();
            q.pop();
            if(v.second->left)
            {
                q.push({v.first-1,v.second->left});
                pq.push({v.first-1,v.second->left});
            }
            if(v.second->right)
            {
                q.push({v.first+1,v.second->right});
                pq.push({v.first+1,v.second->right});
            }
        }
        int maxi=0;
        int mini=INT_MAX;
        while(!pq.empty())
        {
            int a=pq.top().first;
            pq.pop();
             maxi=max(a,maxi);
             mini=min(a,mini);
        }
        return maxi-mini+1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Solution obj;
        Node *root = buildTree(str);

        cout << obj.verticalWidth(root) << "\n";
    }

    return 0;
}

// } Driver Code Ends