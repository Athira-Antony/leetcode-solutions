class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int freq[26] = {0}, start = 0, end = 0, maxChar = 0,res = 0;

        while ( end < s.size())
        {
            freq[s[end]-'A'] ++;
            maxChar = max ( maxChar ,freq[s[end]-'A'] );

            while ( k < (end-start+1) - maxChar)
            {
                freq[s[start]-'A']--;
                start++;
            }

            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};
