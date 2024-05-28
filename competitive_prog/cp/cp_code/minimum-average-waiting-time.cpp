#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Structure to represent a customer's order
struct Customer {
    int arrival_time;
    int cook_time;
};

// Comparator for the priority queue to prioritize customers with shorter cooking times
struct CookTimeComparator {
    bool operator() (Customer& a, Customer& b) {
        return a.cook_time > b.cook_time;
    }
};

// Comparator for sorting customers by arrival time
bool compareByArrivalTime(Customer a, Customer b) {
    return a.arrival_time < b.arrival_time;
}

int main() {
    int num_customers;
    cin >> num_customers;

    vector<Customer> customers(num_customers);

    // Read input
    for (int i = 0; i < num_customers; ++i) {
        cin >> customers[i].arrival_time >> customers[i].cook_time;
    }

    // Sort customers by their arrival time
    sort(customers.begin(), customers.end(), compareByArrivalTime);

    // Priority queue (min-heap) to manage cooking order based on cooking time
    priority_queue<Customer, vector<Customer>, CookTimeComparator> pq;

    long long current_time = 0;
    long long total_waiting_time = 0;
    int index = 0;

    while (true) {
        // Add all customers who have arrived by the current time to the heap
        while (index < num_customers && customers[index].arrival_time <= current_time) {
            pq.push(customers[index]);
            index++;
        }

        if (!pq.empty()) {
            // Serve the customer with the smallest cook time
            Customer current_customer = pq.top();
            pq.pop();
            current_time += current_customer.cook_time;
            total_waiting_time += current_time - current_customer.arrival_time;
        } else {
            // No customers are currently available to serve, jump to the next arrival time
            if (index < num_customers) {
                current_time = customers[index].arrival_time;
            }
        }

        // Break the loop if all customers are served and no pending customers
        if (index == num_customers && pq.empty()) {
            break;
        }
    }

    // Output the integer part of the average waiting time
    cout << total_waiting_time / num_customers << endl;

    return 0;
}
