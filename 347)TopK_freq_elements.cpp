class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++)   
            mp[nums[i]]++;

        priority_queue<pair<int,int>>pq; // maxheap
        for( auto [num,freq] : mp)
            pq.push({freq,num});    // max freq at top
        
        vector<int>res;
        while(!pq.empty() && k>0)
        {
            int x = pq.top().second;
            pq.pop();
            res.push_back(x);
            k--;
        }

        return res;
    }
};