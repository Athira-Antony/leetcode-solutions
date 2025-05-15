class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
           unordered_map<char, int>mp;
           int len = 0, start = 0;
           for(int i=0; i<s.size(); i++)
           {
                char c = s[i];

                //  if it is the part of current window , 
                //change the start of the window
                if(mp.find(c) != mp.end() && mp[c] >= start)  
                    start = mp[c] + 1;
                
                mp[c] = i;
                len = max (len, i - start + 1);
           }
           return len;
    }
};
