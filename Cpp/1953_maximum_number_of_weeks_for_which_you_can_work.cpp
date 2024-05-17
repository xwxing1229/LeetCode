// https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long s = 0;
        int longest = milestones[0];
        for (auto m: milestones) {
            s += m;
            longest = max(longest, m);
        }
        return longest < s-longest+1 ? s : 2*(s-longest)+1;
    }
};
