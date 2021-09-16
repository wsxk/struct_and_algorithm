/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if ( root == nullptr ) return "";
        ostringstream output;
        queue<TreeNode*> que;
        que.push(root);
        while ( !que.empty() ) {
            TreeNode* node = que.front();
            que.pop();
            if ( node == nullptr ) output << "# ";
            else {
                output << node->val << ' ';
                que.push(node->left);
                que.push(node->right);
            }
        }
        return output.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if ( data.empty() ) return nullptr;
        vector<TreeNode*> nodes;
        string val;
        istringstream input(data);
        while ( input >> val ) {
            if ( val == "#" ) nodes.push_back(nullptr);
            else nodes.push_back(new TreeNode(stoi(val)));
        };
        int pos = 1;
        for ( int i = 0; i < nodes.size(); ++i ) {
            if ( nodes[i] == nullptr ) continue;
            nodes[i]->left = nodes[pos++];
            nodes[i]->right = nodes[pos++];
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));