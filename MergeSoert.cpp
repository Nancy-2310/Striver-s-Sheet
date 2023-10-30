#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int a = m - 1;
    int b = n - 1;
    int c = (n + m - 1);

    if (m == 0) {
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
    }

    while (a >= 0 && b >= 0) {
        if (nums1[a] < nums2[b]) {
            nums1[c] = nums2[b];
            c--;
            b--;
        } else {
            nums1[c] = nums1[a];
            a--;
            c--;
        }
    }

    while (b >= 0) {
        nums1[c] = nums2[b];
        c--;
        b--;
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}
