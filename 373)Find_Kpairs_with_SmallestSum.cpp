class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k == 0) 
            return res;

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;

        for(int i=0; i<nums1.size(); i++)
            pq.emplace(nums1[i] + nums2[0], i, 0);
       
        while( !pq.empty() && k>0)
        {
            auto [s,x,y] = pq.top();
            pq.pop();
            res.push_back({nums1[x] ,nums2[y]});
            k--;

            if(nums2.size() > y + 1)
                pq.emplace( nums1[x] + nums2[y+1], x, y+1 );
        }
        return res;


    }
};