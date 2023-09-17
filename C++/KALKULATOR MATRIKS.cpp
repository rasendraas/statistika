#include <iostream>
using namespace std;

int main() {
    char pil2;
    do {
        int pil;

        cout << "Program Operasi Matriks" << endl;
        cout << "------------------------" << endl;
        cout << "1. Penjumlahan & Pengurangan" << endl;
        cout << "2. Perkalian Matriks" << endl;
        cout << "3. Transpose" << endl;
        cout << "-----------------------------" << endl;
        cout << "Pilihan : ";
        cin >> pil;
        cout << "------------" << endl;

        switch (pil) {
            case 1: {
                int baris, kolom;
                cout << "Masukkan banyaknya baris = ";
                cin >> baris;
                cout << "Masukkan banyaknya kolom = ";
                cin >> kolom;
                cout << "----------------------------" << endl;

                if (baris != kolom) {
                    cout << "Ordo matriks tidak sama" << endl;
                } else {
                    float matriksA[baris][kolom];
                    float matriksB[baris][kolom];
                    float hasil_jumlah[baris][kolom];
                    float hasil_kurang[baris][kolom];

                    cout << "Masukkan elemen matriks A:" << endl;
                    for (int i = 0; i < baris; i++) {
                        for (int j = 0; j < kolom; j++) {
                            cout << "Elemen matriks A[" << i + 1 << "][" << j + 1 << "] = ";
                            cin >> matriksA[i][j];
                        }
                    }

                    cout << "Masukkan elemen matriks B:" << endl;
                    for (int i = 0; i < baris; i++) {
                        for (int j = 0; j < kolom; j++) {
                            cout << "Elemen matriks B[" << i + 1 << "][" << j + 1 << "] = ";
                            cin >> matriksB[i][j];
                        }
                    }

                    for (int i = 0; i < baris; i++) {
                        for (int j = 0; j < kolom; j++) {
                            hasil_jumlah[i][j] = matriksA[i][j] + matriksB[i][j];
                            hasil_kurang[i][j] = matriksA[i][j] - matriksB[i][j];
                        }
                    }

                    cout << "Hasil penjumlahan matriks" << endl;
                    for (int i = 0; i < baris; i++) {
                        for (int j = 0; j < kolom; j++) {
                            cout << " " << hasil_jumlah[i][j] << "  ";
                        }
                        cout << endl;
                    }

                    cout << "Hasil pengurangan matriks" << endl;
                    for (int i = 0; i < baris; i++) {
                        for (int j = 0; j < kolom; j++) {
                            cout << " " << hasil_kurang[i][j] << "  ";
                        }
                        cout << endl;
                    }
                }
                break;
            }

            case 2: {
                int barisA, KolomA_BarisB, KolomB;
                cout << "Masukkan banyak baris matriks A = ";
                cin >> barisA;
                cout << "Masukkan banyak kolom matriks A & baris matriks B = ";
                cin >> KolomA_BarisB;
                cout << "Masukkan banyak kolom matriks B = ";
                cin >> KolomB;
                cout << "--------------------------------------------------------" << endl;

                if (KolomA_BarisB != KolomB) {
                    cout << "Kolom matriks A & baris matriks B tidak cocok untuk perkalian" << endl;
                } else {
                    float matriksA[barisA][KolomA_BarisB];
                    float matriksB[KolomA_BarisB][KolomB];
                    float hasilPerkalian[barisA][KolomB];

                    cout << "Masukkan elemen matriks A:" << endl;
                    for (int i = 0; i < barisA; i++) {
                        for (int j = 0; j < KolomA_BarisB; j++) {
                            cout << "Elemen matriks A[" << i + 1 << "][" << j + 1 << "] = ";
                            cin >> matriksA[i][j];
                        }
                    }

                    cout << "Masukkan elemen matriks B:" << endl;
                    for (int i = 0; i < KolomA_BarisB; i++) {
                        for (int j = 0; j < KolomB; j++) {
                            cout << "Elemen matriks B[" << i + 1 << "][" << j + 1 << "] = ";
                            cin >> matriksB[i][j];
                        }
                    }

                    for (int i = 0; i < barisA; i++) {
                        for (int j = 0; j < KolomB; j++) {
                            hasilPerkalian[i][j] = 0;
                            for (int k = 0; k < KolomA_BarisB; k++) {
                                hasilPerkalian[i][j] += matriksA[i][k] * matriksB[k][j];
                            }
                        }
                    }

                    cout << "Hasil perkalian matriks:" << endl;
                    for (int i = 0; i < barisA; i++) {
                        for (int j = 0; j < KolomB; j++) {
                            cout << hasilPerkalian[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;
            }

            case 3: {
                int barisTrans, kolomTrans;
                cout << "Masukkan banyaknya baris matriks = ";
                cin >> barisTrans;
                cout << "Masukkan banyaknya kolom matriks = ";
                cin >> kolomTrans;
                cout << "----------------------------------" << endl;

                float matriksTrans[barisTrans][kolomTrans];
                float transpose[kolomTrans][barisTrans];

                cout << "Masukkan elemen matriks:" << endl;
                for (int i = 0; i < barisTrans; i++) {
                    for (int j = 0; j < kolomTrans; j++) {
                        cout << "Elemen matriks[" << i + 1 << "][" << j + 1 << "] = ";
                        cin >> matriksTrans[i][j];
                    }
                }

                for (int i = 0; i < kolomTrans; i++) {
                    for (int j = 0; j < barisTrans; j++) {
                        transpose[i][j] = matriksTrans[j][i];
                    }
                }

                cout << "Hasil transpose matriks:" << endl;
                for (int i = 0; i < kolomTrans; i++) {
                    for (int j = 0; j < barisTrans; j++) {
                        cout << transpose[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
        }

        cout << "Apakah ingin kembali ke pilihan awal? (y/t)" << endl;
        cout << "Pilihan : ";
        cin >> pil2;
    } while (pil2 == 'y' || pil2 == 'Y');

    return 0;
}
