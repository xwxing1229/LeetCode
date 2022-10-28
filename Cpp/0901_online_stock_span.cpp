// https://leetcode.cn/problems/online-stock-span/

class StockSpanner {
public:
    StockSpanner() {
        stk.push_back(make_pair(-1, INT_MAX));
        idx = -1;
    }
    
    int next(int price) {
        idx += 1;
        while (price >= stk.back().second) {
            stk.pop_back();
        }
        int res = idx - stk.back().first;

        stk.push_back(make_pair(idx, price));
        
        return res;
    }

private:
    vector<pair<int,int>> stk;
    int idx;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */