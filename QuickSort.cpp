#include <iostream>
using namespace std;

int partition(int a[], int l, int r) {
    int p = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= p) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i + 1]; a[i + 1] = a[r]; a[r] = t;
    return i + 1;
}

void quickSortRec(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSortRec(a, l, p - 1);
        quickSortRec(a, p + 1, r);
    }
}

void quickSortIter(int a[], int n) {
    int stack[1000];
    int top = -1;
    stack[++top] = 0;
    stack[++top] = n - 1;
    while (top >= 0) {
        int r = stack[top--];
        int l = stack[top--];
        int p = partition(a, l, r);
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
}

int main() {
    int a[] = {10,7,8,9,1,5};
    int b[] = {10,7,8,9,1,5};
    int n = 6;
    quickSortRec(a, 0, n - 1);
    quickSortIter(b, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    return 0;
}
