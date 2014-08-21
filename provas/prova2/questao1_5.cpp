//Faça um programa que calcula o IMC (índice da massa corpórea) de uma
//pessoa. O IMC é calculado com o peso em kg, dividido pelo quadrado da altura,
//em metros, IMC = Peso/Altura².
//De acordo com o IMC calculado retorne o nível de obesidade de acordo com
//a tabela abaixo:
//
//Abaixo de 17        Muito abaixo do peso
//Entre 17 e 18,49    Abaixo do peso
//Entre 18,5 e 24,99  Peso normal
//Entre 25 e 29,99    Acima do peso
//Entre 30 e 34,99    Obesidade I
//Entre 35 e 39,99    Obesidade II (severa)
//Acima de 40         Obesidade III (mórbida)
enum NivelObesidade {MuitoAbaixo, Abaixo, Normal, Obeso, Severo, Morbido};

NivelObesidade verificarPeso(float peso, float altura);


