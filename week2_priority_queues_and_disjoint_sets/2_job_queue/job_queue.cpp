#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::pair;

struct heap {
  int thread_id;
  long long int start_time;
  heap() {
    this->start_time=0;
  }
};

int left (int i) {
  return 2*i+1;
}

int right(int i) {
  return 2*i+2;
}

int parent(int i) {
  return (i-1)/2;
}

void siftdown(int i,std::vector<heap> &assigned_workers_) {

  int mini = i;
  int l = left(i);
  int r = right(i);

  if(l < assigned_workers_.size() && assigned_workers_[mini].start_time == assigned_workers_[l].start_time) {
    if(assigned_workers_[mini].thread_id > assigned_workers_[l].thread_id)
      mini = l;
  }
  else if(l < assigned_workers_.size() && assigned_workers_[mini].start_time > assigned_workers_[l].start_time)
    mini = l;

    if(r < assigned_workers_.size() && assigned_workers_[mini].start_time == assigned_workers_[r].start_time) {
      if(assigned_workers_[mini].thread_id > assigned_workers_[r].thread_id)
        mini = r;
    }
    else if(r < assigned_workers_.size() && assigned_workers_[mini].start_time > assigned_workers_[r].start_time)
      mini = r;

    if(mini != i) {
      std::swap(assigned_workers_[i],assigned_workers_[mini]);
      siftdown(mini,assigned_workers_);
    }

}

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<heap> assigned_workers_;
  std::vector<pair <int ,long long int> > v;



  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << v[i].first << " " << v[i].second << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    assigned_workers_.resize(num_workers_);
    jobs_.resize(m);
    v.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
    for(int j=0;j<num_workers_;j++)
        assigned_workers_[j].thread_id=j;
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    for(int i=0;i<jobs_.size();i++) {
      v[i]=std::make_pair(assigned_workers_[0].thread_id, assigned_workers_[0].start_time);
      if(jobs_[i] != 0) {
        assigned_workers_[0].start_time = assigned_workers_[0].start_time+jobs_[i];
        siftdown(0,assigned_workers_);
      }
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
