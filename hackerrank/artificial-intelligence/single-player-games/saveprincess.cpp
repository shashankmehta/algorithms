/**
 * https://www.hackerrank.com/challenges/saveprincess
 * This program has been optimised for best result and not fastest result.
 * This program gives the best score for this problem.
 */

#include <iostream>
#include <vector>
using namespace std;
/* Head ends here */

void displayPathtoPrincess(int m, vector <string> grid){
    if(grid[0][0] == 'p' || grid[0][m-1] == 'p'){
        for(int i=0; i<(m/2); i++ ){
            cout << "UP" << "\n";
        }
    }
    if(grid[m-1][0] == 'p' || grid[m-1][m-1] == 'p'){
        for(int i=0; i<(m/2); i++ ){
            cout << "DOWN" << "\n";
        }
    }
    if(grid[0][0] == 'p' || grid[m-1][0] == 'p'){
        for(int i=0; i<(m/2); i++ ){
            cout << "LEFT" << "\n";
        }
    }
    if(grid[0][m-1] == 'p' || grid[m-1][m-1] == 'p'){
        for(int i=0; i<(m/2); i++ ){
            cout << "RIGHT" << "\n";
        }
    }
}

/* Tail starts here */
int main() {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    // for(int i=0; i<m; i++){
    //     cout << grid[i][0];
    // }

    displayPathtoPrincess(m,grid);

    return 0;
}