/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        root->next=NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            Node* temp2=NULL;

            for(int i=0;i<n;i++){
            Node* temp=q.front();
            if(temp2){
                temp2->next=temp;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            temp2=temp;
            q.pop();
                
            }
            temp2->next=NULL;
           // q.pop();
        }
        return root;
        
    }
};
