// https://leetcode.cn/problems/build-an-array-with-stack-operations/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int i = 1;
        for (int num: target) {
            while (num != i) {
                res.push_back("Push");
                res.push_back("Pop");
                i = i + 1;
            }
            res.push_back("Push");
            i = i + 1;
        }
        return res;
    }
};
