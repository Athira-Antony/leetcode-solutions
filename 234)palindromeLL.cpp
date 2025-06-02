/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        stack<int>s;
        ListNode * x = head;
        while(x!=nullptr)
        {
            s.push(x->val);
            x = x->next;
        }
        ListNode * y = head;
        while(y!=nullptr)
        {
            int temp = s.top();  s.pop();
            if(temp != y->val)
                return false;
            y = y->next;
        }
        return true;
    }
};
