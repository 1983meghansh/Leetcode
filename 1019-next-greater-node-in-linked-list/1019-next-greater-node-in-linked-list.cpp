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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>pos;
        vector<int>value;
        ListNode* curr=head;
        while(curr)
        {
            value.push_back(curr->val);
            curr=curr->next;
        }
        vector<int>ans(value.size(),0);
        for(auto i=0;i<value.size();i++)
        {
            while(!pos.empty()and value[pos.top()]<value[i])
            {
                ans[pos.top()]=value[i];
                pos.pop();
            }
            pos.push(i);
        }
        
        return ans;
    }
};