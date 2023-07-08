ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd_start=head;
        ListNode* even_start=head->next;
        //idea : connext all nodes to odd_start and even to even_start as a LL
        //then at last connect odd_end to even_start
        ListNode* slow=odd_start;
        ListNode* fast=even_start;
        while(slow->next!=NULL && fast->next!=NULL){
            slow->next=slow->next->next;
            fast->next=fast->next->next;
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=even_start;
        return odd_start;
        
    }