#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int left(int i) {
    return 2*i + 1;
  }

  int right(int i) {
    return 2*i + 2;
  }

  int parent(int i) {
    return (i-1)/2;
  }

  void swimdown(int i) {
    int mini = i;
    int l = left(i);
    int r = right(i);
    if(l<=data_.size()-1&&data_[l] < data_[mini])
      mini = l;
    if(r<=data_.size()-1&&data_[r] < data_[mini])
      mini = r;
    if(i != mini) {
      swap(data_[i],data_[mini]);
      swaps_.push_back(make_pair(i,mini));
      swimdown(mini);
    }

  }

  void GenerateSwaps() {
    swaps_.clear();
    int n = data_.size();
    for(int i=parent(n);i+1!=0;i--) {
      swimdown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
