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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL or head->next==NULL)return head;
        
        ListNode* dum=new ListNode(-1);
        dum->next=head;
        ListNode* it=dum;
        ListNode* preit=NULL;
        for(int i=0;i<left;i++) //traverse till left
        {
            preit=it;
            it=it->next;
        }
        ListNode* itr=it;
        ListNode* preitr=preit;
        
        for(int i=left;i<=right;i++)
        {
            ListNode* temp=itr->next;
            itr->next=preitr;
            preitr=itr;
            itr=temp;
        }
        
        preit->next=preitr;
        it->next=itr;
        return dum->next;
        
    }
};