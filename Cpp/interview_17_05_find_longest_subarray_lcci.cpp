// https://leetcode.cn/problems/find-longest-subarray-lcci/

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int start = -1, length = 0;
        unordered_map<int, int> record{ {0, -1} };
        int diff = 0; // cnt_digits - cnt_letters
        for (int i = 0; i < array.size(); ++i) {
            if (isdigit(array[i][0])) diff += 1;
            else diff -= 1;

            if (record.find(diff) != record.end()) {
                if (i - record[diff] > length) {
                    start = record[diff] + 1;
                    length = i - record[diff];
                }
            }
            else {
                record[diff] = i;
            }
        }

        vector<string> res(array.begin()+start, array.begin()+start+length);
        return res;
    }
};