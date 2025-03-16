class Solution {
public:
    double myPow(double x, int n) {
        
        if(x==0)
            return 0;
        if(n<0){
            x=1/x;
            if( n== INT_MIN)
                return x*myPow(x,-(n+1));
            n=abs(n);
        }
        if(n==0)
            return 1;

        double half = myPow(x,n/2);

        return (n%2==0)? half * half : half*half*x;

        // Exponentiation by Squaring, and it's used to optimize recursive power calculations. Instead of calling the function n times (which would lead to O(n) time complexity), we halve the exponent in each step, reducing the time complexity to O(log n).
    }
};
