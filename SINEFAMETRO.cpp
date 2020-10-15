#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>
#include <unistd.h>


//declaracao de registro
typedef struct {
 char login[15];
 char senha[15];
} Administrador;

typedef struct {
	char rua[50];
	char casa[5];
	char bairro[10];
}Endereco;

typedef struct {
 char nome[15];
 char login[15];
 char senha[15];
 float matricula[10];
 char telefone[9];
 Endereco endereco;
 
}Funcionario;

typedef struct {
	char nome_curso[50];
	char sigla_curso[10];
}Curso;

typedef struct {
	char nome_instituto[50];
	Endereco endereco;
	char cnpj[14];
	char telefone[9];
	Curso cursos[10];
} Instituicao;
typedef struct{
 char nome_aluno[50];
 char curso[50];
 char instituicao[50];
 char matricula[5];
 char login_email[50];
 char senha[50];
 int status;
 float saldo;
 int credito;
}Aluno;

//variaveis globais
Administrador adm;
Funcionario funcionarios[3];
int countFunc = 0, countCurso = 0, countInst = 0, countAlu = 0;
Aluno alunos[3];
Curso cursos[10];
Instituicao instituicoes[10];
char alunoOnline[5];



//procedures
void MenuAdmin();
void MenuFunc();
void Admin();
void Login();
void CadastrarFun();
void CadastrarCurso();
void CadastrarInstituicao();
void CadastrarAluno();
void PesquisarERecarregar();
void AprovarAlunos();
void VisualizarCreditosESaldo();
//MAIN
int main() {
	setlocale(LC_ALL,"portuguese");
	Admin();
	do {
		Login();
	}while(true);
	
}

//Procedures logic
void MenuAdmin(){
	
int op;
int aprovar = 0;	
int tam2 = (int) (sizeof(alunos) / sizeof(alunos[0]));
	
	if(countAlu > 0) {
		for(int i = 0; i <= tam2; i++) {
		 	if (alunos[i].status == 0) {
		 		aprovar++;
			}
	 	}
	}
	 
	 do{
	 system("cls");	
	 printf("*---------------------------------BEM-VINDO AO SINEFAMETRO----------------------------------------------*\n");
	 printf("\t\t\t\t\t1-Cadastrar Funcionario\n");
	 printf("\t\t\t\t\t2-Cadastrar Curso\n");
	 printf("\t\t\t\t\t3-Cadastrar Instituicao\n");
	 printf("\t\t\t\t\t4-Cadastrar Aluno\n");
	 printf("\t\t\t\t\t5-Pesquisar Aluno\n");
		if(aprovar > 0 && countAlu > 0) {
			printf("\t\t\t\t6-Ativar Alunos novos");
		}
	 printf("\t\t\t\t\t0-Sair\n");
	 
	 printf("\n\n *--------------------------------DIGITE O CODIGO DE UMA DAS OPCOES ACIMA--------------------------------*\n");
	 scanf("%d",&op);
	 switch(op){
		case 1:
			CadastrarFun();
			break;
		case 2:
			CadastrarCurso();
			break;	
		case 3:
			CadastrarInstituicao();
			break;
		case 4:
			CadastrarAluno();
			break;
		case 5:
			PesquisarERecarregar();
			break;
		case 6:
			AprovarAlunos();
			break;
		case 0:
			op = 0;
			break;
		default:
		printf("Opcao invalida\n");	
			
     }//fim switch menu
	}while(op!=0);//fim do while menu	
	
}//fim procedimento menu

void MenuFunc(){
	
int op;
	 do{
	 system("cls");	
	 printf("*---------------------------------BEM-VINDO AO SINEFAMETRO----------------------------------------------*\n");
	 printf("\t\t\t\t\t1-Cadastrar Aluno\n");
	 printf("\t\t\t\t\t2-Pesquisar Aluno\n");
	 printf("\t\t\t\t\t0-Sair\n");
	 
	 printf("\n\n *--------------------------------DIGITE O CODIGO DE UMA DAS OPCOES ACIMA--------------------------------*\n");
	 scanf("%d",&op);
	 switch(op){
		case 1:
			CadastrarAluno();
			break;
		case 2:
			PesquisarERecarregar();
			break;	
		case 0:
			op = 0;
			break;
		default:
		printf("Opcao invalida\n");	
			
     }//fim switch menu
     system("pause");
	}while(op!=0);//fim do while menu	
	
}//fim procedimento menu
void Admin() {
	strcpy(adm.login, "ADM");
	strcpy(adm.senha, "123");
}

void Login() {
	int checkd = 0, tam = (int) sizeof(funcionarios) / sizeof(funcionarios[0]);
	char login[15], senha[15];
	
	do {
		system("cls");	
		printf("*---------------------------------LOGIN----------------------------------------------*\n");
		printf("Login: ");
		scanf("%s", &login);
		printf("\nSenha: ");
		scanf("%s", &senha);
		
		if (stricmp(login, adm.login) == 0 && stricmp(senha, adm.senha) == 0) {
			MenuAdmin();
		}
		
		for (int i = 1; i <= countFunc; i++) {
			if (stricmp(login, funcionarios[i-1].login) == 0 && stricmp(senha, funcionarios[i-1].senha) == 0) {
				MenuFunc();
			}
		}
		
		for (int j = 1; j <= countAlu; j++) {
			if (stricmp(login, alunos[j-1].login_email) == 0 && stricmp(senha, alunos[j-1].senha) == 0) {
				strcpy(alunoOnline, alunos[j-1].matricula);
				VisualizarCreditosESaldo();
			}
		}
		
		if (checkd != 1) {
			printf("\nUsuario invalido, tente novamente...");
			sleep(2);
			
		}
	}while(checkd != 1);
}

void CadastrarFun() {
	int checked = 0;
	
	do {
	 system("cls");	
	 printf("*---------------------------------TELA CADASTRO FUNCIONARIO----------------------------------------------*\n");
	 printf("\n");
	 printf("Digite o nome do funcionario: ");
	 scanf("%s", &funcionarios[countFunc].nome);
	 
	 printf("\nDigite matricula do funcionario: ");
	 scanf("%s", &funcionarios[countFunc].matricula);
	 
	 printf("\n\n*---------------------------------Endereco----------------------------------------------*\n");
	 printf("\n");
	 printf("Digite rua do funcionario: ");
	 scanf("%s", &funcionarios[countFunc].endereco.rua);
	 
	 printf("\nDigite numero da casa do funcionario: ");
	 scanf("%s", &funcionarios[countFunc].endereco.casa);
	 
	 printf("\nDigite bairro do funcionario: ");
	 scanf("%s", &funcionarios[countFunc].endereco.bairro);
	 
	 printf("*\n\n---------------------------------Dados adicionais----------------------------------------------*\n");
	 printf("\n");
	 
	 printf("Digite telefone do funcionario: ");
	 scanf("%s", &funcionarios[countFunc].telefone);
	 
	 printf("\nDigite login para o funcionario: ");
	 scanf("%s", &funcionarios[countFunc].login);
	 
	 printf("\nDigite senha para o funcionario: ");
	 scanf("%s", &funcionarios[countFunc].senha);
	 
	 printf("\nFuncionario cadastrado com sucesso! Deseja cadastrar mais? 1 - SIM; 0 - NAO");
	 scanf("%d", &checked);
	 
	 if (countFunc == 2) {
	 	printf("\n Base de dados para funcionarios está cheia.");
		checked = 0;
	 } else {
		countFunc++;
	 }
	 
	 if (checked == 1) {
	 	sleep(2);
	 }
	
	}while(checked != 0);
}

void CadastrarCurso() {
	int checked = 0;
	
	do {
	 system("cls");	
	 printf("*---------------------------------TELA CADASTRO DE CURSOS----------------------------------------------*\n");
	 printf("\n");
	 printf("Digite o nome do curso: ");
	 scanf("%s", &cursos[countCurso].nome_curso);
	 
	 printf("\nDigite a sigla para o curso: ");
	 scanf("%s", &cursos[countCurso].sigla_curso);
	 
	 printf("\nCurso cadastrado com sucesso! Deseja cadastrar mais? 1 - SIM; 0 - NAO");
	 scanf("%d", &checked);
	 
	 
	 
	 if (checked == 1) {
	 	sleep(2);
	 	if (countCurso == 9) {
		 	printf("\n Base de dados para cursos está cheia.");
			checked = 0;
		 } else {
			countCurso++;
		 }
	 } else if(checked != 0) {
	 	printf("\nOpção inválida, saindo...");
	 	checked = 0;
	 }
	
	}while(checked != 0);
}

void CadastrarInstituicao() {
	int checked = 0, checkCur = 0;
	int tam = (int) (sizeof(cursos) / sizeof(cursos[0]));
	if (tam == 0) {
		printf("Antes de cadastrar uma instituicao, você deve ter cursos cadastrados na base de dados.");
	} else {
		do {
		 system("cls");	
		 printf("*---------------------------------TELA CADASTRO DE INSTITUICAO----------------------------------------------*\n");
		 printf("\n");
		 printf("Digite o nome da instituicao: ");
		 scanf("%s", &instituicoes[countInst].nome_instituto);
		 
		 printf("\nDigite CNPJ da instituicao: ");
		 scanf("%s", &instituicoes[countInst].cnpj);
		 
		 printf("*---------------------------------Endereco----------------------------------------------*\n");
		 printf("\n");
		 printf("Digite rua da instituicao: ");
		 scanf("%s", &instituicoes[countInst].endereco.rua);
		 
		 printf("\nDigite numero da instituicao: ");
		 scanf("%s", &instituicoes[countInst].endereco.casa);
		 
		 printf("\nDigite bairro da instituicao: ");
		 scanf("%s", &instituicoes[countInst].endereco.bairro);
		 
		 printf("*---------------------------------Dados adicionais----------------------------------------------*\n");
		 printf("\n");
		 
		 printf("Digite telefone da instituicao: ");
		 scanf("%s", &instituicoes[countInst].telefone);
		 
		 do {
		 	int cursoSelect = 0, incrementCurso = 0;
		 	
		 	printf("*---------------------------------Selecione um curso ----------------------------------------------*\n");
		 	printf("\n");
		 	
		 	for (int i = 0; i <= tam; i++) {
		 		printf("%d - %s\n", i, cursos[i]);
			}
			scanf("%d", &cursoSelect);
			instituicoes[countInst].cursos[incrementCurso] = cursos[cursoSelect];
			
			printf("Deseja cadastrar mais cursos? 1 - SIM; 0 - NAO\n");
			scanf("%d", &checkCur);
			
			if (checkCur == 1) {
				incrementCurso++;
				cursoSelect = 0;
			}
			
		 } while(checkCur != 0);
		 
		 printf("\nInstituicao cadastrada com sucesso! Deseja cadastrar mais? 1 - SIM; 0 - NAO");
		 scanf("%d", &checked);
		 
		 if (countInst == 9) {
		 	printf("\n Base de dados para instituicao está cheia.");
			checked = 0;
		 } else {
			countInst++;
		 }
		 
		 if (checked == 1) {
		 	sleep(2);
		 }
		
		}while(checked != 0);
	}
	
}

void CadastrarAluno() {
	int checked = 0, checkCur = 0;
	
	int tam2 = (int) (sizeof(instituicoes) / sizeof(instituicoes[0]));
	int tam = (int) (sizeof(cursos) / sizeof(cursos[0]));
	if (tam == 0 || tam2 == 0) {
		printf("Antes de cadastrar um aluno, você deve ter cursos e instituicoes cadastradas na base de dados.");
	} else {
		do {
		 system("cls");	
		 printf("*---------------------------------TELA CADASTRO DE ALUNO----------------------------------------------*\n");
		 printf("\n");
		 printf("Digite o nome do aluno: ");
		 scanf("%s", &alunos[countAlu].nome_aluno);
		 
		 printf("\nDigite matricula do aluno: ");
		 scanf("%s", &alunos[countAlu].matricula);
		 
		 printf("\nDigite curso do aluno: ");
		 scanf("%s", &alunos[countAlu].curso);
	     
	     
		 for (int i = 0; i <= tam2; i++) {
		 	int tamanho = (int) (sizeof(instituicoes[i].cursos) / sizeof(instituicoes[i].cursos[0]));
		 	for(int j = 0; j <= tamanho; j++) {
		 		if (stricmp(instituicoes[i].cursos[j].nome_curso, alunos[countAlu].curso) == 0) {
		 			strcpy(alunos[countAlu].instituicao, instituicoes[i].nome_instituto);
				 } else {
				 	strcpy(alunos[countAlu].instituicao, "NULL");
				 }
			 }
		 }
		 
		 printf("\nDigite email do aluno: ");
		 scanf("%s", &alunos[countAlu].login_email);
		 
		 printf("\nDigite senha do aluno: ");
		 scanf("%s", &alunos[countAlu].senha);
		 
		 alunos[countAlu].status = 0;
		 alunos[countAlu].saldo = 0.0;
		 alunos[countAlu].credito = 0;
		 
		 printf("\nAluno cadastrado com sucesso! Deseja cadastrar mais? 1 - SIM; 0 - NAO");
		 scanf("%d", &checked);
		 
		 if (countAlu == 2) {
		 	printf("\n Base de dados para alunos está cheia.");
			checked = 0;
		 } else {
			countAlu++;
		 }
		 
		 if (checked == 1) {
		 	sleep(2);
		 }
		
		}while(checked != 0);
	}
	
}

void PesquisarERecarregar() {
	int tam = (int) (sizeof(alunos) / sizeof(alunos[0]));
	int addCredit = 0;
	float valor;
	char searchMat[5];
	
	 system("cls");	
	 printf("*---------------------------------PESQUISA DE ALUNO POR MATRICULA----------------------------------------------*\n");
	 printf("Digite a matricula do aluno, para continuação da pesquisa: ");
	 scanf("%s", &searchMat);
	 
	 for(int i = 0; i <= tam; i++) {
	 	if (stricmp(searchMat, alunos[i].matricula) == 0 ) {
	 		printf("\nAluno encontrado...");
	 		printf("\n---------------------------------------------------------------------------");
	 		printf("\nNome: %s", alunos[i].nome_aluno);
	 		printf("\nMatricula: %s", alunos[i].matricula);
	 		printf("\nCurso: %s", alunos[i].curso);
	 		printf("\nInstituição: %s", alunos[i].instituicao);
	 		printf("\n---------------------------------------------------------------------------");
	 		
	 		do {
	 			printf("\nDeseja adicionar creditos ao aluno? 1 - SIM. 0 - NÃO");
	 			scanf("%d", &addCredit);
	 			
	 			if (addCredit == 1) {
	 				printf("\nDigite o valor em R$ para adicionamento de créditos.");
	 				scanf("%f", &valor);
	 				
					 int newCredito = 0;
	 				 newCredito = (valor + alunos[i].saldo) / 1.5;
	 				 alunos[i].saldo = (valor + alunos[i].saldo) - (newCredito * 1.5);
					 alunos[i].credito += newCredito;
					 
					 
					 printf("\nRecarga feita com sucesso total de créditos: %d", alunos[i].credito);
					 printf("\nSaldo para próximas recargas: %.2f", alunos[i].saldo);
				 } else if (addCredit != 0) {
				 	printf("\nDígito inválido, tente novamente!!");
				 }
			 }while(addCredit != 0);
	 		
	 		
		 }
	 }
	 
	 
}

void AprovarAlunos() {
	int count = 0, op = 0, encontrado = 0;
	char matricula[5];
	for(int i = 0; i <= countAlu; i++) {
	 	if (alunos[i].status == 0) {
	 		count++;
		 }
	}
	system("cls");	
	 printf("*---------------------------------APROVAR ALUNOS INATIVOS----------------------------------------------*\n");
	 printf("Existe %d de alunos para aprovar", &count);
	 do {
	 	printf("Você desejar aprovar estes alunos? Escolher 1 para atualizar? DIGITE 1 ou 2 PARA TODOS!!");
	 	scanf("%d", op);
	 	
	 	if (op == 2) {
	 		for(int i = 0; i <= countAlu; i++) {
			 	if (alunos[i].status == 0) {
			 		alunos[i].status == 1;
				 }
			}
			printf("\n Todos alunos que estavam inativos foram aprovados!");
		 } else if(op == 1) {
		 	printf("\nDigite a matricula do aluno para aprova-lo");
		 	scanf("%s", &matricula);
		 	for(int i = 0; i <= countAlu; i++) {
			 	if (stricmp(matricula, alunos[i].matricula) == 0 ) {
			 		alunos[i].status == 1;
			 		encontrado = 1;
			 		printf("\nAluno: $s foi aprovado com sucesso!", alunos[i].nome_aluno);
			 		break;
				 }
			}
			
			if (encontrado == 0) {
				printf("\nNão existe aluno com está matricula na base de dados!");
				op = 0;
			}
		 } else {
		 	printf("\nOpção invalida, tente novamente!");
		 }
	 	
	 }while(op != 1 && op != 2);
	 
}

void VisualizarCreditosESaldo() {
	for(int i = 0; i <= countAlu; i++) {
	 	if (stricmp(alunoOnline, alunos[i].matricula) == 0 ) {
	 		printf("\n*---------------------------------DADOS ALUNO----------------------------------------------*\n");
	 		printf("Bem-vindo %s você possui um total de %d de créditos e saldo para próximas recargas de %.2f.", alunos[i].nome_aluno, alunos[i].credito, alunos[i].saldo);
	 		
		 }
	}
}
