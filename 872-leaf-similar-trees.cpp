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
    
    void inorder(vector<int> &x, TreeNode* root)
    {
        if(root == NULL)
            return;
        
        inorder(x, root->left);
        if(!root->left && !root->right)
            x.push_back(root->val);
        inorder(x, root->right);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a, b;
        inorder(a, root1);
        inorder(b, root2);
        
        return a == b;
    }
};
