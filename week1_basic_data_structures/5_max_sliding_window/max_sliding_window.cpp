#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const & A, int w) {
    int i = 0;
    std::deque<int> dq;
    for(;i<w;i++) {
      while(!dq.empty() && A[dq.back()] <= A[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }
    //int j=1;
    for(;i < A.size();i++) {
      std::cout << A[dq.front()] << ' ';
      while(!dq.empty() && i-w >= dq.front()) {
        dq.pop_front();
      }
      while(!dq.empty() && A[dq.back()] <= A[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }
    std::cout << A[dq.front()] << '\n';
    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
