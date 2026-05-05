// https://leetcode.cn/problems/find-unique-binary-string/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        auto to_bin = [&n](int num) {
            vector<char> bins(n, '0');
            string res;
            int i = n-1;
            while (num > 0) {
                bins[i] = '0' + num % 2;
                i -= 1;
                num /= 2;
            }
            for (const auto &ch: bins) {
                res += ch;
            }
            return res;
        };

        for (int num = 0; num < (1 << n); ++num) {
            string tar = to_bin(num);
            int left = 0, right = n-1;
            bool find = false;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] < tar) left = mid + 1;
                else if (nums[mid] > tar) right = mid - 1;
                else {
                    find = true;
                    break;
                }
            }
            if (!find) return tar;
        }
        return to_bin(0);
    }
};

int main() {
    Solution sol;
    vector<string> nums = {"01", "10"};
    cout << sol.findDifferentBinaryString(nums) << '\n';
    return 0;
}