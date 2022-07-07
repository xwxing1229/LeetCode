// https://leetcode.cn/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        // Double pointers.
        int slow = n, fast = getNext(n);
        while (slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        if (slow == 1) {
            return true;
        }
        else {
            return false;
        }
    }

private:
    int getNext(int n) {
        int sqsum = 0;
        while (n > 0) {
            int rem = n % 10;
            sqsum = sqsum + rem * rem;
            n = n / 10;
        }
        return sqsum;
    }
};
