

class Solution {
private:  
void insertAtTail(Node* &head, Node* &tail, int d){
    Node* val = new Node(d); 
    if(!head){
        head = val; 
        tail = val; 
        return ; 
    }
    else{
        tail->next = val; 
        tail = val;  
    }
}
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head; 

        while(temp){
            insertAtTail(cloneHead, cloneTail, temp->val); 
            temp = temp->next; 
        }

        unordered_map<Node*, Node*> mp; 

        Node* first = head; 
        Node* clone = cloneHead; 

        while(first and clone){
            mp[first] = clone; 
            first = first->next; 
            clone = clone->next; 
        }

        first = head; 
        clone = cloneHead; 

        while(first){
            clone->random = mp[first->random]; 
            first = first->next; 
            clone = clone->next; 
        }
        return cloneHead; 
    }
};