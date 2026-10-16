#include "KTriangleMatrix.h"
#include <iostream>
using namespace std;


//用来找在矩阵中坐标为(i,j)的元素在BandMatrix里数组的存储下标
int Find_elm_in_Band (int i, int j, const BandMatrix& a) {
    //求出一个完整行有多少个有几个对角线元素
    int complete = a.k>a.n? a.n:a.k;
    //求出有几个不完整的行
    int incom_row=complete-(a.k+1)/2;
    //求出所有完整行之前的不完整行一共有几个元素
    int all_incom=incom_row*((a.k-1)/2+complete)/2;
    //分情况判断并计算
    if (i<=incom_row) {
        return (a.k-1+i)*(i-1)/2+j-1;
    } else if (i>incom_row&&i<=a.n-incom_row) {
        //计算当前行之前的所有行有多少元素
        int before_row=all_incom+(i-incom_row-1)*complete;
        //判断完整行是否被矩阵边界截断
        if (complete<a.k) {
            return before_row+j-1;
        } else if (complete==a.k) {
            return before_row+j-i+(a.k-1)/2;
        }
    } else if (i>a.n-incom_row) {
        //计算当前行之前的所有行有多少元素
        int before_row=all_incom+(a.n-2*incom_row)*complete+(2*complete-i+a.n-incom_row)*(i-a.n+incom_row-1)/2;
        return before_row+j-i+(a.k-1)/2;
    }
}

DiagonalMatrix compress(const BandMatrix& a) {
    DiagonalMatrix ans;
    ans.n=a.n;
    ans.k=a.k;
    ans.count=ans.n*(ans.k+1)-(ans.k*ans.k-1)/4-ans.n;
    ans.data = new long long [ans.count];
    //当前ans.data的最后一个元素存储下标
    int p=-1;
    //遍历位于下三角的对角线以及主对角线
    for (int i=1; i<=(ans.k+1)/2; i++) {
        //计算该条对角线的元素个数
        int num=ans.n-(ans.k+1)/2+i;
        //当前对角线的首个元素在矩阵中的坐标
        int first_i=(ans.k+1)/2+1-i;
        int first_j=1;
        int curr_i=first_i;
        int curr_j=first_j;
        for (int j=0; j<num; j++) {
            p++;
            ans.data[p]=a.data[Find_elm_in_Band(curr_i,curr_j,a)];
            //最后更新元素在矩阵中的坐标
            curr_i++;
            curr_j++;
        }
    }
    //遍历上三角部分的对角线
    for (int i=1; i<=(ans.k-1)/2; i++) {
        //计算该条对角线的元素个数
        int num=ans.n-i;
        int first_i=1;
        int first_j=1+i;
        int curr_i=first_i;
        int curr_j=first_j;
        for (int j=0; j<num; j++) {
            p++;
            ans.data[p]=a.data[Find_elm_in_Band(curr_i,curr_j,a)];
            curr_i++;
            curr_j++;
        }
    }
    return ans;
}

long long getValue(const DiagonalMatrix& a, int row, int col) {
    //先调整下标为从1开始
    int i=row+1;
    int j=col+1;
    //先处理元素不是对角线元素
    if (j<i-(a.k-1)/2||j>i+(a.k-1)/2) {
        return 0;
    }
    //确定元素位于哪一条对角线上
    int diagonal_num=(a.k+1)/2-i+j;
    //设一个变量用来计算在存储数组中该查询元素前有几个元素
    int elm_before=0;
    if (diagonal_num<=(a.k+1)/2) {      //考虑是在下三角的对角线和主对角线
        elm_before+=(2*a.n-a.k+diagonal_num-1)*(diagonal_num-1)/2;  //前面对角线上的总元素数目
        elm_before+=j-1;
        return a.data[elm_before];
    } else {        //考虑是在上三角的对角线
        elm_before+=(a.k+1)*(2*a.n-(a.k+1)/2+1)/4;  //下三角和主对角线上的总元素数目
        elm_before+=(2*a.n-diagonal_num+(a.k+1)/2)*(diagonal_num-(a.k+1)/2-1)/2;  //前面对角线上总元素数目
        elm_before+=i-1;
        return a.data[elm_before];
    }
}