// https://leetcode.cn/problems/categorize-box-according-to-criteria/

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false, heavy = false;
        int L = 1e4, V = 1e9, M = 100;
        if (length >= L || width >= L || height >= L || length * width >= V / height) {
            bulky = true;
        }
        if (mass >= M) {
            heavy = true;
        }
        if (bulky && heavy) return (string)"Both";
        else if (bulky && (!heavy)) return (string)"Bulky";
        else if ((!bulky) && heavy) return (string)"Heavy";
        else return (string)"Neither";
    }
};