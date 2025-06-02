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

 struct Compare{
    bool operator() (ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode * , vector<ListNode *>, Compare> minheap;

        for (auto head: lists) // insert heads of lists to minheap
        {
            if(head)
                 minheap.push(head);
        }
           
        
        ListNode * temp = new ListNode(0);
        ListNode * tail = temp;

        while (!minheap.empty())
        {
            ListNode * curr = minheap.top();
            minheap.pop();

            tail->next = curr;
            tail = curr;

            if(curr->next)
                minheap.push(curr->next);
        }

        return temp->next;
    }
};
