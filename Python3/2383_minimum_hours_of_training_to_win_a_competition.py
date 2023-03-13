# https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/

class Solution:
    def minNumberOfHours(self, initialEnergy, initialExperience, energy, experience):
        """
            Inputs:
                initialEnergy, initialExperience: int
                energy, experience: list[int]
            Outputs:
                res: int
        """
        req_energy = 1 + sum(energy)
        res = max(0, req_energy - initialEnergy)
        cur_exp = initialExperience
        for e in experience:
            if cur_exp <= e:
                add_exp = e - cur_exp + 1
                res += add_exp
                cur_exp += add_exp
            cur_exp += e
        return res