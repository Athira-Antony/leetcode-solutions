class Solution {
private:
    int cnt(vector<int>&nums, int k)
    {
        if(k<0)
            return 0;
        int end = 0, oddCnt = 0, start = 0,res = 0;

        while(end < nums.size())
        {
            if(nums[end] % 2 == 1)
                oddCnt ++;
            
            while(oddCnt > k)
            {
                if(nums[start] % 2 == 1)
                    oddCnt--;
                start++;
            }
            res += (end - start + 1);
            end++;
        }
        return res;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int cnt1 = cnt(nums,k) , cnt2 = cnt(nums,k-1);
        return abs(cnt1-cnt2);
    }
};