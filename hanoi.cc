#include <iostream>
#include <stack>

// moves the top disk from one stack to another
void move(stack<int> a, stack<int> b) {
    if (a.empty())
}

// Iterative method


// Recursive method


void hanoi(int n, stack<int> source, stack<int> target, stack<int> spare) {
    if (n == 1) {
        move(source, target);
    }
    else {
        hanoi(n - 1, source, spare, target);
        move(source, target);
        hanoi(n - 1, spare, target, source);
    }
}