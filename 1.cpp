#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define N 10

void BubbleSort(int A[], int n)
{
	int i,j,t;
	for(i=n; i>1; i--)
		for(j=0; j<i-1; j++){
			if (A[j]>A[j+1])
				t = A[j], A[j] = A[j+1], A[j+1] = t;
		}
}

int main()
{
	//A = ArrayGenerate();
	int A[N],i;
	srand((unsigned int)time(0));
	for(i=0; i<N; i++){
		A[i] = rand()%100;
		cout<<A[i]<<' ';
	}
	cout<<endl;
	BubbleSort(A,N);
	for(i=0; i<N; i++) cout<<A[i]<<' ';
	cout<<endl;
	return 0;
}
