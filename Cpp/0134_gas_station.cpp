// https://leetcode.cn/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // If start -> idx is not possible, check from idx rather than start+1.
        int start = -1, idx = 0;
        int n = gas.size();
        while (start < idx) {
            start = idx;
            int g = gas[idx];
            while (g >= 0) {
                g = g - cost[idx];
                idx = (idx + 1) % n;

                if (g >= 0) {
                    g = g + gas[idx];
                    if (idx == start) {
                        return start;
                    }
                }
            }
        }
        return -1;
    }
};
