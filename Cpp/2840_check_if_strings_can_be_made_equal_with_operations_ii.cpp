// https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> cnt1(26, vector<int>(2,0));
        vector<vector<int>> cnt2(26, vector<int>(2,0));
        for (int i = 0; i < s1.size(); ++i) {
            cnt1[s1[i]-'a'][i%2] += 1;
            cnt2[s2[i]-'a'][i%2] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i][0] != cnt2[i][0] || cnt1[i][1] != cnt2[i][1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s1 = "abcdba";
    string s2 = "cabdab";
    cout << sol.checkStrings(s1, s2) << '\n';
    return 0;
}