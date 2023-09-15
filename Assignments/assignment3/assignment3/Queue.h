#ifndef QUEUE_H
#define QUEUE_H
#include "Order.h"

class Queue{

    class Node{
        public:
            Order* data;
            Node* next;
            
            
    };

    public:
    Queue();
    ~Queue();

    bool empty() const;
    int size() const;
    Order* peekFirst();
    Order* popFirst();
    void addLast(Order* order);



    

    private:
    Node* head;
    Node* tail;
    int numOrders;



};

#endif
