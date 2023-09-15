#include "Queue.h"

Queue::Queue(){
    //initilization
    head = nullptr;
    tail = nullptr;
    numOrders = 0;
};

Queue::~Queue(){
    Node* curr = head;
    while(curr != nullptr){ //if its not null ptr then we can iterate and free the memory from each node
        Node* temp = curr; //create a temp node so we can delete later after iterating
        curr = curr->next; // iterating the linklist
        delete temp;
    }

};


bool Queue::empty() const{
    return head == nullptr;
};

int Queue::size() const{
    return numOrders;
};

Order* Queue::peekFirst(){
    if(head != nullptr){
        return head->data;
    }
    else{
        return nullptr;
    }


}


Order* Queue::popFirst(){
    if(head == nullptr){
        return nullptr;
    };
    Node* temp = head; //keep temp as head
    Order* r = temp->data; //our result
    head = head->next;
    if(head==nullptr){
        tail = nullptr;
    };
    delete temp;
    numOrders--;
    return r;
};


void Queue::addLast(Order* order) {
    Node* new_node = new Node(); //create a new node
    new_node->data = order;
    new_node->next = nullptr;

    if (tail == nullptr) {
        //if the queue is empty set the tail and head to a new node
        head = new_node;
        tail = new_node;
    } else {
        //else just add the new node to end of queue update the tail
        tail->next = new_node;
        tail = new_node;
    }

    numOrders++;
}




