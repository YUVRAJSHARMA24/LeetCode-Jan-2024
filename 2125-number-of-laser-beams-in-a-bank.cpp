class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0;
        int beam = 0;

        for(int i = 0; i<n; i++)
        {
            int curr = 0;
            string str = bank[i];
            for(auto &ch : str)
            {
                if(ch == '1')
                    curr++;
            }

            beam += (prev * curr);

            prev = curr == 0 ? prev : curr;
        }

        return beam;
    }
};
