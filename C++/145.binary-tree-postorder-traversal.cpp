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

    // reference : http://blog.csdn.net/yimingsilence/article/details/54783208


    // recursive version
    
    /*
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return res;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }
    */
    
    //non-recursive version
    /*
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curNode;
        TreeNode* preNode = NULL;
        if (!root) {
            return res;
        }
        s.push(root);
        while (!s.empty()) {
            curNode = s.top();
            if ((!curNode->left && !curNode->right) || (preNode && (preNode == curNode->left || preNode == curNode->right)))   {
                res.push_back(curNode->val);
                s.pop();
                preNode = curNode;
            } else {
                if (curNode->right) {
                    s.push(curNode->right);
                }
                if (curNode->left) {
                    s.push(curNode->left);
                }    
            }
            
        }
        return res;
    }
    */
    // non-recursive version 2
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> myStack;
        
        TreeNode *current = root, *lastVisited = NULL;
        while (current != NULL || !myStack.empty()) {
            while (current != NULL) {
                myStack.push(current);
                current = current->left;
            }
            current = myStack.top(); 
            if (current->right == NULL || current->right == lastVisited) {
                myStack.pop();
                result.push_back(current->val);
                lastVisited = current;
                current = NULL;
            } else {
                current = current->right;
            }
        }
        return result;
    }    
    
};