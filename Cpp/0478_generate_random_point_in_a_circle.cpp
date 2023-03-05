// https://leetcode.cn/problems/generate-random-point-in-a-circle/

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        rng_ = mt19937 (device_());
        dist_ = uniform_real_distribution<double> (-radius-1e-5, radius+1e-5);
        x_ = x_center;
        y_ = y_center;
        r_square_ = radius * radius;
    }
    
    vector<double> randPoint() {
        while (true) {
            double x = dist_(rng_), y = dist_(rng_);
            if (x*x + y*y <= r_square_) {
                return vector<double> {x_ + x, y_ + y};
            }
        }
    }

    random_device device_;
    mt19937 rng_;
    uniform_real_distribution<double> dist_;
    double x_, y_, r_square_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */