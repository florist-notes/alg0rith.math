#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N = 101;
int elements[MAX_N];
int num_elements;

// Function to check if there exists a permutation with M(B) >= 2^k
bool isKManipulative(int k) {
    map<int, int> countMap;
    int mask = 0;

    // Create a mask to consider only the top k bits
    for (int i = 30; i >= k; i--) {
        mask |= (1 << i);
    }

    // Count occurrences of masked elements
    for (int i = 0; i < num_elements; i++) {
        countMap[elements[i] & mask]++;
    }

    vector<int> counts;
    for (const auto& pair : countMap) {
        counts.push_back(pair.second);
    }

    // Sort counts to check the condition for being k-manipulative
    sort(counts.begin(), counts.end());
    if (counts.size() == 1) return false;

    int cumulative_sum = counts[0];
    for (size_t i = 1; i < counts.size(); i++) {
        if (cumulative_sum < counts[i]) return false;
        cumulative_sum += counts[i];
    }

    return true;
}

int main() {
    // Read input
    cin >> num_elements;
    for (int i = 0; i < num_elements; i++) {
        cin >> elements[i];
    }

    // Find the largest k for which there exists a k-manipulative permutation
    for (int k = 30; k >= 0; k--) {
        if (isKManipulative(k)) {
            cout << k << endl;
            return 0;
        }
    }

    // If no valid k found, output -1 (though by constraints, we should always find a valid k)
    cout << -1 << endl;
    return 0;
}