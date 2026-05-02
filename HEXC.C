#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <unistd.h>
#include <windows.h>
//HEADERS
char caminho[256];


//GLOBAIS

int main(int argc, char *argv[]){
    _getcwd(caminho, sizeof(caminho));

    if(argc < 2){
        printf("\nBem-vindo ao HEXC!!\nEncriptador de arquivos com XOR | by: Joao Machado\n\n\ntente HEXC.exe exemplo.txt\n\nPressione qualquer tecla para sair. . .");
        getchar();
        return 1;
    }

    FILE *input =
    fopen(argv[1], "rb"); //somente leitura

    FILE *output =
    fopen("output.dat", "wb"); //somnte escrita

    if (input ==NULL || output ==NULL) {
        printf("\n\nERRO: Nao foi possivel ler/encontrar o arquivo\n\n");
        return 1;
    }
    unsigned char key = 173;
    int byte;
    int line;
    int cont_byte;

    printf("Escaneando e encriptando BYTECODE");
    Sleep(1000);
    printf(" .");
    Sleep(1000);
    printf(" .");
    Sleep(1000);
    printf(" .\n\n");

    while ((byte = fgetc (input)) != EOF ) { //Leia cada caractere do arquivo até encontrar EOF
        printf("%d", byte);


        byte = byte ^ key;

        fputc(byte, output);

        line++;
        cont_byte++;
        if (line % 200 == 0) {printf("\n");}

    }
    printf("\n\nBYTECODE Escaneado e encriptado com sucesso!!\n\n");
    printf("Quantidade de bytes encriptados:  %d", cont_byte);
    printf("\n\n");

    printf("\n\nSucesso!! Arquivo gerado no local [ %s ]\n\n", caminho);



    fclose(input);
    fclose(output);

    return 0;
    
}
//MAIN FUNCTION
