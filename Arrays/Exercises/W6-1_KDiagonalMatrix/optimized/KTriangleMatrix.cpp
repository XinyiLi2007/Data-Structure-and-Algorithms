#include "KTriangleMatrix.h"
#include <iostream>
#include <vector>
using namespace std;

DiagonalMatrix compress(const BandMatrix& a) {
    DiagonalMatrix ans;
    ans.n=a.n;
    ans.k=a.k;
    ans.count=a.count;
    ans.data = new long long [ans.count];

    //预处理行优先存储数组
    vector <int> rowStart (a.n,0);
    rowStart[0]=0;
    for (int i=1; i<a.n; i++) {
        //计算每行对角线带状区域的边界
        int j_min=(i-(a.k-1)/2)>1? (i-(a.k-1)/2):1;
        int j_max=(i+(a.k-1)/2)<a.n? (i+(a.k-1)/2):a.n;
        rowStart[i]=rowStart[i-1]+j_max-j_min+1;
    }

    //当前ans.data的最后一个元素的存储下标
    int p=-1;
    //遍历下三角对角线和主对角线
    for (int i=1; i<=(ans.k+1)/2; i++) {
        //计算当前对角线的元素个数
        int num=ans.n-(ans.k+1)/2+i;
        //计算当前对角线首元素在矩阵中的真实坐标
        int first_i=(ans.k+1)/2-i+1;
        int first_j=1;
        //设置保存当前元素在矩阵中的真实坐标的变量
        int curr_i=first_i;
        int curr_j=first_j;
        //遍历该对角线上的所有元素,依此放入存储数组中
        for (int j=0; j<num; j++) {
            //即将在对角线存储数组中存入新元素，提前把下标更新
            p++;
            //计算当前元素在行优先矩阵数组中的存储位置并取出
            int j_min=(curr_i-(ans.k-1)/2)>1? (curr_i-(ans.k-1)/2):1;
            int elm_before=rowStart[curr_i-1]+curr_j-j_min;
            ans.data[p]=a.data[elm_before];
            //更新当前矩阵坐标，指向下一个位置
            curr_i++;
            curr_j++;
        }
    }
    //遍历上三角对角线
    for (int i=1; i<=(ans.k-1)/2; i++) {
        //计算当前对角线的元素总数
        int num=ans.n-i;
        //计算当前对角线首元素在矩阵中的真实坐标
        int first_i=1;
        int first_j=i+1;
        //设置保存当前元素在矩阵中的真实坐标的变量
        int curr_i=first_i;
        int curr_j=first_j;
        //遍历该对角线上的所有元素，依此放入存储数组中
        for (int j=0; j<num; j++) {
            //操作与下三角和主对角线的情况完全相同
            p++;
            int j_min=(curr_i-(ans.k-1)/2)>1? (curr_i-(ans.k-1)/2):1;
            int elm_before=rowStart[curr_i-1]+curr_j-j_min;
            ans.data[p]=a.data[elm_before];
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