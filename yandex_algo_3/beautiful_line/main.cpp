#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N, K, sticker;
  int DiegosAdd = 0;
  vector<int> Diegos_num;
  set<int> Diegos_num_set;
  cin>>N;
  for (int i = 0; i < N; i++)
  {
    cin>>sticker;
    Diegos_num_set.insert(sticker);
  }
  set<int>::iterator it = Diegos_num_set.begin();
    while (it != Diegos_num_set.end())
    {
        Diegos_num.push_back(*(it));
        it++;
    }

  cin>>K;
  int start = 0;
  int end = Diegos_num.size() - 1;
  int midInd, mid;
  int countNum = 0;
  for(int i = 0; i < K; i++)
  {
    cin>>sticker;
    start = 0;
    end = Diegos_num.size() - 1;
    midInd = (end - start) / 2;
    countNum = 0;
    mid = Diegos_num[midInd];
    // cout<<"NUM = "<< sticker<<endl;

    while (start <= end)
    {
        midInd = start + (end - start) / 2;
        mid = Diegos_num[midInd];
        // cout<<"mid = "<<mid<<" midInd = "<< midInd<< " (start, end): "<<start<<", "<<end<<endl;
        if (mid > sticker)
          end = midInd - 1;
        else if (mid < sticker)
          start = midInd + 1;
        else
          break;
    }
    // cout<<"before (start, end): "<<start<<", "<<end<<endl;
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
/*
1
5
2
4 6
*/


/*

3
100 1 50
3
300 0 75

*/


/*

5
1 2 3 4 5
3
3 10 0

*/