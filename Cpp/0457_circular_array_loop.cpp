// https://leetcode.cn/problems/circular-array-loop/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        // If a position is visited, label it by directly changing the
        // corresponding number in the original array.
        int n = nums.size();
        int flag = 2000 * n; // -1000 <= nums[i] <= 1000
        for (int i = 0; i < n; ++i) {
            // Only consider unvisited positive numbers.
            if ((nums[i] >= 2000) || (nums[i] < 0)) {
                continue;
            }
            int j = i, circular = 0;
            while (nums[j] > 0) {
                int cur = j, step = nums[j];
                nums[j] = flag; // label the jth position
                circular += 1;
                j = (j + step) % n;
                if (nums[j] == flag) {
                    if ((circular > 1) && (j != cur)) {
                        return true;
                    }
                    break;
                }
            }
            flag += n;
        }

        flag = -2000 * n;
        for (int i = 0; i < n; ++i) {
            // Only consider unvisited negative numbers.
            if ((nums[i] <= -2000) || (nums[i] > 0)) {
                continue;
            }
            int j = i, circular = 0;
            while (nums[j] < 0) {
                int cur = j, step = nums[j];
                nums[j] = flag;
                circular += 1;
                // Notice the difference of modulo operators in different
                // programming languages.
                j = (j + step) % n;
                if (j < 0) j += n;
                if (nums[j] == flag) {
                    if ((circular > 1) && (j != cur)) {
                        return true;
                    }
                    break;
                }
            }
            flag -= n;
        }
        return false;

        // Another solution is based on fast and slow pointers.
        // Check details in the solution section on LeetCode.
    }
};
