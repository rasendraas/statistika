#include <iostream>
#include <math.h>

using namespace std;

float RumusSoal(float a){
	return (1.0/(a+1));
}

int main(){
	
	float a, hasil[20];
	cout<<"Masukkan nilai a = ";
	cin>>a;
	for(int i=0; i<17; i++){
		a = RumusSoal(a);
		hasil[i] = a;
		cout<<"Iterasi ke-"<<i+1<<" = "<<hasil[i]<<endl;
	}
	
	float epsilon = 1e-6; // Nilai epsilon yang diizinkan

    if (abs(hasil[15] - hasil[16]) < epsilon) {
        cout << "Maka nilai yang akan terus sama adalah " << hasil[15] << endl;
    }
}
