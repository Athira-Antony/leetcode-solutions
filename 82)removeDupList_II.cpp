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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;

       
        ListNode *curr = head->next;
        ListNode dummy = new ListNode(0,head);
         ListNode *prev = &dummy;
        
        while(curr!=nullptr)
        {
            if(curr->next && curr->val == curr->next->val)
            {
                int dup = curr->val;
                while(curr && curr->val == dup)
                    curr = curr->next;
                prev->next = curr;
            }
                
            else
            {
                prev = curr;
                curr = curr->next;
            }
                
            
            
        }

        return head;
    }

};
