class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int c1[128] = {0}, c2[128] = {0};
        for(int i=0; i<s.size(); i++)
        {
            if(c1[s[i]] != c2[t[i]])  // last seen indices are not same
                return false;
            
            c1[s[i]] = i+1;
            c2[t[i]] = i+1;
        }
        return true;

    }
};
