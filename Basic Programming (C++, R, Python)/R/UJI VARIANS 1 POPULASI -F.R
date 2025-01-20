# One - population Variance Test

# Pilihan
# 1. Lower Tail (H1: sigma^2 < sigma^20) 
# 2. Upper Tail (H1: sigma^2 > sigma^20)
# 3. Two-tailed (H1: sigma^2 tidak sama dengan sigma^20)

Uji_Varian_Populasi = function(keputusan, samples_variance, p_variance, alpha, n){
  
  chish = ((n-1)*samples_variance)/(p_variance)
  
  # Menggunakan kondisi P-VALUE dengan Alpha
  
  if (keputusan == 1){
    pval = pchisq(chish, df=n-1)
    chis.alpha = qchisq(alpha, df=n-1)
    
    if (pval <= alpha){
      cat ("Chi-square (Hitung) =",chish,"\n")
      cat ("Chi-square table =",chis.alpha,"\n")
      print("Tolak H0")
    } else {
      cat ("Chi-square (hitung) = ",chish,"\n")
      cat ("Chi-square table = ",chis.alpha,"\n")
      print("Gagal tolak H0")
    }
    cat ("P-Value =",pval,"\n")
    cat ("Alpha =",alpha,"\n")
    
  } else if (keputusan == 2){
    pval = pchisq(chish, df=n-1, lower.tail=FALSE)
    chis.alpha = qchisq(1-alpha, df=n-1)
    
    if (pval < alpha){
      cat ("Chi-square (Hitung) =",chish,"\n")
      cat ("Chi-square table =",chis.alpha,"\n")
      print("Tolak H0")
    } else {
      cat ("Chi-square (hitung) = ",chish,"\n")
      cat ("Chi-square table = ",chis.alpha,"\n")
      print("Gagal tolak H0")
    }
    cat ("P-Value =",pval,"\n")
    cat ("Alpha =",alpha,"\n")
    
  } else{
    
    chis.alpha.kiri = qchisq(alpha/2, df=n-1)
    chis.alpha.kanan = qchisq(1-alpha/2, df=n-1)
    
    if (chish<chis.alpha.kiri){
      pval = 2*pchisq(chish, df=n-1)
    } else if (chish>chis.alpha.kiri&&chish<chis.alpha.kanan){
      pval = 2*pchisq(chish, df=n-1)
    } else{
      pval = 2*pchisq(chish, df=n-1, lower.tail = FALSE)
    }
    
    if (chish <= chis.alpha.kiri || chish >= chis.alpha.kanan){
      cat ("Chi-square (Hitung) =",chish,"\n")
      cat ("Chi-square table =",chis.alpha.kiri,chis.alpha.kanan,"\n")
      print("Tolak H0")
    } else {
      cat ("Chi-square (Hitung) =",chish,"\n")
      cat ("Chi-square table =",chis.alpha.kiri,chis.alpha.kanan,"\n")
      print("Gagal tolak H0")
    }
    cat ("P-Value =",pval,"\n")
    cat ("Alpha =",alpha,"\n")
  }
}
Uji_Varian_Populasi(3, 55^2, 60^2, 0.05, 30)