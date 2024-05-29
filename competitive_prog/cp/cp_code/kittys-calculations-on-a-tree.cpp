#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

using Graph = vector<vector<int>>; // Alias for the graph representation

const long mod = 1000000007; // Modulo value

// Class to record and manipulate values for each node
class Record {
    long s, su, sudu; // s: sum, su: sum of u, sudu: sum of u*v

public:
    Record(): s(0), su(0), sudu(0) { } // Constructor
    Record(int id): s(0), su(id), sudu(0) { } // Constructor with initial value

    int get_s() const { return s; } // Getter for sum value

    // Function to add values of another Record
    inline void add(Record &b) {
        long ns = (
            s + b.s
            + sudu * b.su
            + su * (b.sudu + b.su)
        );
        if (ns >= mod) ns %= mod;

        long nsu = su + b.su;
        if (nsu >= mod) nsu %= mod;

        long nsudu = sudu + b.sudu + b.su;
        if (nsudu >= mod) nsudu %= mod;

        s = ns;
        su = nsu;
        sudu = nsudu;
    }

    // Function to check if the record is zero
    inline bool zero() {
        return s == 0 && su == 0 && sudu == 0;
    }
};

// Class to generate and execute the code
class Code {
    vector<pair<int, int>> code; // Code representation

    // Recursive function to generate the code
    void gen_code(Graph &g, vector<bool> &color, int i) {
        color[i] = true;
        for (int child : g[i]) {
            if (color[child]) continue;

            gen_code(g, color, child);
            code.push_back({ child, i });
        }
    }

public:
    // Constructor to generate the code from the graph
    Code(Graph &g) {
        vector<bool> color(g.size());
        gen_code(g, color, 0); // Start with the root node (0)
    }

    // Function to execute the code and return the result
    int exec(vector<Record> &data) {
        int last = 0;
        for (auto c : code) {
            last = c.second;
            if (!data[c.first].zero())
                data[c.second].add(data[c.first]);
        }
        return data[last].get_s(); // Return the sum from the last node
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    Graph g(n); // Graph representation
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1); // Edge between nodes a and b
        g[b - 1].push_back(a - 1); // Edge between nodes b and a
    }

    Code code(g); // Generate code from the graph
    vector<Record> data(n); // Data for each node

    while (q--) {
        fill(data.begin(), data.end(), Record()); // Reset data for each query
        int m;
        cin >> m;
        while (m--) {
            int a;
            cin >> a;
            data[a - 1] = Record(a); // Initialize data for node a
        }

        cout << code.exec(data) << endl; // Execute the code and print the result
    }

    return 0;
}
