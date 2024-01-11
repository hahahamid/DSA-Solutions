// very basic approach to reverse a LL !
// nothing much to even think of 
// ratt lo bkc

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL; 
        ListNode* curr = head; 

        ListNode* forward = NULL;
         
        while(curr != NULL){
            forward = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = forward;
        }
        return prev; 
    }
};


// Do it recursively if you want to 


class Solution {
public:

    void f(ListNode* &head, ListNode* curr, ListNode* prev){
        if(curr == NULL){
            head = prev;
            return ; 
        }

        ListNode* forward = curr->next; 
        f(head, forward, curr); 
        curr->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head; 
        ListNode* prev = NULL; 

        f(head, curr, prev);
        return head;
    }
};


// No one's is really gonna ask me shit about it. I am anyway going to use this reverse function in solving other questions only 


// Update - I was totally wrong! they did ask me this in an interview, Life's Good .  
