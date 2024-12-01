// https://leetcode.cn/problems/find-if-digit-game-can-be-won/

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        for (int num: nums) {
            if (num < 10) s1 += num;
            else s2 += num;
        }
        return s1 != s2;
    }
};
