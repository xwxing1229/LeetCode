// https://leetcode.cn/problems/distribute-candies/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        int res = 1, pre = candyType[0];
        int n = candyType.size(), half = n/2, i = 1;
        while (i < n && res < half) {
            int candy = candyType[i];
            if (candy != pre) {
                res += 1;
                pre = candy;
            }
            i += 1;
        }
        return res;
    }
};
