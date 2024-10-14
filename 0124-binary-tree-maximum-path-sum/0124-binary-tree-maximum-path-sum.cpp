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
class Solution {
public:
    int helper(TreeNode* root, int &ans) {
        if(root == nullptr) return 0;

        int leftsum = max(0, helper(root->left, ans));
        int rightsum = max(0, helper(root->right, ans));

        ans = max(ans, leftsum + rightsum + root->val);

        return (root->val) + max(leftsum, rightsum);
    }


    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }

};