/*
 * Atividade Avaliativa 3 - Estrutura de Dados 2026-01
 * UTFPR - Curso: Tecnologia em Analise e Desenvolvimento de Sistemas
 * Professor: Clayton Kossoski
 *
 * Sistema de Cadastro de Alunos utilizando arvore Binaria de Busca (ABB)
 * Chave de ordenacao: nome do aluno (ordem alfabetica)
 */

#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------
// Estrutura que representa um aluno (nó da arvore)
// ---------------------------------------------
struct Aluno {
    int matricula;       // Número de Matricula
    string nome;         // Nome completo (chave de busca)
    string curso;        // Curso do aluno
    Aluno* esquerda;     // Ponteiro para subarvore esquerda (nomes menores)
    Aluno* direita;      // Ponteiro para subarvore direita (nomes maiores)

    // Construtor do nó
    Aluno(int mat, string nom, string cur) {
        matricula = mat;
        nome = nom;
        curso = cur;
        esquerda = nullptr;
        direita = nullptr;
    }
};

// ---------------------------------------------
// Classe que representa a arvore Binaria de Busca
// ---------------------------------------------
class ABB {
private:
    Aluno* raiz;       // Ponteiro para a raiz da arvore
    int totalAlunos;   // Contador de alunos cadastrados

    // -- Insercao recursiva ----------------------------------------------
    // Percorre a arvore comparando nomes ate encontrar o lugar correto
    Aluno* inserirRecursivo(Aluno* no, int matricula, string nome, string curso) {
        // Caso base: posicao vazia encontrada, cria o novo nó
        if (no == nullptr) {
            totalAlunos++;
            return new Aluno(matricula, nome, curso);
        }

        // Compara o nome com o nó atual
        if (nome < no->nome) {
            // Nome menor -> vai para a subarvore esquerda
            no->esquerda = inserirRecursivo(no->esquerda, matricula, nome, curso);
        } else if (nome > no->nome) {
            // Nome maior -> vai para a subarvore direita
            no->direita = inserirRecursivo(no->direita, matricula, nome, curso);
        } else {
            // Nome igual: aluno ja cadastrado
            cout << "Aluno \"" << nome << "\" ja esta cadastrado.\n";
            return no;
        }

        return no;
    }

    // -- Busca recursiva -------------------------------------------------
    // Retorna o ponteiro para o nó encontrado, ou nullptr se nao existir
    Aluno* buscarRecursivo(Aluno* no, const string& nome) {
        // Caso base: chegou em nó vazio -> nao encontrou
        if (no == nullptr) return nullptr;

        if (nome == no->nome) {
            return no; // Encontrou!
        } else if (nome < no->nome) {
            return buscarRecursivo(no->esquerda, nome); // se for menor, Busca à esquerda
        } else {
            return buscarRecursivo(no->direita, nome);  // se for maior, Busca à direita
        }
    }

    // -- Percurso em-ordem ------------------------------------
    // Visita: esquerda -> raiz -> direita
    // Garante listagem em ordem alfabetica crescente de nomes
    void emOrdem(Aluno* no) {
        if (no == nullptr) return;

        emOrdem(no->esquerda);                              // Vai até o Último nó da Esquerda
        cout << no->nome                                    // Apresenta o conteúdo do nó
             << " - Matricula: " << no->matricula           // 
             << " - Curso: " << no->curso << "\n";          // 
        emOrdem(no->direita);                               // Volta para o nó direito até o Último
    }

    // -- Calculo da altura da arvore -------------------------------------
    // Altura = número de arestas no caminho mais longo ate um vertice
    int calcularAltura(Aluno* no) {
        if (no == nullptr) return -1; // arvore vazia tem altura -1

        int alturaEsq = calcularAltura(no->esquerda);
        int alturaDir = calcularAltura(no->direita);

        // Altura atual = 1 + maior altura entre os filhos
        return 1 + max(alturaEsq, alturaDir);
    }

    // -- Liberacao de memória ---------------------------------------------
    // Percurso pós-ordem para deletar todos os nós
    void destruir(Aluno* no) {
        if (no == nullptr) return;
        destruir(no->esquerda);
        destruir(no->direita);
        delete no;
    }

public:
    // Construtor: inicializa arvore vazia
    ABB() {
        raiz = nullptr;
        totalAlunos = 0;
    }

    // Destrutor: libera toda a memória alocada
    ~ABB() {
        destruir(raiz);
    }

    // -- Interface pública: Inserir --------------------------------------
    void inserir(int matricula, string nome, string curso) {
        raiz = inserirRecursivo(raiz, matricula, nome, curso);
    }

    // -- Interface pública: Buscar ---------------------------------------
    void buscar(const string& nome) {
        Aluno* encontrado = buscarRecursivo(raiz, nome);

        if (encontrado != nullptr) {
            cout << "Aluno encontrado:\n";
            cout << "  Nome:       " << encontrado->nome << "\n";
            cout << "  Matricula:  " << encontrado->matricula << "\n";
            cout << "  Curso:      " << encontrado->curso << "\n";
        } else {
            cout << "Aluno \"" << nome << "\" nao encontrado.\n";
        }
    }

    // -- Interface pública: Listar em ordem alfabetica -------------------
    void listarEmOrdem() {
        if (raiz == nullptr) {
            cout << "Nenhum aluno cadastrado.\n";
            return;
        }
        cout << "\n=== Alunos em Ordem Alfabetica ===\n";
        emOrdem(raiz);
        cout << "==================================\n";
    }

    // -- Interface pública: Informacoes da arvore ------------------------
    void exibirInformacoes() {
        cout << "\n=== Informacoes da arvore ===\n";
        cout << "Total de alunos: " << totalAlunos << "\n";
        cout << "Altura da arvore: " << calcularAltura(raiz) << "\n";
        cout << "=============================\n";
    }
};

// ---------------------------------------------
// Funcao principal com menu interativo
// ---------------------------------------------
int main() {
    ABB arvore;
    int opcao;

    // Insercao dos alunos de Exemplo
    arvore.inserir(101, "John Smith", "Engenharia de Software");
    arvore.inserir(102, "Alice Johnson", "Sistemas de Informacao");
    arvore.inserir(103, "Michael Brown", "Ciencia da Computacao");
    arvore.inserir(104, "Emily Davis", "Engenharia de Software");

    do {
        cout << "\n====== SISTEMA DE CADASTRO DE ALUNOS ======\n";
        cout << "1. Inserir aluno\n";
        cout << "2. Buscar aluno\n";
        cout << "3. Listar alunos em ordem alfabetica\n";
        cout << "4. Exibir informacoes da arvore\n";
        cout << "0. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore(); // Limpa o '\n'

        if (opcao == 1) {
            int mat;
            string nome, curso;
            cout << "Matricula: ";
            cin >> mat;
            cin.ignore();
            cout << "Nome completo: ";
            getline(cin, nome);
            cout << "Curso: ";
            getline(cin, curso);
            arvore.inserir(mat, nome, curso);
            cout << "Aluno inserido com sucesso!\n";

        } else if (opcao == 2) {
            string nome;
            cout << "Nome do aluno a buscar: ";
            getline(cin, nome);
            arvore.buscar(nome);

        } else if (opcao == 3) {
            arvore.listarEmOrdem();

        } else if (opcao == 4) {
            arvore.exibirInformacoes();

        } else if (opcao != 0) {
            cout << "Opcao invalida.\n";
        }

    } while (opcao != 0);

    cout << "Encerrando o sistema.\n";
    arvore.~ABB(); // Ativa o destruidor antes de encerrar o programa.
    return 0;
}
