#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes
const int TAMANHO = 256;
const int ALUNOS = 14;

//Structs
struct Aluno {
	int index;
	char* nome;
	char* email;
	int ru;
};
struct Aluno* alunos[ALUNOS];

//Prototipos
void InicializarAlunos();
void InicializarAluno(const char* nome, const char* email, int ru);
void ListarAlunos();
void ListarAluno(Aluno* aluno);
void Trocar(int anterior, int proximo);
//Por RU
void BubbleSortPorRU();
void OrdernarRU(int aluno1, int aluno2);
int BinarySearchPorRU(int inicio, int fim, int busca);
int CompararRU(const char* nome, const char* comparacao);
//Por Nome
void BubbleSortPorNome();
void OrdernarNome(int aluno1, int aluno2);
int BinarySearchPorNome(int inicio, int fim, const char* busca);
int CompararNomeMaior(const char* nome, const char* comparacao);

//Index Automatico
int indexAlunos = 0;

void main()
{
	InicializarAlunos();
	//Logica do Menu. Enquanto finalizar for falso, o menu continua rodando
	int finalizar = 0;
	char* buscaNome = (char*)malloc(sizeof(char) * TAMANHO);
	int buscaRU = -1;
	int index = -1;
	while (!finalizar)
	{
		printf("Opcoes:\n1- Buscar por nome\n2- Buscar por ru\n3- Listar alunos\n4- Finalizar\n> ");
		int opcao = 0;
		scanf_s("%d", &opcao);
		switch (opcao)
		{
		case 1:
			BubbleSortPorNome();
			ListarAlunos();
			printf("Digite um nome para procurar da lista acima:\n> ");
			scanf_s("%s", buscaNome, TAMANHO);
			index = BinarySearchPorNome(0, ALUNOS, buscaNome);
			printf("Index buscado eh: %d\n", index);			
			if (index == -1)
			{
				printf("Nome nao encontrado!\n");
				continue;
			}
			ListarAluno(alunos[index]);
			break;
		case 2:
			BubbleSortPorRU();
			ListarAlunos();
			printf("Digite um ru para procurar da lista acima:\n> ");
			scanf_s("%d", &buscaRU);
			index = BinarySearchPorRU(0, ALUNOS, buscaRU);
			printf("Index buscado eh: %d\n", index);
			if (index == -1)
			{
				printf("RU nao encontrado!\n");
				continue;
			}
			ListarAluno(alunos[index]);
			break;
		case 3:
			ListarAlunos();
			break;
		default:
			finalizar = 1;
			break;
		}
	}

	system("pause");
}

//Inicializacao
void InicializarAlunos()
{
	//Inicializa todos os alunos
	InicializarAluno("Ingrid", "ingrid@email.com", 983756);
	InicializarAluno("Felipe", "felipe@email.com", 123213);
	InicializarAluno("Joao", "joao@email.com", 532563);
	InicializarAluno("Rafael", "rafael@email.com", 785612);
	InicializarAluno("Stephanie", "stephanie@email.com", 95472);
	InicializarAluno("Brian", "brian@email.com", 78254);
	InicializarAluno("Monica", "monica@email.com", 310564);
	InicializarAluno("Marcelo", "marcelo@email.com", 50964);
	InicializarAluno("Belinha", "belinha@email.com", 140513);
	InicializarAluno("Lina", "lina@email.com", 211108);
	InicializarAluno("Elune", "elune@email.com", 121108);
	InicializarAluno("Meg", "meg@email.com", 51019);
	InicializarAluno("Nilze", "nilze@email.com", 3312120);
	InicializarAluno("Gabriel", "gabriel@email.com", 131189);
}
void InicializarAluno(const char* nome, const char* email, int ru)
{
	//Inicializa o aluno com os parametros passados. Aloca memoria para os ponteiros da string
	alunos[indexAlunos] = (struct Aluno*)malloc(sizeof(struct Aluno));
	alunos[indexAlunos]->nome = (char*)malloc(sizeof(char) * TAMANHO);
	alunos[indexAlunos]->email = (char*)malloc(sizeof(char) * TAMANHO);

	alunos[indexAlunos]->index = indexAlunos;
	//Copia as strings usando strcpy_s
	strcpy_s(alunos[indexAlunos]->nome, TAMANHO, nome);
	strcpy_s(alunos[indexAlunos]->email, TAMANHO, email);
	alunos[indexAlunos]->ru = ru;
	//Aumenta o index a cada vez que um aluno novo é inserido
	indexAlunos++;
}

//Listagem
void ListarAlunos()
{
	for (int i = 0; i < ALUNOS; i++)
	{
		ListarAluno(alunos[i]);
	}
}
void ListarAluno(Aluno* aluno)
{
	printf("Id: %02d - Nome: %9s - Email: %19s - RU: %d\n", aluno->index, aluno->nome, aluno->email, aluno->ru);
}
void Trocar(int anterior, int proximo)
{
	//Realiza a troca de elementos com os indices passados usando uma variavel auxiliar
	//Também atribui o indice ao campo index da struct aluno para melhor visualizacao
	Aluno* aux = alunos[anterior];
	alunos[anterior] = alunos[proximo];
	alunos[anterior]->index = anterior;
	alunos[proximo] = aux;
	alunos[proximo]->index = proximo;
}

//Por RU
void BubbleSortPorRU()
{
	//Chama o método Trocar se o ru for menor, ordenando ascendentemente
	for (int i = 0; i < ALUNOS - 1; i++)
	{
		for (int j = 0; j < ALUNOS - i - 1; j++)
		{
			if (alunos[j]->ru > alunos[j + 1]->ru)
			{
				Trocar(j, j + 1);
			}
		}
	}
}
int BinarySearchPorRU(int inicio, int fim, int busca)
{
	//Se o fim for maior que inicio ou fim for maior que o total tamanho do vetor, busca nao existe e retorna -1
	if (fim < inicio || fim > ALUNOS)
	{
		return -1;
	}

	//Calcula o ponto mediano entre os elementos inicio e fim
	int mid = inicio + (fim - inicio) / 2;

	//Se o ponto mediano for igual ou maior que o total de elementos, elemento nao existe
	if (mid >= ALUNOS)
	{
		return -1;
	}

	//Apenas para Debug. Vou deixar para ficar mais claro qnd o programa rodar
	printf("Atual Mid: %s \n", alunos[mid]->nome);

	//Se o ru for igual a busca, retorna o índice
	if (alunos[mid]->ru == busca)
	{
		return mid;
	}

	//Se todos os indices forem iguais, elemento não existe
	if (inicio == fim == mid)
	{
		return -1;
	}

	//Se o RU for maior que a busca, chama o metodo novamente, passando o ponto mediano como fim
	if (alunos[mid]->ru > busca)
	{
		return BinarySearchPorRU(inicio, mid, busca);
	}

	//Se o RU for menor que a busca, chama o metodo novamente, passando o ponto mediano mais 1 como inicio
	return BinarySearchPorRU(mid + 1, fim, busca);
}

//Por Nome
void BubbleSortPorNome()
{
	//Chama o método Trocar se as letras do nome forem menores, ordenando ascendentemente
	for (int i = 0; i < ALUNOS - 1; i++)
	{
		for (int j = 0; j < ALUNOS - i - 1; j++)
		{
			OrdernarNome(j, j + 1);
		}
	}
}
void OrdernarNome(int aluno1, int aluno2)
{
	//Recupera o tamanho da string utilizando strlen
	int tamanho = strlen(alunos[aluno1]->nome);

	//Varre todas as letras da string comparando
	for (int i = 0; i < tamanho; i++)
	{
		//Se a letra for igual, passa a próxima
		if (alunos[aluno1]->nome[i] == alunos[aluno2]->nome[i])
		{
			continue;
		}

		//Se a letra for menor, troca. Pois alfabeticamente letras menores vem na frente
		if (alunos[aluno1]->nome[i] > alunos[aluno2]->nome[i])
		{
			Trocar(aluno1, aluno2);
			break;
		}

		//Se chegar aqui, significa que a letra é menor e não precisa ser trocada
		break;
	}
}
int BinarySearchPorNome(int inicio, int fim, const char* busca)
{
	//Se o fim for maior que inicio ou fim for maior que o total tamanho do vetor, busca nao existe e retorna -1
	if (fim < inicio || fim > ALUNOS)
	{
		return -1;
	}

	//Calcula o ponto mediano entre os elementos inicio e fim
	int mid = inicio + (fim - inicio) / 2;

	//Se o ponto mediano for igual ou maior que o total de elementos, elemento nao existe
	if (mid >= ALUNOS)
	{
		return -1;
	}

	//Apenas para Debug. Vou deixar para ficar mais claro qnd o programa rodar
	printf("Atual Mid: %s \n", alunos[mid]->nome);

	//Se o nome for igual a busca, retorna o índice (Usando strcmp para comparar as 2 strings)
	if (strcmp(alunos[mid]->nome, busca) == 0)
	{
		return mid;
	}

	//Se todos os indices forem iguais, elemento não existe
	if (inicio == fim == mid)
	{
		return -1;
	}

	//Se as letras do nome forem maiores que a busca, chama o metodo novamente, passando o ponto mediano como fim
	if (CompararNomeMaior(alunos[mid]->nome, busca))
	{
		return BinarySearchPorNome(inicio, mid, busca);
	}

	//Se as letras do nome forem menores que a busca, chama o metodo novamente, passando o ponto mediano mais 1 como inicio
	return BinarySearchPorNome(mid + 1, fim, busca);
}
int CompararNomeMaior(const char* nome, const char* comparacao)
{
	//Recupera o tamanho da string nome
	int tamanho = strlen(nome);
	int resultado = 0;
	//Varre a palavra para comparar. Similar a ordenação
	for (int i = 0; i < tamanho; i++)
	{
		//Se a letra for igual, passa a próxima
		if (nome[i] == comparacao[i])
		{
			continue;
		}

		//Se a letra for menor, troca. Pois alfabeticamente letras menores vem na frente
		if (nome[i] > comparacao[i])
		{
			resultado = 1;
		}
		//Se chegar aqui, significa que a letra é menor e não precisa ser trocada
		break;
	}

	return resultado;
}
