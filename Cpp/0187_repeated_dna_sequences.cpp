// https://leetcode.cn/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> cnt;
        int n = s.size();
        for (int i = 0; i < n-9; ++i) {
            string ssub = s.substr(i, 10);
            cnt[ssub] = cnt[ssub] + 1;
            if (cnt[ssub] == 2) {
                res.push_back(ssub);
            }
        }
        return res;
    }
};
