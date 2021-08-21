/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        if(root->left||root->right){
            TreeNode * tmp = root->right;
            root->right=mirrorTree(root->left);
            root->left = mirrorTree(tmp);
        }
        return root;
    }
};