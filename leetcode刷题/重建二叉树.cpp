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
    unordered_map<int,int> index;
    TreeNode * build(vector<int>&preorder,vector<int>&inorder,int pre_left,int pre_right,int in_left,int in_right){
        if(pre_left>pre_right){
            return nullptr;
        }
        int root_val = preorder[pre_left];
        int position = index[root_val];
        int left_num = position - in_left;
        TreeNode * root = new TreeNode(root_val);
        root->left = build(preorder,inorder,pre_left+1,pre_left+left_num,in_left,position-1);
        root->right = build(preorder,inorder,pre_left+left_num+1,pre_right,position+1,in_right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            index[inorder[i]]=i;
        }
        TreeNode *ret =  build(preorder,inorder,0,n-1,0,n-1);
        return ret;
    }
};