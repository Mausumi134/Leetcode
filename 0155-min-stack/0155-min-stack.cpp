class MinStack {
public:

    stack<int>st;
    stack<int>mins;
    MinStack() {
        mins.push(INT_MAX);
    }
    
    void push(int val) {
        if(val<=mins.top())mins.push(val);
        st.push(val);
    }
    
    void pop() {
        if(mins.top()==st.top())mins.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */