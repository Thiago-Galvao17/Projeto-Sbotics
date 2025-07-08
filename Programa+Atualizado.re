tarefa Frente com numero velocidade {
TravarMotor("BackL", falso)
TravarMotor("BackR", falso)
TravarMotor("L", falso)
TravarMotor("R", falso)

Motor("BackL", velocidade)
Motor("BackR", velocidade)
Motor("L", velocidade)
Motor("R", velocidade)
}

tarefa Direita com numero velocidade {
TravarMotor("BackL", falso)
TravarMotor("BackR", falso)
TravarMotor("L", falso)
TravarMotor("R", falso)

Motor("BackL", velocidade)
Motor("BackR", 0-velocidade)
Motor("L", velocidade)
Motor("R", 0-velocidade)
}

tarefa Esquerda com numero velocidade {
TravarMotor("BackL", falso)
TravarMotor("BackR", falso)
TravarMotor("L", falso)
TravarMotor("R", falso)

Motor("BackL", 0-velocidade)
Motor("BackR", velocidade)
Motor("L", 0-velocidade)
Motor("R", velocidade)
}

tarefa Parar {
TravarMotor("BackL", verdadeiro)
TravarMotor("BackR", verdadeiro)
TravarMotor("L", verdadeiro)
TravarMotor("R", verdadeiro)
}

tarefa Tras com numero velocidade {
TravarMotor("BackL", falso)
TravarMotor("BackR", falso)
TravarMotor("L", falso)
TravarMotor("R", falso)

Motor("BackL", 0-velocidade)
Motor("BackR", 0-velocidade)
Motor("L", 0-velocidade)
Motor("R", 0-velocidade)
}

tarefa Haste com numero velocidade {  	 #Parametro 0 - 1.5 para subir  
TravarMotor("Haste", falso)			     #Parametro 1 para descer
Motor("Haste", velocidade*100)
Esperar(1050)
TravarMotor("Haste", verdadeiro)
}

#Posicionamento dos sensores da esquerda para a direita: SL, S1, S2, S3, SR

inicio
AbrirConsole()
enquanto (verdadeiro) farei {
Esperar(10)

se ((Ultra("UltraU") <= 1) e (Ultra("UltraU") > 0)) entao {
EscreverLinha("Obstáculo")
Direita(100)
Esperar(4900)
Frente(100)
Esperar(3500)
Esquerda(100)
Esperar(4900)
Frente(100)
Esperar(6800)
Esquerda(100)
Esperar(4000)
enquanto (Cor("S3") != "Preto") farei {
Frente(100)
}
}

senao se ((CorVermelho("S2") == 77) e (CorVerde("S2") == 85) e (CorAzul("S2") == 96)) entao { 
		Frente(200)   															#Ignorar zona de resgate
		Esperar(2200)											
		Parar()       
		Direita(200)
		Esperar(1850)
		Parar()
		LigarLuz("LuzL",160,160,160)  #Para que seja possível ver o verde adiante
		LigarLuz("LuzR",160,160,160)  #/\											 /\
		Frente(250)
		Esperar(2000)
}

senao se ((Cor("SL") == "Preto") e (Cor("S1") == "Preto") e (Cor("S2") == "Preto") e (Cor("S3") == "Preto") e (Cor("SR") == "Preto")) entao {												#Para ultrapassar intersecções
EscreverLinha("Ultrapassando")
Frente(200)
Esperar(800)
}

senao se (((Cor("SL") == "Verde") e (Cor("S2") == "Verde")) ou ((Cor("S1") == "Verde") e (Cor("S3") == "Verde")) ou ((Cor("S2") == "Verde") e (Cor("SR") == "Verde"))) entao {				#Casos do verde
EscreverLinha("Meia volta")
Esquerda(200)
Esperar(4335)
Parar()
}

senao se (Cor("S1") == "Verde") entao {										#Casos do verde
EscreverLinha("90 graus a esquerda")
Frente(200)   #Ajuste para ficar centralizado \/
Esperar(1300)
Parar()       #Ajuste para ficar centralizado /\
Esquerda(200)
Esperar(2200)
Parar()
Esperar(500)  #Para não detectar o verde acidentalmente de novo  \/
Frente(200)
Esperar(1000) #Para não detectar o verde acidentalmente de novo. /\
}

senao se (Cor("S3") == "Verde") entao {										#Casos do verde
EscreverLinha("90 graus a direita")
Frente(200)   #Ajuste para ficar centralizado \/
Esperar(1300)
Parar()       #Ajuste para ficar centralizado /\
Direita(200)
Esperar(2200)
Parar()
Esperar(500)  #Para não detectar o verde acidentalmente de novo  \/
Frente(200)
Esperar(1000) #Para não detectar o verde acidentalmente de novo. /\
}

senao se ((Cor("S1") == "Branco") e (Cor("S2") == "Preto") e (Cor("S3") == "Branco"))entao { #Seguir Reto
EscreverLinha("Frente")
Frente(200)
}
senao se ((Cor("S1") == "Branco") e (Cor("S3") == "Branco")) entao {							#Seguir Reto
EscreverLinha("Frente")
Frente(200)
}

senao se ((Cor("SL") == "Preto") ou (Cor("S1") == "Preto")) entao {							#Curvas \/ 
EscreverLinha("Esquerda")
Esquerda(50)
}
senao se ((Cor("S3") == "Preto") ou (Cor("SR") == "Preto")) entao { 							# /\ 	 /\
EscreverLinha("Direita")
Direita(50)
}
}
fim