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
    int findSecondMinimumValue(TreeNode* root) {
        return findBigger(root,root->val);
    }
        int findBigger(TreeNode* root, int val) {
        // 根节点为空
        if(root == nullptr) {
            return -1;
        }
        // 遇到大的直接返回，否则继续
        if(root -> val > val) {
            return root -> val;
        }
        // 找到左右子树中比val大一点的值
        int leftNum = findBigger(root -> left, val);
        int rightNum = findBigger(root -> right, val);
        // 如果都有大的，取小的
        if(leftNum > 0 && rightNum > 0) {
            return min(leftNum, rightNum);
        } 
        // 其他情况都取大
        return max(leftNum, rightNum);
    }

};