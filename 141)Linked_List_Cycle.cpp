/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        // ListNode * x = head; 
        // while(x!=nullptr) //  visited change the key value to INT_MAX
        // {
        //     if(x->val == INT_MAX)
        //         return true;
        //     x->val = INT_MAX;
        //     x = x->next;
        // }
        // return false;

        ListNode * slow = head , *fast = head;
        while(fast!=nullptr && fast->next!=nullptr )
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};
