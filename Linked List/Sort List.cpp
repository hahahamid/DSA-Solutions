// Merge Sort but on Linked List. 
// Easy hi hai if you think about it. 

class Solution {
public:

  ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* merge(ListNode* left, ListNode* right) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    
    while (left && right) {
        if (left->val < right->val) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }
    
    // Append any remaining elements from both lists.
    if (left) {
        current->next = left;
    } else {
        current->next = right;
    }
    
    return dummy.next;
}


  ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    
    ListNode* middle = findMiddle(head);
    ListNode* left = head;
    ListNode* right = middle->next;
    middle->next = nullptr;
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(left, right);
}


    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};