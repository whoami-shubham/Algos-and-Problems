/*           Merge Sort
 * 
 *    Time Complexity O(nlogn)  for each case
 */

#include<bits/stdc++.h>
using namespace std;

void Merge_Sort(vector<int>& v,int start,int end);
void Merge(vector<int>& v,int start,int mid,int end);

int main(){

	int n;
	cin>>n;
	vector<int>input(n);

	for(int i=0;i<n;i++){
  		cin>>input[i];
	}

	Merge_Sort(input,0,n-1);
	for(int i=0;i<n;i++){
   		cout<<input[i]<<" ";
	}	
	cout<<endl;


	return 0;
}

void Merge_Sort(vector<int>& v,int start,int end){

    if(start>=end){    /*  if start == end then array is already sorted      */
        return;
    }

    int mid = (start + end)/2;
    Merge_Sort(v,start,mid);
    Merge_Sort(v,mid+1,end);
    Merge(v,start,mid,end);
}

void Merge(vector<int>& v,int start,int mid,int end){
    int n = mid-start + 1;   /*      */
    int m = end - mid;      /*  m = { end - (mid+1) } + 1     */
    int left = 0 , right = 0, start_ = start;

    vector<int>v_left(n);
    vector<int>v_right(m);
    for(int i = start;i<=mid;i++){
        v_left[i-start] = v[i];          /* normalized index  */
    }
    for(int i = mid+1;i<=end;i++){
        v_right[i-(mid+1)] = v[i];
    }

    while(left<n && right<m && start_<(end+1)){
        if(v_left[left]<v_right[right]){
            v[start_++] = v_left[left++];
        }
        else{
            v[start_++] = v_right[right++];
        }
    }

    while(left<n && start_<(end+1)){
        v[start_++] = v_left[left++];
    }

    while(right<m && start_<(end+1)){
         v[start_++] = v_right[right++];
    }

}

