/*           Bubble Sort
 * 
 *    Time Complexity O(n^2)
 */

#include<bits/stdc++.h>
using namespace std;

void Bubble_Sort(vector<int>& v);
void swap(int &a,int &b);

int main(){

	int n;
	cin>>n;
	vector<int>input(n);

	for(int i=0;i<n;i++){
  		cin>>input[i];
	}

	Bubble_Sort(input);
	for(int i=0;i<n;i++){
   		cout<<input[i]<<" ";
	}	
	cout<<endl;


	return 0;
}

void Bubble_Sort(vector<int>& v){

   	int n = v.size();

    	for(int i=0;i<n;i++){
        	 for(int j=1;j<n-i;j++){
            		if(v[j]<v[j-1]){
               			swap(v[j],v[j-1]);

	    		}
	 	}
  
    	}


}

void swap(int &a,int &b){
     	int temp = a;
     	a = b;
     	b = temp;
}
