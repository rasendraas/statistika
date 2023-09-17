#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Banyaknya deret: " ;
	cin >> n;
	cout << "Masukkan data pada deret: ";
	int data[n];
	cout<<endl;
	for(int i=0;i<n;i++){
		cin >> data[i];	
	} 
	bool aritmatika = true, geometrika = true;
	for(int i=2;i<n;i++){
		if(data [i]-data[i-1]!=data[i-1]-data[i-2]){
			aritmatika=false;
		}
	}
	for(int i=2;i<n;i++){
		if(data [i]/data[i-1]!=data[i-1]/data[i-2]){
			geometrika=false;
		}
	}
	if(aritmatika){
		cout << "Deret Aritmatika" << endl;
	}
	else if(geometrika){
		cout << "Deret Geometri" << endl;
	}
	else{
		cout << "-1" << endl;
	}
}
