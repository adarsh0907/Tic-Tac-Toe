#include <iostream>
using namespace std;
struct Move{
    int row;
    int col;
};
/////////////////////
char player1='x',player2='o';
    //function return false if no moves left to play else return true.
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
    //checking for rows for player1 or player2 victory.
    for(int row=0;row<3;row++){
        if(a[row][0]==a[row][1] && a[row][1]==a[row][2]){
            if(a[row][0]==player1){
            return 1;
            }else{
                return -1;
            }
    }
    }
    //checking for columns for player1 or player2 victory
    for(int col=0;col<3;col++){
        if(a[0][col]==a[1][col]&&a[1][col]==a[2][col]){
            if(a[0][col]==player1){
            return 1;
            }else{
            return -1;
            }
    }
    }
    //checking for diagonals for player1 or player2 victory.
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
    //else if none of them win return 0
    return 0;
}
/*This is the minimax function.
It considers all the possible ways the game can go
returns the value of the board*/
int minimax(char a[3][3],int depth,bool isMax){
    int val=evaluation(a);
    //if maximizer has won the game return its evaluated score
    if(val==1){
        return 1;
    }
    //if minimizer has won the game return its evaluated score
    if(val==-1){
        return -1;
    }
    // if no more moves left and no winnner then declare its a tie.
    if(move_left(a)==false){
        return 0;
    }
    //if this is maximizer's move
    if (isMax){
       {
           int best = INT_MIN;
           for (int i = 0; i<3; i++){
               for (int j = 0; j<3; j++){
                //check if the cell is empty
                   if (a[i][j]=='/'){
                //make the move
                       a[i][j] = player1;
                //call the minimax fun recursively and choose maximum
                       best = max(best,minimax(a,depth+1,!isMax));
                //undo the move
                       a[i][j] = '/';
                   }
               }
           }
           return best;
       }
    }
    //if this is minimizer's move
    else
        {
        int best=INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
          //check if cell is empty
                if(a[i][j]=='/'){
          //make the move
                    a[i][j]=player2;
          //call minimax function recursively and find the minimum value
                    best=min(best,minimax(a,depth+1,!isMax));
          //undo the move
                    a[i][j]='/';
                }
            }
        }
        return best;
    }
}
         //this fuction will return the best possible move for player
Move findBestMove(char a[3][3]){
        int bestVal = -1000;
        Move bestMove;
        bestMove.row = -1;
        bestMove.col = -1;
    /* Traverse all cells, evaluate minimax function for
    all empty cells and return the cell with optimal
     value*/
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
            //check if the cell is empty
                if (a[i][j]=='/'){
            //make the move
                    a[i][j] = player1;
            //compute evaluation function for this move
                    int moveVal = minimax(a,0,false);
            // undo the move
                    a[i][j] = '_';
            /*If the value of the current move is
            more than the best value, then update
            best*/
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
