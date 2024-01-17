class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       
        unordered_map<int, int> mp;
        unordered_set<int> unq;
        
        for(auto x : arr) mp[x]++;
        for(auto &s : mp) unq.insert(s.second);
        
        if(mp.size() == unq.size())
            return true;
        
        return false;
    }
};
