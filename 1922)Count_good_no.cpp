class Solution {
private:
     const int mod = 1e9 + 7;

    long long pow (long long x, long long n)
    {
        long long res = 1;
        x %= mod ;

        while ( n > 0)
        {
            if ( n%2 == 1)
                res = (res * x) % mod;
            x = (x * x) % mod;
            n /= 2;
        }
        return res;
    }

public:

    int countGoodNumbers(long long n) 
    {
        long long evenPos = (n+1) / 2;
        long long oddPos = n/2;

        long long  ans1 = pow(5,evenPos) , ans2 = pow(4,oddPos);
        return (ans1 * ans2) % mod;
        
    }
};
