#include "imagemanager.h"

map<int, vector<Texture> > ImageManager::texturasObstaculo;
map<int, vector<Texture> > ImageManager::texturasInimigo;
map<int, vector<Texture> > ImageManager::texturasPremio;
map<int, vector<Texture> > ImageManager::texturasCaminho;

SpriteComponenteMovel ImageManager::texturasMoveis;
SpriteComponenteMovel ImageManager::texturasMoveisOlhar;

void ImageManager::init() {

    fstream file;
    file.open(TEXTO_PATH);

    if(file.fail())
        cout << "ERRO!" << " " << TEXTO_PATH << " não encontrado" << endl;

    while(!file.eof()) {
        stringstream linha;
        char c = ' ';

        while(c != '\n' && !file.eof()) {
            file.read(&c, 1);
            linha << c;
        }

        if(file.eof()) break;

        char tipo;
        int variacao;
        string path;

        linha >> tipo;

        //{PERSONAGEM, OBSTACULO, INIMIGO, PREMIO, CAMINHO};
        if(tipo == 'O') {
            linha >> variacao;
            cout << "Adicionando obstaculo " << variacao << endl;
            linha >> path;
            carregarTextura(OBSTACULO, path, variacao);

        } else if(tipo == 'I') {
            linha >> variacao;
            cout << "Adicionando inimigo " << variacao << endl;
            linha >> path;
            carregarTextura(INIMIGO, path, variacao);

        } else if(tipo == 'R') {
            linha >> variacao;
            cout << "Adicionando premio " << variacao << endl;
            linha >> path;
            carregarTextura(PREMIO, path, variacao);

        } else if(tipo == 'C') {
            linha >> variacao;
            cout << "Adicionando caminho " << variacao << endl;
            linha >> path;
            carregarTextura(CAMINHO, path, variacao);

        } else if(tipo == 'P') {
            char variacaoC;
            linha >> variacaoC;
            cout << "Adicionando personagen" << endl;
            string path2;
            string path3;
            string path4;
            linha >> path >> path2 >> path3 >> path4;

            if(variacaoC == 'C')
                carregarTextura(path, path2, path3, path4);
            else if(variacaoC == 'O')
                carregarTexturaOlhar(path, path2, path3, path4);
        }
    }

}

Texture* ImageManager::getTexture(Objeto tipo, int frame, int variacao) {
    switch(tipo) {
    case OBSTACULO:
        return &texturasObstaculo[variacao][frame];
    case INIMIGO:
        return &texturasInimigo[variacao][frame];
    case PREMIO:
        return &texturasPremio[variacao][frame];
    case CAMINHO:
        return &texturasCaminho[variacao][frame];
    }
}

Texture* ImageManager::getTexture(int frame, Direcao direcao) {
    switch(direcao) {
        case NORTE:
            return &texturasMoveis.norte[frame];
        case SUL:
            return &texturasMoveis.sul[frame];
        case LESTE:
            return &texturasMoveis.leste[frame];
        default:
            return &texturasMoveis.oeste[frame];
    }
}

Texture* ImageManager::getTextureOlhar(int frame, Direcao direcao) {
    switch(direcao) {
        case NORTE:
            return &texturasMoveisOlhar.norte[frame];
        case SUL:
            return &texturasMoveisOlhar.sul[frame];
        case LESTE:
            return &texturasMoveisOlhar.leste[frame];
        default:
            return &texturasMoveisOlhar.oeste[frame];
    }
}

void ImageManager::carregarTextura(string endN, string endS, string endL, string endO) {
    int i = 0;

    SpriteComponenteMovel* sprites = &texturasMoveis;

    while(true) {
        stringstream s0, s1, s2, s3;
        s0 << IMAGENS_PASTA << endN << i << ".png";
        s1 << IMAGENS_PASTA << endS << i << ".png";
        s2 << IMAGENS_PASTA << endL << i << ".png";
        s3 << IMAGENS_PASTA << endO << i << ".png";

        Texture t0, t1, t2, t3;
        if(!t0.loadFromFile(s0.str()))
            break;
        if(!t1.loadFromFile(s1.str()))
            break;
        if(!t2.loadFromFile(s2.str()))
            break;
        if(!t3.loadFromFile(s3.str()))
            break;

        t0.setSmooth(true);
        t1.setSmooth(true);
        t2.setSmooth(true);
        t3.setSmooth(true);

        sprites->norte.push_back(t0);
        sprites->sul.push_back(t1);
        sprites->leste.push_back(t2);
        sprites->oeste.push_back(t3);
        i++;

    }

}

void ImageManager::carregarTexturaOlhar(string endN, string endS, string endL, string endO) {
    int i = 0;

    SpriteComponenteMovel* sprites = &texturasMoveisOlhar;

    while(true) {
        cout << "carregando textura olhar..." << i << endl;
        stringstream s0, s1, s2, s3;
        s0 << IMAGENS_PASTA << endN << i << ".png";
        s1 << IMAGENS_PASTA << endS << i << ".png";
        s2 << IMAGENS_PASTA << endL << i << ".png";
        s3 << IMAGENS_PASTA << endO << i << ".png";

        Texture t0, t1, t2, t3;
        if(!t0.loadFromFile(s0.str()))
            break;
        if(!t1.loadFromFile(s1.str()))
            break;
        if(!t2.loadFromFile(s2.str()))
            break;
        if(!t3.loadFromFile(s3.str()))
            break;

        t0.setSmooth(true);
        t1.setSmooth(true);
        t2.setSmooth(true);
        t3.setSmooth(true);

        sprites->norte.push_back(t0);
        sprites->sul.push_back(t1);
        sprites->leste.push_back(t2);
        sprites->oeste.push_back(t3);
        i++;

    }

}


void ImageManager::carregarTextura(Objeto tipo, string end, int variacao) {
    int i = 0;

    vector<Texture>* tex;

    switch(tipo) {
    case OBSTACULO:
        tex = &texturasObstaculo[variacao];
        break;
    case INIMIGO:
        tex = &texturasInimigo[variacao];
        break;
    case PREMIO:
        tex = &texturasPremio[variacao];
        break;
    case CAMINHO:
        tex = &texturasCaminho[variacao];
        break;
    }

    fstream file;
    while(true) {
        stringstream s;
        s << IMAGENS_PASTA << end << i << ".png";
        Texture t;
        if(!t.loadFromFile(s.str()))
            break;

        t.setSmooth(true);

        tex->push_back(t);
        i++;

    }
}

int ImageManager::getAnimacaoSize(Objeto tipo, int variacao) {
    vector<Texture>* tex;

    switch(tipo) {
    case OBSTACULO:
        tex = &texturasObstaculo[variacao];
        break;
    case INIMIGO:
        tex = &texturasInimigo[variacao];
        break;
    case PREMIO:
        tex = &texturasPremio[variacao];
        break;
    case CAMINHO:
        tex = &texturasCaminho[variacao];
        break;
    default:
        cout << "BUGG" << endl;
        return 0;
    }

    return tex->size();
}

int ImageManager::getAnimacaoSize() {
    return texturasMoveis.norte.size();
}

int ImageManager::getAnimacaoSizeOlhar() {
    return texturasMoveisOlhar.norte.size();
}
