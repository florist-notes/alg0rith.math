#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int num_integers;
    cin >> num_integers;

    vector<long long> integers(num_integers);
    for (int i = 0; i < num_integers; i++)
        cin >> integers[i];

    long long min_xor = 0;
    for (int bit_position = 30; bit_position >= 0; bit_position--) {
        vector<int> counts(2);
        for (int j = 0; j < num_integers; j++) {
            counts[integers[j] >> bit_position & 1]++;
        }

        if (counts[0] == num_integers || counts[1] == num_integers) continue;

        vector<long long> high_bit, low_bit;
        for (int j = 0; j < num_integers; j++) {
            if (integers[j] >> bit_position & 1) {
                high_bit.push_back(integers[j]);
            } else {
                low_bit.push_back(integers[j]);
            }
        }

        long long min_xor_value = LLONG_MAX;
        for (long long x : high_bit) {
            for (long long y : low_bit) {
                min_xor_value = min(min_xor_value, x ^ y);
            }
        }
        min_xor = min_xor_value;
        break;
    }

    cout << min_xor << endl;

    return 0;
}
