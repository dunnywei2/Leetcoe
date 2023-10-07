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
        ListNode* l3=new ListNode();
        std::vector<int> carryV;
        ListNode* carryL;
        int counter=0;
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
            
            int sum=0;
            if(carryV.empty())
            {
                sum=val1+val2;
            }
            else
            {
                sum=val1+val2+carryV.at[counter];

            }
            

            //32+87
            //Firt digit (3+8)-10=1 with carry 1
            //Second digit (2+9+1)=2 with carry 1
            int remain=sum%10;
            int carry=0;
            if(sum>10)
            {
                carry=(sum-10);
            }    
            l1=l1->next;
            l2=l2->next;
            carryV.push(sum)
            counter++;
         }
           
        return l3;   
    }
    
};
