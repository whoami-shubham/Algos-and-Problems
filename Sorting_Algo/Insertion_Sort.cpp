/*
 *    Insertion Sort
 *
 *  Time Complexity in Best Case O(n)  and in all other cases O(n^2)
 */

#include<bits/stdc++.h>
using namespace std;

void Insertion_Sort(vector<int>& v);
void swap(int &a,int &b);


int main(){

	int n;
	cin>>n;
	vector<int>input(n);

	for(int i=0;i<n;i++){
  		cin>>input[i];
	}

	Insertion_Sort(input);
	for(int i=0;i<n;i++){
   		cout<<input[i]<<" ";
	}	
	cout<<endl;


	return 0;
}

void Insertion_Sort(vector<int>& v){
     int n = v.size();
     int current = 1;
     while(current<n){
          int prev = current-1;
           while(prev>=0 && v[prev]>v[current]){
               swap(v[prev],v[current]);
               prev--;
               current--;
           }      

        current++;
     }

}

void swap(int &a,int &b){
     	int temp = a;
     	a = b;
     	b = temp;
}
