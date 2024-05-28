# minimum-average-waiting-time

Tieu owns a pizza restaurant and he manages it in his own way. While in a normal restaurant, a customer is served by following the first-come, first-served rule, Tieu simply minimizes the average waiting time of his customers. So he gets to decide who is served first, regardless of how sooner or later a person comes.

Different kinds of pizzas take different amounts of time to cook. Also, once he starts cooking a pizza, he cannot cook another pizza until the first pizza is completely cooked. Let's say we have three customers who come at time t=0, t=1, & t=2 respectively, and the time needed to cook their pizzas is 3, 9, & 6 respectively. If Tieu applies first-come, first-served rule, then the waiting time of three customers is 3, 11, & 16 respectively. The average waiting time in this case is (3 + 11 + 16) / 3 = 10. This is not an optimized solution. After serving the first customer at time t=3, Tieu can choose to serve the third customer. In that case, the waiting time will be 3, 7, & 17 respectively. Hence the average waiting time is (3 + 7 + 17) / 3 = 9.

Help Tieu achieve the minimum average waiting time. For the sake of simplicity, just find the integer part of the minimum average waiting time.

### Input Format

+ The first line contains an integer N, which is the number of customers.
+ In the next N lines, the ith line contains two space separated numbers Ti and Li. Ti is the time when ith customer order a pizza, and Li is the time required to cook that pizza.

+ The ith customer is not the customer arriving at the ith arrival time.

### Output Format

+ Display the integer part of the minimum average waiting time.

### Constraints

$$ 1 ≤ N ≤ 105 $$
$$ 0 ≤ Ti ≤ 109 $$
$$ 1 ≤ Li ≤ 109 $$

### Note

The waiting time is calculated as the difference between the time a customer orders pizza (the time at which they enter the shop) and the time she is served.

Cook does not know about the future orders.


<table width=100%>
<tr>
<th>Sample Input 0:</th>
<th>Sample Output 0:</th>
</tr>

<tr>
<td>

```
3
0 3
1 9
2 6
```
</td>

<td>

```
9
```
</td>
</tr>


<tr>
<th>Sample Input 1:</th>
<th>Sample Output 1:</th>
</tr>

<tr>
<td>

```
3
0 3
1 9
2 5
```
</td>

<td>

```
8
```
</td>
</tr>
</table>


#### Explanation #01

Let's call the person ordering at time = 0 as A, time = 1 as B and time = 2 as C. By delivering pizza for A, C and B we get the minimum average wait time to be


```
(3 + 6 + 16)/3 = 25/3 = 8.33
```

the integer part is 8 and hence the answer.

### Solution:

To minimize the average waiting time for the customers in the pizza restaurant, we use a strategy similar to the Shortest Job First (SJF) scheduling algorithm. The steps are as follows:

+ `Sort Customers by Arrival Time`: First, sort all the customers based on their arrival time. This helps in processing the customers in the order they arrive.

+ `Use a Min-Heap (Priority Queue)`: A priority queue is used to keep track of the cooking times of the customers who are waiting to be served. The priority queue allows us to always serve the customer with the shortest cooking time first, which helps minimize the waiting time.

+ Simulation of Serving Process:

    + Start with the current time set to 0.
    + Add customers to the priority queue as they arrive.
    + Continuously serve the customer with the shortest cooking time from the priority queue.
    + Update the current time and the total waiting time accordingly.
    + If there are no customers in the queue but some customers are yet to arrive, jump the current time to the next customer's arrival time.
    + Repeat the process until all customers are served.

```cpp
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
```