// https://leetcode.cn/problems/count-symmetric-integers/

#include <iostream>
#include <string>

using namespace std;
        
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        auto isSym = [](const int num) {
            string s = to_string(num);
            int n = s.size();
            if (n % 2) return false;
            int s1 = 0, s2 = 0, half = n/2;
            for (int i = 0; i < half; ++i) {
                s1 += s[i] - '0';
                s2 += s[i+half] - '0';
            }
            return s1 == s2;
        };

        int res = 0;
        for (int num = low; num <= high; ++num) {
            res += isSym(num);
        }
        return res;
    }
};

int main() {
    Solution sol;
    int low = 1, high = 100;
    cout << sol.countSymmetricIntegers(low, high) << '\n';
    return 0;
}