# https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/
    
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        boxes = [0 for _ in range(46)]
        for num in range(lowLimit, highLimit+1):
            s, cur = 0, num
            while cur:
                s += cur % 10
                cur //= 10
            boxes[s] += 1
        return max(boxes)