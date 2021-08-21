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
    bool compare1(TreeNode *A,TreeNode *B){
        if(B==nullptr)
            return true;
        if(A==nullptr)
            return false;
        return A->val==B->val && compare1(A->left,B->left) && compare1(A->right,B->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==nullptr||A==nullptr)
            return false;
        if(compare1(A,B))
            return true;
        return isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
};