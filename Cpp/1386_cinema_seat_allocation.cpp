// https://leetcode.cn/problems/cinema-seat-allocation/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        for (const auto &r: reservedSeats) {
            if (r[1] >= 2 && r[1] <= 9) {
                reserved[r[0]] |= (1 << r[1]);
            }
        }
        int res = (n - reserved.size()) * 2;
        int tmp1 =     0b111100;
        int tmp2 =   0b11110000;
        int tmp3 = 0b1111000000;
        for (const auto &[_, seat]: reserved) {
            if ((seat & tmp1) == 0 || (seat & tmp2) == 0 || (seat & tmp3) == 0) {
                res += 1;
            }
        }
        return res;
    }
};