class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int,int>mp; // sum, index
        int maxlength = 0, sum = 0;
        mp[0] = -1;

        for(int i=0; i<nums.size(); i++)
        {
            sum += (nums[i] == 1? 1: -1);

            if(mp.count(sum))
                maxlength = max(maxlength, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return maxlength;
    }
};
