#include <iostream>
using namespace std;

int binarySearchRec(int a[], int l, int r, int x) {
    if (l > r) return -1;
    int m = l + (r - l) / 2;
    if (a[m] == x) return m;
    if (a[m] > x) return binarySearchRec(a, l, m - 1, x);
    return binarySearchRec(a, m + 1, r, x);
}

int binarySearchIter(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int a[] = {1,2,3,4,5,6,7};
    int n = 7;
    cout << binarySearchIter(a, n, 5) << endl;
    cout << binarySearchRec(a, 0, n - 1, 5);
    return 0;
}
