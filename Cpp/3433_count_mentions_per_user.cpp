// https://leetcode.cn/problems/count-mentions-per-user/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string> &e1, const vector<string> &e2) {
            int t1 = stoi(e1[1]), t2 = stoi(e2[1]);
            return t1 < t2 || (t1 == t2 && e1[0] > e2[0]);
        });
        vector<int> res(numberOfUsers, 0);
        vector<int> online(numberOfUsers, 0);
        int mention_all = 0;
        for (const auto &e: events) {
            if (e[0][0] == 'M') {
                if (e[2] == "ALL") mention_all += 1;
                else if (e[2] == "HERE") {
                    int t = stoi(e[1]);
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (online[i] <= t) res[i] += 1;
                    }
                }
                else {
                    int start = 0;
                    for (int i = 0; i < e[2].size(); ++i) {
                        if (e[2][i] == ' ') {
                            int user = stoi(e[2].substr(start+2, i-start-2));
                            res[user] += 1;
                            start = i + 1;
                        }
                    }
                    int user = stoi(e[2].substr(start+2, e[2].size()-start-2));
                    res[user] += 1;
                }
            }
            else {
                online[stoi(e[2])] = stoi(e[1]) + 60;
            }
        }
        for (int i = 0; i < numberOfUsers; ++i) {
            res[i] += mention_all;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int numberOfUsers = 2;
    vector<vector<string>> events = {
        {"MESSAGE","10","id1 id0"},
        {"OFFLINE","11","0"},
        {"MESSAGE","71","HERE"}
    };
    auto res = sol.countMentions(numberOfUsers, events);
    for (auto val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}