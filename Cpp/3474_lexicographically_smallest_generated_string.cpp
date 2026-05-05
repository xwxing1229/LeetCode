// https://leetcode.cn/problems/lexicographically-smallest-generated-string/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<char> res(n+m-1, ' ');
        for (int i = 0; i < n; ++i) {
            if (str1[i] != 'T') continue;
            for (int j = 0; j < m; ++j) {
                char ch = res[i+j];
                if (ch != ' ' && ch != str2[j]) {
                    return "";
                }
                res[i+j] = str2[j];
            }
        }
        vector<char> res_prev(res);
        for (int i = 0; i < n+m-1; ++i) {
            if (res[i] == ' ') {
                res[i] = 'a';
            }
        }
        for (int i = 0; i < n; ++i) {
            if (str1[i] != 'F') continue;
            string sub(res.begin()+i, res.begin()+i+m);
            if (sub != str2) continue;
            bool valid = false;
            for (int j = m-1; j >= 0; --j) {
                if (res_prev[i+j] == ' ') {
                    res[i+j] = 'b';
                    valid = true;
                    break;
                }
            }
            if (!valid) {
                return "";
            }
        }
        return string(res.begin(), res.end());
    }
};

int main() {
    Solution sol;
    string str1 = "TFTF";
    string str2 = "ab";
    cout << sol.generateString(str1, str2) << '\n';
    return 0;
}