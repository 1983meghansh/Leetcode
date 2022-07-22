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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(-1);
        ListNode* large=new ListNode(-1);
        ListNode* shead=small;
        ListNode* lhead=large;
        
        while(head!=NULL)
        {
            if(head->val<x)
            {
                small->next=head;
                small=small->next;
                 head=head->next;
                small->next=NULL;
            }
            else{
                large->next=head;
                large=large->next;
                 head=head->next;
                large->next=NULL;
            }
           
        }
        small->next=lhead->next;
        return shead->next;
    }
};