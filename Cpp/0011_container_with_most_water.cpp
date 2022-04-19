// https://leetcode-cn.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int l = 0, r = height.size()-1;
    	int res = 0, tmp;
    	while (l < r) {
    		tmp = min(height[l], height[r]) * (r - l);
    		res = max(res, tmp);
    		if (height[l] < height[r]) {
    			l = l + 1;
    		}
    		else {
    			r = r - 1;
    		}
    	}
    	return res;
    }
};