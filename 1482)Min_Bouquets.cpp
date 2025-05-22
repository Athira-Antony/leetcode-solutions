class Solution 
{
private:
    bool makeBou (int k, int m, vector<int>& arr, int day)
    {
        int tot = 0;

        for(int i=0; i<arr.size(); i++)
        {
            int cnt = 0;
            while (i<arr.size() && arr[i] <= day && cnt < k)
            {
                cnt++;
                i++;
            }

            if(cnt == k)
            {
                tot++;
                i--;
            }

            if(tot >= m)
                return true;
        }

        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();
        if( (long long ) m * k > n)   
            return -1;
        

        int low = 1 ;

        int high = 0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] >= high)
                high = bloomDay[i];
        }

        while (low < high)
        {
            int mid = low + (high - low)/2;

            if(makeBou(k,m,bloomDay,mid))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};
