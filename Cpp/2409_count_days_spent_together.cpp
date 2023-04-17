// https://leetcode.cn/problems/count-days-spent-together/

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };
        vector<string> alice_bob = {arriveAlice, leaveAlice, arriveBob, leaveBob};
        vector<int> days(4);
        for (int i = 0; i < 4; ++i) {
            int tmp = stoi(alice_bob[i].substr(3, 2));
            for (int j = 0; j < stoi(alice_bob[i].substr(0, 2)) - 1; ++j) {
                tmp += months[j];
            }
            days[i] = tmp;
        }
        int res = min(days[1], days[3]) - max(days[0], days[2]) + 1;
        if (res < 0) {
            res = 0;
        }
        return res;
    }
};
