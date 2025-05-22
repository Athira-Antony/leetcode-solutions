class Solution {
public:
    void recurse(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int>&comb, int start)
    {
        if(target == 0)
        {
            ans.push_back(comb);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++)
        {
            if(candidates[i] <= target)
            {
                comb.push_back(candidates[i]);
                recurse(candidates,target - candidates[i],ans,comb,i);
                comb.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>comb;
        recurse(candidates,target,ans,comb,0);
        return ans;
    }
};
