class Solution {
public:
    

    void dfs (vector<int> &nums, vector<int> &path, int ind,vector<vector<int>> &res)
    {
        res.push_back(path);

        for(int i=0; i<nums.size(); i++)
        {
            path.push_back(nums[i+1]);
            dfs(nums,path,i+1,res);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int>path;
        dfs(nums,path,0,res);
        return res;
    }
};
