class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            st.push({val,min(st.top().second,val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        auto top=st.top();
        return top.first;
    }
    
    int getMin() {
        auto getmin=st.top();
        return getmin.second;
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