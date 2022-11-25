// https://leetcode.cn/problems/expressive-words/

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        string ss = "";
        vector<int> cnt;
        int k = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i-1]) {
                ss += s[i-1];
                cnt.push_back(k);
                k = 1;
            }
            else k += 1;
        }
        ss += s[s.size()-1];
        cnt.push_back(k);

        int res = words.size();
        for (string& word: words) {
            word += ' ';
            int j = 0, k = 1;
            for (int i = 1; i < word.size(); ++i) {
                if (word[i] != word[i-1]) {
                    if (j == ss.size()) {
                        res -= 1;
                        break;
                    }
                    if ((word[i-1] != ss[j]) || (cnt[j] < k) || (cnt[j] > k && cnt[j] < 3)) {
                        break;
                    }
                    j += 1;
                    k = 1;
                }
                else {
                    k += 1;
                }
            }
            if (j != ss.size()) res -= 1;
        }
        return res;
    }
};
