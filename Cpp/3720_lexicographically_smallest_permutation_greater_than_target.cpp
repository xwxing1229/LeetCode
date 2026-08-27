// https://leetcode.cn/problems/lexicographically-smallest-permutation-greater-than-target/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            count[s[i] - 'a'] += 1;
            count[target[i] - 'a'] -= 1;
        }
        for (int i = n-1; i >= 0; --i) {
            // Try to replace target[i] with a larger char.
            count[target[i] - 'a'] += 1;
            bool valid = true;
            for (int cnt: count) {
                if (cnt < 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            for (int j = target[i]-'a'+1; j < 26; ++j) {
                if (count[j] <= 0) continue;
                // Replace target[i] with ch_new.
                string res = target.substr(0, i);
                res += 'a' + j;
                count[j] -= 1;
                for (int k = 0; k < 26; ++k) {
                    res += string(count[k], 'a'+k);
                }
                return res;
            }
        }
        return "";
    }
};