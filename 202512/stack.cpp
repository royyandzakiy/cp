#include <bits/stdc++.h>
using namespace std;

string rev(string &text) {
    string rev_text = "";
    stack<char> temp_stack;

    for (auto letter : text) {
        temp_stack.push(letter);
    }
    while (!temp_stack.empty()) {
        rev_text.push_back(temp_stack.top());
        temp_stack.pop();
    }

    return rev_text;
}

auto main() -> int {
    string text = "Hello, World!";

    cout << text << endl;
    cout << rev(text) << endl;

    return 0;
}