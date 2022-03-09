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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* test=head;
        for(int i=0;i<k;i++)
        {
            if(test==NULL)
                return head;
            test=test->next;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nex=NULL;
        for(int i=0;i<k;i++)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
       head->next=reverseKGroup(curr,k);
        return prev;
    }
};