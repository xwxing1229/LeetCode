// https://leetcode.cn/problems/minimum-operations-to-sort-a-string/

#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        char mn = 'z', mx = 'a';
        int mn_cnt = 0, mx_cnt = 0;
        char prev = 'a';
        bool sorted = true;
        for (char ch: s) {
            if (ch < mn) {
                mn = ch;
                mn_cnt = 1;
            }
            else if (ch == mn) {
                mn_cnt += 1;
            }

            if (ch > mx) {
                mx = ch;
                mx_cnt = 1;
            }
            else if (ch == mx) {
                mx_cnt += 1;
            }

            if (ch < prev) {
                sorted = false;
            }
            prev = ch;
        }

        if (sorted) return 0;
        else if (s.size() == 2) return -1;
        else if (s[0] == mn || s.back() == mx) return 1;
        else if (s[0] == mx && s.back() == mn && mn_cnt == 1 && mx_cnt == 1) return 3;
        else return 2;
    }
};