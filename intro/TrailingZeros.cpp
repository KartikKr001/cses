#include<bits/stdc++.h>
using namespace std;
/* number of trailling zeroes in x = {
    number of 5's
     = x/5 + x/25 + x/125 + x/625 ........

} */
int main(){
    int n;
    cin>> n;
    int trail = 0;
    int div = 5;
    while(div <= n){
        trail += n/div;
        div *= 5;
    }
    cout<<trail<<endl;
}


