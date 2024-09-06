#include <iostream>
#include <vector>

class SegmentTree {
private:
    std::vector<int> tree;
    int n;

    void build(const std::vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build the segment tree
            build(arr, start, mid, 2 * node + 1);
            build(arr, mid + 1, end, 2 * node + 2);
            // Internal node will have the sum of both of its children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int start, int end, int idx, int value, int node) {
        if (start == end) {
            // Leaf node
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                // If idx is in the left child, recurse on the left child
                update(start, mid, idx, value, 2 * node + 1);
            } else {
                // Otherwise, recurse on the right child
                update(mid + 1, end, idx, value, 2 * node + 2);
            }
            // Internal node will have the sum of both of its children
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int start, int end, int l, int r, int node) const {
        if (r < start || l > end) {
            // Range represented by this node is completely outside the given range
            return 0;
        }
        if (l <= start && end <= r) {
            // Range represented by this node is completely inside the given range
            return tree[node];
        }
        // If a part of this segment overlaps with the query range
        int mid = (start + end) / 2;
        int leftSum = query(start, mid, l, r, 2 * node + 1);
        int rightSum = query(mid + 1, end, l, r, 2 * node + 2);
        return leftSum + rightSum;
    }

public:
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, n - 1, 0);
    }

    void update(int idx, int value) {
        update(0, n - 1, idx, value, 0);
    }

    int query(int l, int r) const {
        return query(0, n - 1, l, r, 0);
    }
};

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    // Query sum from index 1 to 3
    std::cout << "Sum of values in given range = " << segTree.query(1, 3) << std::endl;

    // Update: set arr[1] = 10
    segTree.update(1, 10);

    // Query sum from index 1 to 3 after update
    std::cout << "Sum of values in given range after update = " << segTree.query(1, 3) << std::endl;

    return 0;
}

