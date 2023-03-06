#include "pilha.c"

typedef struct calc {
    int format; 
    Pilha *p; 
} Calc;

Calc calc_cria(int f);
void calc_operando(Calc* c, float v); 
void calc_operador(Calc* c, char op);
void calc_libera(Calc *c);

int main(void){   
    setlocale(LC_ALL, "Portuguese");

    int n;
    printf("\n\nInforme o número de casas após a vírgula desejado: ");
    scanf("%d", &n);

    Calc calculadora = calc_cria(n);

    char opcao[21];
    while (1){
        printf("\n\nInforme o operando ou operador (Digite 'q' para sair): ");
        scanf("%s", opcao);
        if (opcao[0] == 'q' || opcao[0] == 'Q') {
            printf("\nSaindo do programa...");
            break;
        } else {
            if ((opcao[0] == '+' || opcao[0] == '-' || opcao[0] == '*' || opcao[0] == '/') && (strlen(opcao) == 1)) {
                calc_operador(&calculadora, opcao[0]);
            } else if (((opcao[0] == '0') && (strlen(opcao) == 1)) || ((atof(opcao) > 0) || (atof(opcao) < 0))){
                calc_operando(&calculadora, atof(opcao));
            } else {
                printf("\nERRO! Opção inexistente.");
                break;
            }
        }
    }
    calc_libera(&calculadora);
}

Calc calc_cria(int f){
    Calc c;
    c.format = f;
    c.p = pilha_cria();
    return c;
}

void calc_operando(Calc* c, float v){
    pilha_push(&(c->p), v);
    printf("\n%.*f", c->format, v);
}

void calc_operador(Calc* c, char op){
    float valor2 = 0.00f;
    float valor1 = 0.00f;
    if (!pilha_vazia(c->p)) {
        valor2 = pilha_pop(&(c->p));
        if (!pilha_vazia(c->p)) 
            valor1 = pilha_pop(&(c->p));
    } 
    float resultado;
    switch (op) {
        case '+': 
            resultado = valor1 + valor2;
            break;
        case '-':
            resultado = valor1 - valor2;
            break;
        case '*':
            resultado = valor1 * valor2;
            break;
        case '/':
            resultado = valor1 / valor2;
            break;
        default: printf("ERRO! Operador inexistente.");
    }
    pilha_push(&(c->p), resultado);
    printf("\n%.*f", c->format, resultado);
} 

void calc_libera(Calc *c) {
    pilha_libera(&(c->p));
    c->format = NULL;
}
