class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        map<int, int>mp;
        
        for(int i=0; i<n; i++)
        {
            mp[matches[i][1]]++;
        }
        
        vector<int> loser;
        vector<int> winner;
        
        for(int i=0; i<n; i++)
        {
            if(mp[matches[i][1]] == 1)
            {
                loser.push_back(matches[i][1]);
            }
            
            if(mp.find(matches[i][0]) == mp.end())
               {
                   winner.push_back(matches[i][0]);
                   mp[matches[i][0]] = 2;
               }
        }
        
        sort(loser.begin(), loser.end());
        sort(winner.begin(), winner.end());
        return {winner, loser};
    }
};
