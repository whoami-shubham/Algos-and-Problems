/*
 *      Modified Bubble Sort 
 *
 *  Time Complexity in Best Case O(n)  and in all other cases O(n^2)
 *
 */

#include<bits/stdc++.h>
using namespace std;

void Bubble_Sort_2(vector<int>& v);
void swap(int &a,int &b);

int main(){

	int n;
	cin>>n;
	vector<int>input(n);

	for(int i=0;i<n;i++){
  		cin>>input[i];
	}

	Bubble_Sort_2(input);
	for(int i=0;i<n;i++){
   		cout<<input[i]<<" ";
	}	
	cout<<endl;


	return 0;
}

void Bubble_Sort_2(vector<int>& v){

   	int n = v.size();
    bool flag,sorted=false;  
    	for(int i=0;i<n;i++){
            flag = true;
        	 for(int j=1;j<n-i && !sorted;j++){
            		if(v[j]<v[j-1]){
               			swap(v[j],v[j-1]);
                       flag = false;
	    		}
	 	    }
            sorted = flag;
  
    	}


}



void swap(int &a,int &b){
     	int temp = a;
     	a = b;
     	b = temp;
}



