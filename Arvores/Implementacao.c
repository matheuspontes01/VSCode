/*
    Implementando uma arvore binaria: 
    *Operacoes:
    1) criacao da arvore
    2) insercao de um elemento
    3) remocao de um elemento
    4) acesso a um elemento
    5) destruicao da arvore


    *Tipo: 
    1) Estatica
    * Uso de array
    * Usar 2 funcoes para retornar a posicao dos filhos à esquerda e à direita de um pai:
    FILHO_ESQ(pai) = 2 * PAI + 1;
    FILHO_DIR(pai) = 2 * PAI + 2;
    pai : indice da posicao do vertice pai


    *Desvantagem: ocupa muitos espacos em branco no vetor, precisa saber o tamanho da arvore

    - Dinamica
    * Utilizacao de lista encadeada
    * Cada no da arvore é tratado como um ponteiro alocado dinamicamente a medida que os dados são inseridos
    * O nó vai guardar essas informações: endereco do nó à esquerda | dado | endereço do nó à direita
    * Para guardar o primeiro no da arvore, utilizamos um "ponteiro para ponteiro" (ArvBin* raiz) -> Resolve o problema de quem e a raiz
    * 
*/