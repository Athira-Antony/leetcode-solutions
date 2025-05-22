class Solution {
private :
    void paren(vector<string> &ans, int op, int cl, string currStr, int n)
    {
        if (currStr.length() == n * 2)
        {
            ans.push_back(currStr);
            return;
        }
        
        if(op < n)
            paren(ans, op+1, cl, currStr+"(",n);
        
        if(cl < op)
            paren(ans, op, cl+1, currStr+")",n);
    }

public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        paren(ans,0,0,"",n);
        return ans;
    }
};
