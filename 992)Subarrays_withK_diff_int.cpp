class Solution 
{
    private:
        int atmostK(vector<int> &nums, int k)
        {
            int left = 0, right = 0,cnt = 0;
            unordered_map<int,int>freq;
            
            while (right < nums.size())
            {
                if(freq[nums[right]] == 0)
                    k--;
                
                freq[nums[right]]++;

                while (k < 0)
                {
                    freq[nums[left]] --;
                    if(freq[nums[left]] == 0)
                        k ++;
                    left++;
                }

                right++;
                cnt += right - left + 1;
            }

            return cnt;
        }
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) 
        {
            int cnt1 = atmostK (nums,k);
            int cnt2 = atmostK (nums, k-1);
            return abs (cnt1 - cnt2);
        }
};
