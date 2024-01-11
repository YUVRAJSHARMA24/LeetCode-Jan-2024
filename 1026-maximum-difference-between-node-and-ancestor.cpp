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
    int preorder(TreeNode* root, int maxi, int mini)
    {
        if(root == NULL)
            return maxi - mini;
        
        maxi = max(root->val, maxi);
        mini = min(root->val, mini);
        
        return max(preorder(root->left, maxi, mini), preorder(root->right, maxi, mini));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxNum = 0, minNum = 100000;
        return preorder(root, maxNum, minNum);
    }
};
