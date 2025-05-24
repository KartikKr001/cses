#include<bits/stdc++.h>
using namespace std;
vector<vector<char>>board;
bool canPlace(int x,int y){
    if(board[x][y] != '.') return false;
    // check horizontally and vertically
    for(int i=0;i<x;i++){
        if(board[i][y] == 'Q') return false;
    }
    for(int j=0;j<y;j++){
        if(board[x][j] == 'Q') return false;
    }
    // check diagonally
    int tempx = x;
    int tempy = y;
    while(tempx>=0 && tempy>=0){
        if(board[tempx][tempy] == 'Q') return false;
        tempx--,tempy--;
    }
    tempx = x;
    tempy = y;
    while(tempx>=0 && tempy<8){
        if(board[tempx][tempy] == 'Q') return false;
        tempx--,tempy++;
    }
    return true;
}
int ans = 0;
void chess(int x){
    if(x>=8){
        ans++;
        return;
    }
    for(int i=0;i<8;i++){
        char temp = board[x][i];
        if(canPlace(x,i)){
            board[x][i] = 'Q';
            chess(x+1);
            board[x][i] = temp;
        }
    }
}

int main(){
    board.clear();
    board.resize(8,vector<char>(8,'.'));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>board[i][j];
        }
    }
    chess(0);
    cout<<ans<<endl;


    return 0;
}