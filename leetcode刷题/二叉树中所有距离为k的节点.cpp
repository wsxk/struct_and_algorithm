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
    unordered_map<int,TreeNode*>parent;
    vector<int> ans;
    void find_parent(TreeNode *node){
        if(node->left!=NULL){
            parent[node->left->val] = node;
            find_parent(node->left);
        }
        if(node->right!=NULL){
            parent[node->right->val]= node;
            find_parent(node->right);
        }
    }
    void find_ans(TreeNode*node,TreeNode*from,int depth,int k){
        if(node==NULL){
            return;
        }
        if(depth==k){
            ans.push_back(node->val);
            return;
        }
        if(node->left!=from){
            find_ans(node->left,node,depth+1,k);
        }
        if(node->right!=from){
            find_ans(node->right,node,depth+1,k);
        }
        if(parent[node->val]!=from){
            find_ans(parent[node->val],node,depth+1,k);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find_parent(root);
        find_ans(target,NULL,0,k);
        return ans;
    }
};