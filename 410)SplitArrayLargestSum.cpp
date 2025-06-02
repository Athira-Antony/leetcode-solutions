class Solution {
private:
    bool makeKsub(vector<int> &nums, int k, int sum)
{
    int sub = 1;
    int temp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] + temp > sum)
        {
            sub++;
            temp = nums[i];  // ✅ include current number in new subarray
            if (sub > k)
                return false;
        }
        else
        {
            temp += nums[i];
        }
    }
    return true;
}

public:
    int splitArray(vector<int>& nums, int k) 
    {
        int low = *max(nums.begin(), nums.end()),
        high = 0 ;

        for(int i=0; i<nums.size(); i++)
            high += nums[i];
        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low)/2;

            if(makeKsub(nums,k,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }

        return ans;
    }
};
