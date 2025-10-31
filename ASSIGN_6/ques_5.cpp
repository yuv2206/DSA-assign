bool Circular() {
        if(head==nullptr)
            return false;
        node* temp=head->next;
        while(temp!=nullptr&&temp!=head)
            temp=temp->next;
        return (temp==head);
    }
