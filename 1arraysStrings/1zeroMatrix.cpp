#include <iostream>
#include <deque>
using namespace std;

/* Sort of BruteForce solution */
/* First row and col can be used to get rid of queue stuff*/
 void zeroMat(int ** m, int M, int N){
    deque<int> row,col; 
    for(int i=0; i<M; i++){
        for( int j=0; j<N; j++){
            if(m[i][j] == 0){
                row.push_front(i);
                col.push_front(j);
            }
        }
    }
    while(!row.empty()){
        int idx = row.back();
        row.pop_back();
        for(int j=0; j<N ;j++){
            m[idx][j]=0;
        }
    }
    while(!col.empty()){
        int idx = col.back();
        col.pop_back();
        for(int i=0; i<M ;i++){
            m[i][idx]=0;
        }
    }
}


void printMatrix( int ** matrix, int M, int N ) {
	for ( int i = 0; i < M; ++i ) {
		for ( int j = 0; j < N; ++j ) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main()
{
	int M, N;
	std::cout << "Enter number of rows:";
	std::cin >> M;
	std::cout << "Enter number of cols:";
	std::cin >> N;
	int ** matrix = new int*[M];
	for ( int i =0; i < M; ++i ) {
		matrix[i] = new int[N];
	}
	std::cout << "Provide M x N matrix \n";
	for ( int i = 0; i < M; ++i ) {
		for ( int j = 0; j < N; ++j ) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << "Matrix Before:\n";
	printMatrix(matrix, M, N);
	zeroMat(matrix, M, N);
	std::cout << "Matrix After:\n";
	printMatrix(matrix, M, N);
	return 0;
}