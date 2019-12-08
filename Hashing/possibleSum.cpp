/*

You have a collection of coins, and you know the values of the coins and the quantity of each type of coin in it. You want to know how many distinct sums you can make from non-empty groupings of these coins.

Example

For coins = [10, 50, 100] and quantity = [1, 2, 1], the output should be
possibleSums(coins, quantity) = 9.

Here are all the possible sums:

50 = 50;
10 + 50 = 60;
50 + 100 = 150;
10 + 50 + 100 = 160;
50 + 50 = 100;
10 + 50 + 50 = 110;
50 + 50 + 100 = 200;
10 + 50 + 50 + 100 = 210;
10 = 10;
100 = 100;
10 + 100 = 110.


*/

int possibleSums(vector<int> coins, vector<int> quantity) {
    
    int n = quantity.size();
    set<int>ans;
    ans.insert(0);
    for(int i=0;i<n;i++){
        set<int>temp = ans;
        for(int j=1;j<=quantity[i];j++){
            int sum = coins[i]*j; 
            for(auto x:temp){
                ans.insert(sum+x);
            }
            
        }
       
    }
    
    return ans.size()-1;
}
