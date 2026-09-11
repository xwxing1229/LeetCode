// https://leetcode.cn/problems/unique-3-digit-even-numbers/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        int n = digits.size();
        // The number is cba.
        for (int ia = 0; ia < n; ++ia) {
            if (digits[ia] % 2 == 1) continue;
            for (int ib = 0; ib < n; ++ib) {
                if (ib == ia) continue;
                for (int ic = 0; ic < n; ++ic) {
                    if (digits[ic] == 0 || ic == ia || ic == ib) continue;
                    s.insert(digits[ic] * 100 + digits[ib] * 10 + digits[ia]);
                }
            }
        }
        return s.size();
    }
};