#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int ans = 0;
    int arr[] = {10, 2, -2, -20, 10};
    int tar = -10;
    int sum = 0;

    unordered_map<int, int> prefixSumMap;
    prefixSumMap[0] = 1;
    
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
         if (prefixSumMap.find(sum - tar) != prefixSumMap.end()) {
            ans += prefixSumMap[sum - tar]; 
            }
          prefixSumMap[sum]++;
    }

    cout << ans << " is the ans" << endl;

    return 0;
}
