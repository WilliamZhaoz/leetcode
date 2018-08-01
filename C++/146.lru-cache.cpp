// version 1: use list in STL
/*
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) { 
        // auto it = m.find(key);
        // if (it == m.end()) {
        //     return -1;
        // }
        // l.splice(l.begin(), l, it->second);
        // return it->second->second;  
        if (m.count(key)) {
            l.splice(l.begin(), l, m[key]);
            return m[key]->second;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            l.erase(it->second);
        }
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap) {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};
*/

// version 2: defined ListNode struct

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        used = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (m.count(key)) {
            Node *p = m[key];
            int val = p->val;
            delete_node(p);
            m[key] = insert_node(key, val);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {       
            delete_node(m[key]);
            used--;
        }
        m[key] = insert_node(key, value);
        used++;
        if (used > cap) {           
            m.erase(tail->pre->key); 
            delete_node(tail->pre);          
            used--;
        }
        
    }
private:
    int cap, used;
    struct Node{
        int val, key;
        Node *pre, *next;
        Node(int key, int val): key(key), val(val), pre(NULL), next(NULL){};
    };
    unordered_map<int, Node*> m;
    Node *head, *tail;
    void delete_node(Node *p) {
        p->pre->next = p->next;
        p->next->pre = p->pre;    
        delete p;
        
    }
    Node* insert_node(int key, int val) {
        Node *node = new Node(key, val);
        head->next->pre = node;
        node->next = head->next;
        head->next = node;
        node->pre = head;
        return node;
    }    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */