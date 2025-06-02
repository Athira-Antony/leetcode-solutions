class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if (dividend == divisor)   
            return 1;
        
        long long ans = 0;
        int  sign = 1;

        if(dividend  >=0 && divisor < 0)
            sign = -1;
        if(dividend  < 0 && divisor >= 0)
            sign = -1;

        long long n = abs((long long)dividend); //numerator
        long long d = abs((long long)divisor);  //denominator

        while ( n >= d)
        {
            int cnt = 0;

            while ( n >= (d * pow(2,cnt+1)))
                cnt++;

            ans += pow(2,cnt);
            n -= d*pow(2,cnt);
        }

        if(ans >= pow (2,31) && sign == 1)
            return INT_MAX;
        else if (ans >= pow(2,31) && sign == -1)
            return INT_MIN;
        else
            return (int)sign * ans;
    }
};
