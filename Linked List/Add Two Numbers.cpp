// EASY HAI BHNCHOOODDDD


class Solution {
private: 
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* temp = new ListNode(val); 

        if(!head){
            head = temp; 
            tail = temp; 
            return ; 
        }
        else{
            tail->next = temp; 
            tail = temp; 
        }
    }
    ListNode* add(ListNode* first, ListNode* second){
        int carry = 0; 

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while(first or second or carry){
            int val1 = 0; 
            if(first) val1 = first->val; 
            int val2 = 0; 
            if(second) val2 = second->val; 

            int sum = carry + val1 + val2; 
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit); 
            carry = sum/10; 

            if(first) first = first->next; 
            if(second) second = second->next; 
        }

        return ansHead; 
    }   

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = add(l1, l2); 
        return ans; 
    }
};