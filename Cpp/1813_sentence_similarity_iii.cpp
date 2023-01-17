// https://leetcode.cn/problems/sentence-similarity-iii/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1), words2 = split(sentence2);
        int i = 0, j = 0, n1 = words1.size(), n2 = words2.size();
        while ((i < n1) && (i < n2) && (words1[i] == words2[i])) {
            i += 1;
        }
        while ((j < n1 - i) && (j < n2 - i) && (words1[n1-1-j] == words2[n2-1-j])) {
            j += 1;
        }
        if (i + j == min(n1, n2)) {
            return true;
        }
        else {
            return false;
        }
    }

    vector<string> split(string s) {
        vector<string> res;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                res.push_back(s.substr(start, i-start));
                start = i + 1;
            }
        }
        res.push_back(s.substr(start, s.size()-start));
        return res;
    }
};
