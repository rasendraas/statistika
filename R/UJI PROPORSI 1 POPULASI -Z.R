# Test of Population Proportion

# Pilihan
# 1. Lower Tail (H1: p < p0) 
# 2. Upper Tail (H1: p > p0)
# 3. Two-tailed (H1: p tidak sama dengan p0)

Uji_Proporsi_Populasi = function(keputusan, samples_taken, p0, alpha, n){
  
  pbar = samples_taken/n
  z = (pbar-p0)/(sqrt(p0*(1-p0)/n))
  
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

Uji_Proporsi_Populasi(1, 12, 0.5, 0.05, 20)