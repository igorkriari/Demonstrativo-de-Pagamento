#include<stdio.h>
#include<stdlib.h>
/*LINKS UTILIZADOS NO TRABALHO
  SALARIO MINIMO https://bxblue.com.br/aprenda/segundo-aumento-do-salario-minimo-em-2020/

  FGTS https://www.folhavitoria.com.br/economia/noticia/05/2020/confira-como-consultar-o-saldo-do-fgts-e-veja-se-pode-sacar-os-r-1-045-em-junho

  IMPOSTO DE RENDA https://blog.convenia.com.br/como-calcular-irrf-na-folha-de-pagamento/

  INSS https://www.contabeis.com.br/noticias/42234/calculo-da-nova-tabela-progressiva-do-inss-aliquotas-e-parcela-a-deduzir/

  TODAS AS FUNÇÕES ESTARÃO AQUI ABAIXO*/
float calculoFGTS (float salBruto){
    float fgtsCalc = salBruto*0.08;
     return fgtsCalc;}

float calculoINSS (float salBruto){
    float inssFinal;
       if (salBruto <= 1045.01) inssFinal = salBruto*0.075;
       else if (salBruto > 1045.01 && salBruto <= 2089.60) inssFinal = salBruto*0.09;
       else if (salBruto > 2089.60 && salBruto <= 3134.40) inssFinal = salBruto*0.12;
       else if (salBruto > 3134.40 && salBruto <= 6101.06) inssFinal = salBruto*0.14;
       else if (salBruto > 6101.06) inssFinal = 713.10;
     return inssFinal;}

float calculoIRPF (float salBruto, float INSS, float qtddepen){
    float irpfFinal, dependentes,salMdescontos;
    dependentes = qtddepen*189.59;
    salMdescontos = salBruto-INSS-dependentes;

     if (salMdescontos <= 1903.98) irpfFinal = 0;
       else if (salMdescontos > 1903.98 && salMdescontos <= 2826.65) irpfFinal = (salMdescontos*0.075)-142.80;
       else if (salMdescontos > 2826.65 && salMdescontos <= 3751.05) irpfFinal = (salMdescontos*0.15)-354.80;
       else if (salMdescontos > 3751.05 && salMdescontos <= 4664.69) irpfFinal = (salMdescontos*0.225)-636.13;
       else if (salMdescontos > 4664.69) irpfFinal = (salMdescontos*0.275)-869.36;
  return irpfFinal;}

int main (void){
  float salB, salL, FGTS,INSS,IRPF, dependentes, descontos, inssA, irffA, faixaIRRF;
  char s, nome[10], sobrenome[10], cargo[10];
system("cls");
  //INFORMAÇÕES ANTES DE COMEÇAR A COLETA DE DADOS. Fiz essa parte para que você saiba quais dados usei noe meus cálculos.
    printf("\n\n*INFORMACOES IMPORTANTES");
    printf("\n__________________________\n\n");
    printf("\n1. O salario minimo eh de R$ 1.045 desde 01/02/2020;");
    printf("\n\n2. FGTS = 8%% do salario bruto e nao eh descontado do salario;");
    printf("\n\n3. INSS = com a reforma da previdencia, a partir de Marco/2020 a aliquota do INSS varia progressivamente de acordo com a faixa salarial:");
    printf("\n\n          FAIXA SALARIAL         FAIXA  DE ALIQUOTA ");
    printf("\nate R$ 1.045 (salario minimo)    7,5%%");
    printf("\nentre R$ 1.045,01 e R$ 2.089,60  9%%      ");
    printf("\nentre R$ 2.089,61 e R$ 3.134,40	 12%%     ");
    printf("\nentre R$ 3.134,41 e R$ 6.101,06	 14%%     ");
    printf("\nAcima do teto  de   R$ 6.101,06	 7,13%% taxa fixa de R$ 713,09");
    printf("\n\n4. IRPF = salario bruto - aliquota do INSS - valor de deducao por dependente caso houver (deducao de R$ 189,59 mensais, por dependente) * aliquota do IR - a parcela a deduzir do IR. Veja a tabela do IRRF a seguir:");
    printf("\n\n   FAIXA  VALOR EM REAL              ALIQUOTA  A DEDUZIR");
    printf("\n     ate  R$1.903,98                  isencao");
    printf("\n1a faixa: R$ 1.903,99 a R$ 2.826,65   7,5%%     R$ 142,80");
    printf("\n2a faixa: R$ 2.826,66 a R$ 3.751,05   15%%      R$ 354,80");
    printf("\n3a faixa: R$ 3.751,06 a R$ 4.664,68   22,5%%    R$ 636,13");
    printf("\n4a faixa: a partir de R$ 4.664,69     27,5%%    R$ 869,36");
    printf("\n\nPressione ENTER para comecar o preenchimento");
    scanf("%c", &s);

  //COLETA DE DADOS COMEÇA AQUI
system("cls");
    printf("\n------------------------------------------------------------\n");
    printf("Preenchendo folha de pagamento de funcionario do RESTAURANTE\n");
    printf("------------------------------------------------------------\n");
    printf("\nVoce eh dono(a) de um restaurante chamado BALANCEADO.");
    printf("\n\nPor favor, informe:");
    printf("\nNome e apenas um sobrenome do funcionario: ");
      scanf("%s%s", nome, sobrenome);
    printf("O cargo do funcionario: ");
      scanf("%s", cargo);
    printf("O salario bruto do funcionario: ");
      scanf("%f", &salB);
    printf("A quatidade de dependentes do funcionario: ");
      scanf("%f", &dependentes);

    FGTS = calculoFGTS(salB);
    INSS = calculoINSS(salB);
    IRPF = calculoIRPF(salB, INSS, dependentes);
    inssA = INSS/salB*100;
    irffA = IRPF/salB*100;
    descontos = INSS + IRPF;
    salL = salB - descontos;
     faixaIRRF = salB-INSS-(dependentes*189.59);
  //TELA FINAL COM A FOLHA DE PAGAMENTO PRONTA E PREENCHIDA
system("cls"); //limpeza de tela para resultado final
  printf("\n____________________________________________________");
  printf("\n\n             Recibo de pagamento de salario");
  printf("\n____________________________________________________");
  printf("\n\nBalanceado Restaurante LTDA                Maio/2020");
  printf("\nCNPJ: 07.258.885/0001-72");
  printf("\n\nCODIGO | NOME DO FUNCIONARIO                   CARGO");
  printf("\n  001  | %s %s                       %s",nome, sobrenome,cargo);
  printf("\n\n----------------------------------------------------");
  printf("\nDESCRICAO     REFERENCIA     VENCIMENTO     DESCONTO");
  printf("\nSalario              30d      R$%.2f", salB);
  printf("\nINSS                 %.0f%%                    R$%.2f",inssA, INSS);
  printf("\nIRRF S. SALARIO    %.2f%%(aliquota efetiva)  R$%.2f",irffA, IRPF);
  printf("\n\n                           TOTAL VENCI.   TOTAL DESC.");
  printf("\n                              R$%.2f     R$%.2f", salB, descontos);
  printf("\n\n                          VALOR LIQUIDO >> R$%.2f", salL);
  printf("\n\nsal. base        R$%.2f", salB);
  printf("\nsal contri INSS  R$%.2f", salB);
  printf("\nbase calc FGTS   R$%.2f", salB);
  printf("\nFGTS do mes      R$%.2f", FGTS);
  printf("\nBase calc IRRF   R$%.2f", faixaIRRF);
    if (faixaIRRF <= 1903.98) printf("\nfaixa IRRF       isento");
       else if (faixaIRRF > 1903.98 && faixaIRRF <= 2826.65) printf("\nfaixa IRRF       primeira: 7,5%%");
       else if (faixaIRRF > 2826.65 && faixaIRRF <= 3751.05) printf("\nfaixa IRRF       segunda: 15%%");
       else if (faixaIRRF > 3751.05 && faixaIRRF <= 4664.69) printf("\nfaixa IRRF       terceira: 22,5%%");
       else if (faixaIRRF > 4664.69) printf("\nfaixa IRRF       quarta: 27,5%%");
  return 0;}
