// https://leetcode.cn/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char ch: s) {
            cnt[ch] += 1;
        }
        vector<pair<char, int>> cnt_sort;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            cnt_sort.push_back(make_pair(it->first, it->second));
        }
        sort(cnt_sort.begin(), cnt_sort.end(),
            [](const pair<char,int>& p1, const pair<char,int>& p2) {
                return p1.second > p2.second;
            });

        string res;
        for (pair<char,int>& p: cnt_sort) {
            for (int i = 0; i < p.second; ++i) {
                res += p.first;
            }
        }
        return res;
    }
};
