#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
};

void DOWN_HEAPIFY(Node* cur) {
    Node *lf = cur->left, *rt = cur->right;
    if (lf != NULL and rt != NULL) {
        int mn = min(lf->val, rt->val);
        if (cur->val > mn) {
            if (lf->val > rt->val) {
                swap(cur->val, rt->val);
                DOWN_HEAPIFY(rt);
            } else {
                swap(cur->val, lf->val);
                DOWN_HEAPIFY(lf);
            }
        } 
    } else if (lf != NULL) {
        if (cur->val > lf->val) {
            swap(cur->val, lf->val);
            DOWN_HEAPIFY(lf);
        }
    } else if (rt != NULL) {
        if (cur->val > rt->val) {
            swap(cur->val, rt->val);
            DOWN_HEAPIFY(rt);
        }
    }
}
Node* FASTHEAP(int a[], int start, int end) {
    Node* cur = new Node();
    if (start > end) return cur;
    if (start == end) {
        cur->val = a[start];
        return cur;
    }
    cur->val = a[end];
    int mid = (end - start + 1) / 2; // number of elements in the left part
    if (mid) {
        cur->left = FASTHEAP(a, start, start + mid - 1);
    }
    if (start + mid <= end - 1) {
        cur->right = FASTHEAP(a, start + mid, end - 1);
    }
    DOWN_HEAPIFY(cur);
    return cur;
}
void print(Node* root, int num) {
    if (root == NULL) return;
    cout << num << " " << (root->val) << endl;
    print(root->left, 2 * num);
    print(root->right, 2 * num + 1);
}
int main() {
    
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Node* root = FASTHEAP(a, 0, n - 1); // to construct the heap and get its root
    print(root, 1); // to print the constructed heap using divide and conquer
    return 0;
}
// T(n) = 2* T(n/2) + O(log(n))-> O(n)