// https://leetcode.cn/problems/destination-city/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for (auto &p: paths) {
            s.insert(p[1]);
        }
        for (auto &p: paths) {
            s.erase(p[0]);
        }
        string res;
        for (const string &city: s) {
            res = city;
            break;
        }
        return res;
    }
};
