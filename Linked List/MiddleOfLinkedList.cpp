// Very basic approach to find the middle of the LL. 
// All I did was find the length of the LL and start traversing on the entire list, 
// once is reach the node which is at length len/2, we return that node. 


class Solution {
public:

    int getLen(ListNode* head){
        int len = 0; 
        
        while(head){
            len++; 
            head = head->next; 
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int len = getLen(head); 

        int ans = len/2; 
        int cnt(0);
        ListNode* temp = head; 
        while(cnt < ans){
            temp = temp->next; 
            cnt++; 
        }
        return temp; 
    }
};




// Efficient Approach which I am gonna use most of the times. 
// The slow and fast two pointer approach 

class Solution {
public:

    ListNode* f(ListNode* head){
        if(!head or !head->next){
            return head; 
          }

          ListNode* slow = head;
          ListNode* fast = head->next; 

          while(fast){
              fast = fast->next; 
              if(fast){
                fast = fast->next; 
              }
              slow = slow->next; 
          }
          return slow;
    }

    ListNode* middleNode(ListNode* head) {
        return f(head);  

    }
};


// There is nothing much to do, take two pointers and make them traverse through the list
// make the slow pointer get one step ahead in one step while the fast pointer moves two steps
// when the fast pointer reaches the end/null , the slow pointer will be at the mid, return that !


