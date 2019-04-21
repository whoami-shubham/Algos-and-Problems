/*           Quick Sort
 * 
 *    Time Complexity O(nlogn)  for average and best case O(n^2) for worst case
 */

#include<bits/stdc++.h>
using namespace std;

void Quick_Sort(vector<int>& v,int start,int end);
int Partition(vector<int>& v,int start,int end);

int main(){

	int n;
	cin>>n;
	vector<int>input(n);

	for(int i=0;i<n;i++){
  		cin>>input[i];
	}

	Quick_Sort(input,0,n-1);
	for(int i=0;i<n;i++){
   		cout<<input[i]<<" ";
	}	
	cout<<endl;


	return 0;
}

void Quick_Sort(vector<int>& v,int start,int end){

    if(start<end){    
        
        int pivot = Partition(v,start,end);
        Quick_Sort(v,start,pivot-1);
        Quick_Sort(v,pivot+1,end);

    }
    
}

int Partition(vector<int>& v,int start,int end){
 
  int prev = start-1;
  for(int i = start;i<end;i++){
      if(v[i]<=v[end]){
         prev++;
         swap(v[prev],v[i]);
      }
  }
  prev++;
  swap(v[prev],v[end]);
  return prev;


}