#include <stdio.h>

int main() {

    void limparBuffer() {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    char heroi[20];
    char boss[20] = "Python";
    int raca = 0;

    printf("Digite seu nome de Heroi: ");
    scanf("%s", heroi);

    printf("\nNo coracao do misterioso Reino de C99, onde os feiticos sao lancados com linhas de codigo e a logica e a maior arma,\n");
    printf("%s nasceu com um dom raro: o poder de compilar magia pura.\n", heroi);
    printf("Desde pequeno, treinou nas artes ancestrais do Debugging, dominou os grimorios do ponteiro e aprendeu a invocar funcoes recursivas com precisao cirurgica.\n\n");

    printf("Escolha sua raca:\n");
    printf("[1] Mago\n[2] Guerreiro\n[3] Elfo\n> ");
    scanf("%d", &raca);

    switch(raca) {
        case 1:
            printf("\nAgora, ja adulto, %s e reconhecido como o mais promissor MAGO do reino.\n", heroi);
        break;
        case 2:
            printf("\nAgora, ja adulto, %s e reconhecido como o mais promissor GUERREIRO do reino.\n", heroi);
        break;
        case 3:
            printf("\nAgora, ja adulto, %s e reconhecido como o mais promissor ELFO do reino.\n", heroi);
        break;
        default:
            printf("\nRaca desconhecida... %s segue como um heroi misterioso.\n", heroi);
        break;
    }

    printf("Mas agora, uma nova ameaca surge...\n");
    printf("A terrivel cobra %s, do reino dos Sem ponto e virgula, esta prestes a destruir tudo com sua sintaxe maleavel e veneno mortal.\n", boss);
    printf("A batalha epica esta para comecar. Prepare-se!\n\n");

    limparBuffer();
    printf("Aperte enter para continuar>");
    getchar();

    printf("O ceu escurece repentinamente...\n");
    printf("Raios de codigo binario cortam os ceus enquanto a terra treme sob os pes de %s.\n", heroi);
    printf("A trilha de erros leva ate uma cratera flamejante...\n");
    printf("De dentro dela, emerge %s, a cobra ancestral dos bugs eternos!\n\n", boss);

    printf("                 /^\\/^\\\n");
    printf("               _|__|  O|\n");
    printf("      \\/     /~     \\_/ \\\n");
    printf("       \\____|__________/  \\\n");
    printf("              \\_______      \\\n");
    printf("                      `\\     \\                 \\\n");
    printf("                        |     |                  \\\n");
    printf("                       /      /                    \\\n");
    printf("                      /     /                       \\\n");
    printf("                    /      /                         \\ \\\n");
    printf("                   /     /                            \\  \\\n");
    printf("                 /     /             _----_            \\   \\\n");
    printf("                /     /           _-~      ~-_         |   |\n");
    printf("               (      (        _-~    _--_    ~-_     _/   |\n");
    printf("                \\      ~-____-~    _-~    ~-_    ~-_-~    /\n");
    printf("                  ~-_           _-~          ~-_       _-~\n");
    printf("                     ~--______-~                ~-___-~\n");

    printf("%s encara a criatura com olhar firme. Sua raca, sua coragem, sua historia...\n", heroi);
    printf("Tudo o que viveu o trouxe ate este momento final.\n");

    printf("\nAperte enter para iniciar a batalha contra %s...\n", boss);
    limparBuffer();
    getchar();

    printf("\n================ BATALHA DE QUIZ =================\n");

    int hpboss = 100;
    int hpheroi = 100;
    int pergunta = 1;
    char resposta;

    while (hpboss > 0 && hpheroi > 0) {
        printf("\nHP Heroi: %d | HP Boss: %d\n", hpheroi, hpboss);

        switch (pergunta) {
            case 1:
                printf("Qual das alternativas e um tipo de dado em C?\n");
                printf("A) inteiro\nB) double\nC) palavra\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'B' || resposta == 'b') {
                    printf("Voce acertou um ataque de compilacao!\n");
                    hpboss -= 20;
                } else {
                    printf("Errou! Python lancou um ataque de 010101\n");
                    hpheroi -= 20;
                }
                break;
            case 2:
                printf("O que o comando 'scanf' faz?\n");
                printf("A) Imprime na tela\nB) Le entrada do usuario\nC) Compara dois valores\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'B' || resposta == 'b') {
                    printf("Boa! Voce atingiu o boss!\n");
                    hpboss -= 20;
                } else {
                    printf("Errou a habilidade!\n");
                    hpheroi -= 20;
                }
                break;
            case 3:
                printf("Como declarar uma variavel do tipo inteiro?\n");
                printf("A) int x;\nB) inteiro x;\nC) num x;\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'A' || resposta == 'a') {
                    printf("Certeiro!\n");
                    hpboss -= 20;
                } else {
                    printf("Dano sofrido por erro de sintaxe!\n");
                    hpheroi -= 20;
                }
                break;
            case 4:
                printf("Qual operador representa 'igual a' em C?\n");
                printf("A) =\nB) ==\nC) !=\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'B' || resposta == 'b') {
                    printf("Voce acertou em cheio!\n");
                    hpboss -= 20;
                } else {
                    printf("Voce confundiu o operador!\n");
                    hpheroi -= 20;
                }
                break;
            case 5:
                printf("Qual a funcao da chave '{' em C?\n");
                printf("A) Iniciar comentario\nB) Iniciar bloco de codigo\nC) Encerrar programa\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'B' || resposta == 'b') {
                    printf("Ataque critico de logica!\n");
                    hpboss -= 20;
                } else {
                    printf("Voce se perdeu no codigo...\n");
                    hpheroi -= 20;
                }
                break;
            case 6:
                printf("Qual o resultado de: 2 + 2 * 2?\n");
                printf("A) 8\nB) 6\nC) 4\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'B' || resposta == 'b') {
                    printf("Voce dominou a precedencia dos operadores!\n");
                    hpboss -= 20;
                } else {
                    printf("Erro de logica! Sofreu um contra-ataque!\n");
                    hpheroi -= 20;
                }
                break;
            case 7:
                printf("O que significa '%%d' dentro do printf?\n");
                printf("A) Imprimir um char\nB) Imprimir um inteiro\nC) Imprimir um float\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'B' || resposta == 'b') {
                    printf("Boa! Comando de ataque eficaz!\n");
                    hpboss -= 20;
                } else {
                    printf("Erro de formatacao... dano recebido!\n");
                    hpheroi -= 20;
                }
                break;
            case 8:
                printf("Qual desses e um operador logico?\n");
                printf("A) &&\nB) ++\nC) ==\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'A' || resposta == 'a') {
                    printf("Voce desferiu um golpe de sabedoria!\n");
                    hpboss -= 20;
                } else {
                    printf("Confundiu operadores... dano sofrido!\n");
                    hpheroi -= 20;
                }
                break;
            case 9:
                printf("Qual comando e usado para repetir um bloco pelo menos uma vez?\n");
                printf("A) for\nB) while\nC) do while\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'C' || resposta == 'c') {
                    printf("Voce usou um ataque garantido!\n");
                    hpboss -= 20;
                } else {
                    printf("A magia falhou...\n");
                    hpheroi -= 20;
                }
                break;
            case 10:
                printf("Como se declara uma variavel float corretamente?\n");
                printf("A) float x = '2.0';\nB) float x = 2.0;\nC) float x = \"2.0\";\n> ");
                scanf(" %c", &resposta);
                if (resposta == 'B' || resposta == 'b') {
                    printf("Voce dominou os tipos corretamente!\n");
                    hpboss -= 20;
                } else {
                    printf("Declaracao errada... dano sofrido!\n");
                    hpheroi -= 20;
                }
                break;
        }

        pergunta++;
        if (pergunta > 10) pergunta = 1;
    }

    if (hpboss <= 0 && hpheroi > 0) {
        printf("\n*** VOCE DERROTOU O BOSS PYTHON! ***\n");
        printf("O reino de C99, por tanto tempo mergulhado na escuridao dos medos e erros de sintaxe,\n");
        printf("finalmente viu a luz da esperanca brilhar. A ameaca do poderoso Python, que assombrava\n");
        printf("todas as variaveis e lacos de repeticao, foi vencida por um verdadeiro heroi do codigo.\n");
        printf("Os compiladores agora cantam hinos de liberdade, e a IDE sorri com orgulho. A paz reina\n");
        printf("mais uma vez entre os blocos de codigo.\n");
    } else if (hpheroi <= 0 && hpboss > 0) {
        printf("\n*** O BOSS PYTHON VENCEU... ***\n");
        printf("As sombras cobriram o reino de C99. O heroi caiu, e com ele, as ultimas esperancas de\n");
        printf("um mundo livre de bugs desapareceram...\n");
    }

    return 0;
}
