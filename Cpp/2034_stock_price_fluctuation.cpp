// https://leetcode.cn/problems/stock-price-fluctuation/

class StockPrice {
public:
    StockPrice() {
        cur_ = 0;
    }
    
    void update(int timestamp, int price) {
        cur_ = max(cur_, timestamp);
        stock_[timestamp] = price;
        pq_max_.emplace(make_pair(price, timestamp));
        pq_min_.emplace(make_pair(-price, timestamp));
    }
    
    int current() {
        return stock_[cur_];
    }
    
    int maximum() {
        while (true) {
            auto pt = pq_max_.top();
            if (pt.first == stock_[pt.second]) {
                return pt.first;
            }
            pq_max_.pop();
        }
    }
    
    int minimum() {
        while (true) {
            auto pt = pq_min_.top();
            if (-pt.first == stock_[pt.second]) {
                return -pt.first;
            }
            pq_min_.pop();
        }
    }

private:
    int cur_;
    unordered_map<int, int> stock_;
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq_max_, pq_min_;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */