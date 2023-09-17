#include <iostream>

using namespace std;

int main(){
	
	
	int n;
	cout<<"Masukkan banyak deret : ";
	cin>>n;
	cout<<"_________________________"<<endl;
	cout<<endl;
	
	for(int i = 1; i<=n; i++){
		int faktorial=1;
		for(int j = 1; j<=i; j++){
			faktorial *= j;
			cout<<faktorial<<" ";
		}
		cout<<endl;
	}
}
