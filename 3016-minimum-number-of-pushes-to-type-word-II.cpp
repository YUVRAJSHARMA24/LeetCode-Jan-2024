class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        int n = word.size(), cnt = 0, res = 0;

        for(int i = 0; i<n; i++) freq[word[i]-'a']++;

        //sort based on occurance
        sort(freq.rbegin(), freq.rend());

        for(int i = 0; i<26; i++)
        {
            if(freq[i] == 0) break;
            if(cnt <= 7) res += freq[i];
            else if(cnt <= 15) res += 2 * freq[i];
            else if(cnt <= 23) res += 3 * freq[i];
            else res += 4 * freq[i];

            cnt++;
        }

        return res;
    }
};
