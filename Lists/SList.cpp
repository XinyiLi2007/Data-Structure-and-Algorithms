#include "SList.h"
#include <iostream>
#include <stdexcept>
using namespace std;

SList:: SList (): length(0) {
    head=new Node;
    head->next=nullptr;
    tail=head;
}

SList:: ~SList () {
    Node* curr=head->next;
    Node* next;
    for (int i=0; i<length; i++) {
        next=curr->next;
        delete curr;
        curr=next;
    }
    delete head;
    head=nullptr;
    tail=nullptr;
    length=0;
}

int SList:: size () const {
    return length;
}

bool SList:: empty () const {
    return length==0;
}

SList:: Node* SList:: front () const {
    return head->next;
}

SList:: Node* SList:: back () const {
    return length==0? nullptr: tail;
}

SList:: Node* SList:: push_back (int x) {
    Node* new_node=new Node;
    new_node->data=x;
    new_node->next=nullptr;
    tail->next=new_node;
    tail=new_node;
    length++;
    return new_node;
}

SList:: Node* SList:: push_front (int x) {
    Node* new_node=new Node;
    new_node->data=x;
    if (length==0) {
        tail=new_node;
    }
    new_node->next=head->next;
    head->next=new_node;
    length++;
    return new_node;
}

SList:: Node* SList:: find (int x) const {
    Node* curr=head->next;
    for (int i=0; i<length; i++) {
        if (curr->data==x) {
            return curr;
        }
        curr=curr->next;
    }
    return nullptr;
}

void SList:: erase (Node* p) {
    if (p==nullptr) {
        throw invalid_argument ("node pointer is nullptr");
    }
    if (length==0) {
        throw underflow_error ("SList is empty");
    }
    Node* curr=head->next;
    Node* prev=head;
    bool is_find=false;
    for (int i=0; i<length; i++) {
        if (curr==p) {
            if (curr==tail) {
                tail=prev;
            }
            prev->next=curr->next;
            delete curr;
            length--;
            is_find=true;
            break;
        } else {
            prev=curr;
            curr=curr->next;
        }
    }
    if (is_find==false) {
        throw invalid_argument ("node not find");
    }
}

int SList:: pop_front () {
    if (length==0) {
        throw underflow_error ("SList is empty");
    }
    int first_element=head->next->data;
    Node* temp=head->next->next;
    delete head->next;
    head->next=temp;
    length--;
    if (length==0) {
        tail=head;
    }
    return first_element;
}

void SList:: move_to_back (Node* p) {
    if (p==nullptr) {
        throw invalid_argument ("node pointer is nullptr");
    }
    if (length==0) {
        throw underflow_error ("SList is empty");
    } else if (p==tail) {
        return;
    }
    Node* curr=head->next;
    Node* prev=head;
    bool is_find=false;
    for (int i=0; i<length; i++) {
        if (curr==p) {
            prev->next=curr->next;
            tail->next=curr;
            tail=curr;
            curr->next=nullptr;
            is_find=true;
            break;
        } else {
            prev=curr;
            curr=curr->next;
        }
    }
    if (is_find==false) {
        throw invalid_argument ("node not find");
    }
}

void SList:: clear () {
    Node* curr=head->next;
    Node* next;
    for (int i=0; i<length; i++) {
        next=curr->next;
        delete curr;
        curr=next;
    }
    head->next=nullptr;
    tail=head;
    length=0;
}

void SList:: print () const {
    Node* curr=head->next;
    for (int i=0; i<length; i++) {
        cout << curr->data << " ";
        curr=curr->next;
    }
    cout << endl;
}