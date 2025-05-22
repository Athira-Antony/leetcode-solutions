class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int ans = 0 ,n = cardPoints.size();

        for(int i=0; i<k && i < n; i++)
            ans+=cardPoints[i];

       int temp = ans;
       for (int i=1; i<=k; i++)
       {
         temp = temp - cardPoints[k-i] + cardPoints[n-i];
         ans = max(ans,temp);
       }
       return ans;
    }
};
