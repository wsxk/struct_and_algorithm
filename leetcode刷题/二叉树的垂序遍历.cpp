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
    vector<tuple<int,int,int>>nodes;
    void dfs(TreeNode*node,int row,int col){
        if(!node){
            return ;
        }
        nodes.emplace_back(col, row, node->val);
        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        sort(nodes.begin(),nodes.end());
        vector<vector<int>>ans;
        int lastcol = INT_MIN;
        for(const auto &[col,row,val]:nodes){
            if(col != lastcol){
                ans.emplace_back();
                lastcol = col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};