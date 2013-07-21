/**
 * https://www.hackerrank.com/challenges/botcleanr
 * This program has been optimised for best result and not fastest result.
 * This program gives the best score for this problem.
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

int check(int a, int b){
    if ((a == 1 || a == 0) && (b == 1 || b == 0))
        return 1;
    if ((a == 1 || a == 0) && (b == 3 || b == 4))
        return 2;
    if ((a == 3 || a == 4) && (b == 1 || b == 0))
        return 3;
    if ((a == 3 || a == 4) && (b == 3 || b == 4))
        return 4;
    else return 5;
}

void next_move(int posx, int posy, vector <string> board) {
    // If the bot is on a dirty tile
    int nextx = posx, nexty = posy, steps = 100;
    if(board[posx][posy] == 'd'){
        cout << "CLEAN";
    }
    else {
        // Bot is not on a dirty tile. Lets find out the next closest dirtball

        /**
         * This part finds the next dirtball that is visible
         */
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
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
            else {
                // This happens when there are no dirtballs visible
                int quadrant;
                quadrant = check(posx, posy);
                if (quadrant == 1){
                    if (posx == 1 && posy == 0)
                        cout << "RIGHT";
                    else
                        cout << "DOWN";
                }
                if (quadrant == 2){
                    if (posx == 1 && posy == 4)
                        cout << "LEFT";
                    else
                        cout << "DOWN";
                }
                if (quadrant == 3){
                    if (posx == 3 && posy == 0)
                        cout << "RIGHT";
                    else
                        cout << "UP";
                }
                if (quadrant == 4){
                    if (posx == 3 && posy == 4)
                        cout << "LEFT";
                    else
                        cout << "UP";
                }
                if (quadrant == 5){
                    if (posx == 2)
                        if ((posy == 0 || posy == 1))
                            cout << "RIGHT";
                        else
                            cout << "LEFT";
                    else if ((posx == 3 || posx == 4))
                        cout << "UP";
                    else
                        cout << "DOWN";
                }
            }
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
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}