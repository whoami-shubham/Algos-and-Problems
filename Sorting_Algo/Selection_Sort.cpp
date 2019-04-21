/*           Selection Sort
 * 
 *    Time Complexity O(n^2)  for all cases
 */

#include<bits/stdc++.h>
using namespace std;

void Selection_Sort(vector<int>& v);

int main(){

  int n;
  cin>>n;
  vector<int>input(n);

  for(int i=0;i<n;i++){
      cin>>input[i];
  }

  Selection_Sort(input);
  for(int i=0;i<n;i++){
      cout<<input[i]<<" ";
  } 
  cout<<endl;


  return 0;
}

void Selection_Sort(vector<int>& v){
     int size = v.size();

     for(int i = 0;i<size;i++){
         int min_element = v[i],index = i;
          for(int j = i+1;j<size;j++){
              if(v[j]<min_element){
                 index = j;
                 min_element = v[j];
              }
          }
          swap(v[i],v[index]);
     }
}

