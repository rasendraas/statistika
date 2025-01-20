document.addEventListener("DOMContentLoaded", function () {
    const variableCountElement = document.getElementById("variableCount");
    const incrementButton = document.getElementById("incrementButton");
    const decrementButton = document.getElementById("decrementButton");
    const inputDataButton = document.getElementById("inputDataButton");
    const inputContainer = document.getElementById("inputContainer");
    const correlationResultContainer = document.getElementById("correlationResult");

    let variableCount = 2;
    const maxVariableCount = 10;
    let data = {};
    let lastCorrelationMatrix = [];

    updateVariableCount();
    initializeInputFields();

    incrementButton.addEventListener("click", function () {
        if (variableCount < maxVariableCount) {
            variableCount++;
            hideMaxVariableWarning();
            updateVariableCount();
            createInputField(variableCount);
        } else {
            showMaxVariableWarning();
        }
    });

    decrementButton.addEventListener("click", function () {
        if (variableCount > 2) {
            variableCount--;
            hideMaxVariableWarning();
            updateVariableCount();
            removeLastInputField();
        }
    });

    inputDataButton.addEventListener("click", function () {
        collectInputData();
        calculateCorrelationMatrix();
    });

    function updateVariableCount() {
        variableCountElement.textContent = variableCount;
    }

    function showMaxVariableWarning() {
        maxVariableWarning.classList.remove("hide");
    }

    function hideMaxVariableWarning() {
        maxVariableWarning.classList.add("hide");
    }

    function initializeInputFields() {
        for (let i = 1; i <= variableCount; i++) {
            createInputField(i);
        }
    }

    function createInputField(index) {
        const inputField = document.createElement("div");
        inputField.classList.add("variable-input");

        const label = document.createElement("label");
        label.textContent = "Variabel " + index;

        const inputElement = document.createElement("textarea");
        inputElement.setAttribute("type", "text");
        inputElement.setAttribute("id", "variable" + index);
        inputElement.setAttribute("placeholder", "(format : 23, 11, 20.5, 74, 52, 24.2)");

        inputField.appendChild(label);
        inputField.appendChild(inputElement);
        inputContainer.appendChild(inputField);
    }

    function removeLastInputField() {
        const lastInputField = inputContainer.lastElementChild;
        if (lastInputField) {
            inputContainer.removeChild(lastInputField);
        }
    }

    function collectInputData() {
        data = {};

        let dataLength = null;

        for (let i = 1; i <= variableCount; i++) {
            const variableName = "Variabel " + i;
            const inputValue = document.getElementById("variable" + i).value.trim();

            if (inputValue === "") {
                alert("Isikan data tiap variabel yang ditentukan");
                return;
            }

            const dataArray = inputValue.split(',').map(item => parseFloat(item.trim()));

            if (dataLength === null) {
                dataLength = dataArray.length;
            } else if (dataLength !== dataArray.length) {
                alert("Jumlah data tiap variabel harus sama.");
                return;
            }

            data[variableName] = dataArray;
        }
    }

    function calculateCorrelationMatrix() {
        const variables = Object.keys(data);
        const matrix = [];

        for (const variable1 of variables) {
            const row = [];
            for (const variable2 of variables) {
                if (variable1 === variable2) {
                    row.push(1);
                } else {
                    const correlationValue = calculateCorrelation(data[variable1], data[variable2]);
                    row.push(correlationValue);
                }
            }
            matrix.push(row);
        }

        lastCorrelationMatrix = matrix;
        displayCorrelationMatrix();
    }

    function calculateCorrelation(data1, data2) {
        function mean(data) {
            return data.reduce((sum, value) => sum + value, 0) / data.length;
        }

        function standardDeviation(data) {
            const meanValue = mean(data);
            const squaredDifferences = data.map(value => Math.pow(value - meanValue, 2));
            const sumSquaredDiff = squaredDifferences.reduce((sum, value) => sum + value, 0);
            return Math.sqrt(sumSquaredDiff / data.length);
        }

        function correlation(data1, data2) {
            const mean1 = mean(data1);
            const mean2 = mean(data2);
            const stdDev1 = standardDeviation(data1);
            const stdDev2 = standardDeviation(data2);

            const numerator = data1.reduce((sum, value, index) => sum + (value - mean1) * (data2[index] - mean2), 0);
            const denominator = stdDev1 * stdDev2;

            return (numerator / denominator)/10;
        }

        return correlation(data1, data2);
    }

    function displayCorrelationMatrix() {
        correlationResultContainer.innerHTML = "";
    
        let resultHTML = "<table>";
        const variables = Object.keys(data);
    
        resultHTML += "<tr><td class='corner-cell'></td>";
        for (let i = 0; i < variables.length; i++) {
            resultHTML += "<th>Var " + (i + 1) + "</th>";
        }
        resultHTML += "</tr>";
    
        for (let i = 0; i < lastCorrelationMatrix.length; i++) {
            resultHTML += "<tr>";
    
            resultHTML += "<th>Var " + (i + 1) + "</th>";
    
            for (let j = 0; j < lastCorrelationMatrix[i].length; j++) {
                let cellContent = lastCorrelationMatrix[i][j].toFixed(5);
    
                let cellClass = (i > j) ? 'lower-triangle-cell' : '';
    
                if (i === 0 && j === 0) {
                    cellContent = "<span class='dark-cell " + cellClass + "'>" + cellContent + "</span>";
                }
    
                resultHTML += "<td class='" + cellClass + "'>" + cellContent + "</td>";
            }
    
            resultHTML += "</tr>";
        }
        resultHTML += "</table>";
    
        correlationResultContainer.innerHTML = resultHTML;
    }
});
function downloadSyntaxPy() {
    const syntaxContent = `
def korelasi (data1, data2):
    def rata2(data):
        hasil = 0
        for i in range (len(data)):
            hasil += data[i]
        hasil /= len(data)
        return hasil
    def standardeviasi(data):
        hasil_std = 0
        for i in range(len(data)):
            hasil_std += (data[i] - rata2(data))**2
        hasil_std = hasil_std**0.5
        return hasil_std
    def standardeviasi_xy(data1, data2):
        hasil_stdxy = 0
        for i in range(len(data1)):
            hasil_stdxy += (data1[i]-rata2(data1))*(data2[i]-rata2(data2))
        return hasil_stdxy

    hasil_korelasi = standardeviasi_xy(data1, data2)/(standardeviasi(data1)*standardeviasi(data2))
    return hasil_korelasi

import numpy as np
coba1 = [25, 30, 35, 40, 28, 22, 15, 18, 25, 32]
coba2 = [18, 22, 16, 20, 24, 30, 28, 25, 26, 35]
coba3 = [12, 15, 18, 20, 14, 22, 28, 30, 25, 40]
coba4 = [32, 28, 25, 30, 35, 18, 20, 24, 22, 15]
coba5 = [22, 24, 28, 30, 26, 40, 35, 18, 20, 24]
c = np.column_stack((coba1,coba2,coba3,coba4,coba5))
kolom = c.shape[1]

matriks_korelasi = np.zeros((kolom,kolom))

for i in range(kolom):
    for j in range(kolom):
        if i==j:
            matriks_korelasi[i,j] = 1
        else:
            matriks_korelasi[i,j] = korelasi(c[:,i],c[:,j])

print(matriks_korelasi)`;
    // Membuat blob (Binary Large Object) dari isi file syntax
    const blob = new Blob([syntaxContent], { type: "text/plain" });

    // Membuat objek URL dari blob
    const url = window.URL.createObjectURL(blob);

    // Membuat elemen <a> untuk mengunduh file
    const a = document.createElement("a");
    a.href = url;
    a.download = "Matriks Korelasi (Py).txt";

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
rata2 <- function(data) {
    return(mean(data))
}
        
standardeviasi <- function(data) {
    return(sqrt(sum((data - rata2(data))^2) / length(data)))
}
        
standardeviasi_xy <- function(data1, data2) {
    return(sum((data1 - rata2(data1)) * (data2 - rata2(data2))))
}
        
korelasi <- function(data1, data2) {
    return(standardeviasi_xy(data1, data2) / (standardeviasi(data1) * standardeviasi(data2)))
}
        
coba1 <- c(25, 30, 35, 40, 28, 22, 15, 18, 25, 32)
coba2 <- c(18, 22, 16, 20, 24, 30, 28, 25, 26, 35)
coba3 <- c(12, 15, 18, 20, 14, 22, 28, 30, 25, 40)
coba4 <- c(32, 28, 25, 30, 35, 18, 20, 24, 22, 15)
coba5 <- c(22, 24, 28, 30, 26, 40, 35, 18, 20, 24)
        
c <- cbind(coba1, coba2, coba3, coba4, coba5)
kolom <- ncol(c)
        
matriks_korelasi <- matrix(0, nrow = kolom, ncol = kolom)
        
for (i in 1:kolom) {
    for (j in 1:kolom) {
        if (i == j) {
            matriks_korelasi[i, j] <- 1
        } else {
            matriks_korelasi[i, j] <- korelasi(c[, i], c[, j])
        }
    }
}
        
print(matriks_korelasi)`;

    // Membuat blob (Binary Large Object) dari isi file syntax
    const blob = new Blob([syntaxContent], { type: "text/plain" });

    // Membuat objek URL dari blob
    const url = window.URL.createObjectURL(blob);

    // Membuat elemen <a> untuk mengunduh file
    const a = document.createElement("a");
    a.href = url;
    a.download = "Matriks Korelasi (R).txt";

    // Menambahkan elemen <a> ke dalam dokumen
    document.body.appendChild(a);

    // Simulasi klik otomatis pada elemen <a> untuk mengunduh file
    a.click();

    // Menghapus elemen <a> setelah selesai diunduh
    document.body.removeChild(a);

    // Membebaskan objek URL
    window.URL.revokeObjectURL(url);
}