class Solution {
public:
    bool rotateString(string s, string goal) 
    {
       string allComb = s+s;

       if(s.length() != goal.length())
        return false;
       
        
       return allComb.find(goal) != string :: npos;
    }
};
