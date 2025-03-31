// https://leetcode.cn/problems/adding-spaces-to-a-string/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n1 = s.size(), n2 = spaces.size();
        string res(n1+n2, ' ');
        int i2 = 0, ires = 0;
        for (int i1 = 0; i1 < n1; ++i1) {
            if (i2 < n2 && i1 == spaces[i2]) {
                i2 += 1;
                ires += 1;
            }
            res[ires] = s[i1];
            ires += 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8, 13, 15};
    cout << sol.addSpaces(s, spaces) << '\n';
    return 0;
}