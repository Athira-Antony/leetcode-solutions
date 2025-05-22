class Solution {
public:
    int myAtoi(string s) 
    {
        if(s.length() == 0)
            return 0;
        
        long res = 0, i =0 , sign = 1;

        while (s[i] == ' ')
            i++;

        if( s[i] == '-') 
        {
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
            i++;

        while (i<s.length())
        {
            if(s[i] < '0' || s[i] > '9')
                break;
            
            res = res * 10 + (s[i] - '0');

            if(sign * res >= INT_MAX)
                return INT_MAX;
            else if (sign * res <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return  sign * (int)res;

    }
};
