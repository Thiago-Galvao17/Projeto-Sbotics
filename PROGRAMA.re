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

inicio
AbrirConsole()
enquanto (verdadeiro) farei {
Esperar(1)

se ((Cor("S3") == "Branco") e (Cor("S2") == "Preto") e (Cor("S1") == "Branco"))entao {
EscreverLinha("Frente")
Frente(200)
}
senao se ((Cor("S3") == "Branco") e (Cor("S1") == "Branco")) entao {
EscreverLinha("Frente")
Frente(200)
}

senao se ((Cor("S3") == "Branco") e (Cor("S1") == "Preto")) entao {
EscreverLinha("Esquerda")
Esquerda(50)
}
senao se ((Cor("S3") == "Preto") e (Cor("S1") == "Branco")) entao {
EscreverLinha("Direita")
Direita(50)
}
}
fim
