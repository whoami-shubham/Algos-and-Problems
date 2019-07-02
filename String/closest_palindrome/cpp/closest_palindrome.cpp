
/* problem link : https://leetcode.com/problems/find-the-closest-palindrome/
*
*
*  divide string into two halfs e.g. let two strings  abcd and abcde even and odd length respectively
*  for even length string abcd make cd to ba to make pelindrome because if we convert ab into dc then that number will be more distant  
*  from given number abcd . and for odd length string abcde convert de into ba. there are few edge cases when this algorithm fails that are 
*  covered in solution
*/
long long replicate(long long left_half,long long N,int len){
    string s = to_string(left_half<0?abs(left_half):left_half),rev(s.rbegin(),s.rend());
    if(left_half==0 && len<=2){
        return N==1?0:9;
    }
    if(len%2==0){
        if(s.length()>to_string(left_half-1<0?abs(left_half-1):left_half-1).length()){ // if left half is power of 10
             return atol((s + rev.substr(1)).c_str());
        }
        if(s.length()<to_string(left_half+1<0?abs(left_half+1):left_half+1).length()){ // if every digit is 9 in left half
             return atol((s + rev + "9").c_str());
        }
        return atol((s+rev).c_str());
    }
    else{
        if(s.length()>to_string(left_half-1<0?abs(left_half-1):left_half-1).length()){
             return atol((s + rev.substr(2)).c_str());
        }
        if(s.length()<to_string(left_half+1<0?abs(left_half+1):left_half+1).length()){
             return atol((s + rev.substr(1) + "9").c_str());
        }
        return atol((s+rev.substr(1)).c_str());
    }
}
class Solution {
public:
    string nearestPalindromic(string n) {
        long long N = atol(n.c_str());
        int len = n.length();
        long long left = atol(n.substr(0,(len+1)/2).c_str());
        long long eql = replicate(left,N,len);
        long long plus_one = replicate(left+1,N,len);
        long long minus_one = replicate(left-1,N,len);
        long long ans = abs(N - minus_one)<= abs(N - plus_one) ? minus_one:plus_one;
        ans = eql!=N && abs(N-eql)<=abs(N-ans) ? (abs(N-eql)==abs(N-ans) ? (ans<eql?ans:eql):eql):ans;
        return to_string(ans);
    }
};