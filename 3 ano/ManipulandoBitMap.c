include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push,1)
struct cabecalho_arquivo
{
    char BfType1;
    char BfType2;
    int BfSize;
    short int BfReser1;
    short int BfReser2;
    int BfOffSetBits;
}cabecalho_arquivo_1;
#pragma pack(pop)

#pragma pack(push,1)
struct cabecalho_bitmap
{
    unsigned int BiSize;
    unsigned int BiWidth;
    unsigned int BiHeight;
    short int BiPlanes;
    short int BiBitCount;
    unsigned int BiCompress;
    unsigned int BiSizeImag;
    unsigned int BiXPPMeter;
    unsigned int BiYPPMeter;
    unsigned int BiClrUsed;
    unsigned int BiClrImpor;
}cabecalho_bitmap_1;
#pragma pack(pop

#pragma pack(push,1)
struct paleta_cores
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
}paleta_cores_1;
#pragma pack(pop)

int main()
{

    FILE *fp;
    FILE *fp_green;
    FILE *fp_blue;
    FILE *fp_red;

    char nome_arquivo[100];
    char nome_arquivo_green[100];
    char nome_arquivo_blue[100];
    char nome_arquivo_red[100];

    printf("----------------------------\n");
    printf("Digite o nome do arquivo:");
    printf("\n----------------------------\n");
    gets(nome_arquivo);

    strcpy(nome_arquivo_green,nome_arquivo);
    strcat(nome_arquivo_green,"_green.bmp");
    strcpy(nome_arquivo_blue,nome_arquivo);
    strcat(nome_arquivo_blue,"_blue.bmp");
    strcpy(nome_arquivo_red,nome_arquivo);
    strcat(nome_arquivo_red,"_red.bmp");
    strcat(nome_arquivo,".bmp");

    fp = fopen(nome_arquivo,"r+b");
    if(fp == NULL)
    {
        printf("Arquivo nao encontrado");
        return 0;
    }
    fp_green = fopen(nome_arquivo_green,"a+b");
    fp_blue = fopen(nome_arquivo_blue,"a+b");
    fp_red = fopen(nome_arquivo_red,"a+b");


    fread(&cabecalho_arquivo_1, sizeof(cabecalho_arquivo_1),1,fp);
    fread(&cabecalho_bitmap_1, sizeof(cabecalho_bitmap_1),1,fp);

    fwrite(&cabecalho_arquivo_1, sizeof(cabecalho_arquivo_1),1,fp_green);
    fwrite(&cabecalho_arquivo_1, sizeof(cabecalho_arquivo_1),1,fp_blue);
    fwrite(&cabecalho_arquivo_1, sizeof(cabecalho_arquivo_1),1,fp_red);

    fwrite(&cabecalho_bitmap_1, sizeof(cabecalho_bitmap_1),1,fp_green);
    fwrite(&cabecalho_bitmap_1, sizeof(cabecalho_bitmap_1),1,fp_blue);
    fwrite(&cabecalho_bitmap_1, sizeof(cabecalho_bitmap_1),1,fp_red);

    printf("\n---------------------------- INFOS ----------------------------\n");
    printf("    Nome do Arquivo: %s\n",nome_arquivo);
    printf("    Assinatura: %c%c\n",cabecalho_arquivo_1.BfType1,cabecalho_arquivo_1.BfType2);
    printf("    Tamanho do Arquivo em Bytes: %i\n",cabecalho_arquivo_1.BfSize);
    printf("    Campos reservados (devem ser 0!!!!!)bbeb: 1:%i 2:%i\n",cabecalho_arquivo_1.BfReser1,cabecalho_arquivo_1.BfReser2);
    printf("    OffSet: %i\n",cabecalho_arquivo_1.BfOffSetBits);
    printf("    Tamanho do cabecalho do bitmap (deve ser 40): %i Bytes\n",cabecalho_bitmap_1.BiSize);
    printf("    Largura da Imagem: %i\n",cabecalho_bitmap_1.BiWidth);
    printf("    Altura da Imagem: %i\n",cabecalho_bitmap_1.BiHeight);
    printf("    Planos da imagem (deve ser 1): %i\n",cabecalho_bitmap_1.BiPlanes);
    printf("    Quantidade de Bits por pixel: %i\n",cabecalho_bitmap_1.BiBitCount);
    printf("    Compressao usada(0 = BI_RGB_sem compressao, 1 = BI_RLE8 - compressao RLE 8 bits, 2 = BI_RLE4 - compressao RLE 4 bits): %i\n",cabecalho_bitmap_1.BiCompress);
    printf("    Tamanho da imagem em Bytes: %i\n",cabecalho_bitmap_1.BiSizeImag);
    printf("    Resolucao Horizontal: %i\n",cabecalho_bitmap_1.BiXPPMeter);
    printf("    Resolucao Vertical: %i\n",cabecalho_bitmap_1.BiYPPMeter);
    printf("    Numero de cores usadas (0 = maximo de cores pela quantidade de Bits por pixel): %i\n",cabecalho_bitmap_1.BiClrUsed);
    printf("    Numero de cores imoportantes: %i\n",cabecalho_bitmap_1.BiClrUsed);
    printf("-------------------------------------------------------------\n");
    int tamanho_imagem = cabecalho_bitmap_1.BiHeight * cabecalho_bitmap_1.BiWidth;
    for(int i = 0; i < tamanho_imagem; i++)
    {
        fread(&paleta_cores_1, sizeof(paleta_cores_1),1,fp);
        paleta_cores_1.red = 0;
        paleta_cores_1.green = 0;
        fwrite(&paleta_cores_1, sizeof(paleta_cores_1),1,fp_blue);
    }
    fseek(fp,sizeof(cabecalho_arquivo_1)+sizeof(cabecalho_bitmap_1),SEEK_SET);
    for(int i = 0; i < tamanho_imagem; i++)
    {
        fread(&paleta_cores_1, sizeof(paleta_cores_1),1,fp);
        paleta_cores_1.red = 0;
        paleta_cores_1.blue = 0;
        fwrite(&paleta_cores_1, sizeof(paleta_cores_1),1,fp_green);
    }
    fseek(fp,sizeof(cabecalho_arquivo_1)+sizeof(cabecalho_bitmap_1),SEEK_SET);
    for(int i = 0; i < tamanho_imagem; i++)
    {
        fread(&paleta_cores_1, sizeof(paleta_cores_1),1,fp);
        paleta_cores_1.blue = 0;
        paleta_cores_1.green = 0;
        fwrite(&paleta_cores_1, sizeof(paleta_cores_1),1,fp_red);
    }


    fclose(fp);
    fclose(fp_green);
    fclose(fp_blue);
    fclose(fp_red);


    return 0;
}
