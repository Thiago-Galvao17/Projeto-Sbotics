se ((Cor("S1") == "Verde") e (Cor("S3") == "Verde")) entao {
Parar()
Girar(50)
Esperar(10000)
  
senao se (Cor("S3") == "Verde") entao {
EscreverLinha("Verde - Direita")
Direita(50)
Esperar(2000)
}
senao se (Cor("S1") == "Verde") entao {
EscreverLinha("Verde - Esquerda")
Esperar(2000)
}
