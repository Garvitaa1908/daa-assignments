#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int crossingsum(vector<int>& arr, int l, int mid, int r) {
        int sum = 0;
        int leftmax = INT_MIN;

        for (int i = mid; i >= l; i--) {
            sum += arr[i];
            leftmax = max(leftmax, sum);
        }

        sum = 0;
        int rightmax = INT_MIN;

        for (int i = mid + 1; i <= r; i++) {
            sum += arr[i];
            rightmax = max(rightmax, sum);
        }

        return leftmax + rightmax;
    }

    int divide(vector<int>& arr, int l, int r) {
        if (l == r) return arr[l];

        int mid = l + (r - l) / 2;

        int leftsub = divide(arr, l, mid);
        int rightsub = divide(arr, mid + 1, r);
        int crosssum = crossingsum(arr, l, mid, r);

        return max({leftsub, rightsub, crosssum});
    }

    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size() - 1);
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int ans = sol.maxSubArray(nums);

    cout << "Maximum Subarray Sum = " << ans << endl;

    return 0;
}
