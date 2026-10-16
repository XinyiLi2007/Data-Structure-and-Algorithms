#ifndef K_TRIANGLE_MATRIX_H
#define K_TRIANGLE_MATRIX_H

// n 为阶数，k 为奇数且表示对角线总条数，count 为带内元素总数。
// 所有坐标及数组下标均从 0 开始，带内的 0 也占存储位置。
struct BandMatrix { int n, k, count; long long* data; };
struct DiagonalMatrix { int n, k, count; long long* data; };

// 输入 data 按行排列；返回 data 按 d=col-row 递增、同条对角线内行号递增排列。
// 返回值拥有独立的 data 数组，由 main.cpp 用 delete[] 释放。
DiagonalMatrix compress(const BandMatrix& a);
long long getValue(const DiagonalMatrix& a, int row, int col);

#endif
