#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main() {
    int m, n, tA, tB;
    cin >> m >> n >> tA >> tB;

    SparseMatrix a;
    a.rows = m;
    a.cols = n;
    a.count = tA;
    a.data = new Triple[tA];

    for (int i = 0; i < a.count; i++) {
        cin >> a.data[i].row;
        cin >> a.data[i].col;
        cin >> a.data[i].value;
    }

    SparseMatrix b;
    b.rows = m;
    b.cols = n;
    b.count = tB;
    b.data = new Triple[tB];

    for (int i = 0; i < b.count; i++) {
        cin >> b.data[i].row;
        cin >> b.data[i].col;
        cin >> b.data[i].value;
    }

    SparseMatrix c = add(a, b);

    cout << c.rows << " " << c.cols << " " << c.count << '\n';

    for (int i = 0; i < c.count; i++) {
        cout << c.data[i].row << " "
             << c.data[i].col << " "
             << c.data[i].value << '\n';
    }

    delete[] a.data;
    delete[] b.data;
    delete[] c.data;

    return 0;
}
