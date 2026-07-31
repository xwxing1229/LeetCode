// https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-ii/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for (const char ch: word) {
            count[ch - 'a'] += 1;
        }
        sort(count.begin(), count.end(), greater<int>());

        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res += (i / 8 + 1) * count[i];
        }
        return res;
    }
};