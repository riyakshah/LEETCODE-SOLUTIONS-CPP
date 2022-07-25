/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> umap;
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        Node* temp=new Node(node->val);
        umap[node]=temp;
        vector<Node*> ne=node->neighbors;
        vector<Node*> be;
        
        for(int i=0;i<ne.size();i++){
            if(umap.find(ne[i])!=umap.end()){
                be.push_back(umap[ne[i]]);
            }
            else{
                be.push_back(cloneGraph(ne[i]));
            }
        }
        temp->neighbors=be;
        return temp;
    }
};
