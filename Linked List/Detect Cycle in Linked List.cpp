// the O(1) solution 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head; 
        ListNode *fast = head; 

        while(fast and fast->next){
            slow = slow->next; 
            fast = fast->next->next; 

            if(fast == slow) return 1; 
        }

        return 0;
    }
};