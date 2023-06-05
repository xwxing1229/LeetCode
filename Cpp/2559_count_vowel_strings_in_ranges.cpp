// https://leetcode.cn/problems/count-vowel-strings-in-ranges/

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> vowels(26, 0);
        vowels['a' - 'a'] = 1;
        vowels['e' - 'a'] = 1;
        vowels['i' - 'a'] = 1;
        vowels['o' - 'a'] = 1;
        vowels['u' - 'a'] = 1;
        vector<int> valid(n+1, 0);
        for (int i = 0; i < n; ++i) {
            string word = words[i];
            if (vowels[word[0]-'a'] && vowels[word.back()-'a']) {
                valid[i+1] = valid[i] + 1;
            }
            else {
                valid[i+1] = valid[i];
            }
        }

        vector<int> res(queries.size(), 0);
        for (int k = 0; k < queries.size(); ++k) {
            res[k] = valid[queries[k][1]+1] - valid[queries[k][0]];
        }
        return res;
    }
};