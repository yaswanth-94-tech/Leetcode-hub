class Solution {
    public int totalMoney(int n) {
        int deposit = 1;
        int day = 0;
        int res = 0;
        while(day<n){
            res=res+deposit;
            deposit++;
            day++;
            if(day%7==0){
                deposit=1+day/7;
            }
        }
        return res;
    }
}