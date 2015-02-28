/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */

#include<iostream>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h>

#define N 20
#define MAX (1+(1<<6)) // Why? :D
#define inf 0x7fffffff

int arr[N];
int tree[MAX];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a == b) { // Leaf node
    		tree[node] += value;
    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return -inf; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result

	return res;
}

int main() {
	for(int i = 0; i < N; i++) arr[i] = 1;

	build_tree(1, 0, N-1);

	update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
	update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
	update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100

	cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}
view rawsegment_tree.cpp hosted with ❤ by GitHub

Lazy Propagation

Sometimes a segment tree operation wouldn't survive if the problem constraints is too large, here it come lazy propagation along with the segment tree.

In the current version when we update a range, we branch its childs even if the segment is covered within range. In the lazy version we only mark its child that it needs to be updated and update it when needed.


1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */

#include<iostream>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h>

#define N 20
#define MAX (1+(1<<6)) // Why? :D
#define inf 0x7fffffff

int arr[N];
int tree[MAX];
int lazy[MAX];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return -inf; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result

	return res;
}

int main() {
	for(int i = 0; i < N; i++) arr[i] = 1;

	build_tree(1, 0, N-1);

	memset(lazy, 0, sizeof lazy);

	update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
	update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
	update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100

	cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}
