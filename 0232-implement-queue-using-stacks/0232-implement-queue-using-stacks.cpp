class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int value = peek();
        output.pop();
        return value;
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()) {
                int value = input.top();
                output.push(value);
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/*
    1,4,5,6
    
    stack 1 : 1 -> 4 -> 5 -> 6
    stack 2 : 6 -> 5 -> 4 -> 1
    pop : 1
    stack 2 : 6 -> 5 -> 4 
    push : 7
    stack 1 : 4 -> 5 -> 6 -> 7
    stack 2 : 7 -> 6 -> 5 -> 4
    pop : 4
    stack 2 : 7 -> 6 -> 5
    print stack (queue implemented) : 5 -> 6 -> 7
    
    queue : 1 -> 4 -> 5 -> 6 
    pop : 1
    push : 7
    queue : 4 -> 5 -> 6 -> 7
    pop : 4
    queue : 5 -> 6 -> 7
    
*/ 



/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */