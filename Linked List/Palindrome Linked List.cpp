// the easiest way is to convert the list into a string or even an array and just check if the array or the string is palindrome or not




// this approach is way better and it is quite simple too.
// find mid, and make two lists, one from the head of the given list and the other from the next of the mid element
// reverse the second list, and just check if the values in the node is same or not. 
// as easy as it can get


class Solution {
private: 
ListNode* getMid(ListNode* head){
    ListNode* fast = head->next; 
    ListNode* slow = head; 

    while(fast and fast->next){
        fast = fast->next->next; 
        slow = slow->next; 
    }
    return slow; 
}

ListNode* reverse(ListNode* head){
    ListNode* curr = head; 
    ListNode* prev = NULL; 
    ListNode* next = NULL; 

    while(curr){
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    }
    return prev; 
}

public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return 1; 

        ListNode* middle = getMid(head); 

        ListNode* temp = middle->next; 
        middle->next = reverse(temp); 

        ListNode* head1 = head; 
        ListNode* head2 = middle->next; 

        while(head2){
            if(head1->val != head2->val){
                return 0; 
            }
            head1 = head1->next; 
            head2 = head2->next; 
        }
        return 1; 
    }
};