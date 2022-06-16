Node *rotate(Node *head, int k) {
     // Write your code here.
    if(head == NULL || head->next == NULL || k==0)
        {
            return head;
        }
        Node *temp = head;
        int length = 1;
        while(temp->next!=NULL)
        {
            length++;
            temp= temp->next;
        }
        temp->next= head;
        k= k%length;
        int end= length-k;
        while(end--)
        {
            temp= temp->next;
        }
        head= temp->next;
        temp->next= NULL;
        return head;
}