// https://leetcode.cn/problems/minimum-common-value/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2) {
            if (nums1[i1] == nums2[i2]) return nums1[i1];
            else if (nums1[i1] < nums2[i2]) i1 += 1;
            else i2 += 1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4};
    cout << sol.getCommon(nums1, nums2) << '\n';
    return 0;
}