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
    bool isValidBST(TreeNode* root) {
        return isvalidhelper(root, LONG_MIN, LONG_MAX);
    }

    bool isvalidhelper(TreeNode* root, long long minval, long long maxval) {
        if(root == nullptr) {
            return true;
        }

        if(minval >= root->val || maxval <= root->val) 
            return false;

        return isvalidhelper(root->left, minval, root->val) and isvalidhelper(root->right, root->val, maxval);
    }
};