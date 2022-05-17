class LRUCache {
public:
    int r=0;
    
    class Node{
      public:  
        int key;
        int value;
        Node* prev;
        Node* next;
    }; 
    Node* tail=NULL;
    Node* head=NULL;
    unordered_map<int,Node*> umap;

    Node* newNode(int keys, int val){
        Node* node=new Node();
        node->key=keys;
        node->value=val;
        if(tail!=NULL){
        tail->next=node;
        }
        node->prev=tail;
        node->next=NULL;
        tail=node;
        if(head==NULL){
            head=node;
            
        }
        return node;
    }
    
    void moveToTail(Node* node){
        Node* previ=node->prev;
        Node* nexti=node->next;
        if(previ!=NULL){
        previ->next=nexti;
        }
        if(nexti!=NULL){
        nexti->prev=previ;
        }
        tail->next=node;
        node->prev=tail;
        node->next=NULL;
        if(head==node){
            head=nexti;
        }
        tail=node;
    }
    
    Node* removeHead(){
        Node* temp=head;
        Node* nexti=head->next;
        head=nexti;
        temp->next=NULL;
        return temp;
        
    }
    
    LRUCache(int capacity) {
        r=capacity;
    }
    
    int get(int key) {
        if (umap.find(key)!=umap.end()){
            Node* node=umap[key];
            if(node!=tail){
            moveToTail(node);
            }
            return umap[key]->value;
        }    
        return -1;
    }
    
    void put(int key, int val) {
        if(umap.find(key)!=umap.end()){
            umap[key]->value=val;
            if(umap[key]!=tail){
            moveToTail(umap[key]);
            }
            return;
        }
        else{
            if(umap.size()==r){
                Node* removed=removeHead();
                umap.erase(removed->key);
            }
            Node* node= newNode(key,val);
            umap[key]=node;

        }
        
    }
};

