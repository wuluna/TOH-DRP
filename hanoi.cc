#include <iostream>
#include <stack>

using namespace std;

// moves the top disk from one stack to another
void move(stack<int> a, stack<int> b) {
    if (a.empty() || (!b.empty() && b.top() < a.top())) {
        int top = b.top();
        b.pop();
        a.push(top);
    }
    else if (b.empty() || (!a.empty() && a.top() < b.top())) {
        int top = a.top();
        a.pop();
        b.push(top);
    }
}

void print_stack(stack<int> s) {
    stack<int> scpy = s;
    while (!scpy.empty()) {
        cout << scpy.top() << ", ";
        scpy.pop();
    }
}

// Iterative method
void hanoi_it(int n, stack<int> source, stack<int> target, stack<int> spare) {
    while (target.size() != n && spare.size() != n) {
        move(source, target);
        move(source, spare);
        move(target, spare);
    }
}

// Recursive method
void hanoi_rec(int n, stack<int> source, stack<int> target, stack<int> spare) {
    if (n == 1) {
        move(source, target);
    }
    else {
        hanoi_rec(n - 1, source, spare, target);
        move(source, target);
        hanoi_rec(n - 1, spare, target, source);
    }
}