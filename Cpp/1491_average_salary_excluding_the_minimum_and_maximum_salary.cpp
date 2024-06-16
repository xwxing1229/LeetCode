// https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution {
public:
    double average(vector<int>& salary) {
        int min_ = salary[0], max_ = salary[0], s = 0;
        for (auto val: salary) {
            min_ = min(min_, val);
            max_ = max(max_, val);
            s += val;
        }
        double res = (s - min_ - max_) / (salary.size() - 2);
        return res;
    }
};
