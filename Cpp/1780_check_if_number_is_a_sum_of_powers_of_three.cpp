// https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        // Check if there is a 2 in the number converted with base 3.
        while (n > 0) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }

//     bool checkPowersOfThree(int n) {
//         // Dfs is not necessary.
//         int power_of_3 = 1;
//         while (power_of_3 <= n / 3) {
//             power_of_3 *= 3;
//             powers.push_back(power_of_3);
//         }
//         for (int i = powers.size()-1; i >= 0; --i) {
//             dfs(n, i, powers[i]);
//             if (res) return res;
//         }
//         return res;
//     }

// private:
//     void dfs(int n, int cur_idx, int cur_sum) {
//         if (cur_sum == n) {
//             res = true;
//             return;
//         }
//         for (int i = cur_idx-1; i >= 0; --i) {
//             dfs(n, i, cur_sum + powers[i]);
//         }
//     }

//     bool res = false;
//     vector<int> powers = {1};
};