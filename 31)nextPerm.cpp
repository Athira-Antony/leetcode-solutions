class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i = nums.size()-2;

        while (i>=0 && nums[i] >= nums[i+1]) // find the ind at which start decreasing
            i--;

        if(i>=0)
        {
            int j = nums.size()-1;
            while(nums[j] <= nums[i]) // element just larger than nums[i]
                j--;
            
            swap(nums[j],nums[i]);
        }

        reverse(nums.begin()+i+1, nums.end());
    }
};
