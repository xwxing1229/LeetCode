// https://leetcode.cn/problems/random-flip-matrix/

class Solution {
public:
    Solution(int m, int n) {
        m_ = m;
        n_ = n;
        zeros_ = m * n;
        last_idx_ = zeros_ - 1;
    }
    
    vector<int> flip() {
        int idx = rand() % zeros_;
        vector<int> res(2);
        if (idx == last_idx_ || ones_.find(idx) != ones_.end()) {
            while (ones_.find(last_idx_) != ones_.end()) {
                last_idx_ -= 1;
            }
            res[0] = last_idx_ / n_;
            res[1] = last_idx_ % n_;
            last_idx_ -= 1;
        }
        else {
            ones_.insert(idx);
            res[0] = idx / n_;
            res[1] = idx % n_;
        }
        zeros_ -= 1;
        return res;
    }
    
    void reset() {
        zeros_ = m_ * n_;
        last_idx_ = zeros_ - 1;
        ones_.clear();
    }

    int m_, n_, zeros_;
    int last_idx_;
    unordered_set<int> ones_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
