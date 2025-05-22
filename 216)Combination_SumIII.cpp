class Solution {
public:

    void recurse(int n, int k,vector<vector<int>> &ans, vector<int> &comb, int start)
    {
        if(comb.size() == k && n == 0)
        {
            ans.push_back(comb);
            return;
        }
        
        if(comb.size() >= k ||  n <= 0)
            return;
        
        for(int i = start; i<=9; i++)
        {
            comb.push_back(i);
            recurse(n-i,k,ans,comb,i+1);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>>ans;
        vector<int>comb;
        recurse(n,k,ans,comb,1);
        return ans;
    }
};
