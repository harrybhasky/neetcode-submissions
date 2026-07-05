class MinStack {
public:
stack<int> stck;
stack<int> minstack;

    MinStack() {
        
    }
    
    void push(int val) {
        stck.push(val);
        val = std:: min(val, minstack.empty()? val: minstack.top());
        minstack.push(val);
    }
    
    void pop() {
       stck.pop(); 
       minstack.pop();

    }
    
    int top() {
        return stck.top();
    
    }
    
    int getMin() {
        return minstack.top();
    }
};
