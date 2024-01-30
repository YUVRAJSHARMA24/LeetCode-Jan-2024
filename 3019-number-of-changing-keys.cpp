class Solution {
public:
    int countKeyChanges(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 0; i<n-1; i++)
        {
            if(s[i] == toupper(s[i+1]) || s[i] == tolower(s[i+1])) continue;
            else cnt++;
        }

        return cnt;
    }
};
