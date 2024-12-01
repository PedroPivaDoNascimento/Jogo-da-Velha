//ATENÇÃO, Esse código só funciona em distribuições linux

#include <iostream>

using namespace std;

//funcao responsavel por terminar a criação da matriz
void criarMatriz(char ** matriz){
    for (int i = 0; i < 3; i++){
        matriz[i] = new char[3];
    }
    
    //limpar o licho de memoria presente nas variaveis
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matriz[i][j] = '\0';
        }
    }
}

//funcao responsavel por adicionar os valores O ou X na posicao correta
void alocarValores(char ** jogoDaVelha, int posicaoLinha, int posicaoColuna, int numRodada){
    system("clear");
    
    //Variavel que vai receber o X ou o O
    char valorAlocado = '\0';

    //condicional para ver se o X ou o O vai ser digitado
    if (numRodada % 2 == 0){
        valorAlocado = 'X';
    }else{
        valorAlocado = 'O';
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(i == posicaoLinha && j == posicaoColuna){
                jogoDaVelha[i][j] = valorAlocado;
            }
        }
    }
}  

//funcao que imprimi o tabuleiro
void imprimirJogo(char ** jogoDaVelha){
    for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout << "\t[" << jogoDaVelha[i][j] << "]";
            }
            cout << "\n\n";
        }
        cout << "\n\n";
}

//Função que acha os carcteres que não podem entrar no programa
bool acharCaracteresProibidos(string numero){
    //cacarteres que bugam o programa
    size_t posicaoVirgula = numero.find(",");
    size_t posicaoEspaco = numero.find(" ");
    size_t posicaoPonto = numero.find(".");
    size_t posicaoSoma = numero.find("+");
    size_t posicaoSubtracao = numero.find("-");
    size_t posicaoDivisao = numero.find("/");
    size_t posicaoMultiplicacao = numero.find("*");
    size_t posicaoAcento = numero.find("´");
    size_t posicaoAspasSimples = numero.find("'");
    size_t posicaoAspasCompostas = numero.find("\"");

    //verificar se não tem nenhum deles

    if (posicaoVirgula != string::npos || posicaoEspaco != string::npos || posicaoPonto != string::npos || posicaoSoma != string::npos || posicaoSubtracao != string::npos || posicaoMultiplicacao != string::npos || posicaoDivisao != string::npos || posicaoAcento != string::npos || posicaoAspasSimples != string::npos || posicaoAspasCompostas != string::npos){
        return true;
    }else{
        return false;
    }
}

//função que verifica se a string pode ser convertida para int
bool podeConverterStringParaInt(const string &numero){
    try{
        stoi(numero);
        return true;
    }catch(const invalid_argument&){
        return false;
    }catch(const out_of_range&){
        return false;
    }
    
}

//função que verifica quuem que vai jogar, o X ou O
char verificarQuemJoga(int numRodada){
    if (numRodada % 2 == 0){
        return 'X';
    }else{
        return 'O';
    }
}

//Recebe o valor da posição da linha
int digitarPosicaoLinha(char ** jogoDaVelha, int numRodada){
    string posicaoLinhaStr = " ";
    char quemJoga = '\0';
    int posicaoLinhaInt = 0;
    bool converte;
    bool temVirgulaOuEspacos;

    quemJoga = verificarQuemJoga(numRodada);
    
    do{
        cout << "Digite a posição da linha em que o " << quemJoga << " vai jogar (1/2/3): ";
        getline(cin, posicaoLinhaStr);

        converte = podeConverterStringParaInt(posicaoLinhaStr);

        //Verifica se essa strinfg pode ser convertida
        if (converte == true){
            posicaoLinhaInt = stoi(posicaoLinhaStr);

            //verficar se tem virulas ou espaços no campo preenchido
            temVirgulaOuEspacos = acharCaracteresProibidos(posicaoLinhaStr);
                    
            //subtração por menos para a posicao ser lida pelos vetores de 0 ate 2
            posicaoLinhaInt = posicaoLinhaInt - 1;
        }
                    
        //verificar se houve algum erro na hora de digitar as variaveis
        if (posicaoLinhaInt < 0 || posicaoLinhaInt > 2 || temVirgulaOuEspacos == true || converte == false){
            cin.clear();
            system("clear");
                    
            imprimirJogo(jogoDaVelha);
            cout << "ERRO - Essa posiçao não existe no jogo da velha.\n\n";
        }

    }while(posicaoLinhaInt < 0 || posicaoLinhaInt > 2 || temVirgulaOuEspacos == true || converte == false);

    return posicaoLinhaInt; 
}

//Recebe o valor da posição da coluna
int digitarPosicaoColuna(char ** jogoDaVelha, int numRodada){

    string posicaoLinhaStr = " ";
    char quemJoga = '\0';
    int posicaoColunaInt = 0;
    bool converte;
    bool temVirgulaOuEspacos;

    quemJoga = verificarQuemJoga(numRodada);
    
    do{
        cout << "Digite a posição da coluna em que o " << quemJoga << " vai jogar (1/2/3): ";
        getline(cin, posicaoLinhaStr);

        converte = podeConverterStringParaInt(posicaoLinhaStr);

        //Verifica se essa strinfg pode ser convertida
        if (converte == true){
         posicaoColunaInt = stoi(posicaoLinhaStr);

            //verficar se tem virulas ou espaços no campo preenchido
            temVirgulaOuEspacos = acharCaracteresProibidos(posicaoLinhaStr);
                    
            //subtração por menos para a posicao ser lida pelos vetores de 0 ate 2
         posicaoColunaInt = posicaoColunaInt - 1;
                
        }
                    
        //verificar se houve algum erro na hora de digitar as variaveis
        if (posicaoColunaInt < 0 || posicaoColunaInt > 2 || temVirgulaOuEspacos == true || converte == false){
            cin.clear();
            system("clear");
                    
            imprimirJogo(jogoDaVelha);
            cout << "ERRO - Essa posiçao não existe no jogo da velha.\n\n";
        }

    }while(posicaoColunaInt < 0 || posicaoColunaInt > 2 || temVirgulaOuEspacos == true || converte == false);

    return posicaoColunaInt;
}

//Verifica se o a posição digtada está ocupada
bool verificaQuadradoDisponivel(char ** jogoDaVelha, int linha, int coluna){
    bool quadradoDisponivel;
    
    if(jogoDaVelha[linha][coluna] == 'X' || jogoDaVelha[linha][coluna] == 'O'){
        system("clear");
        imprimirJogo(jogoDaVelha);
        quadradoDisponivel = false;
        cout << "ERRO - Esse quadrado ja esta ocupado.\n\n";
    }else{
        quadradoDisponivel = true;
    }

    return quadradoDisponivel;
}

//função responsavel por realizar a jogada durante cada rodada
void realizarJogada(char ** jogoDaVelha, int numRodada){
    int posicaoLinhaInt = 0;
    int posicaoColunaInt = 0;
    bool quadradoDisponivel;

    //Verificar se os valores digitados esta totalmente correto de acordo com o pedido no programa
    do{
        posicaoLinhaInt = digitarPosicaoLinha(jogoDaVelha, numRodada);
        posicaoColunaInt =  digitarPosicaoColuna(jogoDaVelha, numRodada);
        quadradoDisponivel = verificaQuadradoDisponivel(jogoDaVelha, posicaoLinhaInt, posicaoColunaInt);
    }while(quadradoDisponivel == false);
    
    //Alocação dos valores
    alocarValores(jogoDaVelha, posicaoLinhaInt, posicaoColunaInt, numRodada);
}

//Verifica se teve algum vencedor
bool verificaVitoria(char ** jogoDaVelha){
    //verificar por sequencia de diagonais
    if (jogoDaVelha[0][0] == jogoDaVelha[1][1] && jogoDaVelha[1][1] == jogoDaVelha[2][2]){
        if (jogoDaVelha[0][0] == 'X' || jogoDaVelha[0][0] == 'O'){
            return true;
        }
    }

    if(jogoDaVelha[0][2] == jogoDaVelha[1][1] && jogoDaVelha[1][1] == jogoDaVelha[2][0]){
        if (jogoDaVelha[0][2] == 'X' || jogoDaVelha[0][2] == 'O'){
            return true;
        }
    }

    //verificar por sequencia de linhas
    for (int i = 0; i < 3; i++){
        if (jogoDaVelha[i][0] == jogoDaVelha[i][1] && jogoDaVelha[i][1] == jogoDaVelha[i][2]){
            if (jogoDaVelha[i][0] == 'X' || jogoDaVelha[i][0] == 'O'){
                return true;
            }
        }
    }

    //verificar por sequencia de colunas
    for (int i = 0; i < 3; i++){
        if (jogoDaVelha[0][i] == jogoDaVelha[1][i] && jogoDaVelha[1][i] == jogoDaVelha[2][i]){
            if (jogoDaVelha[0][i] == 'X' || jogoDaVelha[0][i] == 'O'){
                return true;
            }
        }
    }

    return false;

}

//verifica se o jogo acabou, verificando todas as possivbilidades possiveis
bool verificarJogoAcabou(char ** jogoDaVelha, int numRodada){
    //verificar por numero de jogados
    if (numRodada >= 9){
        return true;
    }

    if (verificaVitoria(jogoDaVelha) == true){
        return true;
    }

    return false;
}

//tabuleiro responsavel por mostrar o andamento do jogo da velha
void tabuleiro(char ** jogoDaVelha){    
    //variavel que determinara quando o jogo vai acabar e outro bolleano para confirmar se o jogo empatou
    bool acabou = false;
    bool teveVencedor;
    //Variavel que determinada o numero de rodadas, que vai ser usada para ver se o X ou a O vai jogar
    int numRodada = 0;
    char vencedor = '\0';

    do{
        imprimirJogo(jogoDaVelha);
        realizarJogada(jogoDaVelha, numRodada);
        numRodada++;

        acabou = verificarJogoAcabou(jogoDaVelha, numRodada);

        if (acabou == true){
            if (numRodada % 2 != 0){
                vencedor = 'X';
            }else{
                vencedor = 'O';
            }
        }
    }while(acabou == false);
    teveVencedor = verificaVitoria(jogoDaVelha);

    if (teveVencedor == false){
        vencedor = 'N';
    }

    imprimirJogo(jogoDaVelha);

    if (vencedor != 'N'){
        cout << "O vencedor foi o " << vencedor << "!\n";
    }else{
        cout << "O jogo empatou!\n";
    }
}

int main(){
    //limpar o terminal antes da execução
    system("clear");
    //criando uma matriz char 3x3 que ira representar o tabuleiro do jogo da velha
    char ** jogoDaVelha = new char*[3];

    criarMatriz(jogoDaVelha);
    tabuleiro(jogoDaVelha);

    return 0;
}

