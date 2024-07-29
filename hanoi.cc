#include <iostream>
#include <stack>

using namespace std;

// moves the top disk from one stack to another
void move(stack<int> &a, stack<int> &b) {
    if (a.empty() && b.empty()) return;
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

void print_stack(stack<int> &s) {
    stack<int> scpy = s;
    while (!scpy.empty()) {
        cout << scpy.top() << " ";
        scpy.pop();
    }
    cout << endl;
}

// Iterative method
void hanoi_it(int n, stack<int> &source, stack<int> &spare, stack<int> &target) {
    while (target.size() != n && spare.size() != n) {
        move(source, spare);
        move(source, target);
        move(spare, target);
    }
}


void hanoi_rec(int n, stack<int> &source, stack<int> &target, stack<int> &spare) {
    if (n == 0) {
        return;
    }
    hanoi_rec(n - 1, source, spare, target);
    move(source, target);
    hanoi_rec(n - 1, spare, target, source);
}

int main() {
    stack<int> source, spare, target;
    int n;
    cin >> n;
    for (int i = n; i > 0; i-- ) {
        source.push(i);
    }
    hanoi_rec(n, source, spare, target);
}
