#include <iostream>
using namespace std;
struct Move{
    int row;
    int col;
};
char player1='x',player2='o';
bool move_left(char a[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]=='/'){
                return true;
            }
        }
    }
    return false;
}
int evaluation(char a[3][3]){
    for(int row=0;row<3;row++){
        if(a[row][0]==a[row][1] && a[row][1]==a[row][2]){
            if(a[row][0]==player1){
            return 1;
            }else{
                return -1;
            }
    }
    }
    for(int col=0;col<3;col++){
        if(a[0][col]==a[1][col]&&a[1][col]==a[2][col]){
            if(a[0][col]==player1){
            return 1;
            }else{
            return -1;
            }
    }
    }
        if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]){
            if(a[0][0]=='x'){
                return 1;
            }else{
                return -1;
            }
        }
        if(a[2][0]==a[1][1]&&a[1][1]==a[0][2]){
            if(a[2][0]=='x'){
                return 1;
            }else{
               return -1;
            }
        }
    return 0;
}
int minimax(char a[3][3],int depth,bool isMax){
    int val=evaluation(a);
    if(val==1){
        return 1;
    }
    if(val==-1){
        return -1;
    }
    if(move_left(a)==false){
        return 0;
    }
    if (isMax){
       {
           int best = INT_MIN;
           for (int i = 0; i<3; i++){
               for (int j = 0; j<3; j++){
                   if (a[i][j]=='/'){
                       a[i][j] = player1;
                       best = max(best,minimax(a,depth+1,!isMax));
                       a[i][j] = '/';
                   }
               }
           }
           return best;
       }
    }else{
        int best=INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[i][j]=='/'){
                    a[i][j]=player2;
                    best=min(best,minimax(a,depth+1,!isMax));
                    a[i][j]='/';
                }
            }
        }
        return best;
    }
}
    Move findBestMove(char a[3][3]){
        int bestVal = -1000;
        Move bestMove;
        bestMove.row = -1;
        bestMove.col = -1;
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if (a[i][j]=='/'){
                    a[i][j] = player1;
                    int moveVal = minimax(a,0,false);
                    a[i][j] = '_';
                    if (moveVal > bestVal)
                    {
                        bestMove.row = i;
                        bestMove.col = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
        cout<<bestVal<<endl;
        return bestMove;
    }
int main() {
    char a[3][3] =
        {
            { 'x', 'o', 'x' },
            { 'o', 'o', 'x' },
            { '/', '/', '/' }
        };
        findBestMove(a);
        return 0;
}
