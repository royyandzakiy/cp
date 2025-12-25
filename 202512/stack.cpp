#include <bits/stdc++.h>
using namespace std;

string to_reverse(string &text) {
    string reversed_text = "";
    stack<char> temp_stack;

    for (auto letter : text) {
        temp_stack.push(letter);
    }
    while (!temp_stack.empty()) {
        reversed_text.push_back(temp_stack.top());
        temp_stack.pop();
    }

    return reversed_text;
}

auto main() -> int {
    string text = "Hello, World!";

    cout << text << endl;
    cout << to_reverse(text) << endl;

    return 0;
}