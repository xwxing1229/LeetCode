// https://leetcode.cn/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> stk1, stk2;
    MyQueue() {

    }
    
    void push(int x) {
        int n = stk1.size();
        for (int i = 0; i < n; ++i) {
            int num = stk1.top();
            stk1.pop();
            stk2.push(num);
        }
        stk1.push(x);
        for (int i = 0; i < n; ++i) {
            int num = stk2.top();
            stk2.pop();
            stk1.push(num);
        }
    }
    
    int pop() {
        int res = stk1.top();
        stk1.pop();
        return res;
    }
    
    int peek() {
        return stk1.top();
    }
    
    bool empty() {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */