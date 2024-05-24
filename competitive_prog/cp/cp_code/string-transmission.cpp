#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int num_test_cases, length, max_corruption;
char binary_string[1024];
int dp[1024], dp2[1024][1024];
int cost[1024][2];

const int MOD = 1000000007;

void add(int& y, int x) { 
    y += x; 
    if (y >= MOD) 
        y -= MOD; 
}

void sub(int& y, int x) { 
    y -= x; 
    if (y < 0) 
        y += MOD; 
}

// Calculate the cost of flipping each bit for each section of the string
void calculate_costs(int section_size) {
    for (int i = 0; i < section_size; i++) {
        cost[i][0] = cost[i][1] = 0;
        for (int j = 0; j < length / section_size; j++) {
            if (binary_string[j * section_size + i] == '0') {
                cost[i][1]++;
            } else {
                cost[i][0]++;
            }
        }
    }
}

// Recursive function to solve the problem using dynamic programming
int solve(int section_size, int idx, int remaining_corruption) {
    if (remaining_corruption < 0) 
        return 0;
    if (idx == section_size) 
        return 1;
    
    int& result = dp2[idx][remaining_corruption];
    if (result == -1) {
        result = solve(section_size, idx + 1, remaining_corruption - cost[idx][0]);
        add(result, solve(section_size, idx + 1, remaining_corruption - cost[idx][1]));
    }
    return result;
}

int main() {
    cin >> num_test_cases;
    
    while (num_test_cases--) {
        cin >> length >> max_corruption;
        cin >> binary_string;
        
        for (int i = 1; i <= length; i++) {
            if (length % i == 0) {
                memset(dp2, -1, sizeof dp2);
                calculate_costs(i);
                dp[i] = solve(i, 0, max_corruption);
                
                // Adjust the result based on divisor
                for (int j = 1; j < i; j++) {
                    if (i % j == 0) {
                        sub(dp[i], dp[j]);
                    }
                }
            }
        }
        
        cout << dp[length] << endl;
    }
    return 0;
}
