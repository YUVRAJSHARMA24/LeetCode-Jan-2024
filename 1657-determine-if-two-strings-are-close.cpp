class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if(n != m) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(int i = 0; i<n; i++){
            char ch1 = word1[i];
            char ch2 = word2[i];

            int idx = ch1 - 'a';
            int j = ch2 - 'a';

            freq1[idx]++;
            freq2[j]++;
        }

       for(int i = 0; i<26; i++)
       {
           if(freq1[i]!=0 && freq2[i]!= 0) continue;
           if(freq1[i] == 0 && freq2[i] == 0) continue;

           return false;
       }

       sort(freq1.begin(), freq1.end());
       sort(freq2.begin(), freq2.end());
       return freq1 == freq2;
    }
};
