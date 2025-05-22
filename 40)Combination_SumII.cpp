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
            //skip the repeated values
            if(i>start && candidates[i] == candidates[i-1])
                continue; 

            if(candidates[i] <= target)
            {
                comb.push_back(candidates[i]);
                recurse(candidates,target - candidates[i],ans,comb,i+1);
                comb.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>comb;
        recurse(candidates,target,ans,comb,0);
        return ans;  
    }
};S
