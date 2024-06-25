#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50
typedef struct // estrutura de dados
{
    int id;
    float price;
    char nome[max];
    
}itens;
// adiciona produto funcao
void addproduto(itens produtos[],int *contar){
    itens novoproduto;
    novoproduto.id = *contar + 1;
    printf("Nome do produto: ");
    scanf("%s", novoproduto.nome);
    printf("Preço do produto: ");
    scanf("%f", &novoproduto.price);
    produtos[*contar] = novoproduto;
    (*contar)++;
    printf("Produto adicionado com sucesso.\n");
    
}
// listar produtos
void mostrar(int id, itens produtos[]){
    printf("ID DO PRODUTO: %d, NOME DO PRODUTO: %s, PRECO DO PRODUTO: %f",produtos[id].id,produtos[id].nome,produtos[id].price);
}
//deletar
void deletar(itens produtos[],int *contar){
int id;
    int index = -1;
    printf("Escreva o id do produto: ");
    scanf("%d", &id); 
    for (int iterador = 0; iterador < *contar; iterador++) {
        if (produtos[iterador].id == id) {
            index = iterador;
            break;
        }
    }
    if (index == -1) {
        printf("Produto com ID %d não encontrado.\n", id);
        return;
    }
    for (int i = index; i < *contar - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    (*contar)--;
    printf("Produto removido com sucesso.\n");
}
// atualizar produto
void attproduto(itens produtos[], int count) {
    int id;
    printf("ID do produto a ser atualizado: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (produtos[i].id == id) {
            printf("Novo nome do produto: ");
            scanf("%s", produtos[i].nome);
            printf("Novo preço do produto: ");
            scanf("%f", &produtos[i].price);
            printf("Produto atualizado com sucesso.\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}
// main principal
int main(){
    int choice;
    int contar=0;
    itens produtos[max];
    while(1){
        
        printf("1 - para cadastrar \n");
        printf("2 - para monstrar produtos cadastrados \n");
        printf("3 - para deletar produto \n");
        printf("4 - para atualizar produto \n digite qualquer outro numero para sair");
        scanf("%d", &choice);
        
        if(choice == 1){
            addproduto(produtos,&contar);
        }
        else if(choice == 2){
            printf("escreva o id do produto \n");
            int escolha;
            scanf("%d", &escolha);
            if(escolha <=0){
                printf("escreva o id maior que zero");
                continue;
            }
            escolha = escolha - 1;
            mostrar(escolha,produtos);
        }
        else if(choice == 3){
            deletar(produtos,&contar);
        }
        else if(choice == 4){
            attproduto(produtos,contar);
        }
        else{
            printf("saindo");
            break;
        }
    }
    return 0;
    
}