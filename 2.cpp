#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define N 100

void BubbleSort(int A[], int n)
{
	int i,j,t;
	for(i=n; i>1; i--)
		for(j=0; j<i-1; j++){
			if (A[j]>A[j+1])
				t = A[j], A[j] = A[j+1], A[j+1] = t;
		}
}

void generate(int *A, int n)
{
	int i;
	srand((unsigned int)time(0));
	for(i=0; i<n; i++){           //generate the array
		A[i] = rand()%1000;
		cout<<A[i]<<' ';
	}
	cout<<endl<<endl;
}

void Aprint(int *A,int n)
{
	int i;
	for(i=0; i<n; i++){
		cout<<A[i]<<' ';
	}
	cout<<endl;
}

void Verify(int *A, int n)
{
	vector<int> v;
	int i;
	for(i=0; i<n; i++){
		v.push_back(A[i]);
	}
	sort(v.begin(), v.end(),less<int>());
	for(i=0; i<n; i++){
		if (A[i] != v[i]){
			cout<<"wrong"<<endl;
			break;
		}
		if (i == n-1) cout<<"right"<<endl;
	}
}

int main()
{
	int A[N],i;
	vector<int> v;
	srand((unsigned int)time(0));
	cout<<"-----before-----"<<endl;
	generate(A,N);
	BubbleSort(A,N);
	cout<<"-----after-----"<<endl;
	Aprint(A,N);
	Verify(A,N);
	return 0;
}
