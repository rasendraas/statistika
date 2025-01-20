function hitung() {
    // Mendapatkan data dari textarea
    const inputData = document.getElementById('dataInput').value;

    // Parsing data yang dimasukkan menjadi array
    const data = inputData.split(',').map(item => parseFloat(item.trim()));

    // Memanggil fungsi untuk menghitung outliers dan menampilkan hasilnya
    calculateOutliers(data);
}

function calculateOutliers(data) {
    // Hitung nilai-nilai yang diperlukan seperti q1, q3, iqr, lowerBound, dan upperBound
    const q1 = calculateQ1(data);
    const q3 = calculateQ3(data);
    const iqr = calculateIQR(data, q1, q3);
    const { lowerBound, upperBound } = calculateOutlierBounds(q1, q3, iqr);

    // Filter data untuk mendapatkan outliers
    const outliers = data.filter(value => value < lowerBound || value > upperBound);

    // Menampilkan hasil di tabel
    displayResults(outliers, q1, q3, iqr, lowerBound, upperBound);
}

function calculateQ1(data) {
    // Hitung kuartil pertama (Q1) dari data
    return math.quantileSeq(data, 0.25);
}

function calculateQ3(data) {
    // Hitung kuartil ketiga (Q3) dari data
    return math.quantileSeq(data, 0.75);
}

function calculateIQR(data, q1, q3) {
    // Hitung interquartile range dari data
    return q3 - q1;
}

function calculateOutlierBounds(q1, q3, iqr) {
    // Hitung batas bawah dan atas untuk menentukan outliers
    const lowerBound = q1 - 1.5 * iqr;
    const upperBound = q3 + 1.5 * iqr;
    return { lowerBound, upperBound };
}

function displayResults(outliers, q1, q3, iqr, lowerBound, upperBound) {
    // Mengisi tabel dengan hasil perhitungan outliers
    const outliersResult = document.getElementById('outliersResult');
    const q1Result = document.getElementById('q1Result');
    const q3Result = document.getElementById('q3Result');
    const iqrResult = document.getElementById('iqrResult');
    const lowerBoundResult = document.getElementById('lowerBoundResult');
    const upperBoundResult = document.getElementById('upperBoundResult');

    if (outliers.length === 0) {
        // Jika tidak ada outlier, tampilkan pesan khusus
        outliersResult.textContent = 'Tidak ada outlier';
        q1Result.textContent = q1.toFixed(2);
        q3Result.textContent = q3.toFixed(2);
        iqrResult.textContent = iqr.toFixed(2);
        lowerBoundResult.textContent = lowerBound.toFixed(2);
        upperBoundResult.textContent = upperBound.toFixed(2);
    } else {
        // Jika ada outlier, tampilkan nilai seperti biasa
        outliersResult.textContent = outliers.join(', ');
        q1Result.textContent = q1.toFixed(2);
        q3Result.textContent = q3.toFixed(2);
        iqrResult.textContent = iqr.toFixed(2);
        lowerBoundResult.textContent = lowerBound.toFixed(2);
        upperBoundResult.textContent = upperBound.toFixed(2);
    }
}
function downloadSyntaxPy() {
    const syntaxContent = `
def cari_outlier(data):
    kuartil1 = np.percentile(data, 25)
    kuartil3 = np.percentile(data, 75)
    interquartile = kuartil3 - kuartil1
    list_outlier = []
    for i in range(len(data)):
        if (data[i] < kuartil1 - 1.5*interquartile) or (data[i] > kuartil3 + 1.5*interquartile):
            list_outlier.append(data[i])
    print(list_outlier)
    if len(list_outlier) == 0:
        print("Tidak ada outlier")
    print ("Q1 = ",kuartil1)
    print ("Q3 = ",kuartil3)
    print ("IQR = ",interquartile)

test = [12, 15, 18,-2100, 20, 14, 22, 1000, 28, 30, 25, 40]
cari_outlier(test)`;
    // Membuat blob (Binary Large Object) dari isi file syntax
    const blob = new Blob([syntaxContent], { type: "text/plain" });

    // Membuat objek URL dari blob
    const url = window.URL.createObjectURL(blob);

    // Membuat elemen <a> untuk mengunduh file
    const a = document.createElement("a");
    a.href = url;
    a.download = "Cari Outliers (Py).txt";

    // Menambahkan elemen <a> ke dalam dokumen
    document.body.appendChild(a);

    // Simulasi klik otomatis pada elemen <a> untuk mengunduh file
    a.click();

    // Menghapus elemen <a> setelah selesai diunduh
    document.body.removeChild(a);

    // Membebaskan objek URL
    window.URL.revokeObjectURL(url);
}
function downloadSyntaxR() {
    const syntaxContent = `
cari_outlier <- function(data) {
    kuartil1 <- quantile(data, 0.25)
    kuartil3 <- quantile(data, 0.75)
    interquartile <- kuartil3 - kuartil1
    list_outlier <- data[data < kuartil1 - 1.5 * interquartile | data > kuartil3 + 1.5 * interquartile]
        
    cat("Outliers: ", list_outlier, "\n")
    if (length(list_outlier) == 0) {
        cat("Tidak ada outlier\n")
    }
    cat("Q1 = ", kuartil1, "\n")
    cat("Q3 = ", kuartil3, "\n")
    cat("IQR = ", interquartile, "\n")
}
      
test <- c(12, 15, 18, -2100, 20, 14, 22, 1000, 28, 30, 25, 40)
cari_outlier(test)`;

    // Membuat blob (Binary Large Object) dari isi file syntax
    const blob = new Blob([syntaxContent], { type: "text/plain" });

    // Membuat objek URL dari blob
    const url = window.URL.createObjectURL(blob);

    // Membuat elemen <a> untuk mengunduh file
    const a = document.createElement("a");
    a.href = url;
    a.download = "Cari Outliers (R).txt";

    // Menambahkan elemen <a> ke dalam dokumen
    document.body.appendChild(a);

    // Simulasi klik otomatis pada elemen <a> untuk mengunduh file
    a.click();

    // Menghapus elemen <a> setelah selesai diunduh
    document.body.removeChild(a);

    // Membebaskan objek URL
    window.URL.revokeObjectURL(url);
}