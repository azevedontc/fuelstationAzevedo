#define C_RED     "\x1b[31m"
#define C_GREEN   "\x1b[32m"
#define C_YELLOW  "\x1b[33m"
#define C_BLUE    "\x1b[34m"
#define C_MAGENTA "\x1b[35m"
#define C_CYAN    "\x1b[36m"
#define C_RESET   "\x1b[0m"

struct MCarro
{
    char modelo[30];
    char marca[30];
    int ano;
    int tanque;
};

void imprimeMCarro(struct MCarro l)
{
    printf("\nDados do carro:\n");
    printf("Modelo: %s \nMarca: %s \nAno: %d\n", l.modelo, l.marca, l.ano);
}

void lerString(char s[], int t)
{
    // limpaBuffer();
    fgets(s, t, stdin);
    s[strcspn(s, "\n")] = 0;
}

void apagacarro1(struct MCarro *l)
{
    strcpy(l->modelo, "");
    strcpy(l->marca, "");
    l->ano = 0;
}

void limpaTela()
{
    printf("\33[H\33[2J");
}

void limpaBuffer()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

int op1(int quant, int tam)
{
    if (quant < tam)
    {
        quant++;
        printf(C_RED "\n Carro adicionado com sucesso !" C_RESET);
        printf("\n");
        printf("\n Tamanho atual da fila %d !", quant);
        printf("\n");
        printf("\n Limite da fila %d !", tam);
        printf("\n");
    }
    if (quant >= tam)
    {
        printf("\n A fila esta cheia, favor aguardar !");
        printf("\n");
    }
    if (quant < 0)
    {
        printf("\n Numero invalido, digite novamente !");
        printf("\n");
    }
    return (quant);
}

int op3(int quant, int tam)
{
    if (quant > 0)
    {
        quant--;
        printf(C_RED "\n Obrigado, seu carro ja esta fora da fila !" C_RESET);
        printf("\n");
        printf("\n Tamanho atual da fila %d !", quant);
        printf("\n");
    }
    if (quant <= 0)
    {
        printf("\n Fila ja esta vazia !");
        printf("\n");
    }
    return (quant);
}