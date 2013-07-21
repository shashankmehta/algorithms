/**
 * www.hackerrank.com/challenges/botcleanlarge
 * This program has been optimised for best result and not fastest result.
 * More optimisation is still needed as my score is not the best yet.
 */

#include <iostream>
#include <vector>
using namespace std;

/* Head ends here */
int bad(int bad){
    if (bad < 0)
        return bad*(-1);
    else
        return bad;
}

void next_move(int posx, int posy, int dimx, int dimy, vector <string> board) {
    // If the bot is on a dirty tile
    int nextx = 0, nexty = 0, steps = 100;
    if(board[posx][posy] == 'd'){
        cout << "CLEAN";
    }
    else {
        // Bot is not on a dirty tile. Lets find out the next closest dirtball

        for (int i=0; i<dimx; i++){
            for (int j=0; j<dimy; j++){
                if (board[i][j] == 'd'){
                    int tempx = posx - i;
                    tempx = bad(tempx);
                    int tempy = posy - j; 
                    tempy = bad(tempy);
                    int tempsteps = tempx + tempy;
                    if (tempsteps < steps){
                        nextx = i;
                        nexty = j;
                        steps = tempsteps;
                    }
                }
            }
        }

        if (posx == nextx){
            if (posy < nexty){
                cout << "RIGHT";
            }
            else if (posy > nexty){
                cout << "LEFT";
            }
            else cout << "toobad";
        }
        else if (posx < nextx){
            cout << "DOWN";
        }
        else if (posx > nextx){
            cout << "UP";
        }
        else cout <<"oops";
    }
}

/* Tail starts here */
int main() {
    int pos[2];
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}