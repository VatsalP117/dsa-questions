//bruteforce solution by me(passes all cases)
//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* start=NULL;
    if(head==NULL || head->next==NULL)return 0;
        Node* slow=head;
        Node* fast=head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        Node* entry=head;
        while(slow!=NULL && entry!=NULL){
            if(slow==entry){
                start=slow;
                break;
            }
            slow=slow->next;
            entry=entry->next;
            
        }
        if(start==NULL)return 0;
        Node* x=start;
        int res=0;
        while(x!=NULL){
            x=x->next;
            res++;
            if(x==start) return res;
        }
        return 0;
}