#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    std::vector<int> v;
    int top=-1;

  public:

    void Push(int value) {
        stack.push_back(value);
        if(top == -1){
          v.push_back(value);
          top++;
        }
        else {
            v.push_back(value > v[top]?value:v[top]);
            top++;
        }
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
        v.pop_back();
        top--;
    }

    int Max() const {
        assert(stack.size());
        return v[top];
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
