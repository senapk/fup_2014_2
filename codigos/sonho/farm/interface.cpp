#include "interface.h"

RenderWindow Interface::janela;
vector<Componente*> Interface::componentes;
ComponenteMovel* Interface::personagem;
int Interface::SLEEP_MOV = SLEEP_MOVIMENTO;

void Interface::create(string nome) {
    int altura = 0;
    int largura = 0;
    carregarCampo(TEXTO_CAMPO, largura, altura);
    janela.create(VideoMode(largura, altura), nome);
    janela.setFramerateLimit(FRAME_RATE);
}

void Interface::create(int largura, int altura, string nome) {
    int altura2 = 0;
    int largura2 = 0;
    carregarCampo(TEXTO_CAMPO, largura2, altura2);
    janela.create(VideoMode(largura2, altura2), nome);
    janela.setSize(Vector2u(largura, altura));
    janela.setFramerateLimit(FRAME_RATE);
}

void Interface::carregarCampo(string campo, int &largura, int &altura) {
    fstream file;
    file.open(campo.c_str());

    if(file.fail())
        cout << "ERRO!" << " " << campo << " não encontrado" << endl;

    int i = 0;
    int j = 0;
    int jMax = 0;

    PersonagemFactory perFact;

    while(!file.eof()) {
        char c;
        char* variacao = new char[2];
        variacao[1] = '\0';
        file.read(&c, 1);

        Componente* cp;

        switch(c) {
        case 'P':

            cp = perFact.criar(CAMINHO, atoi(variacao), j*TAM_BLOCO, i*TAM_BLOCO);
            componentes.push_back(cp);

            file.read(variacao, 1);
            personagem = perFact.criarPersonagem(j*TAM_BLOCO, i*TAM_BLOCO);
            break;
        case 'O':
            file.read(variacao, 1);
            Componente* co;
            co = perFact.criar(OBSTACULO, atoi(variacao), j*TAM_BLOCO, i*TAM_BLOCO);
            componentes.push_back(co);
            break;
        case 'R':

            cp = perFact.criar(CAMINHO, atoi(variacao), j*TAM_BLOCO, i*TAM_BLOCO);
            componentes.push_back(cp);

            file.read(variacao, 1);
            Componente* cr;
            cr = perFact.criar(PREMIO, atoi(variacao), j*TAM_BLOCO, i*TAM_BLOCO);
            componentes.push_back(cr);
            break;
        case 'I':

            cp = perFact.criar(CAMINHO, atoi(variacao), j*TAM_BLOCO, i*TAM_BLOCO);
            componentes.push_back(cp);

            file.read(variacao, 1);
            Componente* ci;
            ci = perFact.criar(INIMIGO, atoi(variacao), j*TAM_BLOCO, i*TAM_BLOCO);
            componentes.push_back(ci);
            break;
        case ' ':
            file.read(variacao, 1);
            Componente* cc;
            cc = perFact.criar(CAMINHO, atoi(variacao), j*TAM_BLOCO, i*TAM_BLOCO);
            componentes.push_back(cc);
            break;
        case '\n':
            i++;
            j = -1;
            break;
        }

        j++;
        jMax = j > jMax? j: jMax;
    }

    largura = jMax*TAM_BLOCO;
    altura = (i-1)*TAM_BLOCO;
}

void Interface::espera() {
    while(janela.isOpen()) {
        mostrarComponentes();

        verificarEventos();
    }
}

void Interface::espera(string s) {

    bool anim = true;

    while(janela.isOpen()) {
        mostrarComponentesSemDisplay();

        Escritor e;
        e.setCor(Color::Red);

        if(anim)
            e.escreverAnimacao(s);
        anim = false;
        e.escrever(s);

        janela.display();

        verificarEventos();
    }
}

void Interface::espera(int sl) {
    for(int i = 0; i < 10; i++) {  //Gambiarra desgraçada 3:D
        janela.clear();
        janela.display();
    }
    mostrarComponentes();
    sleep(milliseconds(sl));
}

RenderWindow* Interface::getJanela() {
    return &janela;
}

ComponenteMovel* Interface::getPersonagem() {
    return personagem;
}

vector<Componente*> Interface::getComponentes() {
    return componentes;
}

void Interface::mostrarComponente(Componente *c) {
    janela.clear();
    for (unsigned int i = 0; i < componentes.size(); i++) {
        if(componentes[i]->getTipo() == PERSONAGEM)
            ((ComponenteMovel*)componentes[i])->paint(&janela);
        else
            componentes[i]->paint(&janela);
    }
    personagem->paint(&janela);
    c->paint(&janela);
    janela.display();

    verificarEventos();
}

void Interface::mostrarComponentes() {
    janela.clear();
    for (unsigned int i = 0; i < componentes.size(); i++) {
        if(componentes[i]->getTipo() == PERSONAGEM)
            ((ComponenteMovel*)componentes[i])->paint(&janela);
        else
            componentes[i]->paint(&janela);
    }
    personagem->paint(&janela);

    janela.display();

    verificarEventos();

}

void Interface::mostrarComponentesSemDisplay() {
    janela.clear();
    for (unsigned int i = 0; i < componentes.size(); i++) {
        if(componentes[i]->getTipo() == PERSONAGEM)
            ((ComponenteMovel*)componentes[i])->paint(&janela);
        else
            componentes[i]->paint(&janela);
    }
    personagem->paint(&janela);
}

void Interface::verificarEventos() {
    Event event;
    if(janela.pollEvent(event)) {
        if(event.type == Event::Closed) {
            janela.close();
            exit(0);
        }
    }
}

void Interface::tratarColisao() {
    Objeto o = PERSONAGEM;

    for(int i = 0; i < (int)componentes.size(); i++) {
        if(componentes[i]->colide(personagem))
            o = componentes[i]->getTipo();
    }

    if(o == OBSTACULO) {
        espera("Nao eh por ai!\nTente novamente!");
    }

    if(o == PREMIO) {
        espera("Parabens! Vc ganhou! :D");
    }

    if(o == INIMIGO) {
        espera("Vc perdeu! :(");
    }
}

void Interface::init() {
    ImageManager::init();
    Interface::create("learnCode");
    Interface::espera(SLEEP_INICIAL);
}

void Interface::setSpeed(int speed) {
    SLEEP_MOV = 1000/speed;
}




