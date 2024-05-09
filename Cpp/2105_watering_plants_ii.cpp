// https://leetcode.cn/problems/watering-plants-ii/

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int res = 0;
        int left = 0, right = plants.size()-1;
        int curA = capacityA, curB = capacityB;
        while (left < right) {
            int pleft = plants[left], pright = plants[right];
            if (curA >= pleft) {
                curA -= pleft;
            }
            else {
                curA = capacityA - pleft;
                res += 1;
            }
            left += 1;

            if (curB >= pright) {
                curB -= pright;
            }
            else {
                curB = capacityB - pright;
                res += 1;
            }
            right -= 1;
        }
        if (left == right && max(curA, curB) < plants[left]) {
            res += 1;
        }
        return res;
    }
};