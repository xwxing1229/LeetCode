// https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii/

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> cnts(24, 0);
        long long res = 0;
        for (int h: hours) {
            int rem = h % 24;
            if (rem == 0) {
                res += cnts[0];
            }
            else {
                res += cnts[24 - rem];
            }
            cnts[rem] += 1;
        }
        return res;
    }
};

