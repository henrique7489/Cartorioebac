#include <stdio.h> //bliblioteca de comunicação com o usuário
#include <stdlib.h> //bliblioteca de alocação de espaço em memória
#include <locale.h> //bliblioteca de alocação de texto por região
#include <string.h> //bliblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variável/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletandoi informação do usuário
	scanf("%s", cpf); //refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // chama e cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); // virgula 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); // nome do cliente
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");// virgula 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); // sobrenome do cliente
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); // virgula
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s,",cargo); // cargo do cliente
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");		
}

int consultar () //inicio da função de consultar cliente/aluno
{
	//inicio criação de variáveis/string
	setlocale(LC_ALL, "Portuguese"); //Linguagem para identificar a acentuação
	char cpf[40];
	char conteudo[200];
	//final da criação de variável/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abre arquivo
	
	if(file == NULL) //caso não localizar o arquivo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //mostra as informações caso localizada
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Fim da função de consultar cliente/aluno
}

int deletar() //Começo da função deletar cliente/aluno
{
	//inicio criação de variáveis/string
	char cpf[40];
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	//final da criação de variável/string
	
	//Diferente do exercicio aqui foi utlizado o else.
	if(remove(cpf) == 0){
	  	printf("Cliente deletado com sucesso.\n");  
	} else {
		printf("O usuário não se encontra no sistema! .\n");
	}
	
	system("pause"); //Fim do função de deletar cliente/aluno
}
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Defenindo a linguagem
	
		printf("\t### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("\tEscolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();	//chamada de funções	
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause"); 
					
		}  //fim da seleção
	
    }
}
