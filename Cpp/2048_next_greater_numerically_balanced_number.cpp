// https://leetcode.cn/problems/next-greater-numerically-balanced-number/

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int res = n + 1;
        while (!isBalance(res)) {
            res += 1;
        }
        return res;
    }

    bool isBalance(int num) {
        vector<int> cnt(10, 0);
        while (num > 0) {
            cnt[num % 10] += 1;
            num /= 10;
        }
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt[i] > 0 && cnt[i] != i) {
                return false;
            }
        }
        return true;
    }
};