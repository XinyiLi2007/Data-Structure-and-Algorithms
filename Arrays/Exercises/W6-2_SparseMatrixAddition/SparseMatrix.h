#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

// 定义表示矩阵非零元素的三元组
struct Triple {
    int row;
    int col;
    long long value;
};

// 定义稀疏矩阵
// 其中 rows 为行数，cols 为列数，count 为非零元素个数
// 按照行优先存储元素在 data 中
struct SparseMatrix {
    int rows;
    int cols;
    int count;
    Triple* data;
};

SparseMatrix add(const SparseMatrix& a, const SparseMatrix& b);

#endif
