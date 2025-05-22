class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
       int n = nums.size();
       int low = 1 , high = 0;
       for(int i=0; i<n; i++)
       {
            if(nums[i] > high)
               high = nums[i];
        }
        

        while (low < high)
        {
            int mid = low + (high - low)/2;
            int sum = 0;

            for (int i=0; i<n; i++)
            {
                int x = nums[i] / mid ;
                if (nums[i]%mid != 0)
                    x ++;
                
                sum += x ;
            }

            if (sum <= threshold)
                high = mid;
            else
                low = mid + 1 ;
        }
        return low;
    }
};
