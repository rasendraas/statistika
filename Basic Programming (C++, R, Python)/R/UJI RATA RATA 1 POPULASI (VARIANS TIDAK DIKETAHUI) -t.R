# Population Mean with Unknown Variance

# Pilihan
# 1. Lower Tail (H1: Miu < Xbar) 
# 2. Upper Tail (H1: Miu > Xbar)
# 3. Two-tailed (H1: Miu tidak sama dengan Xbar)

Uji_Rata_Populasi = function(keputusan, xbar, miu0, sigma, alpha, n){
  
  t = (xbar - miu0) / (sigma/sqrt(n))
  
  if (keputusan == 1){
    pval = pt(t, df=n-1)
    t.alpha = qt(alpha, df=n-1)
    
    if (t <= t.alpha){
      cat ("t =",t,"\n")
      cat ("t-table =",t.alpha,"\n")
      print("Tolak H0")
    } else {
      cat ("t = ",t,"\n")
      cat ("t-table = ",t.alpha,"\n")
      print("Gagal tolak H0")
    }
    cat ("P-Value =",pval,"\n")
    cat ("Alpha =",alpha,"\n")
    
  } else if (keputusan == 2){
    pval = pt(t, df=n-1, lower.tail=FALSE)
    t.alpha = qt(1-alpha, df=n-1)
    
    if (t >= t.alpha){
      cat ("t =",t,"\n")
      cat ("t-table = ",t.alpha,"\n")
      print("Tolak H0")
    } else {
      cat ("t =",t,"\n")
      cat ("t-table = ",t.alpha,"\n")
      print("Gagal tolak H0")
    }
    cat ("P-Value =",pval,"\n")
    cat ("Alpha =",alpha,"\n")
    
  } else{
    
    t.alpha.kiri = qt(alpha/2, df=n-1)
    t.alpha.kanan = qt(1-alpha/2, df=n-1)
    
    if (t<t.alpha.kiri){
      pval = 2*pt(t, df=n-1)
    } else if (t>t.alpha.kiri && t<t.alpha.kanan){
      pval = 2*pt(t, df=n-1)
    } else{
      pval = 2*pt(t, df=n-1, lower.tail=FALSE)
    }
    
    if (t <= t.alpha.kiri || t >= t.alpha.kanan){
      cat ("t =",t,"\n")
      cat ("t-table =",t.alpha.kiri,t.alpha.kanan,"\n")
      print("Tolak H0")
    } else {
      cat ("t =",t,"\n")
      cat ("t-table =",t.alpha.kiri,t.alpha.kanan,"\n")
      print("Gagal tolak H0")
    }
    cat ("P-Value =",pval,"\n")
    cat ("Alpha =",alpha,"\n")
  }
}

Uji_Rata_Populasi(3, 14.6, 15.4, 2.5, 0.05, 35)