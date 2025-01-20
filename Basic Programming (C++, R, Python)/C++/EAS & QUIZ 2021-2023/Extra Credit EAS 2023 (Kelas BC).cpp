#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

float Similarity(string seq1, string seq2) {
    float score = 0;
    for (int i = 0; i < seq1.length(); ++i) {
        if (seq1[i] == seq2[i]) {
            score += 1.0;  // pasangan nukleotida sama
        } 
		else if ((seq1[i] == 'C' && seq2[i] == 'G') || (seq1[i] == 'G' && seq2[i] == 'C')) {
            score += 0.6;  // pasangan (C, G) atau (G, C)
        }
		else if ((seq1[i] == 'A' && seq2[i] == 'T') || (seq1[i] == 'T' && seq2[i] == 'A')) {
            score += 0.2;  // pasangan (A, T) atau (T, A)
        }
		else if (seq1[i] == '-' || seq2[i] == '-') {
            score += -0.5;  // pasangan yang mengandung (-)
        }
		else {
            score += 0.0;  // pasangan selain di atas
        }
    }
    return score;
}


int main(){
	
	// KODE NOMOR 1
	/**************
	string baris;
	ifstream miles_morales;
	miles_morales.open("haplotype.txt");
	
	while(getline(miles_morales, baris)){
		cout<<baris<<endl;
	} ***************/
	
	
	// KODE NOMOR 2
	string baris;
	vector<string> DNA;
	ifstream peter_parker;
	peter_parker.open("haplotype.txt");
	
	while(getline(peter_parker, baris)){
		DNA.push_back(baris);
	}
	
	int n = DNA.size();
	
	cout<<"Nomor 2 : Import Data (Vector)"<<endl;
	cout<<"-----------------------------------------"<<endl;
	for(int i=0; i<n; i++){
		cout<<DNA[i]<<endl;
	}
	cout<<endl;
	
	// KODE NOMOR 3
	string Array_1[n], Array_2[n];
	int indeks_1 = 0, indeks_2 = 0;
	
	for(int i=0; i<n; i++){
		if (i==0){
			Array_1[indeks_1] = DNA[i];
			indeks_1++;
		}
		else if (i%2!=0){
			Array_2[indeks_2] = DNA[i];
			indeks_2++;
		}
		else{
			Array_1[indeks_1] = DNA[i];
			indeks_1++;
		}
		
	}
	cout<<"Nomor 3 : Filter Data pada Array"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"Array 1 = "<<endl;
	for(int i=0; i<indeks_1; i++){
		cout<<Array_1[i]<<endl;
	}
	cout<<endl;
	cout<<"Array 2 = "<<endl;
	for(int i=0; i<indeks_2; i++){
		cout<<Array_2[i]<<endl;
	}
	cout<<endl;
	// KODE NOMOR 4
	float matriks_s [8][8];
	cout<<"Nomor 4 : Matriks Similarity"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"Matriks Similarity = "<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			matriks_s [i][j] = Similarity(Array_2[i],Array_2[j]);
			cout<<matriks_s[i][j]<<"\t";
		}
		cout<<endl;
	}
	// KODE NOMOR 5
	float Skor_maks;
    int Maks_Bar, Maks_Kol;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (matriks_s[i][j] > matriks_s[0][1] && matriks_s[i][j] < 40) { // Loop ini akan terus mencari nilai tertinggi
                Skor_maks = matriks_s[i][j];
                Maks_Bar = i;
                Maks_Kol = j;
            }
        }
    }
    cout << endl;
    cout<<"Nomor 5 : Skor tertinggi"<<endl;
	cout<<"-----------------------------------------"<<endl;
    cout << "Skor similarity tertinggi: " << Skor_maks << endl;
    cout << "Pasangan sekuens DNA yang menghasilkan skor tertinggi: " << endl;
    cout << "Seq1: " << Array_2[Maks_Bar] << endl;
    cout << "Seq2: " << Array_2[Maks_Kol] << endl;
    
    
    // KODE NOMOR 6
    // MENCARI SKOR TERTINGGI DENGAN Array_2[4]
    cout << endl;
    cout<<"Nomor 6 : 3 Seq yang mirip dengan SRX5"<<endl;
	cout<<"-----------------------------------------"<<endl;
    cout<<"Matriks Similarity SRX5 = "<<endl;
    float matriks_srx5[8];
	for(int i=0; i<8; i++){
		matriks_srx5[i] = Similarity(Array_2[4],Array_2[i]);
		cout<<matriks_srx5[i]<<"\t";
	}
	cout<<endl<<endl;
	
	float maks = 0;
	int p_1, p_2, p_3;
	
	for(int i=0; i<8; i++){
		if(matriks_srx5[i] > maks &&  matriks_srx5[i] != 40){
			p_1 = i;
			maks = matriks_srx5[i];
		}
	}
	
	float maks1 = 0;
	for(int i=0; i<8; i++){
		if(matriks_srx5[i] > maks1 && matriks_srx5[i] != 40 && matriks_srx5[i] != maks){
			p_2 = i;
			maks1 = matriks_srx5[i];
		}
	}
	
	float maks2 = 0;
	for(int i=0; i<8; i++){
		if(matriks_srx5[i] > maks2 && matriks_srx5[i] != 40 && matriks_srx5[i] != maks && matriks_srx5[i] != maks1){
			p_3 = i;
			maks2 = matriks_srx5[i];
		}
	}
	ofstream UploadFile;
	UploadFile.open("haplotype1.txt");
	
	
	cout<<"3 Sequences yang mirip dengan Seq SRX5 = "<<endl;
	cout<<"SRX5 = "<<Array_2[4]<<endl;
	cout<<"---------------------------------------------------"<<endl;
	cout<<"Yang termirip pertama dengan SRX5 dilihat dari skor similairty :"<<endl;
	cout<<"Skor = "<<maks<<endl;
	cout<<"Dengan DNA Sequence : "<<Array_2[p_1]<<endl;
	cout<<endl;
	cout<<"Yang termirip kedua dengan SRX5 dilihat dari skor similairty :"<<endl;
	cout<<"Skor = "<<maks1<<endl;
	cout<<"Dengan DNA Sequence : "<<Array_2[p_2]<<endl;
	cout<<endl;
	cout<<"Yang termirip ketiga dengan SRX5 dilihat dari skor similairty :"<<endl;
	cout<<"Skor = "<<maks2<<endl;
	cout<<"Dengan DNA Sequence : "<<Array_2[p_3]<<endl;
	
	UploadFile<<"3 Sequences yang mirip dengan Seq SRX5 = "<<endl;
	UploadFile<<"SRX5 = "<<Array_2[4]<<endl;
	UploadFile<<"---------------------------------------------------"<<endl;
	UploadFile<<"Yang termirip pertama dengan SRX5 dilihat dari skor similairty :"<<endl;
	UploadFile<<"Skor = "<<maks<<endl;
	UploadFile<<"Dengan DNA Sequence : "<<Array_2[p_1]<<endl;
	UploadFile<<endl;
	UploadFile<<"Yang termirip kedua dengan SRX5 dilihat dari skor similairty :"<<endl;
	UploadFile<<"Skor = "<<maks1<<endl;
	UploadFile<<"Dengan DNA Sequence : "<<Array_2[p_2]<<endl;
	UploadFile<<endl;
	UploadFile<<"Yang termirip ketiga dengan SRX5 dilihat dari skor similairty :"<<endl;
	UploadFile<<"Skor = "<<maks2<<endl;
	UploadFile<<"Dengan DNA Sequence : "<<Array_2[p_3]<<endl;
	
	UploadFile.close();
	
}

