// https://leetcode.cn/problems/design-browser-history/

#include <vector>
#include <string>

using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history_.push_back(homepage);
        cur_ = 0;
    }
    
    void visit(string url) {
        cur_ += 1;
        history_.resize(cur_+1);
        history_[cur_] = url;
    }
    
    string back(int steps) {
        cur_ = max(0, cur_-steps);
        return history_[cur_];
    }
    
    string forward(int steps) {
        cur_ = min((int)history_.size()-1, cur_+steps);
        return history_[cur_];
    }
    
    vector<string> history_;
    int cur_;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */