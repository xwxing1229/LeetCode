// https://leetcode.cn/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num = 0, pre = 0;
        for (int i = 0; i < flowerbed.size()-1; ++i) {
            int cur = flowerbed[i];
            if (pre == 0 && cur == 0 && flowerbed[i+1] == 0) {
                num += 1;
                pre = 1;
            }
            else {
                pre = cur;
            }
        }
        if (pre == 0 && flowerbed.back() == 0) {
            num += 1;
        }
        return (num >= n) ? true : false;
    }
};
