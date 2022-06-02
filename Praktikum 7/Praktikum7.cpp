#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

class sorting{
	friend istream& operator>>(istream& in, sorting& a);
	friend ostream& operator>>(ostream& out, sorting& a);
	
	private:
		void minimum(int, int, int&);
		void tukar(int*, int*);
		int data[10], n, low, high;
	public:
		int pencarianBiner();
		void selection_sort();		
};

void sorting::minimum(int dari, int n, int &tempat){
	int min=data[dari];
	tempat=dari;
	for(int i=dari+1; i<n; i++){
	if(data[i]<min){
		min=data[i];
		tempat=i;
	}
	}
}

void sorting::tukar(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void sorting::selection_sort(){
	int t;
	for(int i=0; i<n; i++){
	minimum(i,n,t);
	tukar(&data[i], &data[t]);	
	cout<<data[i]<<" ";
	}
}

int sorting::pencarianBiner(){
	int middle, kunciPencarian;
	cout<<"\nMasukkan data yang dicari : ";
	cin>>kunciPencarian;
	low = 0;
	high = (n-1);
	middle = (low+high)/2;
	
	while (low <= high){
	middle = (low+high)/2;
// cetakBaris(low, middle, high);
		if (kunciPencarian == data[middle]){
			return middle;
		} else if (kunciPencarian < data[middle]){
			high = middle-1;
		} else {
			low = middle+1;
		}
	}
	
	if(low>high){          
		cout<<"Data tidak ada "<<endl;
	}

}

istream& operator >> (istream& in, sorting& a){
	cout<<"Tentukan banyak data : ";
	in>>a.n;
	for(int i=0; i<a.n; i++){
		cout<<"Masukkan data ke-"<<i<<" : ";
		cin>>a.data[i];
	}
	cout<<"Data setelah diurutkan : ";
	a.selection_sort();
	return in;
}

ostream& operator << (ostream& out, sorting& a){
	out<<"Data berada pada index ke-"<<a.pencarianBiner();
	return out;
}

int main(){
	sorting run;
	cin>>run;
	cout<<run;

    return 0;
}
