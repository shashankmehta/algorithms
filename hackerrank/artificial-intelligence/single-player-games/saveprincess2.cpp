/**
 * https://www.hackerrank.com/challenges/saveprincess2
 * This program has been optimised for best result and not fastest result.
 * This program gives the best score for this problem.
 */

#include <iostream>
#include <vector>
using namespace std;

/* Head ends here */

void nextMove(int n, int x, int y, vector <string> grid){
    string s2 = "p";
    int prow = 0;
    int pcol = 0;
    for(prow; prow<n-1; prow++ ){
        if (grid[prow].find(s2) != string::npos)
            break;
    }

    if (prow < x)
        cout << "UP\n";
    
    if (prow > x)
        cout << "DOWN\n";
    
    if (prow == x) {
        pcol = grid[prow].find(s2);
        if (pcol < y)
            cout << "LEFT\n";
        
        if (pcol > y)
            cout << "RIGHT\n";
    }
}

/* Tail starts here */
int main() {

    int n, x, y;
    vector <string> grid;

    cin >> n;
    cin >> x;
    cin >> y;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, x, y, grid);
    return 0;
}