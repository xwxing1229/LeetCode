// https://leetcode.cn/problems/linked-list-components/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        bool pre_in_nums = false;
        int res = 0;
        while (head != nullptr) {
            if (s.count(head->val)) {
                if (!pre_in_nums) {
                    res = res + 1;
                    pre_in_nums = true;
                }
            }
            else {
                pre_in_nums = false;
            }
            head = head->next;
        }
        return res;
    }
};