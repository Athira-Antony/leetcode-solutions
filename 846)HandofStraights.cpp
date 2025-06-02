class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    { 
        // time complexity O(n log n)
        //space complexity O(n)

        int n = hand.size();
        if( n % groupSize != 0)   
            return false;
        
        unordered_map<int,int>mp;
        priority_queue<int, vector<int>, greater<int>>pq;

        for(int i=0; i<n; i++)
        {
            mp[hand[i]]++;
            if(mp[hand[i]] == 1)
                pq.push(hand[i]);
        }

        while (!pq.empty())
        {
            int small = pq.top();

            for( int  curr =small; curr < small + groupSize; curr++)
            {
                if (mp[curr] == 0)
                    return false;
                
                mp[curr]--;

                if(mp[curr] == 0)
                {
                    if( curr != pq.top())
                        return false;
                    pq.pop();
                }
            }
        }
        return true;
    }
};
