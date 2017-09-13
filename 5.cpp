#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class SorterBase
{
public:
	SorterBase(int *A, int n):Array(A),length(n){}
	void Sort(int method);
protected:
	int *Array;
	int length;
	int compare(int s1,int s2,int method)
	{
		if (method ==0) return s1<s2;
		else return s1>s2;
	}
};

class SorterBubble: public SorterBase
{
public:
	SorterBubble(int *A, int n):SorterBase(A,n){}
	void Sort(int method)
	{
		int i,j;
		int t;
		for(i=length; i>1; i--)
			for(j=0; j<i-1; j++){
				if (compare(Array[j],Array[j+1],method))
					t = Array[j], Array[j] = Array[j+1], Array[j+1] = t;
			}
	}
};

class SorterMerge: public SorterBase
{
public:
	SorterMerge(int *A, int n):SorterBase(A,n){}
	void Sort(int method)
	{
		int* a = Array;
		int* b = new int[length];
		for (int seg = 1; seg < length; seg += seg) {
			for (int start = 0; start < length; start += seg + seg) {
				int low = start, mid = min(start + seg, length), high = min(start + seg + seg, length);
				int k = low;
				int start1 = low, end1 = mid;
				int start2 = mid, end2 = high;
				while (start1 < end1 && start2 < end2)
					b[k++] = !compare(a[start1], a[start2], method) ? a[start1++] : a[start2++];
				while (start1 < end1)
					b[k++] = a[start1++];
				while (start2 < end2)
					b[k++] = a[start2++];
			}
			int* temp = a;
			a = b;
			b = temp;
		}
		if (a != Array) {
			for (int i = 0; i < length; i++)
				b[i] = a[i];
			b = a;
		}
		delete[] b;
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
	int *A1,*A2;
	A1 = new int[N];
	A2 = new int[N];
	cout<<"origin"<<endl;
	Generate(A1,N);
	Generate(A2,N);
	//sort
	SorterBubble BS1(A1,N);   //1 means ascend, 0 means descend
	SorterMerge MS1(A2,N);
	BS1.Sort(0);
	MS1.Sort(0);
	cout<<"Bubble sort"<<endl;
	Aprint(A1,N);
	Verify(A1,N,0);
	cout<<endl;
	cout<<"Merge sort"<<endl;
	Aprint(A2,N);
	Verify(A2,N,0);
	delete []A1;
	return 0;
}
