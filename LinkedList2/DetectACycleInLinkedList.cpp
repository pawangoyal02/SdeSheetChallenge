bool detectCycle(Node *head)
{
	//	Write your code here
    if(head==NULL) return false;
        Node* slow= head;
        Node* fast= head;
        
        while(fast->next!=NULL && fast->next->next!=NULL) {
            fast= fast->next->next;
            slow= slow->next;
            if(fast==slow) {
                return true;
            }
        }
        return false;
}