/*
class MyQueue {
public:
    // Initialize your data structure here. 
    stack<int> s;
    MyQueue() {
        
    }
    
    // Push element x to the back of queue. 
    void push(int x) {
        stack<int> tmp;
        while (!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
    }
    
    // Removes the element from in front of queue and returns that element. 
    int pop() {
        int top = s.top();
        s.pop();
        return top;
    }
    
    // Get the front element. 
    int peek() {
        return s.top();
    }
    
    // Returns whether the queue is empty. 
    bool empty() {
        return s.empty();
    }
};
*/
class MyQueue {
public:
    // Initialize your data structure here. 
    stack<int> q, s;
    MyQueue() {
        
    }
    void shift() {
        if (q.empty()) {
            while (!s.empty()) {
                q.push(s.top());
                s.pop();
            }    
        }
    }
    // Push element x to the back of queue. 
    void push(int x) {
        s.push(x);
    }
    
    // Removes the element from in front of queue and returns that element. 
    int pop() {
        shift();
        int top = q.top();
        q.pop();
        return top;
    }
    
    // Get the front element. 
    int peek() {
        shift();
        return q.top();
    }
    
    // Returns whether the queue is empty. 
    bool empty() {
        return s.empty() && q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */