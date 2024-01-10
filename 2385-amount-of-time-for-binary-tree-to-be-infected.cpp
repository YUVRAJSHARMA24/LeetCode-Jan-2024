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
    
    void solve(TreeNode* curr, int parent, unordered_map<int, vector<int>>&adj)
    {
        if(curr == NULL) return;

        if(parent != -1)
            adj[curr->val].push_back(parent);

        if(curr->left != NULL)
            adj[curr->val].push_back(curr->left->val);

        if(curr->right != NULL)
            adj[curr->val].push_back(curr->right->val);

        solve(curr->left, curr->val, adj);   
        solve(curr->right, curr->val, adj);  
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        solve(root, -1, adj);

        queue<int>q;
        q.push(start);
        unordered_set<int>visited;
        visited.insert(start);
        int minutes = 0;

        while(!q.empty())
        {
            int n = q.size();

            for(int i = 0; i<n; i++)
            {
                int node = q.front();
                q.pop();

                for(auto &it : adj[node])
                {
                    if(visited.find(it) == visited.end()){
                        q.push(it);
                        visited.insert(it);
                    }
                }
            }

            minutes++;
        }

        return minutes-1;
    }
};
