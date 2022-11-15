// https://leetcode.cn/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
            [](const vector<int>& b1, const vector<int>& b2) {
                return b1[1] > b2[1];
            });

        int res = 0, box = 0;
        while ((truckSize > 0) && (box < boxTypes.size())) {
            int num = boxTypes[box][0];
            if (truckSize < num) {
                num = truckSize;
            }
            res += (num * boxTypes[box][1]);
            truckSize -= num;
            box += 1;
        }
        return res;
    }
};
