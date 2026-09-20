//顺序表的实现
#ifndef SQLIST_H
#define SQLIST_H

class SqList {
    private:
        static constexpr int MAX_SIZE=100;
        int data [MAX_SIZE]={0};
        int length;
    public:
        SqList ();      //构造函数
        int size () const;  //返回元素个数
        bool empty () const;    //判空
        int& operator [] (int i);   //下标访问
        int operator [] (int i) const;  //只读下标访问
        int front () const;     //返回第一个元素
        int back () const;      //返回最后一个元素
        void push_back (int x);    //尾部插入
        void push_front (int x);    //头部插入
        int pop_back ();    //删除尾部并返回
        int pop_front ();   //删除头部并返回
        void insert (int i, int x);  //在下标为i的位置前插入值为x的元素
        void erase (int i);     //删除下表为i的元素
        int find (int x) const; //找到返回下标,找不到返回-1
        void move_to_back (int i);  //把下标为i的元素移到尾部
        void clear ();  //清空
        void print () const;    //输出所有元素,空格分隔,末尾换行
};

#endif