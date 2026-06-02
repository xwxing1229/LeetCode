# https://leetcode.cn/problems/earliest-finish-time-for-land-and-water-rides-i/

class Solution:
    def earliestFinishTime(self, landStartTime: list[int], landDuration: list[int], waterStartTime: list[int], waterDuration: list[int]) -> int:
        def f(firstStartTime: list[int], firstDuration: list[int], secondStartTime: list[int], secondDuration: list[int]) -> int:
            res = float("inf")
            for i1, start1 in enumerate(firstStartTime):
                finish1 = start1 + firstDuration[i1]
                for i2, start2 in enumerate(secondStartTime):
                    if finish1 > start2:
                        finish2 = finish1 + secondDuration[i2]
                    else:
                        finish2 = start2 + secondDuration[i2]
                    res = min(res, finish2)
            return res
        
        return min(
            f(landStartTime, landDuration, waterStartTime, waterDuration),
            f(waterStartTime, waterDuration, landStartTime, landDuration)
        )