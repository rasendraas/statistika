# Population Mean with Known Variance

# Pilihan
# 1. Lower Tail (H1: Miu < Xbar) 
# 2. Upper Tail (H1: Miu > Xbar)
# 3. Two-tailed (H1: Miu tidak sama dengan Xbar)

Uji_Rata_Populasi = function(keputusan, xbar, miu0, sigma, alpha, n){
  
  z = (xbar - miu0) / (sigma/sqrt(n))
  
  if (keputusan == 1){
    pval = pnorm(z)
    z.alpha = qnorm(alpha)
    
    if (z <= z.alpha){
      cat ("Z =",z,"\n")
      cat ("Z-table =",z.alpha,"\n")
      print("Tolak H0")
    } else {
      cat ("Z = ",z,"\n")
      cat ("Z-table = ",z.alpha,"\n")
      print("Gagal tolak H0")
    }
    cat ("P-Value =",pval,"\n")
    cat ("Alpha =",alpha,"\n")
    
  } else if (keputusan == 2){
    pval = pnorm(z, lower.tail=FALSE)
    z.alpha = qnorm(1-alpha)
    
    if (z >= z.alpha){
      cat ("Z =",z,"\n")
      cat ("Z-table = ",z.alpha,"\n")
      print("Tolak H0")
    } else {
      cat ("Z =",z,"\n")
      cat ("Z-table = ",z.alpha,"\n")
      print("Gagal tolak H0")
    }
    cat ("P-Value =",pval,"\n")
    cat ("Alpha =",alpha,"\n")
    
  } else{
    
    z.alpha.kiri = qnorm(alpha/2)
    z.alpha.kanan = qnorm(1-alpha/2)
    
    if (z<z.alpha.kiri){
      pval = 2*pnorm(z)
    } else if (z>z.alpha.kiri && z<z.alpha.kanan){
      pval = 2*pnorm(z)
    } else{
      pval = 2*pnorm(z, lower.tail=FALSE)
    }
    
    if (z <= z.alpha.kiri || z >= z.alpha.kanan){
      cat ("Z =",z,"\n")
      cat ("Z-table =",z.alpha.kiri,z.alpha.kanan,"\n")
      print("Tolak H0")
    } else {
      cat ("Z =",z,"\n")
      cat ("Z-table =",z.alpha.kiri,z.alpha.kanan,"\n")
      print("Gagal tolak H0")
    }
    cat ("P-Value =",pval,"\n")
    cat ("Alpha =",alpha,"\n")
  }
}

Uji_Rata_Populasi(2, 2.1, 2, 0.25, 0.05, 35)