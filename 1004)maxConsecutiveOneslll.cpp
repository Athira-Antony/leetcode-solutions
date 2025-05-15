class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
           int start = 0, len = 0, cnt0 = 0;
           for(int i=0; i<nums.size(); i++)
           {
                if(nums[i] == 0)
                    cnt0++;

                while(cnt0 > k)
                {
                    if(nums[start] == 0)
                        cnt0--;
                    start++;
                }

                len = max (len , i-start+1);
           }
           return len;
    }
};
