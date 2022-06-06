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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //brute force
//         ListNode *tmp;
//         while(headA!=NULL)
//         {
//             tmp=headB;
//             while(tmp!=NULL)
//             {
//                 if(tmp==headA)
//                     return tmp;
//                 tmp=tmp->next;
                    
//             }
            
//         }
//         return NULL;
        
        // 2 pointors solution
        
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b)
        {
            if(a==NULL)
                a=headB;
            else
                a=a->next;
            if(b==NULL)
                b=headA;
            else
                b=b->next;
        }
        return b;
    }
};