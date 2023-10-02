#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N, K, sticker;
  int start, end, mid, midInd;
  int countNum;
  vector<int> Diegos_num;
  set<int> Diegos_num_set;
  cin>>N;
  for (int i = 0; i < N; i++)
  {
    cin>>sticker;
    Diegos_num_set.insert(sticker);
  }
  for(set<int>::iterator it = Diegos_num_set.begin(); it != Diegos_num_set.end(); ++it)
    Diegos_num.push_back(*(it));
  cin>>K;
  for(int i = 0; i < K; i++)
  {
    cin>>sticker;
    start = 0;
    end = Diegos_num.size() - 1;
    countNum = 0;
    midInd = (end - start) / 2;
    mid = Diegos_num[midInd];

    while (start <= end)
    {
        midInd = start + (end - start) / 2;
        mid = Diegos_num[midInd];
        if (mid > sticker)
          end = midInd - 1;
        else if (mid < sticker)
          start = midInd + 1;
        else
          break;
    }
    if (end < 0)
      countNum = 0;
    else if (start == Diegos_num.size())
      countNum = Diegos_num.size();
    else if (mid == sticker)
      countNum = midInd;
    else
      countNum = end + 1;
    cout<<countNum<<endl;
  }
  
}
