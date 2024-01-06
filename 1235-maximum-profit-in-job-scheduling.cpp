class Solution {
public:
    
    int getInd(vector<vector<int>>&ans, int low, int end, int n)
    {
        int high = n-1;
        int res = n+1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(ans[mid][0] >= end){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;
    }

    int solve(vector<vector<int>>&ans, int ind, int n, vector<int>&dp)
    {
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int next = getInd(ans, ind+1, ans[ind][1], n);
        int take = ans[ind][2] + solve(ans, next, n, dp);
        
        int notTake = solve(ans, ind+1, n, dp);

        return dp[ind] =  max(take, notTake);
    }
     
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int>dp(n, -1);
        vector<vector<int>>ans(n, vector<int>(3,0));
        for(int i = 0; i<n; i++)
        {
            ans[i][0] = startTime[i];
            ans[i][1] = endTime[i];
            ans[i][2] = profit[i];
        }

        sort(ans.begin(), ans.end());

        return solve(ans, 0, n, dp);
    }
};
