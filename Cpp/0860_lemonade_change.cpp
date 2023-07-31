// https://leetcode.cn/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0;
        bool res = true;
        for (int bill: bills) {
            if (bill == 5) {
                c5 += 1;
            }
            else if (bill == 10) {
                c5 -= 1;
                c10 += 1;
            }
            else if (bill == 20) {
                if (c10 > 0) {
                    c10 -= 1;
                    c5 -= 1;
                }
                else {
                    c5 -= 3;
                }
            }
            if (c5 < 0 || c10 < 0) {
                res = false;
                break;
            }
        }
        return res;
    }
};