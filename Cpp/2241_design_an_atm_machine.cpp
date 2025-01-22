// https://leetcode.cn/problems/design-an-atm-machine/

class ATM {
public:
    ATM() {
        valids_ = {20, 50, 100, 200, 500};
        cnts_ = {0, 0, 0, 0, 0};
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            cnts_[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> res(5, 0);
        for (int i = 4; i >= 0; --i) {
            res[i] = min(cnts_[i], amount / valids_[i]);
            amount -= res[i] * valids_[i];
        }
        if (amount != 0) return vector<int>{-1};
        for (int i = 0; i < 5; ++i) {
            cnts_[i] -= res[i];
        }
        return res;
    }

    vector<int> valids_, cnts_;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */