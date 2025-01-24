// https://leetcode.cn/problems/find-elements-in-a-contaminated-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        vals_.insert(0);
        root->val = 0;
        recover(root);
    }
    
    bool find(int target) {
        if (vals_.find(target) != vals_.end()) return true;
        else return false;
    }

    void recover(TreeNode *node) {
        int x = node->val;
        if (node->left != nullptr) {
            int val = 2 * x + 1;
            node->left->val = val;
            vals_.insert(val);
            recover(node->left);
        }
        if (node->right != nullptr) {
            int val = 2 * x + 2;
            node->right->val = val;
            vals_.insert(val);
            recover(node->right);
        }
    }

    unordered_set<int> vals_;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */