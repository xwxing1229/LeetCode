// https://leetcode.cn/problems/find-the-count-of-numbers-which-are-not-special/

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int cnt = 0;
        for (int num = 3; num <= (int)sqrt(r); num+=2) {
            bool prime = true;
            for (int factor = 3; factor <= (int)sqrt(num); factor+=2) {
                if (num % factor == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime && num * num >= l) {
                cnt += 1;
            }
        }
        int res = r - l + 1 - cnt;
        if (4 >= l && 4 <= r) {
            res -= 1;
        }
        return res;
    }
};
