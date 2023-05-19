// https://leetcode.cn/problems/determine-if-two-events-have-conflict/

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int e1_start = getTime(event1[0]), e1_end = getTime(event1[1]);
        int e2_start = getTime(event2[0]), e2_end = getTime(event2[1]);
        if (e1_end < e2_start || e2_end < e1_start) {
            return false;
        }
        else {
            return true;
        }
    }

    int getTime(string t) {
        int res = stoi(t.substr(0,2)) * 60 + stoi(t.substr(3,2));
        return res;
    }
};
