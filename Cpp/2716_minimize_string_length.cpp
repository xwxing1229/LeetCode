// https://leetcode.cn/problems/minimize-string-length/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
        
class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> check(26, 0);
        for (auto &ch: s) check[ch - 'a'] = 1;
        int res = 0;
        for (auto &val: check) res += val;
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aaabbb";
    cout << sol.minimizedStringLength(s) << '\n';
    return 0;
}