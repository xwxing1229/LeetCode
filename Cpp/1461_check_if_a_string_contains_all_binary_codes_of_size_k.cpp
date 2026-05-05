// https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> record;
        for (int i = 0; i < (int)s.size()-k+1; ++i) {
            record.insert(s.substr(i, k));
        }
        return pow(2, k) == record.size();
    }
};

int main() {
    Solution sol;
    string s = "00110110";
    int k = 2;
    cout << sol.hasAllCodes(s, k) << '\n';
    return 0;
}