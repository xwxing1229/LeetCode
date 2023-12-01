// https://leetcode.cn/problems/smallest-number-in-infinite-set/

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        min_val_ = 1;
    }
    
    int popSmallest() {
        removed_.insert(min_val_);
        int min_value = min_val_;
        while (removed_.find(min_val_) != removed_.end()) {
            min_val_ += 1;
        }
        return min_value;
    }
    
    void addBack(int num) {
        if (removed_.find(num) != removed_.end()) {
            removed_.erase(num);
        }
        min_val_ = min(min_val_, num);
    }

    unordered_set<int> removed_;
    int min_val_;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */