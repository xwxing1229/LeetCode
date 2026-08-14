// https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        vector<int> cnt(26, 0);
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            cnt[idx] += 1;
            while (cnt[idx] > 2) {
                cnt[s[left] - 'a'] -= 1;
                left += 1;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};