class Solution {
public:

    void dfs(vector<vector<int>> &res, vector<int>&nums, vector<int>&path, int start)
    {
        res.push_back(path);
        for(int i=start; i<nums.size(); i++)
        {
            if(i>start && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            dfs(res,nums,path,i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>path;
        dfs(res,nums,path,0)   ;
        return res;
    }
};
