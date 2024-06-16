// https://leetcode.cn/problems/distribute-candies-to-people/

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int idx = 0, candy = 1;
        while (candies > 0) {
            candy = min(candy, candies);
            res[idx] += candy;
            candies -= candy;

            candy += 1;
            idx = (idx + 1) % num_people;
        }
        return res;
    }
};

