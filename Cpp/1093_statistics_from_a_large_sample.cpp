// https://leetcode.cn/problems/statistics-from-a-large-sample/

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> res(5, -1);
        int cnt_all = 0, cnt_max = 0;
        double s = 0;
        for (int num = 0; num < count.size(); ++num) {
            int cnt = count[num];
            if (cnt == 0) continue;
            if (res[0] < 0) res[0] = num;
            res[1] = num;
            if (cnt > cnt_max) {
                res[4] = num;
                cnt_max = cnt;
            }
            s += (double)num * cnt;
            cnt_all += cnt;
        }
        res[2] = s / cnt_all;

        int idx = -1, pre = 0, half = cnt_all/2;
        for (int num = 0; num < count.size(); ++num) {
            int cnt = count[num];
            if (cnt == 0) continue;
            idx += cnt;
            if (idx >= half) {
                if (cnt_all % 2 == 1) {
                    res[3] = num;
                }
                else {
                    if (idx - cnt + 1 == half) {
                        res[3] = ((double)num + pre) / 2;
                    }
                    else {
                        res[3] = num;
                    }
                }
                break;
            }
            pre = num;
        }
        return res;
    }
};