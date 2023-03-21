// https://leetcode.cn/problems/convert-the-temperature/

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahren = celsius * 1.8 + 32.0;
        vector<double> res = {kelvin, fahren};
        return res;
    }
};
