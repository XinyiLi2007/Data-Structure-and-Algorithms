//单链表的实现
#ifndef SLIST_H
#define SLIST_H

class SList {
    public:
        struct Node {
            int data;
            Node* next;
        };
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        SList ();   //构造函数，空表
        ~SList ();  //析构函数，释放所有节点
        int size () const;  //返回长度
        bool empty () const;    //判空
        Node* front () const;     //返回头节点指针
        Node* back () const;  //返回尾节点指针
        Node* push_back (int x);    //尾插，返回新节点指针
        Node* push_front (int x);   //头插，返回新节点指针
        Node* find (int x) const;     //查找，返回节点指针或nullptr
        void erase (Node* p);   //删除指定节点
        int pop_front ();   //删除头节点并返回其值
        void move_to_back (Node* p);    //把指定节点移到尾部
        void clear ();  //删除所有节点
        void print () const;    //输出所有元素，空格分隔
};

#endif