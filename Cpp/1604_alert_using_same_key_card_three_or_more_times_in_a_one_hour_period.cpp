// https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> table;
        for (int i = 0; i < keyName.size(); ++i) {
            int hour = stoi(keyTime[i].substr(0,2));
            int minute = stoi(keyTime[i].substr(3,2));
            table[keyName[i]].push_back(hour * 60 + minute);
        }

        vector<string> res;
        for (auto it = table.begin(); it != table.end(); ++it) {
            vector<int> times = it->second;
            sort(times.begin(), times.end());
            for (int i = 0; i < times.size()-2; ++i) {
                if (times[i+2] - times[i] <= 60) {
                    res.push_back(it->first);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
