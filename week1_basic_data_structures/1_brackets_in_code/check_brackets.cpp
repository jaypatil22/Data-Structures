#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int ans = 0;bool flag = 0;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next,position));
        }

        if (next == ')' || next == ']' || next == '}') {
            if(!opening_brackets_stack.empty() && opening_brackets_stack.top().Matchc(next)) {
              opening_brackets_stack.pop();
            }else {
              flag = 1;
              ans = position;
              break;
            }
        }
    }

    if(flag==1)
      std::cout << ans+1 << '\n';
    else if(!opening_brackets_stack.empty())
      std::cout << opening_brackets_stack.top().position+1 << '\n';
    else
      std::cout << "Success" << '\n';

    return 0;
}
