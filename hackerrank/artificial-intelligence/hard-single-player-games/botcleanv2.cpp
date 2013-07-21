/**
 * https://www.hackerrank.com/challenges/botcleanv2
 * This program has been optimised for best result and not fastest result.
 * More optimisation is still needed as my score is not the best yet.
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int positive(int bad){
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

/**
 * Checks if it's a valid quadrant visit
 * @param  x current pos x
 * @param  y current pos y
 * @return   which quadrant visit is it, if valid
 */
int quadrantvisit(int x, int y){
  if (x == 1 && y == 1)
      return 1;
  if (x == 1 && y == 3)
      return 2;
  if (x == 3 && y == 1)
      return 3;
  if (x == 3 && y == 3)
      return 4;
  else
    return 0;
}

/**
 * Calculates the number of steps from current position to given position
 * @param  x  current x
 * @param  y  current y
 * @param  nx next x
 * @param  ny next y
 * @return    number of steps
 */
int stepsToNext(int x, int y, int nx, int ny){
    int tempx = x - nx;
    tempx = positive(tempx);
    int tempy = y - ny; 
    tempy = positive(tempy);
    int tempsteps = tempx + tempy;
    return tempsteps;
}

/* Head ends here */
void next_move(int posx, int posy, vector <string> board) {
    int nextx = posx, nexty = posy, steps = 100;
    
    // The bot could be on a dirtball
    if(board[posx][posy] == 'd'){
        cout << "CLEAN";
    }
    else {      
      
        /**
         * Ok, so the bot is not on a dirtball.
         * Let's check for any visible dirtball
         */
        int multipledirt = 0; 
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                if (board[i][j] == 'd'){
                    int newsteps = stepsToNext(posx, posy, i, j);
                    if (newsteps <= steps){
                        nextx = i;
                        nexty = j;
                        steps = newsteps;
                    }
                }
            }
        }
        
        int specialMove = 0;
        if(board[0][4] == 'd'){
            nextx = 0;
            nexty = 4;
            specialMove = 2;
        }
        if(board[4][4] == 'd'){
            nextx = 4;
            nexty = 4;
            specialMove = 4;
        }
        if(board[4][0] == 'd'){
            nextx = 4;
            nexty = 0;
            specialMove = 3;
        }

        /**
         * If a dirtball was found
         */
        int movedone = 0; // To check whether a move has been made or not
        if (posx == nextx){
            if (posy < nexty){
                cout << "RIGHT";
                movedone = 1;
            }
            else if (posy > nexty){
                cout << "LEFT";
                movedone = 1;
            }
        }
        else if (posx < nextx){
            cout << "DOWN";
            movedone = 1;
        }
        else if (posx > nextx){
            cout << "UP";
            movedone = 1;
        }

        /**
         * Ok, so there is not dirtball visible.
         * Time to check which quadrant the bot is in
         */
        int quadrant;
        quadrant = check(posx, posy);

        /**
         * Now we need to find out which all quadrants have been checked by the bot
         */
        ifstream readfile;
        ofstream writefile;
        string filename = "quadrant.txt";
        readfile.open( filename.c_str() );
        string quadvisited[5];
        int counter = 1;
        if(readfile){
            // File exists, let's read from it.
            while (!readfile.eof()) {
              readfile >> quadvisited[counter++];
           }
            readfile.close();
        }
        else{
            /**
             * Zomg the file doesn't exist!!
             * Let's make one with 0 as content
             */
            writefile.open( filename.c_str() );
            //write something to the file
            writefile << "0 0 0 0" << endl;
            writefile.close();
            quadvisited[1] = "0 ";
            quadvisited[2] = "0 ";
            quadvisited[3] = "0 ";
            quadvisited[4] = "0 ";
        }

        /**
         * Time to update quadrants visited
         */
        int validquad = quadrantvisit(posx, posy);
        if (validquad){
          quadvisited[validquad] = "1";
          quadvisited[specialMove] = "0";
          writefile.open( filename.c_str() );
          //write something to the file
          writefile << quadvisited[1] << " ";
          writefile << quadvisited[2] << " ";
          writefile << quadvisited[3] << " ";
          writefile << quadvisited[4] << " ";
          writefile.close();          
        }

        /**
         * Now we know which all quadrants have been visited by the bot
         * It's all in quadvisited[]
         * Now we need to find out the next closest unvisited quadrant and send the bot there.
         */
         if(!movedone){   
            int first = 1000;
            int second = 1000;
            int third = 1000;
            int fourth = 1000;
            if (quadvisited[1] == "0"){
              first = stepsToNext(posx, posy, 1, 1);
            }
            if (quadvisited[2] == "0"){
              second = stepsToNext(posx, posy, 1, 3);
            }
            if (quadvisited[3] == "0"){
              third = stepsToNext(posx, posy, 3, 1);
            }
            if (quadvisited[4] == "0"){
              fourth = stepsToNext(posx, posy, 3, 3);
            }
            int closestquad = 0;
            if(first < second && first < third && first < fourth)
              closestquad = 1;
            else if(second < third && second < fourth) {
              closestquad = 2;
            }
            else if(third < fourth)
              closestquad = 3;
            else
              closestquad = 4;

            if(closestquad == 1){
              nextx = 1;
              nexty = 1;
            }
            if(closestquad == 2){
              nextx = 1;
              nexty = 3;
            }
            if(closestquad == 3){
              nextx = 3;
              nexty = 1;
            }
            if(closestquad == 4){
              nextx = 3;
              nexty = 3;
            }
            if (posx == nextx){
                if (posy < nexty){
                    cout << "RIGHT";
                }
                else if (posy > nexty){
                    cout << "LEFT";
                }
            }
            else if (posx < nextx){
                // cout << quadvisited[2];
                // cout << "first = " << first << "second = " << second << "third = " << third << "fourth = " << fourth << endl; 
                // cout << "x = " << nextx << " y = " << nexty;
                cout << "DOWN";
            }
            else if (posx > nextx){
                cout << "UP";
            }
         }
        // if (posx == 3 && posy == 3){
        //   cout << quadvisited[1] << quadvisited[2] << quadvisited[3] << quadvisited[4];
        // }
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