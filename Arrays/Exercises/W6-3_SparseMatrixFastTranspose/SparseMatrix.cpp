#include "SparseMatrix.h"
#include <vector>
using namespace std;

SparseMatrix transpose(SparseMatrix& a) {
    // 引入一个数组记录每一列的元素个数
    vector<int> col_elms(a.cols, 0);

    // 遍历原矩阵，统计各列元素个数
    for (int i = 0; i < a.count; i++) {
        col_elms[a.data[i].col]++;
    }

    // 将该统计数组转变为记录每列元素初始下标的预处理数组
    // 记录当前列的元素个数供下一列使用
    int prev_elm = col_elms[0];

    for (int i = 0; i < a.cols; i++) {
        if (i == 0) {
            col_elms[i] = 0;
        } else {
            int temp = col_elms[i];
            col_elms[i] = col_elms[i - 1] + prev_elm;
            prev_elm = temp;
        }
    }

    // 创建转置矩阵，注意要在 main 函数中为新创建的转置矩阵数组释放空间
    SparseMatrix b;
    b.rows = a.cols;
    b.cols = a.rows;
    b.count = a.count;
    b.data = new Triple[b.count];

    // 直接把 a 矩阵的元素放到对应位置
    for (int i = 0; i < a.count; i++) {
        // 计算当前元素在 b 矩阵存储数组中的下标
        int index = col_elms[a.data[i].col];

        b.data[index].row = a.data[i].col;
        b.data[index].col = a.data[i].row;
        b.data[index].value = a.data[i].value;

        // 更新预处理数组中的元素下标
        col_elms[a.data[i].col]++;
    }

    return b;
}
