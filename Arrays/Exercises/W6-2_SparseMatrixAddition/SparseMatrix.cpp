#include "SparseMatrix.h"
#include <iostream>
using namespace std;

SparseMatrix add(const SparseMatrix& a, const SparseMatrix& b) {
    SparseMatrix ans;
    ans.rows=a.rows;
    ans.cols=a.cols;
    ans.count=0;

    //为data分配内存，data非零元素不超过两个矩阵非零元素个数之和
    ans.data=new Triple [a.count+b.count];

    //使用两个指示下标分别遍历两个矩阵,一个变量指向当前和矩阵数组的最后一个元素下标
    int p=-1;
    int i=0, j=0;
    while (i<a.count&&j<b.count) {
        //如果此时指向的两个元素行列坐标相等
        if (a.data[i].row==b.data[j].row&&a.data[i].col==b.data[j].col) {
            long long sum=a.data[i].value+b.data[j].value;
            if (sum) {      //和不为零才能作为和矩阵的有效元素
                p++;
                ans.data[p].row=a.data[i].row;
                ans.data[p].col=a.data[i].col;
                ans.data[p].value=sum;
                ans.count++;
            }
            //两个待相加矩阵元素都得到了操作，同时更新两个指示变量
            i++;
            j++;
        } else if (a.data[i].row*a.cols+a.data[i].col<b.data[j].row*b.cols+b.data[j].col) { //把坐标映射为线性的，根据坐标字典序来比较
            p++;
            ans.data[p].row=a.data[i].row;
            ans.data[p].col=a.data[i].col;
            ans.data[p].value=a.data[i].value;
            ans.count++;
            //只有a矩阵元素得到处理，更新i
            i++;
        } else {
            p++;
            ans.data[p].row=b.data[j].row;
            ans.data[p].col=b.data[j].col;
            ans.data[p].value=b.data[j].value;
            ans.count++;
            //只有b矩阵元素得到处理，更新j
            j++;
        }
    }
    //注意循环结束了但有可能还有元素未处理
    while (i<a.count) {
        p++;
        ans.data[p].row=a.data[i].row;
        ans.data[p].col=a.data[i].col;
        ans.data[p].value=a.data[i].value;
        ans.count++;
        i++;
    }
    while (j<b.count) {
        p++;
        ans.data[p].row=b.data[j].row;
        ans.data[p].col=b.data[j].col;
        ans.data[p].value=b.data[j].value;
        ans.count++;
        j++;
    }
    return ans;
}