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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1 ; i<preorder.size() ; i++) {
            int data = preorder[i];
            TreeNode* node = root;
            while(true) {
                if(data > node->val and node->right != nullptr) {
                    node = node->right;
                }
                else if(data > node->val and node->right == nullptr) {
                    TreeNode *newnode = new TreeNode(data);
                    node -> right = newnode;
                    break;
                }
                else if(data < node->val and node->left != nullptr) {
                    node = node->left;
                }
                else{
                    TreeNode *newnode = new TreeNode(data);
                    node -> left = newnode;
                    break;
                }
            }
        }
        return root;
    }
};