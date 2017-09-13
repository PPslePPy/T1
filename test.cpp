#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

template <class idv>
class Sorter
{
public:
	Sorter(idv *A, idv n){
		Array = A;
		length = n;
	}
	void BubbleSort(int method)
	{
		int i,j;
		idv t;
		for(i=length; i>1; i--)
			for(j=0; j<i-1; j++){
				if (compare(Array[j],Array[j+1],method))
					t = Array[j], Array[j] = Array[j+1], Array[j+1] = t;
			}
	}
private:
	idv *Array;
	int length;
	int compare(idv s1,idv s2,int method)
	{
		if (method ==0) return s1<s2;
		else return s1>s2;
	}
};

template<typename idv> void Generate(idv *A,int n)
{
	int i;
	srand((unsigned int)time(0));
	for(i=0; i<n; i++){           //Generate the array
		A[i] = idv(rand()%1000/10.0);
		cout<<A[i]<<' ';
	}
	cout<<endl<<endl;
}

template<typename idv> void Aprint(idv *A, int n)
{
	int i;
	for(i=0; i<n; i++){
		cout<<A[i]<<' ';
	}
	cout<<endl;
}

template<typename idv> void Verify(idv *A, int n,int method)
{
	vector<idv> v;
	int i;
	for(i=0; i<n; i++){
		v.push_back(A[i]);
	}
	if (method) sort(v.begin(), v.end(),less<idv>());
	else sort(v.begin(), v.end(),greater<idv>());
	for(i=0; i<n; i++){
		if (A[i] != v[i]){
			cout<<"wrong"<<endl;
			break;
		}
		if (i == n-1) cout<<"right"<<endl;
	}
}

int main() {
	int i,N=100;
	int *A1;
	double *A2;
	A1 = new int[N];
	A2 = new double[N];
	cout<<"origin"<<endl;
	Generate(A1,N);
	Generate(A2,N);
	
	
	//sort
	Sorter<int> BS1(A1,N);   //1 means ascend, 0 means descend
	Sorter<double> BS2(A2,N);
	BS1.BubbleSort(0);
	BS2.BubbleSort(1);
	cout<<"int type with descend"<<endl;
	
	
	Aprint(A1,N);
	Verify(A1,N,0);
	cout<<"double type with ascend"<<endl;
	Aprint(A2,N);
	Verify(A2,N,1);
	delete []A1;
	delete []A2;
	return 0;
}
