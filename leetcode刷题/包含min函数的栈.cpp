class MinStack {
    stack<int> thisstack;
    stack<int> minstack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        thisstack.push(x);
        if(minstack.empty())
            minstack.push(x);
        else{
            int tmp=minstack.top();
            if(x<tmp)
                minstack.push(x);
            else
                minstack.push(tmp);
        }
    }
    
    void pop() {
        thisstack.pop();
        minstack.pop();
    }
    
    int top() {
        return thisstack.top();
    }
    
    int min() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */