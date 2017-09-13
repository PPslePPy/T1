#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Sorter
{
public:
	Sorter(int *A, int n){
		Array = A;
		length = n;
	}
	void BubbleSort(int method)
	{
		int i,j,t;
		for(i=length; i>1; i--)
			for(j=0; j<i-1; j++){
				if (compare(Array[j],Array[j+1],method))
					t = Array[j], Array[j] = Array[j+1], Array[j+1] = t;
			}
	}
private:
	int *Array, length;
	int compare(int s1,int s2,int method)
	{
		if (method ==0) return s1<s2;
		else return s1>s2;
	}
};

void generate(int *A,int n)
{
	int i;
	srand((unsigned int)time(0));
	for(i=0; i<n; i++){           //generate the array
		A[i] = rand()%100;
		cout<<A[i]<<' ';
	}
	cout<<endl<<endl;
}

void Aprint(int *A, int n)
{
	int i;
	for(i=0; i<n; i++){
		cout<<A[i]<<' ';
	}
	cout<<endl;
}

void Verify(int *A, int n, int method)
{
	vector<int> v;
	int i;
	for(i=0; i<n; i++){
		v.push_back(A[i]);
	}
	if (method) sort(v.begin(), v.end(),less<int>());
	else sort(v.begin(), v.end(),greater<int>());
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
	int i,*A,N=100;
	vector<int> v;
	A = new int[N];
	cout<<"origin"<<endl;
	generate(A,N);
	Sorter BS1(A,N);
	//sort and verify
	BS1.BubbleSort(0);//1 means ascend, 0 means decend
	cout<<"descend"<<endl;
	Aprint(A,N);
	Verify(A,N,0);
	cout<<endl;
	cout<<"acend"<<endl;
	BS1.BubbleSort(1);//1 means ascend, 0 means decend
	Aprint(A,N);
	Verify(A,N,1);
	delete []A;
	return 0;
}

//C++如何用定义的单词表示属性