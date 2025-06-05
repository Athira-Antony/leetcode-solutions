class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size(),
        mod = 1e9+7;
        vector<int>pse(n), nse(n);
        stack<int>s;

        for(int i=0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()] >  arr[i])
                s.pop();
            
            pse[i] = (s.empty() ? -1 : s.top());
            s.push(i);
        }

        while(!s.empty())
            s.pop();
        
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            
            nse[i] = (s.empty()? n: s.top());
            s.push(i);
        }

        long long res = 0;
        for(int i=0; i<n; i++)
        {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            res = (res + arr[i]* (right % mod) * (left%mod)) % mod;
        }

        return (int) res;
    }
};
