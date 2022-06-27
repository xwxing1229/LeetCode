// https://leetcode.cn/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> hash_table;
        for (int num: nums) {
            if (hash_table.find(num) == hash_table.end()) {
                int left = 0, right = 0;
                if (hash_table.find(num-1) != hash_table.end())
                    left = hash_table[num-1];
                if (hash_table.find(num+1) != hash_table.end())
                    right = hash_table[num+1];
                int length = left + 1 + right;

                hash_table[num] = length;
                hash_table[num-left] = length;
                hash_table[num+right] = length;

                res = max(res, length);    
            }
        }
        return res;
    }
};
