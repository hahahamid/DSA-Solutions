// Good Stuff but nothing much to even think of !
// Basic pointers games


class Solution {
public:

    ListNode* solve(ListNode* first, ListNode* second){
        
        if(!first->next){
            first->next = second; 
            return first; 
        }

        ListNode* curr1 = first; 
        ListNode* next1 = first->next; 
        ListNode* curr2 = second; 
        ListNode* next2 = second->next; 


        while(next1 and curr2){
            if(curr2->val >= curr1->val and curr2->val <= next1->val){
                curr1->next = curr2; 
                next2 = curr2->next; 
                curr2->next = next1; 

                curr1 = curr2; 
                curr2 = next2; 
            }
            else{
                curr1 = next1; 
                next1 = next1->next; 

                if(!next1){
                    curr1->next = curr2; 
                    return first; 
                }
            }
        }
        return first; 
    }


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2; 
        if(!list2) return list1; 

        if(list1->val <= list2->val){
            return solve(list1, list2); 
        }
        else return solve(list2,list1); 
    }
};