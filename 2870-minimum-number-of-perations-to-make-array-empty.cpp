class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i<n; i++)
        {
            mp[nums[i]]++;
        }

        int cnt = 0;

        for(auto &it : mp)
        {
            if(it.second == 1) return -1;

            cnt += ceil((double)it.second/3);
        }

        return cnt;
    }
};
