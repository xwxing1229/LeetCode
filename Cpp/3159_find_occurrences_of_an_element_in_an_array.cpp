// https://leetcode.cn/problems/find-occurrences-of-an-element-in-an-array/

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, int> records;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                cnt += 1;
                records[cnt] = i;
            }
        }

        vector<int> res(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            if (queries[i] <= cnt) {
                res[i] = records[queries[i]];
            }
        }
        return res;
    }
};

