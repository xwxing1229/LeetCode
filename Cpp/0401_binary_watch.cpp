// https://leetcode.cn/problems/binary-watch/

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        for (int onHour = max(turnedOn-6,0); onHour < min(turnedOn,3)+1; ++onHour) {
            dfsHour(onHour, 0, 0, 0);
            dfsMin(turnedOn-onHour, 0, 0 ,0);
        }

        vector<string> res;
        for (auto iter = hourTable.begin(); iter != hourTable.end(); ++iter) {
            int onHour = iter->first;
            if (minTable.find(turnedOn-onHour) == minTable.end()) {
                continue;
            }
            for (string h: iter->second) {
                for (string m: minTable[turnedOn-onHour]) {
                    res.push_back(h+':'+m);
                }
            }
        }
        return res;
    }

private:
    void dfsHour(int turnedOn, int tmpOn, int tmpTime, int idx) {
        if ((tmpOn == turnedOn) && (tmpTime < 12)) {
            hourTable[turnedOn].push_back(to_string(tmpTime));
            return;
        }

        for (int i = idx; i < 4; ++i) {
            dfsHour(turnedOn, tmpOn+1, tmpTime+hours[i], i+1);
        }
    }

    void dfsMin(int turnedOn, int tmpOn, int tmpTime, int idx) {
        if ((tmpOn == turnedOn) && (tmpTime < 60)) {
            if (tmpTime < 10) {
                string tmp = '0' + to_string(tmpTime);
                minTable[turnedOn].push_back(tmp);
            }
            else {
                minTable[turnedOn].push_back(to_string(tmpTime));
            }
            return;
        }

        for (int i = idx; i < 6; ++i) {
            dfsMin(turnedOn, tmpOn+1, tmpTime+mins[i], i+1);
        }
    }
    unordered_map<int, vector<string>> hourTable, minTable;

    vector<int> hours = {1, 2, 4, 8};
    vector<int> mins = {1, 2, 4, 8, 16, 32};
};
