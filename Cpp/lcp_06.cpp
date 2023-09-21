// https://leetcode.cn/problems/na-ying-bi/

class Solution {
public:
    int minCount(vector<int>& coins) {
        int res = 0;
        for (int c: coins) {
            res += (c+1)/2;
        }
        return res;
    }
};
