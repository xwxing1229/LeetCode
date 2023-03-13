// https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int req_energy = 1;
        for (int e: energy) {
            req_energy += e;
        }
        int res = 0;
        if (initialEnergy < req_energy) {
            res = req_energy - initialEnergy;
        }
        int cur_exp = initialExperience;
        for (int e: experience) {
            if (cur_exp <= e) {
                int add_exp = e - cur_exp + 1;
                res += add_exp;
                cur_exp += add_exp;
            }
            cur_exp += e;
        }
        return res;
    }
};
