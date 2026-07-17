// https://leetcode.cn/problems/sorted-gcd-pair-queries/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = nums[0];
        for (int num: nums) {
            mx = max(mx, num);
        }
        vector<int> cnt_num(mx+1, 0);
        for (int num: nums) {
            cnt_num[num] += 1;
        }

        vector<long long> cnt_gcd(mx+1, 0);
        for (int gcd_ = mx; gcd_ > 0; --gcd_) {
            long long c = 0;
            for (int num = gcd_; num <= mx; num+=gcd_) {
                c += cnt_num[num];
                cnt_gcd[gcd_] -= cnt_gcd[num];
            }
            cnt_gcd[gcd_] += c * (c - 1) / 2;
        }
        vector<long long> cumsum(mx+1, 0);
        for (int i = 1; i <= mx; ++i) {
            cumsum[i] = cumsum[i-1] + cnt_gcd[i];
        }
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int left = 0, right = mx;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (cumsum[mid] > queries[i]) {
                    res[i] = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return res;
    }
};