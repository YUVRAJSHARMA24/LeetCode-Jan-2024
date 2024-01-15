class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int freq = 0;
        unordered_map<int, int> mp;
        for(auto &it : nums){
            mp[it]++;
        }
        
        for(auto &i : mp){
            cnt = max(cnt, i.second);
        }
        int res = 0;
        for(auto &i : mp){
            if(cnt == i.second){
                res += cnt;
            }
        }
        
        return res;
    }
};
