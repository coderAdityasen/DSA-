#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int timeToMinute(const string &time) {
    int minutes = stoi(time.substr(3, 2));
    int hours = stoi(time.substr(0, 2));
    return hours * 60 + minutes;
}

int findDifference(vector<string> &timePoints) {
    vector<int> minutes;

    for (int i = 0; i < timePoints.size(); i++) {  // Start from 0 to include all time points
        int min = timeToMinute(timePoints[i]);
        minutes.push_back(min);
    }

    sort(minutes.begin(), minutes.end());

    int Min_difference = INT_MAX;

    for (int i = 1; i < minutes.size(); i++) {  // Start from 1 to avoid out-of-bounds access
        int diff = minutes[i] - minutes[i - 1];
        Min_difference = min(Min_difference, diff);
    }

    int circularDiff = 1440 - minutes.back() + minutes.front();
    Min_difference = min(Min_difference, circularDiff);

    return Min_difference;
}

int main() {
    vector<string> timePoints = {"15:17", "03:28"};  // Example input

    // Call the function and print the result
    cout << "Minimum Time Difference: " << findDifference(timePoints) << endl;

    return 0;
}

