int TrappingRainWater(vector<int>& height) {
        int ans = 0,n = height.size(),i=0;
        stack<int>s;
        while(i<n){
            if(s.size()==0 || height[s.top()]>=height[i]){
                s.push(i);
                i++;
            }
            else{
                int cur_height = height[s.top()];
                s.pop();
                int prev_height = s.size()>0 ? min(height[s.top()],height[i]) : cur_height;
                int width = s.size()>0 ? i-s.top()-1 : 0;
                ans = ans + (prev_height - cur_height)*width;
            }
            
        }
        return ans;
    }