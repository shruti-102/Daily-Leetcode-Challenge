class MinStack {
public:
    vector<int> v;
    int minval=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        minval=min(minval,val);
    }
    
    void pop() {
        int secmin=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            secmin=min(secmin,v[i]);
        }
        minval=secmin;
        if(v.size()>1) v.pop_back();
        else v.clear();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return minval;
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