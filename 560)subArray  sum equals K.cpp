class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size(),cnt = 0;
        vector<int>ps(n,0);
        ps[0] = nums[0];

        for(int i=1; i<n; i++)
            ps[i] = ps[i-1] + nums[i];
        
        unordered_map<int,int>mp;

        for(int j=0; j<n; j++)
        {
            if(ps[j] == k)
                cnt++;

            int val = ps[j] - k;

            if(mp.find(val) != mp.end())
                cnt += mp[val];
            
            if(mp.find(ps[j]) == mp.end()) // if it is not in the hashmap 
                mp[ps[j]] = 0;
            
            mp[ps[j]]++;
        }
        return cnt;
    }
};
