#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

struct MinHeapNode {

	// One of the input characters
	char ch;

	// Frequency of the character
	unsigned f;
	MinHeapNode *left, *right;

	MinHeapNode(char ch, unsigned f)

	{

		left = right = NULL;
		this->ch = ch;
		this->f = f;
	}
};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {
	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return (l->f >= r->f);
	}
};
void printCodes(struct MinHeapNode* root, string str)
{

	if (!root)
		return;
	if (root->ch != '#')
		cout << root->ch << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char ch[], int f[], int n)
{
	struct MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of ch[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> pq;

	for (int i = 0; i < n; ++i)
		pq.push(new MinHeapNode(ch[i], f[i]));

	while (pq.size() > 1) {

		// Extract the two minimum
		// freq items from min heap
		left = pq.top();
		pq.pop();
		right = pq.top();
		pq.pop();

		// Create a new internal node with
		// frequency equal to the sum of the
		// two nodes frequencies. Make the
		// two extracted node as left and right children
		// of this new node. Add this node
		// to the min heap '#' is used to identify special node with sum of two nodes frequency
		top = new MinHeapNode('#', left->f + right->f);

		top->left = left;
		top->right = right;

		pq.push(top);
	}
	printCodes(pq.top(), "");
}

int main()
{

	int n;
	cin>>n;
	char ch[n];
	int f[n],i;
	for(i=0;i<n;i++) cin>>ch[i]>>f[i];
	HuffmanCodes(ch, f, n);
	return 0;
}
