// https://leetcode.cn/problems/distribute-candies-among-children-i/
        
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        for (int i = 0; i <= limit; ++i) {
            for (int j = 0; j <= limit; ++j) {
                int k = n - i - j;
                if (k >= 0 && k <= limit) res += 1;
                else if (k < 0) break;
            }
        }
        return res;
    }
};
