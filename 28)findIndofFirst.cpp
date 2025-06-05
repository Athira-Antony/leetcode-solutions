class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        
        size_t ind = haystack.find(needle);
        return ind;
    }
};
