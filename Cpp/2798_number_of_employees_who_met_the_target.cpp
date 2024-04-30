// https://leetcode.cn/problems/number-of-employees-who-met-the-target/
        
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int res = 0;
        for (int h: hours) {
            if (h >= target) {
                res += 1;
            }
        }
        return res;
    }
};
