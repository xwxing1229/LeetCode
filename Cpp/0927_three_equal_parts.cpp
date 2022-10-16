// https://leetcode.cn/problems/three-equal-parts/

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> res = {-1,-1};
        int sum_arr = 0;
        for (int i: arr) {
            sum_arr = sum_arr + i;
        }
        if (sum_arr % 3 != 0) {
            return res;
        }

        int n = arr.size(), cnt = 0, partial = sum_arr/3;
        int first = 0, second = 1, third = n-1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                cnt = cnt + 1;

                if (cnt == 1) {
                    first = i;
                }
                else if (cnt == 1 + partial) {
                    second = i;
                }
                else if (cnt == 1 + partial * 2) {
                    third = i;
                    break;
                }
            }
        }

        int len = n - third;
        if ((first + partial <= second) && (second + partial <= third)) {
            for (int i = 0; i < len; ++i) {
                if ((arr[first+i] != arr[second+i]) || (arr[second+i] != arr[third+i])) {
                    return res;
                }
            }
            res[0] = first + len - 1;
            res[1] = second + len;
            return res;
        }
        return res;
    }
};
