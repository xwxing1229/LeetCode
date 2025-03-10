// https://leetcode.cn/problems/find-the-k-beauty-of-a-number/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int res = 0;
        string s = to_string(num);
        for (int i = 0; i <= s.size()-k; ++i) {
            int sub = stoi(s.substr(i, k));
            if (sub == 0 || num % sub != 0) continue;
            res += 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int num = 240, k = 2;
    cout << sol.divisorSubstrings(num, k) << '\n';
    return 0;
}
