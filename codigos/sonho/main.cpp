#include "farm/interface.h"
#include "farm/comando.h"

int main() {
    INICIAR
    VELOCIDADE(30) //recomendado: de 10 a 30

    //COMEÇO DO CÓDIGO DO ALUNO
	andar();
	while(olhar(FRENTE) != PREMIO) {
		if(olhar(ESQUERDA) == CAMINHO)
			virar(ESQUERDA);
			
			andar();
	}
	
	andar();
    //FIM DO CÓDIGO DO ALUNO

    FIM
}

/*
 *FUNÇÕES:
 *andar()       : void
 *virar(lado)   : void
 *olhar(lado)   : Objeto
 *
 *
 *OBJETOS:
 *CAMINHO
 *OBSTACULO
 *PREMIO
 *INIMIGO
 *PERSONAGEM
 *
 */



