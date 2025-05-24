<=b;i++){
        for(int j=1;j<=l;j++){
            if(i == j) continue;
            for(int k=1;k<=min(i,j);k++){
                if(i>k) dp[i][j] = min(dp[i][j],1+f(l,i)+f(l,b-i));
                if(j>k) dp[i][j] = min(dp[i][j],1+f(i,b)+f(l-i,b));
            }
        }
    }