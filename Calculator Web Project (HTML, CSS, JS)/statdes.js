// File: statdes.js

function hitung() {
    // Mendapatkan data dari textarea
    const inputData = document.getElementById('dataInput').value;
    console.log('inputData:', inputData);

    // Parsing data yang dimasukkan menjadi array
    const data = inputData.split(',').map(item => parseFloat(item.trim()));
    console.log('data:', data);

    // Mendapatkan opsi (sample atau population)
    const option = document.getElementById('option').value.toLowerCase();
    console.log('option:', option);

    // Memanggil fungsi untuk menghitung statistik dan menampilkan hasilnya
    calculateStatistics(data, option);
}


function calculateStatistics(data, option) {
    let n, mean, median, mode_value, max_value, min_value, q1, q3, std_dev, variance, mean_abs_deviation, cv, skewness, kurtosis;

    // Tambahkan pengecekan jika data kosong
    if (!data || data.length === 0) {
        console.error('Data is empty.');
        return;
    }

    if (option === 'sample') {
        n = data.length;
        mean = calculateMean(data);
        median = calculateMedian(data);
        mode_value = calculateMode(data);
        max_value = Math.max(...data);
        min_value = Math.min(...data);
        q1 = calculatePercentile(data, 25);
        q3 = calculatePercentile(data, 75);
        std_dev = calculateStandardDeviationSample(data); // true for sample
        variance = calculateVarianceSample(data); // true for sample
        mean_abs_deviation = calculateMeanAbsoluteDeviation(data);
        cv = calculateCoefficientOfVariationSample(data); // true for sample
        skewness = calculateSkewnessSample(data); // true for sample
        kurtosis = calculateKurtosisSample(data); // true for sample
    } else {
        n = data.length;
        mean = calculateMean(data);
        median = calculateMedian(data);
        mode_value = calculateMode(data);
        max_value = Math.max(...data);
        min_value = Math.min(...data);
        q1 = calculatePercentile(data, 25);
        q3 = calculatePercentile(data, 75);
        std_dev = calculateStandardDeviationPopulation(data);
        variance = calculateVariancePopulation(data);
        mean_abs_deviation = calculateMeanAbsoluteDeviation(data);
        cv = calculateCoefficientOfVariationPopulation(data);
        skewness = calculateSkewnessPopulation(data);
        kurtosis = calculateKurtosisPopulation(data);
    }

    // Simpan hasil perhitungan dalam variabel
    const result = {
        n: n,
        mean: mean,
        median: median,
        mode_value: mode_value,
        max_value: max_value,
        min_value: min_value,
        q1: q1,
        q3: q3,
        std_dev: std_dev,
        variance: variance,
        mean_abs_deviation: mean_abs_deviation,
        cv: cv,
        skewness: skewness,
        kurtosis: kurtosis
    };

    // Tampilkan hasil perhitungan di tabel HTML
    displayResults(result);
}

function displayResults(result) {
    // Isi tabel dengan hasil perhitungan
    document.getElementById('nOutput').textContent = result.n;
    document.getElementById('meanOutput').textContent = result.mean.toFixed(8);
    document.getElementById('medianOutput').textContent = result.median;
    document.getElementById('modeOutput').textContent = result.mode_value;
    document.getElementById('maxOutput').textContent = result.max_value;
    document.getElementById('minOutput').textContent = result.min_value;
    document.getElementById('q1Output').textContent = result.q1;
    document.getElementById('q3Output').textContent = result.q3;
    document.getElementById('stdDevOutput').textContent = result.std_dev.toFixed(8);
    document.getElementById('varianceOutput').textContent = result.variance.toFixed(8);
    document.getElementById('madOutput').textContent = result.mean_abs_deviation.toFixed(8);
    document.getElementById('cvOutput').textContent = result.cv.toFixed(8);
    document.getElementById('skewnessOutput').textContent = result.skewness.toFixed(8);
    document.getElementById('kurtosisOutput').textContent = result.kurtosis.toFixed(8);
}

// Fungsi perhitungan statistik
function calculateMean(data) {
    return data.reduce((a, b) => a + b, 0) / data.length;
}

function calculateMedian(data) {
    const sortedData = [...data].sort((a, b) => a - b);
    const middle = Math.floor(sortedData.length / 2);

    if (sortedData.length % 2 === 0) {
        return (sortedData[middle - 1] + sortedData[middle]) / 2;
    } else {
        return sortedData[middle];
    }
}

function calculateMode(data) {
    const frequencyMap = {};

    // Hitung frekuensi masing-masing nilai
    data.forEach(value => {
        frequencyMap[value] = (frequencyMap[value] || 0) + 1;
    });

    // Temukan nilai dengan frekuensi tertinggi
    let maxFrequency = 0;
    let modes = [];

    for (const value in frequencyMap) {
        const frequency = frequencyMap[value];

        if (frequency > maxFrequency) {
            maxFrequency = frequency;
            modes = [value];
        } else if (frequency === maxFrequency) {
            modes.push(value);
        }
    }

    return modes.length === data.length ? '-' : modes.join(', ');
}

function calculatePercentile(data, percentile) {
    const sortedData = [...data].sort((a, b) => a - b);
    const index = Math.ceil((percentile / 100) * sortedData.length);
    return sortedData[index - 1];
}

function calculateStandardDeviationSample(data) {
    const mean = calculateMean(data);
    const squaredDifferences = data.map(x => (x - mean) ** 2);
    const sumSquaredDiff = squaredDifferences.reduce((a, b) => a + b, 0);
    const divisor = data.length - 1;

    return Math.sqrt(sumSquaredDiff / divisor);
}

function calculateStandardDeviationPopulation(data) {
    const mean = calculateMean(data);
    const squaredDifferences = data.map(x => (x - mean) ** 2);
    const sumSquaredDiff = squaredDifferences.reduce((a, b) => a + b, 0);
    const divisor = data.length;

    return Math.sqrt(sumSquaredDiff / divisor);
}

function calculateVarianceSample(data) {
    return calculateStandardDeviationSample(data) ** 2;
}

function calculateVariancePopulation(data) {
    return calculateStandardDeviationPopulation(data) ** 2;
}

function calculateCoefficientOfVariationSample(data) {
    const mean = calculateMean(data);
    const stdDev = calculateStandardDeviationSample(data);

    return (stdDev / mean);
}

function calculateCoefficientOfVariationPopulation(data) {
    const mean = calculateMean(data);
    const stdDev = calculateStandardDeviationPopulation(data);

    return (stdDev / mean);
}

function calculateMeanAbsoluteDeviation(data) {
    const mean = calculateMean(data);
    return data.reduce((sum, value) => sum + Math.abs(value - mean), 0) / data.length;
}

function calculateSkewnessSample(data) {
    const mean = calculateMean(data);
    const n = data.length;
    const stdDevSample = calculateStandardDeviationSample(data);
    const skewness = (n / ((n - 1) * (n - 2))) * data.reduce((sum, value) => sum + ((value - mean) / stdDevSample) ** 3, 0);

    return skewness;
}

function calculateSkewnessPopulation(data) {
    const mean = calculateMean(data);
    const n = data.length;
    const stdDevPopulation = calculateStandardDeviationPopulation(data);
    const skewness = data.reduce((sum, value) => sum + Math.pow((value - mean) / stdDevPopulation, 3), 0) / n;

    return skewness;
}


function calculateKurtosisSample(data) {
    const mean = calculateMean(data);
    const n = data.length;
    const stdDevSample = calculateStandardDeviationSample(data);
    const kurtosis = ((n*(n+1))/((n-1)*(n-2)*(n-3))) * data.reduce((sum, value) => sum + ((value - mean) / stdDevSample) ** 4, 0);

    return kurtosis;
}

function calculateKurtosisPopulation(data) {
    const mean = calculateMean(data);
    const n = data.length;
    const stdDevPopulation = calculateStandardDeviationPopulation(data);
    const kurtosis = data.reduce((sum, value) => sum + Math.pow((value - mean) / stdDevPopulation, 4), 0) / n;
    
    return kurtosis;
}
function downloadSyntaxPy() {
    const syntaxContent = `
import pandas as pd
import numpy as np
from scipy.stats import mode
    
def statdes(data,pilihan):
    if pilihan == 'Sampel':
        n = len(data)
        mean = np.mean(data)
        median = np.median(data)
        if mode(data)[1] > 1:
            mode_value = mode(data)[0]
        else:
            mode_value = "-"
        max_value = np.max(data)
        min_value = np.min(data)
        q1 = np.percentile(data, 25)
        q3 = np.percentile(data, 75)
        std_dev = np.std(data, ddof = 1)
        variance = np.var(data, ddof = 1)
        mean_abs_deviation = np.mean(np.abs(data - mean))
        cv = (std_dev / mean)
        skewness = (n/((n-1)*(n-2)))*np.sum(((data-mean)/std_dev)**3)
        kurtosis = ((n*(n+1))/((n-1)*(n-2)*(n-3)))*np.sum(((data-mean)/std_dev)**4)
    else:
        n = len(data)
        mean = np.mean(data)
        median = np.median(data)
        if mode(data)[1] > 1:
            mode_value = mode(data)[0]
        else:
            mode_value = "-"
        max_value = np.max(data)
        min_value = np.min(data)
        q1 = np.percentile(data, 25)
        q3 = np.percentile(data, 75)
        std_dev = np.std(data)
        variance = np.var(data)
        mean_abs_deviation = np.mean(np.abs(data - mean))
        cv = (std_dev / mean)
        skewness = np.sum((data-mean)**3)/(n*(std_dev**3))
        kurtosis = np.sum((data-mean)**4)/(n*(std_dev**4))
    print("Banyak Data:", n)
    print("Mean:", mean)
    print("Median:", median)
    print("Modus:", mode_value)
    print("Maksimum:", max_value)
    print("Minimum:", min_value)
    print("Q1:", q1)
    print("Q3:", q3)
    print("Standar Deviasi:", std_dev)
    print("Varians:", variance)
    print("Simpangan Rata-rata (SR):", mean_abs_deviation)
    print("Koefisien Variasi (CV):", cv)
    print("Kemencengan (Skewness):", skewness)
    print("Keruncingan (Kurtosis):", kurtosis)
    
d = np.array([11, 23, 29, 80.5, 100, 123])
statdes(d, "Sampel")`;
    // Membuat blob (Binary Large Object) dari isi file syntax
    const blob = new Blob([syntaxContent], { type: "text/plain" });

    // Membuat objek URL dari blob
    const url = window.URL.createObjectURL(blob);

    // Membuat elemen <a> untuk mengunduh file
    const a = document.createElement("a");
    a.href = url;
    a.download = "Statistika Deskriptif (Py).txt";

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
Modus <- function(x) {
    tbl <- table(x)
    mode_value <- as.numeric(names(tbl[tbl == max(tbl)]))
    if (length(mode_value) > 1) {
        mode_value <- "-"
    }
    return(mode_value)
}
      
statdes <- function(data, pilihan) {
    if (pilihan == 'Sampel') {
        n <- length(data)
        mean_value <- mean(data)
        median_value <- median(data)
        mode_value <- Modus(data)
        max_value <- max(data)
        min_value <- min(data)
        q1 <- quantile(data, 0.25)
        q3 <- quantile(data, 0.75)
        std_dev <- sd(data)
        variance <- var(data)
        mean_abs_deviation <- mean(abs(data - mean_value))
        cv <- (std_dev / mean_value)
        skewness <- (n/((n-1)*(n-2))) * sum(((data-mean_value)/std_dev)^3)
        kurtosis <- ((n*(n+1))/((n-1)*(n-2)*(n-3))) * sum(((data-mean_value)/std_dev)^4)
    } else {
        n <- length(data)
        mean_value <- mean(data)
        median_value <- median(data)
        mode_value <- Modus(data)
        max_value <- max(data)
        min_value <- min(data)
        q1 <- quantile(data, 0.25)
        q3 <- quantile(data, 0.75)
        std_dev <- sd(data)
        variance <- var(data)
        mean_abs_deviation <- mean(abs(data - mean_value))
        cv <- (std_dev / mean_value)
        skewness <- sum((data-mean_value)^3)/(n*(std_dev^3))
        kurtosis <- sum((data-mean_value)^4)/(n*(std_dev^4))
    }
        
    cat("Banyak Data:", n, "\n")
    cat("Mean:", mean_value, "\n")
    cat("Median:", median_value, "\n")
    cat("Modus:", mode_value, "\n")
    cat("Maksimum:", max_value, "\n")
    cat("Minimum:", min_value, "\n")
    cat("Q1:", q1, "\n")
    cat("Q3:", q3, "\n")
    cat("Standar Deviasi:", std_dev, "\n")
    cat("Varians:", variance, "\n")
    cat("Simpangan Rata-rata (SR):", mean_abs_deviation, "\n")
    cat("Koefisien Variasi (CV):", cv, "\n")
    cat("Kemencengan (Skewness):", skewness, "\n")
    cat("Keruncingan (Kurtosis):", kurtosis, "\n")
}
      
d <- c(11, 23, 29, 80.5, 100, 123)
statdes(d, "Sampel")`;

    // Membuat blob (Binary Large Object) dari isi file syntax
    const blob = new Blob([syntaxContent], { type: "text/plain" });

    // Membuat objek URL dari blob
    const url = window.URL.createObjectURL(blob);

    // Membuat elemen <a> untuk mengunduh file
    const a = document.createElement("a");
    a.href = url;
    a.download = "Statistika Deskriptif (R).txt";

    // Menambahkan elemen <a> ke dalam dokumen
    document.body.appendChild(a);

    // Simulasi klik otomatis pada elemen <a> untuk mengunduh file
    a.click();

    // Menghapus elemen <a> setelah selesai diunduh
    document.body.removeChild(a);

    // Membebaskan objek URL
    window.URL.revokeObjectURL(url);
}