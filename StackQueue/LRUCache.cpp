class node{
    public:
    node* next;
    node* prev;
    int key;
    int val;
    node(int _key,int _val){
        next=NULL;
        prev=NULL;
        key=_key;
        val=_val;
    }
};

class LRUCache {
public:
    node* head;
    node* tail;
    int size;
    unordered_map<int,node*> mp;
    void addnode(node* currnode){
        node* nextnode=head->next;
        head->next = currnode;
        currnode->prev=head;
        currnode->next=nextnode;
        nextnode->prev=currnode;
    }
    void deletenode(node* currnode){
        node* nextnode=currnode->next;
        node* prevnode=currnode->prev;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }
    LRUCache(int capacity) {
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* currnode = mp[key];
            deletenode(currnode);
            addnode(currnode);
            return currnode->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* currnode = mp[key];
            deletenode(currnode);
            currnode->val = value;
            addnode(currnode);
        }
        else{
            if(mp.size()>=size){
                mp.erase(tail->prev->key);
                deletenode(tail->prev);
            }
            node* currnode = new node(key,value);
            addnode(currnode);
            mp[key]=currnode;
        }
    }
};