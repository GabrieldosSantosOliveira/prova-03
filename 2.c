#include <stdio.h>
#include <stdlib.h>
 
typedef struct
{
    int numero_de_likes;
    int numero_retweets;
    int numero_mencoes;
} Relacionamento;
 
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int i = 0;
    Relacionamento ***relacionamentos = (Relacionamento ***)malloc(n * sizeof(Relacionamento *));
    if (relacionamentos == NULL)
    {
        exit(1);
    }
 
    for (i = 0; i < n; i++)
    {
        relacionamentos[i] = NULL;
    }
    for (i = 0; i < n; i++)
    {
        relacionamentos[i] = (Relacionamento **)malloc(n * sizeof(Relacionamento *));
        if (relacionamentos[i] == NULL)
        {
            exit(1);
        }
        int j;
        for (j = 0; j < n; j++)
        {
            relacionamentos[i][j] = NULL;
        }
    }
    for (i = 0; i < m; i++)
    {
        int u1, u2;
        Relacionamento *tmp = (Relacionamento *)malloc(1 * sizeof(Relacionamento));
        if (tmp == NULL)
        {
            exit(1);
        }
        scanf("%d%d", &u1, &u2);
        scanf("%d%d%d", &(tmp->numero_de_likes), &(tmp->numero_retweets), &(tmp->numero_mencoes));
        relacionamentos[u1][u2] = tmp;
    }
    int total_likes = 0, total_retweets = 0, total_mencoes = 0;
    double quantidade_de_usuarios = 0;
    int total_slots = 0;
    for (i = 0; i < n; i++)
    {
        int total_likes_usuario = 0, total_retweets_usuario = 0, total_mencoes_usuario = 0;
        int j;
        int quantidade_slots = 0;
        for (j = 0; j < m; j++)
        {
            Relacionamento *tmp = relacionamentos[i][j];
            if (tmp != NULL)
            {
                quantidade_slots++;
                total_likes_usuario += tmp->numero_de_likes;
                total_retweets_usuario += tmp->numero_retweets;
                total_mencoes_usuario += tmp->numero_mencoes;
            }
        }
        if (quantidade_slots != 0)
        {
            quantidade_de_usuarios += 1;
            printf("Usuario %d - num. likes: %d, num. retweets: %d e num. mencoes: %d\n", i, total_likes_usuario, total_retweets_usuario, total_mencoes_usuario);
        }
        total_likes += total_likes_usuario;
        total_mencoes += total_mencoes_usuario;
        total_retweets += total_retweets_usuario;
        total_slots += quantidade_slots;
    }
    printf("Slots vazios: %d\n", ((n * n) - total_slots));
    printf("Media de likes por usuario: %.2lf\n", (total_likes / quantidade_de_usuarios));
    printf("Media de retweets por usuario: %.2lf\n", (total_retweets / quantidade_de_usuarios));
    printf("Media de mencoes por usuario: %.2lf\n", (total_mencoes / quantidade_de_usuarios));
    for (i = 0; i < m; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            Relacionamento *tmp = relacionamentos[i][j];
            if (tmp != NULL)
            {
                free(tmp);
            }
        }
        free(relacionamentos[i]);
    }
    free(relacionamentos);
    return 0;
}