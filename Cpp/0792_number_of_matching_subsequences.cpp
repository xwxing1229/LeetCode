// https://leetcode.cn/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> idxs(26);
        for (int i = 0; i < s.size(); ++i) {
            idxs[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        for (string& word: words) {
            // Find a minimum value in idxs[ch-'a'] that is greater than cur.
            int cur = -1;
            for (char ch: word) {
                int n = idxs[ch - 'a'].size();
                int left = 0, right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (idxs[ch-'a'][mid] > cur) right = mid - 1;
                    else left = mid + 1;
                }
                if (left >= n) {
                    res -= 1;
                    break;
                }
                cur = idxs[ch-'a'][left];
            }
        }
        return res;
    }
};
