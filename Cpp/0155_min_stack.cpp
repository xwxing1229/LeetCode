// https://leetcode.cn/problems/min-stack/submissions/

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if (len == 0) {
            stack_.push_back((vector<int>){val, val});
        }
        else {
            stack_.push_back((vector<int>){val, min(stack_[len-1][1], val)});
        }
        len = len + 1;
    }
    
    void pop() {
        stack_.pop_back();
        len = len - 1;
    }
    
    int top() {
        return stack_[len-1][0];
    }
    
    int getMin() {
        return stack_[len-1][1];
    }

private:
    vector<vector<int>> stack_;
    int len = 0;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */