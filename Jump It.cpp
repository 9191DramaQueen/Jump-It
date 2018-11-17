#include<iostream>
#include "random"
#include "time.h"
using namespace std;

int getMinCost(int* a, int size, int start, int cCost = 0){
    if(start == size - 1){
    	return cCost;
    }
    int oneMove = getMinCost(a, size, start+1, cCost + a[start + 1]);
    if(start == size - 2){
    	return oneMove;
    }
    int twoMoves = getMinCost(a, size, start+2, cCost + a[start+2]);
    ///cout << oneMove << " " << twoMoves << endl;
    return min(oneMove, twoMoves);
}

int main(){
    int n;
    srand (time(NULL));
    cout << "Enter number of cols: ";
    cin >> n;
    int *bar = new int[n];
    for(int i = 0; i < n; ++i){
        bar[i] = i == 0? 0 : rand()%200;
        cout << bar[i] << "|";
    }
    int minCost = getMinCost(bar, n, 0);
    cout << "\nLowest cost is: " << minCost ;
    return 0;
}
