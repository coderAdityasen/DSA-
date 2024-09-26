#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long sum = 0;
    int mod = (int)(1e9 + 7);

    for (int i = 0; i < n; i++) {
        int mini = arr[i];
        for (int j = i; j < n; j++) {
            mini = min(mini, arr[j]);
            sum = (sum + mini) % mod;
        }
    }

    cout << sum << " is the sum" << endl;

    return 0;
}