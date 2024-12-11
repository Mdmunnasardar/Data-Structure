head->next = Second;
    Second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    Traverse(head);