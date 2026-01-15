#include <iostream>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[1000], R[1000];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSortRec(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSortRec(a, l, m);
    mergeSortRec(a, m + 1, r);
    merge(a, l, m, r);
}

void mergeSortIter(int a[], int n) {
    for (int sz = 1; sz < n; sz *= 2) {
        for (int l = 0; l < n - 1; l += 2 * sz) {
            int m = l + sz - 1;
            int r = min(l + 2 * sz - 1, n - 1);
            if (m < r) merge(a, l, m, r);
        }
    }
}

int main() {
    int a[] = {5,4,3,2,1};
    int b[] = {5,4,3,2,1};
    int n = 5;
    mergeSortRec(a, 0, n - 1);
    mergeSortIter(b, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    return 0;
}
