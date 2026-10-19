#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main() {
    int m, n, t;
    cin >> m >> n >> t;

    SparseMatrix a;
    a.rows = m;
    a.cols = n;
    a.count = t;
    a.data = new Triple[t];

    for (int i = 0; i < a.count; i++) {
        cin >> a.data[i].row;
        cin >> a.data[i].col;
        cin >> a.data[i].value;
    }

    SparseMatrix b = transpose(a);

    cout << b.rows << " " << b.cols << " " << b.count << '\n';

    for (int i = 0; i < b.count; i++) {
        cout << b.data[i].row << " ";
        cout << b.data[i].col << " ";
        cout << b.data[i].value << '\n';
    }

    delete[] a.data;
    delete[] b.data;

    return 0;
}
