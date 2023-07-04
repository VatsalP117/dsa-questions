// Intuition- let's say 2 people are running in a circular track, one person is running slowly and another person is running faster(2 times the speed of first person)

// After a certain period of time person 2 again meet or overtake person 1,

// In that case we can conclude that the track is circular ( replace running track with our Linked list)

bool hasCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }