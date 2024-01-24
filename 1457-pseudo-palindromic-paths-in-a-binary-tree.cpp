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
    
    void solve(TreeNode* root, vector<int> &ans, int &cnt)
    {
        if(root == NULL) return;

        ans[root->val]++;

        if(root->left == NULL && root->right == NULL){
            int odd = 0;
            for(int i = 0; i<10; i++)
            {
                if(ans[i]%2 != 0){
                    odd++;
                }
            }

            if(odd <= 1){
                cnt++;
            }
        }

        solve(root->left, ans, cnt);
        solve(root->right, ans, cnt);

        ans[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        vector<int> ans(10, 0);
        solve(root, ans, cnt);
        return cnt;
    }
};
