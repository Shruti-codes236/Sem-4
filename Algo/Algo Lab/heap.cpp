#include <iostream>
#include <vector>
using namespace std;

struct node{
    node* left;
    node* right;
    int val;
    node(int t){
        left = NULL;
        right = NULL;
        val = t;
    }
    node(node* a,node* b,int t){
        left=a,right=b;
        val = t;
    }
};

node * fast_heap(int *arr, int i, int j){
    if(j < i)
        return NULL;
    if(i == j){
        node* new_node = new node(arr[i-1]);
        return new_node;
    }
    int  m = (i+j-1)/2;
    node * new_node = new node(fast_heap(arr,i,m),fast_heap(arr,m+1,j-1),arr[j-1]);
    return new_node;
}   

void down_heapify(node * head){
    if(head==NULL)
        return;
    if(!head->left){
        if(!head->right){
            return;
        }
        else{
            if(head->val>head->right->val){
                swap(head->val,head->right->val);
            }
            down_heapify(head->right);
        }
    }
    else{
        if(!head->right){
            if(head->val>head->left->val){
                swap(head->val,head->left->val);
            }
            down_heapify(head->left);
        }
        else{
            if(head->val>min(head->left->val, head->right->val)){
                if(head->left->val < head->right->val){
                    swap(head->val,head->left->val);                }
                else{
                    swap(head->val,head->right->val);
                }
            }
            down_heapify(head->right);
            down_heapify(head->left);
        }
    }
}

void print(node * head, int i,vector<int> &v){
    if(!head)
        return;
    v[i-1] = head->val;
    print(head->left, 2*i,v);
    print(head->right, 2*i+1,v);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    node* head = fast_heap(arr, 1, n);
    down_heapify(head);
    vector<int> a(n);
    print(head, 1,a);    
    for(int i:a){
        cout << i << ' ';
    }
}