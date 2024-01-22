class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n+1, 0);
        int mis = 0, dup = 0;

        for(auto i : nums) res[i]++;

        for(int i = 1; i<res.size(); i++)
        {
            if(res[i] == 2) dup = i;
            if(res[i] == 0) mis = i;
        }

        return {dup, mis};
    }
};
