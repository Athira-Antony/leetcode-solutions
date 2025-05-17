class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int>pq; // kth largest is n - k+1 th small
        int s = nums.size() - k + 1;

    for (int num : nums) {
        if (pq.size() == s) {
            if (num < pq.top()) {
                pq.pop();
                pq.push(num);
            }
        } else {
            pq.push(num);
        }
    }

    return pq.top();  //OTHERWISE JUST PQ AND K POP
    }
};