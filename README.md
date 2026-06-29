# 🌳 Sistema de Cadastro de Alunos — Árvore Binária de Busca (ABB)

> **Atividade Avaliativa 3 — Estrutura de Dados 2026-01**
> UTFPR · Tecnologia em Análise e Desenvolvimento de Sistemas
> Professor: Clayton Kossoski

---

## 📋 Sobre o Projeto

Sistema de cadastro de alunos implementado em **C++** utilizando uma **Árvore Binária de Busca (ABB)**. A chave de ordenação é o **nome do aluno** (ordem alfabética), permitindo inserção, busca e listagem eficientes.

---

## 🧠 Conceitos Aplicados

| Conceito | Descrição |
|---|---|
| **Árvore Binária de Busca** | Estrutura hierárquica onde cada nó possui no máximo dois filhos, organizados por chave |
| **Chave de ordenação** | Nome do aluno (comparação lexicográfica) |
| **Recursão** | Inserção, busca, percurso em-ordem e destruição implementados recursivamente |
| **Percurso Em-Ordem** | Visita esquerda → raiz → direita, garantindo listagem em ordem alfabética |
| **Altura da árvore** | Número de arestas no caminho mais longo até uma folha |
| **Gerenciamento de memória** | Alocação dinâmica com `new` e liberação via destrutor (`delete`) |

---

## 🗂️ Estrutura do Projeto

```
.
└── main.cpp      # Código-fonte completo (estrutura Aluno, classe ABB e main)
```

### Estrutura do Nó (`struct Aluno`)

```
         [nome, matricula, curso]
               /           \
        (menor)             (maior)
       esquerda             direita
```

Cada nó armazena:
- `int matricula` — identificador único do aluno
- `string nome` — chave de busca (ordem alfabética)
- `string curso` — curso do aluno
- `Aluno* esquerda` / `Aluno* direita` — ponteiros para os filhos

---

## ⚙️ Funcionalidades

- ➕ **Inserir aluno** — adiciona um novo nó na posição correta da árvore
- 🔍 **Buscar aluno** — localiza um aluno pelo nome em O(h), onde h é a altura
- 📋 **Listar em ordem alfabética** — percurso em-ordem pela árvore
- 📊 **Exibir informações** — total de alunos cadastrados e altura atual da árvore

---

## 🚀 Como Compilar e Executar

### Pré-requisitos

- Compilador C++ com suporte a C++11 ou superior (`g++`, `clang++`, MSVC)

### Compilação

```bash
g++ -std=c++11 -o cadastro main.cpp
```

### Execução

```bash
./cadastro
```

> **Windows:** use `cadastro.exe` após compilar.

### Menu interativo

```
====== SISTEMA DE CADASTRO DE ALUNOS ======
1. Inserir aluno
2. Buscar aluno
3. Listar alunos em ordem alfabetica
4. Exibir informacoes da arvore
0. Sair
Opcao:
```

---

## 💡 Exemplo de Uso

O programa já inicia com 4 alunos de exemplo:

| Matrícula | Nome | Curso |
|---|---|---|
| 101 | John Smith | Engenharia de Software |
| 102 | Alice Johnson | Sistemas de Informação |
| 103 | Michael Brown | Ciência da Computação |
| 104 | Emily Davis | Engenharia de Software |

Ao listar em ordem alfabética (opção 3), a saída será:

```
=== Alunos em Ordem Alfabetica ===
Alice Johnson - Matricula: 102 - Curso: Sistemas de Informacao
Emily Davis - Matricula: 104 - Curso: Engenharia de Software
John Smith - Matricula: 101 - Curso: Engenharia de Software
Michael Brown - Matricula: 103 - Curso: Ciencia da Computacao
==================================
```

---

## 📐 Complexidade de Tempo

| Operação | Caso Médio | Pior Caso (árvore degenerada) |
|---|---|---|
| Inserção | O(log n) | O(n) |
| Busca | O(log n) | O(n) |
| Listagem em-ordem | O(n) | O(n) |
| Altura | O(n) | O(n) |

> O pior caso ocorre quando os dados são inseridos em ordem crescente ou decrescente, formando uma lista encadeada.

---

## 🏫 Informações Acadêmicas

- **Instituição:** UTFPR — Universidade Tecnológica Federal do Paraná
- **Curso:** Tecnologia em Análise e Desenvolvimento de Sistemas
- **Disciplina:** Estrutura de Dados — 2026/01
- **Professor:** Clayton Kossoski
- **Atividade:** Avaliativa 3
