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
    void traversal(TreeNode* root, vector<int> &temp) {
        if(root == nullptr) return;

        temp.push_back(root->val);
        traversal(root->left, temp);
        traversal(root->right, temp);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        traversal(root, temp);

        sort(temp.begin(), temp.end());
        return temp[k-1];
    }
};