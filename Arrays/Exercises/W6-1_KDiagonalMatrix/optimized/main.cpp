#include <iostream>
#include "KTriangleMatrix.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, q;
    if (!(cin >> n >> k >> q)) return 0;
    int r = (k - 1) / 2;
    int count = static_cast<int>(1LL * n * k - 1LL * r * (r + 1));
    BandMatrix a = {n, k, count, new long long[count]};
    for (int i = 0; i < count; ++i) cin >> a.data[i];
    DiagonalMatrix b = compress(a);
    cout << b.count << '\n';
    for (int i = 0; i < b.count; ++i) {
        if (i) cout << ' ';
        cout << b.data[i];
    }
    cout << '\n';
    while (q--) {
        int row, col;
        cin >> row >> col;
        cout << getValue(b, row, col) << '\n';
    }
    delete[] a.data;
    delete[] b.data;
    return 0;
}
