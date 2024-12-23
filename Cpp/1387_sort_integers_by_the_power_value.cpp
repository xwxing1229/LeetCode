// https://leetcode.cn/problems/sort-integers-by-the-power-value/

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> cnts(hi+1, 0);
        for (int num = 2; num <= hi; ++num) {
            int cur = num, cnt = 0;
            while (cur >= num) {
                if (cur % 2 == 0) cur /= 2;
                else cur = 3 * cur + 1;
                cnt += 1;
            }
            cnts[num] = cnts[cur] + cnt;
        }
        vector<pair<int, int>> nums;
        for (int num = lo; num <= hi; ++num) {
            nums.push_back(make_pair(cnts[num], num));
        }
        sort(nums.begin(), nums.end());
        return nums[k-1].second;
    }
};
