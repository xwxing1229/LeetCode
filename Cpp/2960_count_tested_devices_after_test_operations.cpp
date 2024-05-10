// https://leetcode.cn/problems/count-tested-devices-after-test-operations/
        
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int res = 0, n = batteryPercentages.size();
        for (int i = 0; i < n; ++i) {
            if (batteryPercentages[i] > 0) {
                res += 1;
                for (int j = i+1; j < n; ++j) {
                    batteryPercentages[j] = max(0, batteryPercentages[j]-1);
                }
            }
        }
        return res;
    }
};
