class LRUCache {
public:
    class node{ // doubly Linked list
        public:
        int key, val ; 
        node* next ;
        node* prev; 
        node(int _key , int _val){
            key = _key;
            val = _val;
        }
    };
    //dummy values
    node * head = new node(-1 , -1 );
    node * tail = new node(-1 , -1 );
    
    unordered_map<int , node* > m;
    int cap ;
    LRUCache(int capacity) {
       cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            node* resnode = m[key];
            int res = resnode->val;
           
            //placing on a new address
             m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        } 
        // if key doesn't exists
        return -1 ;
    }
    void put(int key, int value) {
       if(m.find(key) != m.end()) {  // if the key exists in the hashmap 
       //deleting current copy
        node* existingnode = m[key];
        m.erase(key);
        deletenode(existingnode);
       }   
        if (m.size() == cap ){ // if capcity is full
            //deleting the last one 
           m.erase(tail->prev->key);
           deletenode(tail->prev);
        }
        addnode(new node(key ,value)); // add node to head->next
        m[key] = head->next;
    }
    void deletenode(node* delnode){
        node* delprev = delnode->prev ; 
        node* delnext = delnode->next;
        delprev->next = delnext ;  // skipping current node from the list
        delnext->prev= delprev;
    } 
     void addnode(node* newnode){
         node* temp  = head->next; //temp is first element after head
         newnode->next =  temp; //make the first element second 
         newnode->prev = head; // attach newnode with head
         head->next= newnode; //attach head with new node
         temp->prev =newnode;// attach previois first prev as newnode
     } 
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
