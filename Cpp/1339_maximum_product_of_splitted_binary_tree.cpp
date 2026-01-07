// https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/

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

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxProduct(TreeNode* root) {
        using ll = long long;
        auto dfs1 = [](auto &&self, TreeNode *node) -> ll {
            if (!node) {
                return 0;
            }
            return (ll) node->val
                + self(self, node->left)
                + self(self, node->right);
        };
        ll s = dfs1(dfs1, root);

        ll res = 0;
        int mod = 1e9 + 7;
        auto dfs2 = [&](auto &&self, TreeNode *node) -> ll {
            if (!node) {
                return 0;
            }
            long long curr = (ll) node->val
                + self(self, node->left)
                + self(self, node->right);
            res = max(res, curr * (s - curr));
            return curr;
        };
        dfs2(dfs2, root);
        return res % mod;
    }
};