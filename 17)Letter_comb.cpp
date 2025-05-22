class Solution {
public:
    vector<string> ele = {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };

    void backtrack(vector<string> &ans, string digits, int start, string &curr)
    {
        if(start == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        for (char c: ele[digits[start]-'0'])
        {
            curr .push_back(c);
            backtrack(ans,digits,start+1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0)
            return {};
        
        vector<string> ans;
        string curr;
        backtrack(ans,digits,0,curr);
        return ans;
    }
};
