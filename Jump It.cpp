#include<iostream>

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
    //cout << oneMove << " " << twoMoves << endl;
    return min(oneMove, twoMoves);
}

int main(){
    int a[7] = {0, 10, 50, 100, 70, 8, 9};
    int minCost = getMinCost(a, 7, 0);
    cout << minCost << endl;
    return 0;
}
