class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int cnt1 = 0, cnt2 = 0, l =0, r = 0,sum1 = 0, sum2 = 0;

        while (r < nums.size()) // for <= goal
        {
            sum1 += nums[r];
            
            while(sum1 > goal)
            {
                sum1 -= nums[l];
                l = l+1;    
            }

            cnt1 += (r - l + 1);
            r++;
        }
        

        // for <= goal -1
        l =0, r =0;
        goal --;
        if(goal < 0) return cnt1;

         while (r < nums.size()) 
        {
            sum2 += nums[r];
            
            while(sum2 > goal)
            {
                sum2 -= nums[l];
                l = l+1;    
            }


            cnt2 += (r - l + 1);
            r++;
        }

        return abs(cnt1 - cnt2);
        
    }
};
