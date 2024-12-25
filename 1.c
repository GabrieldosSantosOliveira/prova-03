#include <stdio.h>
#include <stdlib.h>
#define SALARIO_MINIMO 1200.0
 
typedef struct
{
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
} FUNCIONARIO;
 
void print_funcionario(FUNCIONARIO *pf)
{
    printf("MATRICULA: %d IDADE: %d NUMERO DE FILHOS: %d SEXO: %c SALARIO:%lf\n", pf->matricula, pf->idade, pf->numFilhos, pf->sexo, pf->salario);
}
 
int main()
{
    int n;
    scanf("%d", &n);
    FUNCIONARIO *funcionarios = (FUNCIONARIO *)calloc(n, sizeof(FUNCIONARIO));
    int i;
    int total_idades = 0;
    int total_filhos = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%*c%c%lf", &funcionarios[i].matricula, &funcionarios[i].idade, &funcionarios[i].numFilhos, &funcionarios[i].sexo, &funcionarios[i].salario);
        total_idades += funcionarios[i].idade;
        total_filhos += funcionarios[i].numFilhos;
    }
    double media_idade = total_idades / (double)n;
    double media_filhos = total_filhos / (double)n;
    int primeira_pergunta = 0;
    int segunda_pergunta = 0;
    int terceira_pergunta = 0;
    int quarta_pergunta = 0;
 
    for (i = 0; i < n; i++)
    {
        if (funcionarios[i].idade > media_idade && funcionarios[i].salario > (SALARIO_MINIMO * 3))
        {
            primeira_pergunta++;
        }
        if (funcionarios[i].sexo == 'F' && funcionarios[i].numFilhos > media_filhos)
        {
            segunda_pergunta++;
        }
        if (funcionarios[i].sexo == 'M' && funcionarios[i].numFilhos > media_filhos)
        {
            terceira_pergunta++;
        }
        double salario_per_caipta = funcionarios[i].salario / (double)(funcionarios[i].numFilhos + 1);
        if (funcionarios[i].idade > 47 && salario_per_caipta < (SALARIO_MINIMO * 2))
        {
            quarta_pergunta++;
        }
    }
    printf("%d %d %d %d\n", primeira_pergunta, segunda_pergunta, terceira_pergunta, quarta_pergunta);
    free(funcionarios);
    return 0;
}