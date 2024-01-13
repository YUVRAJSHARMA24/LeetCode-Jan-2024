class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>cnt1(26, 0);
        vector<int>cnt2(26, 0);

        for(char ch : s)
            cnt1[ch-'a']++;
        
        for(char ch : t)
            cnt2[ch-'a']++;

        int res = 0;
        for(int i = 0; i<26; i++)
        {
            res += abs(cnt1[i] - cnt2[i]);
        }

        return res/2;    
    }
};
