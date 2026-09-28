// https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for (const auto &ab: knowledge) {
            m[ab[0]] = ab[1];
        }
        string res;
        int n = s.size(), i = 0;
        while (i < n) {
            if (s[i] == '(') {
                int prev = i;
                while (i < n && s[i] != ')') {
                    i += 1;
                }
                string sub = s.substr(prev+1, i-prev-1);
                if (m.count(sub)) res += m[sub];
                else res += '?';
            }
            else {
                res += s[i];
            }
            i += 1;
        }
        return res;
    }
};