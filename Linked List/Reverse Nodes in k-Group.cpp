// nothing fancy just reverse like you usually do but make sure to do it till K only 


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head){
            return NULL; 
        }

        ListNode* next = NULL; 
        ListNode* prev = NULL; 
        ListNode* curr = head;
        int cnt(0); 

        ListNode* ptr = head;
        for(int i = 0; i < k; i++) {
            if(ptr == NULL) return head;
            ptr = ptr->next;
        }


        while(curr and cnt < k){
            next = curr->next;
            curr->next = prev; 
            prev = curr; 
            curr = next; 
            cnt++;  
        } 

        if(next != NULL){
            head->next = reverseKGroup(next, k); 
        }

        return prev; 

    }
};