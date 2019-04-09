#include <bits/stdc++.h>
#define ll long long
using namespace std;
int zeller[7] = {6,0,1,2,3,4,5};


int day_of_year(ll year,ll month,ll date){  // this is zellers algorithm 
       if (month == 1) 
        { 
            month = 13; 
            year--; 
        } 
        if (month == 2) 
        { 
            month = 14; 
            year--; 
        } 
        ll q = date; 
        ll m = month; 
        ll k = year % 100; 
        ll j = year / 100; 
        ll h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j; 
        h = h % 7; 
        return zeller[h]; 

}

ll solve(ll year1,ll month1,ll date1,ll year2,ll month2,ll date2){
    
    ll ans = 0;
    if(date1>1){
        if(month1<12){
            month1++;
        }
        else{
            year1++;
            month1 = 1;
        }
    }
    while(year1+2800<year2){  // a fact if you don't include this you'll get TLE
        ans = ans + 4816;
        year1 = year1 + 2800;
    }
    while(year1<year2 || month1<month2){
        if(day_of_year(year1,month1,1)==0){
            ans++;
        }
        month1++;
        if(month1==13){
            year1++;
            month1 = 1;
        }
    }
    if(day_of_year(year1,month1,1)==0){
            ans++;
        }
    return ans;

}
void swap(ll &year1,ll &month1,ll &date1,ll &year2,ll &month2,ll &date2){
    ll temp = year1;
    year1 = year2;
    year2 = temp;
    temp = month1;
    month1 = month2;
    month2 = temp;
    temp = date1;
    date1 = date2;
    date2 = temp;

}
int main() {
     int T;
     cin>>T;
     for(int t=0;t<T;t++){
         ll year1,month1,date1,year2,month2,date2;
         cin>>year1>>month1>>date1;
         cin>>year2>>month2>>date2;
         if(year1>year2 || (year1==year2 && month1>month2) || (year1==year2 && month1==month2 && date1>date2)){ // fix testcase
             swap(year1,month1,date1,year2,month2,date2);
         }
         cout<<solve(year1,month1,date1,year2,month2,date2)<<endl;
     }
   
    return 0;
}
