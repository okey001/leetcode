// merge and reverse two linked lists
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int value;
    Node *next;
};
Node* merge(Node *a, Node *b){
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    Node *head = new Node();
    Node *cur = head;
    while(a && b){
        if (a->value < b->value){
            cur->next = a;
            a = a->next;
        }
        else{
            cur->next = b;
            b = b->next;
        }
        cur = cur->next;
    }
    if (a) cur->next = a;
    if (b) cur->next = b;
    cur = head->next;
    delete head;
    return cur;
}
Node* reverse(Node *a){
    Node *pre = nullptr;
    Node *cur = a;
    while(cur){
        Node *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

Node* mergeAndReverse(Node *a, Node *b){
    Node *result = merge(a, b);
    result = reverse(result);
    return result;
}


// for test
bool test(int n, int m){
    srand(time(nullptr));
    vector<int> dataA, dataB, dataC;
    for(int i = 0; i < n; i++){
        dataA.push_back(rand() % 10);
    }
    for(int i = 0; i < m; i++){
        dataB.push_back(rand() % 10);
    }
    sort(dataA.begin(), dataA.end(), greater<int>());
    sort(dataB.begin(), dataB.end(), greater<int>());
    dataC = dataA;
    for(auto v: dataB) dataC.push_back(v);
    sort(dataC.begin(), dataC.end(), greater<int>());
    Node *a = new Node();
    Node *b = new Node();
    for(int i = 0; i < n; i++){
        Node *node = new Node();
        node->value = dataA[i];
        node->next = a->next;
        a->next = node;
    }
    for(int i = 0; i < m; i++){
        Node *node = new Node();
        node->value = dataB[i];
        node->next = b->next;
        b->next = node;
    }
    Node *cur = mergeAndReverse(a->next, b->next);
    for(auto v: dataC){
        if (!cur || cur->value != v) return false;
        cur = cur->next;
    }
    return true;
}

int main(){
    cout << test(5, 10) << endl;
    cout << test(1, 1000) <<endl;
    cout << test(10000, 10000) <<endl;
    cout << test(1000, 1) <<endl;
    cout << test(1000, 0) <<endl;
    cout << test(0, 1000) <<endl;
    cout << test(0, 0) <<endl;
    return 0;
}