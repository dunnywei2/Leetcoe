class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L3=new ListNode(0) ;
        ListNode *head=NULL;
        std::vector<int> carryV;
        carryV.push_back(0);
        int counter=0;
       while( ((l1->next!=NULL)||(l2->next!=NULL)) && counter ==0)
        {
            int val1,val2;
            if(l1)
            {
                val1=l1->val;
                
            }
            else{
                val1=0;
            }  
            if (l2)
            {
                val2=l2->val;
            }
            else{
                val2=0;
            }
               // int val1=l1 ? NULL : 0 : l1->val;
               // int val2=l2 ? NULL : 0 : l2->val;
            
            int sum=val1+val2+carryV.at(counter);

            
            

            //32+87
            //Firt digit (3+8)-10=1 with carry 1
            //Second digit (2+9+1)=2 with carry 1
            int remain=sum%10;
            int carry=sum/10;
                
            if(l1->next!=NULL)
                l1=l1->next;
            if(l2->next!=NULL) 
                l2=l2->next;
            carryV.push_back(carry);
            L3->next=new ListNode(remain);
            L3=L3->next;
            counter++;
         }
        head=L3;   
        return head;   
    }
    
};
