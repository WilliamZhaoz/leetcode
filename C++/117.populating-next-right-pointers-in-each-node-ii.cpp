/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // version 1 : recursive with extra space (stack)
        /*
        if (!root) {
            return;
        }
        TreeLinkNode *p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) {
            root->right->next = p;
        }
        if (root->left) {
            root->left->next = root->right ? root->right : p;
        }
        connect(root->right);
        connect(root->left);
        */
        
        // version 2 : level traversal with extra space (queue)
        /*
        if (!root) {
            return;
        }
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int l = q.size();
            for (int i = 0; i < l; i++) {
                TreeLinkNode* node = q.front(); q.pop();
                if (i != l - 1) {
                    node->next = q.front();
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        */
        // 
        // version 3: recursive version without extra space
        TreeLinkNode *dummy = new TreeLinkNode(0), *t = dummy;
        while (root) {
            if (root->left) {
                t->next = root->left;
                t = t->next;
            }
            if (root->right) {
                t->next = root->right;
                t = t->next;
            }
            root = root->next;
            if (!root) {
                t = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
    
    }
};