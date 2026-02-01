// https://leetcode.cn/problems/find-smallest-letter-greater-than-target/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        for (const char &ch: letters) {
            if (ch > target) {
                return ch;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    cout << sol.nextGreatestLetter(letters, target) << '\n';
    return 0;
}