// https://leetcode.cn/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        struct HASH {
            int operator()(const vector<int> &V) const {
                int hash = 0;
                for(int i = 0; i < V.size(); ++i) {
                    hash ^= V[i];
                }
                return hash;
            }
        };

        vector<vector<string>> res;

        unordered_map<vector<int>, int, HASH> record;
        int idx = 0;

        for (string s: strs) {
            vector<int> count_s = count(s);
            auto iter = record.find(count_s);
            if (iter != record.end()) {
                res[iter->second].push_back(s);
            }
            else {
                vector<string> res_tmp = {s};
                res.push_back(res_tmp);
                record.emplace(count_s, idx);
                idx = idx + 1;
            }
        }
        return res;
    }

    vector<int> count(string s) {
        vector<int> res(26, 0);
        for (char c: s) {
            int idx = c - 'a';
            res[idx] = res[idx] + 1;
        }
        return res;
    }
};
