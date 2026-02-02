int maxProfit(int* prices, int pricesSize) {
    int profit=0;
    int initialprice=prices[0];

    for(int i=0;i<pricesSize;i++){
        int currentprice=prices[i];
        int diff=currentprice-initialprice;
        if(diff>profit) profit=diff;
        if(currentprice<initialprice){
        initialprice=currentprice;
        }
    }
    return profit;
}
