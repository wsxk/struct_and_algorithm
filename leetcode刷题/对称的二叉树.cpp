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
private:
    TreeNode * mirror(TreeNode *root){
        if(root==nullptr){
            return nullptr;
        }
        TreeNode * image = new TreeNode(root->val);
        if(root->left||root->right){
            image->left=mirror(root->right);
            image->right = mirror(root->left);
        }
        return image;
    }
    bool compare(TreeNode *root,TreeNode * mirror){
        if((root==nullptr && mirror!=nullptr)||(root!=nullptr&&mirror==nullptr))
            return 0;
        if(root==nullptr && mirror==nullptr)
            return 1;
        if(root->val==mirror->val){
            return compare(root->left,mirror->left)&&compare(root->right,mirror->right);
        }   
        return 0;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return 1;
        TreeNode * image = mirror(root);
        return compare(root,image);
    }
};