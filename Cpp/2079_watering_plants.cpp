// https://leetcode.cn/problems/watering-plants/

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int res = 0, cur = capacity;
        for (int i = 0; i < plants.size(); ++i) {
            if (cur >= plants[i]) {
                cur -= plants[i];
                res += 1;
            }
            else {
                cur = capacity - plants[i];
                res += (i+i+1);
            }
        }
        return res;
    }
};