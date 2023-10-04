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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=NULL;
        std::vector<int> carry;
        ListNode* carryL;
       while( (l1->next!=NULL)||(l2->next!=NULL))
        {
            int val1,val2;
            if(l1)
            {
                val1=0
            }
            else{
                val1=l1->val;
            }  
            if (l2)
            {
                val2=l1->val;
            }
            else{
                val2=0;
            }
               // int val1=l1 ? NULL : 0 : l1->val;
               // int val2=l2 ? NULL : 0 : l2->val;
            int sum=l1->val1+val2->val;
               
         }
           
        return l3;   
    }
    
};
