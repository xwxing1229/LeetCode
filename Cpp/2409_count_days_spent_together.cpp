// https://leetcode.cn/problems/count-days-spent-together/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };
        vector<int> cumsum(12, 0);
        for (int i = 1; i < 12; ++i) {
            cumsum[i] = cumsum[i-1] + days[i-1];
        }
        auto convert = [&](const string &s) {
            return cumsum[stoi(s.substr(0,2))-1] + stoi(s.substr(3,2));
        };
        int arrive_a = convert(arriveAlice), leave_a = convert(leaveAlice);
        int arrive_b = convert(arriveBob), leave_b = convert(leaveBob);
        return max(min(leave_a, leave_b) - max(arrive_a, arrive_b) + 1, 0);
    }
};