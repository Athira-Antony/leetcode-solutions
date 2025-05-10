class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        int result = 0;
        vector<int>count(100,0);
        int val;
        for(auto d: dominoes)
        {
            if(d[0] > d[1])
                val = 10 * d[0] + d[1];
            else
                val = 10 * d[1] + d[0];
            result += count[val];
            count[val]++;
        }
        return result;
    }
};
