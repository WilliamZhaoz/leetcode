/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// version 1 : dfs, preorder traversal.
/*
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
        
    }
private:
    void serialize(TreeNode* root, ostringstream &out) {
        if (root) {
            out<<root->val<<' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out<<"# ";
        }
    }
    TreeNode *deserialize(istringstream &in) {
        string val;
        in>>val;
        if (val == "#") {
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
*/
// version 2 : bfs, level traversal.
// version 1 : dfs, preorder traversal.
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        if (!root) {
            return out.str();
        }
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                out<<node->val<<' ';
                q.push(node->left);
                q.push(node->right);
            } else {
                out<<"# ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        istringstream in(data);
        queue<TreeNode*> q;
        string val;
        in>>val;
        TreeNode* res = new TreeNode(stoi(val)), *cur = res;
        q.push(cur);
        while (!q.empty()) {
            TreeNode *t = q.front(); 
            q.pop();
            if (!(in>>val)) break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                t->left = cur;
            }
            if (!(in>>val)) break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                t->right = cur;
            }
        }
        return res;
    }

};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));