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
    vector<int> temp;
    void inorder(TreeNode* root) {
        if(root == nullptr) return;

        inorder(root->left);
        temp.push_back(root->val);
        inorder(root->right);
    } 

    bool findTarget(TreeNode* root, int k) {
        inorder(root);

        unordered_map<int, int> m;
        for(int i=0 ; i<temp.size() ; i++) {
            int compliment = k - temp[i];
            if(m.count(compliment)) return true;
            
            m[temp[i]]++;
        }

        return false;
    }
};