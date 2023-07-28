class MyQueue {
public:
    stack<int> st1,st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            if(st1.empty()) return -1;
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int topele=st2.top();
        st2.pop();
        return topele;
    }
    
    int peek() {
        if(st2.empty()){
            if(st1.empty()) return -1;
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int topele=st2.top();
        return topele;
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()) return true;
        return false;
    }
};