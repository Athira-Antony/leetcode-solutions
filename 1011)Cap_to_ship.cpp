class Solution 
{
private:
    bool minCap(vector<int>& weights, int days, int capacity)
    {
        int currWgt = 0, reqDays = 1;
        for (int w: weights)
        {
            if (currWgt + w > capacity)
            {
                currWgt = 0;
                reqDays++;
            }
            
            currWgt += w;
        }
        return reqDays <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (minCap(weights, days, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

