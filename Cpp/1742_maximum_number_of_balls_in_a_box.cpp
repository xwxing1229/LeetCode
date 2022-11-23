// https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> cnt;
        int res = 0;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int s = 0, num = i;
            while (num > 0) {
                s += (num % 10);
                num /= 10;
            }
            cnt[s] += 1;
            if (res < cnt[s]) {
                res = cnt[s];
            }
        }
        return res;
    }
};
