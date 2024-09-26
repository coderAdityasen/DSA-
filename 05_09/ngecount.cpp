#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> count_NGE(int n, vector<int>& arr, int queries, vector<int>& indices) {
    vector<int> result(queries, 0);   // Result array to store counts for each query
    vector<int> greaterCount(n, 0);   // Array to store the count of greater elements for each index
    stack<int> st;                    // Monotonic decreasing stack

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from stack while they are less than or equal to the current element
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // The size of the stack is the count of greater elements to the right
        greaterCount[i] = st.size();

        // Push the current index onto the stack
        st.push(i);
    }

    // Use the precomputed greaterCount array to fill the results for each query
    for (int i = 0; i < queries; i++) {
        result[i] = greaterCount[indices[i]];
    }

    return result;
}

int main() {
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};   // Input array
    int queries = 2;                               // Number of queries
    vector<int> indices = {0, 5};                  // Indices for queries

    vector<int> result = count_NGE(arr.size(), arr, queries, indices);

    for (int res : result) {
        cout << res << " ";   // Print the result
    }

    return 0;
}
