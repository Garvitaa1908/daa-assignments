#include <iostream>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int maxCross(int a[], int l, int m, int r) {
    int sum = 0, left = -100000;
    for (int i = m; i >= l; i--) {
        sum += a[i];
        left = max(left, sum);
    }
    sum = 0;
    int right = -100000;
    for (int i = m + 1; i <= r; i++) {
        sum += a[i];
        right = max(right, sum);
    }
    return left + right;
}

int maxSubRec(int a[], int l, int r) {
    if (l == r) return a[l];
    int m = (l + r) / 2;
    return max(
        max(maxSubRec(a, l, m), maxSubRec(a, m + 1, r)),
        maxCross(a, l, m, r)
    );
}

int maxSubIter(int a[], int n) {
    int best = a[0], curr = a[0];
    for (int i = 1; i < n; i++) {
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
    }
    return best;
}

int main() {
    int a[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = 8;
    cout << maxSubRec(a, 0, n - 1) << endl;
    cout << maxSubIter(a, n);
    return 0;
}
