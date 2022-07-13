// https://leetcode.cn/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        for (int num: nums) {
            if (hash_table.find(num) != hash_table.end()) {
                return true;
            }
            hash_table[num] = 1;
        }
        return false;
    }
};
