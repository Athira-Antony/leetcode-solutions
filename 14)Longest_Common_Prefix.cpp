class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlength = INT_MAX;
        for(int i=0; i<strs.size(); i++)
        {
            if(strs[i].size() < minlength)
                minlength = strs[i].length();
        }

        int i = 0;
        while(i<minlength)
        {
            for (auto s: strs)
            {
                if(s[i]!=strs[0][i])
                {
                    if(i==0)
                        return "";
                    return s.substr(0,i);
                }
                
            }
            i++;
        }
        return strs[0].substr(0,minlength);
    }
};
