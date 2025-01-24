// https://leetcode.cn/problems/total-distance-traveled/
        
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;
        while (mainTank >= 5 && additionalTank > 0) {
            res += 50;
            mainTank -= 4;
            additionalTank -= 1;
        }
        res += 10 * mainTank;
        return res;
    }
};
