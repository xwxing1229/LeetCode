// https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> beautiful;
        int cnt = 0, left = 0, n = s.size();
        int size_min = n;
        for (int i = 0; i < n; ++i) {
            cnt += (s[i] == '1');
            while (cnt >= k) {
                cnt -= (s[left] == '1');
                left += 1;
            }
            if (cnt == k-1 && left > 0) {
                int size = i - left + 2;
                string sub = s.substr(left-1, size);
                if (size == size_min) {
                    beautiful.push_back(sub);
                }
                else if (size < size_min) {
                    beautiful = {sub};
                    size_min = size;
                }
            }
        }
        if (beautiful.empty()) return "";
        string res = beautiful[0];
        for (const string &sub: beautiful) {
            res = min(res, sub);
        }
        return res;
    }
};