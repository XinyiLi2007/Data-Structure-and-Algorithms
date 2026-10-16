#include "SqList.h"
#include <iostream>
#include <stdexcept>
using namespace std;

SqList:: SqList () {
    length=0;
}

int SqList:: size () const {
    return length;
}

bool SqList:: empty () const {
    return length==0;
}

int& SqList:: operator[] (int i) {
    if (!(i>=0&&i<length)) {
        throw out_of_range ("SqList index out of range");
    }
    return data[i];
}

int SqList:: operator[] (int i) const {
    if (!(i>=0&&i<length)) {
        throw out_of_range ("SqList index out of range");
    }
    return data[i];
}

int SqList:: front () const {
    if (length==0) {
        throw underflow_error ("SqList is empty");
    }
    return data[0];
}

int SqList:: back () const {
    if (length==0) {
        throw underflow_error ("SqList is empty");
    }
    return data[length-1];
}

void SqList:: push_back (int x) {
    if (length==MAX_SIZE) {
        throw overflow_error ("SqList is full");
    }
    data[length]=x;
    length++;
}

void SqList:: push_front (int x) {
    if (length==MAX_SIZE) {
        throw overflow_error ("SqList is full");
    }
    for (int i=length; i>0; i--) {
        data[i]=data[i-1];
    }
    data[0]=x;
    length++;
}

int SqList:: pop_back () {
    if (length==0) {
        throw underflow_error ("SqList is empty");
    }
    int last_element=data[--length];
    data[length]=0;
    return last_element;
}

int SqList:: pop_front () {
    if (length==0) {
        throw underflow_error ("SqList is empty");
    }
    int first_element=data[0];
    for (int i=0; i<length-1; i++) {
        data[i]=data[i+1];
    }
    data[--length]=0;
    return first_element;
}

void SqList:: insert (int i, int x) {
    if (length==MAX_SIZE) {
        throw overflow_error ("SqList is full");
    } else if (!(i>=0&&i<=length)) {
        throw out_of_range ("SqList index out of range");
    }
    for (int j=length; j>i; j--) {
        data[j]=data[j-1];
    }
    data[i]=x;
    length++;
}

void SqList:: erase (int i) {
    if (!(i>=0&&i<length)) {
        throw out_of_range ("SqList index out of range");
    }
    for (int j=i; j<length-1; j++) {
        data[j]=data[j+1];
    }
    data[--length]=0;
}

int SqList:: find (int x) const {
    for (int i=0; i<length; i++) {
        if (data[i]==x) {
            return i;
        }
    }
    return -1;
}

void SqList:: move_to_back (int i) {
    if (!(i>=0&&i<length)) {
        throw out_of_range ("SqList index out of range");
    }
    int i_element=data[i];
    erase(i);
    push_back(i_element);
}

void SqList:: clear () {
    for (int i=0; i<length; i++) {
        data[i]=0;
    }
    length=0;
}

void SqList:: print () const {
    for (int i=0; i<length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
