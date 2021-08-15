#include <stdio.h>
#include <stdlib.h>

//Constantes
const int TAMANHO = 256;

//Structs
struct Musica
{
    char *nome;
    char *banda;
    char *duracao;
};

struct Node
{
    struct Musica *musica;
    struct Node *next;
};

struct Node *inicio = NULL;
struct Node *atual = NULL;

//Prototipos
void Inserir();
void InicializarLista();
Node *InicializarNode();
void Listar();
void ListarMusica(Musica *musica);

//Main
int main()
{
    //Logica do Menu. Enquanto finalizar for falso, o menu continua rodando
    int finalizar = 0;
    while (!finalizar)
    {
        printf("Opcoes:\n1- Inserir nova musica\n2- Listar musicas\n3- Finalizar\n> ");
        int opcao = 0;
        scanf_s("%d", &opcao);
        switch (opcao)
        {
        case 1:
            Inserir();
            break;
        case 2:
            Listar();
            break;
        default:
            finalizar = 1;
            break;
        }
    }

    system("pause");
}

//Metodos
void Inserir()
{
    //Caso o nó inicio for nulo, ele inicializa (acontece apenas na primeira iteração)
    if (inicio == NULL)
    {
        InicializarLista();
    }
    //Caso o proximo nó for nulo, inicializa o nó
    if (atual->next == NULL)
    {
        atual = InicializarNode();
    }

    //Lê os dados das musicas e os guarda na struct musica e atribui nulo ao proximo para tirar sujeira do ponteiro
    printf("Digite o nome da musica: ");
    scanf_s("%s", atual->musica->nome, TAMANHO);
    printf("Digite o nome da banda: ");
    scanf_s("%s", atual->musica->banda, TAMANHO);
    printf("Digite a duracao da musica: ");
    scanf_s("%s", atual->musica->duracao, TAMANHO);
    atual->next = NULL;
}

void InicializarLista()
{
    //Inicializa a lista e atribui inicio a atual
    inicio = InicializarNode();
    atual = inicio;
}

Node *InicializarNode()
{
    //Inicializa um nó novo e inicializa todos seus campos com tamanho padrao definido nas contantes
    Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->musica = (struct Musica *)malloc(sizeof(struct Musica));
    node->musica->nome = (char *)malloc(sizeof(char) * TAMANHO);
    node->musica->banda = (char *)malloc(sizeof(char) * TAMANHO);
    node->musica->duracao = (char *)malloc(sizeof(char) * TAMANHO);

    //Caso o atual nao seja nulo, atribui o nó criado ao proximo e muda atual para o nó criado
    if (atual != NULL)
    {
        atual->next = node;
        atual = node;
    }
    return node;
}

void Listar()
{
    Node *busca = inicio;

    //Enquanto busca não for nulo, imprime os campos da musica na tela
    while (busca != NULL)
    {
        ListarMusica(busca->musica);
        busca = busca->next;
    }
}

void ListarMusica(Musica *musica)
{
    printf("Nome: %s - Banda: %s - Duracao: %s \n", musica->nome, musica->banda, musica->duracao);
}
