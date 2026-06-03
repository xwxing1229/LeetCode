// https://leetcode.cn/problems/earliest-finish-time-for-land-and-water-rides-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto f = [](const vector<int>& firstStartTime, const vector<int>& firstDuration, const vector<int>& secondStartTime, const vector<int>& secondDuration) {
            int finish = firstStartTime[0] + firstDuration[0];
            for (int i = 0; i < firstStartTime.size(); ++i) {
                finish = min(finish, firstStartTime[i] + firstDuration[i]);
            }
            int res = max(finish, secondStartTime[0]) + secondDuration[0];
            for (int i = 0; i < secondStartTime.size(); ++i) {
                int tmp = max(finish, secondStartTime[i]) + secondDuration[i];
                res = min(res, tmp);
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