// https://leetcode.cn/problems/earliest-finish-time-for-land-and-water-rides-i/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto f = [](const vector<int>& firstStartTime, const vector<int>& firstDuration,
                    const vector<int>& secondStartTime, const vector<int>& secondDuration) {
            int res = INT_MAX;
            int n_first = firstStartTime.size(), n_second = secondStartTime.size();
            for (int i1 = 0; i1 < n_first; ++i1) {
                int finish = firstStartTime[i1] + firstDuration[i1];
                for (int i2 = 0; i2 < n_second; ++i2) {
                    int t;
                    if (finish > secondStartTime[i2]) {
                        t = finish + secondDuration[i2];
                    }
                    else {
                        t = secondStartTime[i2] + secondDuration[i2];
                    }
                    res = min(res, t);
                }
            }
            return res;
        };
        
        return min(
            f(landStartTime, landDuration, waterStartTime, waterDuration),
            f(waterStartTime, waterDuration, landStartTime, landDuration)
        );
    }
};

int main() {
    Solution sol;
    vector<int> landStartTime = {2,8}, landDuration = {4,1};
    vector<int> waterStartTime = {6}, waterDuration = {3};
    cout << sol.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << '\n';
    return 0;
}