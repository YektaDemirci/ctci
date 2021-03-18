#include <string>
#include <iostream>
using namespace std;

/* I realized the layer gets smaller as j=j-2 but j/2 is a better approach
void rotate(int ** m, int N){
    int temp = 0;
    for(int j = N-1 j>0; j=j-2){
        for(int i=0; i<N; i++){
            temp = m[i]
        }
    }
} */

/* counterClockwise */
void rotatecct(int ** m, int N){
    for(int i=0; i < N/2; i++){
        for( int j=i; j < N-i-1; j++){
            int temp = m[i][j];
            m[i][j] = m[j][N-i-1];
            m[j][N-i-1] = m[N-i-1][N-j-1];
            m[N-i-1][N-j-1] = m[N-j-1][i];
            m[N-j-1][i] = temp;
        }
    }
}

void rotate(int ** m, int N){
    for(int i=0; i < N/2; i++){
        for( int j=i; j < N-i-1; j++){
            int temp = m[i][j];
            m[i][j] = m[N-j-1][i];
            m[N-j-1][i] = m[N-i-1][N-j-1];
            m[N-i-1][N-j-1] = m[j][N-1-i];
            m[j][N-1-i] = temp;
        }
    }
}

void printMatrix(int ** m, int N){
    for(int i=0; i<N; i++){
        for(int j=0 ; j<N; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
	int N;
	std::cout << "Enter N for NxN matrix:";
	std::cin >> N;
	int ** matrix = new int*[N];
	for ( int i = 0; i < N; ++i ) {
		matrix[i] = new int[N];
	}

	for ( int i = 0; i < N; ++i) {
		for ( int j = 0; j < N; ++j ) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << "Rotated matrix again by 90(anticlockwise):\n";
	rotate(matrix, N);
	printMatrix(matrix, N);
	return 0;
}

