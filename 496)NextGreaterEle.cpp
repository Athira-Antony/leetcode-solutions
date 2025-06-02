class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
           unordered_map<int,int>mp; // ele , ind
           for(int i=0; i<nums2.size(); i++)
           {
                mp[nums2[i]] = i;
           }

            vector<int>ans;

           for(int i=0; i<nums1.size(); i++)
           {
                int ind = mp[nums1[i]];
                ind++;

                while(ind < nums2.size())
                {
                    if(nums2[ind] > nums1[i])
                    {
                        ans.push_back(nums2[ind]);
                        break;
                    }
                    ind++;
                }

                if(ind == nums2.size())
                    ans.push_back(-1);
           }

           return ans;
    }
};
