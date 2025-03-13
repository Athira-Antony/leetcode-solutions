class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode * x = head;
        int len = 1;
        while(x->next)
        {
            len++;
            x = x->next;
        }

        // x is tail now
         x->next = head;

        k = len - k % len;

        ListNode * curr = head;
        ListNode * prev = x;

        while (k!=0)
        {
            prev=prev->next;
            curr=curr->next;
            k--;
        }

        prev->next = nullptr;
        return curr; // new head
    }
};
