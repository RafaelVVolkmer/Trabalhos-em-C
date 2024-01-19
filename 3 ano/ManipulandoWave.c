//Rafael V. Volkmer - 4324 N.21

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <string.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>

typedef struct{
    char ChunkID[4], Format[4], Subchunk1ID[4], Subchunk2ID[4];
    int ChunkSize, Subchunk1Size, SampleRate, ByteRate, Subchunk2Size;
    short AudioFormat, NumChannels, BlockAlign, BitsPerSample;
    short *Data;
}WAV;


short* createData(WAV);
short* createNewData(int);
WAV readWAV(FILE *, WAV);
void writeWAV(FILE *,WAV,int);
void mostraentrada(WAV);
void mostrasaida(WAV);

WAV cortar(char*,WAV);

short* createData(WAV IN_Music){
    short *Data = (short*) malloc(sizeof(short)*(IN_Music.Subchunk2Size)*(IN_Music.BitsPerSample/8));
    return Data;
}

short* createNewData(int size){
    short *Data = (short*) malloc(sizeof(short)*size);
    return Data;
}


WAV readWAV(FILE *input, WAV IN_Music){

    fread(&IN_Music.ChunkID, 1, 4, input);
    fread(&IN_Music.ChunkSize, 4, 1, input);
    fread(&IN_Music.Format, 1, 4, input);
    fread(&IN_Music.Subchunk1ID, 1, 4, input);
    fread(&IN_Music.Subchunk1Size, 4, 1, input);
    fread(&IN_Music.AudioFormat, 2, 1, input);
    fread(&IN_Music.NumChannels, 2, 1, input);
    fread(&IN_Music.SampleRate, 4, 1, input);
    fread(&IN_Music.ByteRate, 4, 1, input);
    fread(&IN_Music.BlockAlign, 2, 1, input);
    fread(&IN_Music.BitsPerSample, 2, 1, input);
    fread(&IN_Music.Subchunk2ID, 1, 4, input);
    fread(&IN_Music.Subchunk2Size, 4, 1, input);

    short *Buffer = createData(IN_Music);
    IN_Music.Data = Buffer;

    fread(IN_Music.Data, IN_Music.BitsPerSample/8, IN_Music.Subchunk2Size/(IN_Music.BitsPerSample/8), input);

    fclose(input);

return IN_Music;
}

void writeWAV(FILE *output,WAV OUT_Music,int out_size){

    fwrite(&OUT_Music.ChunkID, 1, 4, output);
    fwrite(&OUT_Music.ChunkSize, 4, 1, output);
    fwrite(&OUT_Music.Format, 1, 4, output);
    fwrite(&OUT_Music.Subchunk1ID, 1, 4, output);
    fwrite(&OUT_Music.Subchunk1Size, 4, 1, output);
    fwrite(&OUT_Music.AudioFormat, 2, 1, output);
    fwrite(&OUT_Music.NumChannels, 2, 1, output);
    fwrite(&OUT_Music.SampleRate, 4, 1, output);
    fwrite(&OUT_Music.ByteRate, 4, 1, output);
    fwrite(&OUT_Music.BlockAlign, 2, 1, output);
    fwrite(&OUT_Music.BitsPerSample, 2, 1, output);
    fwrite(&OUT_Music.Subchunk2ID, 1, 4, output);
    fwrite(&OUT_Music.Subchunk2Size, 4, 1, output);


    fwrite(OUT_Music.Data, OUT_Music.BitsPerSample/8, out_size/(OUT_Music.BitsPerSample/8), output);

    fclose(output);
}



void mostraentrada(WAV IN_Music){

        puts("Input archive:");
        printf("\n    Chunck ID: %.4s",IN_Music.ChunkID );
        printf("\n\n        Chunck Size: %d",IN_Music.ChunkSize);
        printf("\n        Format: %.4s",IN_Music.Format);
        printf("\n\n    Subchunk1ID: %.4s",IN_Music.Subchunk1ID);
        printf("\n\n        Subchunk1Size: %d",IN_Music.Subchunk1Size);
        printf("\n        AudioFormat: %d",IN_Music.AudioFormat);
        printf("\n        NumChannels: %d",IN_Music.NumChannels);
        printf("\n        Sample Rate: %d",IN_Music.SampleRate);
        printf("\n        ByteRate: %d",IN_Music.ByteRate);
        printf("\n        BlockAlign: %d",IN_Music.BlockAlign);
        printf("\n        Bits Per Sample: %d",IN_Music.BitsPerSample);
        printf("\n\n    Subchunk2ID: %.4s",IN_Music.Subchunk2ID);
        printf("\n\n        Subchunk2Size: %d",IN_Music.Subchunk2Size);
        puts("\n\n");
}


void mostrasaida(WAV OUT_Music){

        puts("Output archive:\n");
        printf("\n    Chunck ID: %0.4s",OUT_Music.ChunkID);
        printf("\n\n        Chunck Size: %d",OUT_Music.ChunkSize);
        printf("\n        Format: %0.4s",OUT_Music.Format);
        printf("\n\n    Subchunk1ID: %0.4s",OUT_Music.Subchunk1ID);
        printf("\n\n        Subchunk1Size: %d",OUT_Music.Subchunk1Size);
        printf("\n        AudioFormat: %d",OUT_Music.AudioFormat);
        printf("\n        NumChannels: %d",OUT_Music.NumChannels);
        printf("\n        Sample Rate: %d",OUT_Music.SampleRate);
        printf("\n        ByteRate: %d",OUT_Music.ByteRate);
        printf("\n        BlockAlign: %d",OUT_Music.BlockAlign);
        printf("\n        Bits Per Sample: %d",OUT_Music.BitsPerSample);
        printf("\n\n    Subchunk2ID: %0.4s",OUT_Music.Subchunk2ID);
        printf("\n\n        Subchunk2Size: %d",OUT_Music.Subchunk2Size);
        puts("\n\n");

}


WAV cortar(char* new_file,WAV  IN_Music){

    int init_time = 0;
    int last_time = -1;
    int out_size;
    int i = 0;

    WAV OUT_Music;

    FILE *output = fopen(new_file, "wb");

    if(output == NULL){
        printf("Arquivo nao pode ser aberto.\n");
    }

    while (init_time > last_time || init_time > IN_Music.Subchunk2Size/IN_Music.ByteRate || last_time > IN_Music.Subchunk2Size/IN_Music.ByteRate){
        printf("Digite o tempo inicial e o final para o corte da musica(O arquivo possui %d segundos).\n",IN_Music.Subchunk2Size/IN_Music.ByteRate);
        puts("\nTempo inicial:");
        scanf("%d",&init_time);
        puts("\nTempo final:");
        scanf("%d",&last_time);
        if (init_time > last_time ){
            puts("\nTempo final maior que o inicial.\n");
        }
        if (init_time > IN_Music.Subchunk2Size/IN_Music.ByteRate || last_time > IN_Music.Subchunk2Size/IN_Music.ByteRate){
            printf("\nO arquivo possui somente %d segundos.\n\n",IN_Music.Subchunk2Size/IN_Music.ByteRate);
        }
    }

    init_time = init_time * IN_Music.ByteRate;
    last_time = last_time * IN_Music.ByteRate;
    out_size = last_time - init_time;

    OUT_Music = IN_Music;
    OUT_Music.Subchunk2Size = out_size;
    OUT_Music.ChunkSize = out_size + 36;


    short *Buffer = createNewData(out_size);
    OUT_Music.Data = Buffer;

    for (i = 0;i<out_size;i++){
        OUT_Music.Data[i] = IN_Music.Data[init_time + i];
    }

    writeWAV(output,OUT_Music,out_size);

    return OUT_Music;
}

int main(){

    char files [100][100];
    char new_file [100];
    int menu_state = 48;
    int user_input = -1;
    int cropped = 0 ;
    int i = 0;

    WAV IN_Music , OUT_Music;

    DIR *d;
    struct dirent *dir;

    d = opendir(".");

    puts("Arquivos da pasta:\n");
    if (d){
        while ((dir = readdir(d)) != NULL){
            char *ptr = strstr(dir->d_name,".wav");
            if (ptr != NULL){
                strcpy(files[i],dir->d_name);
                printf("%d - %s\n",i , files[i]);
                i++;
            }
        }
        i = i - 1;
        closedir(d);
    }
    if (i == -1){
        puts("Nao ha nenhum arquivo do tipo WAV na pasta.");
        exit(0);
    }

    while(user_input < 0 || user_input > i ){
        puts("\nInsira o numero do arquivo desejado:");
        scanf("%d",&user_input);
        if(user_input < 0 || user_input > i ){
           puts("\nNumero de arquivo inxesitente.");
        }
    }

    strcpy(new_file,files[user_input]);
    i = strlen(new_file);
    i = i-4;
    new_file[i] = '\0';
    strcat(new_file,"_x.wav");

    FILE *input = fopen(files[user_input], "rb");

    if(input == NULL){
        printf("Arquivo nao pode ser aberto.\n");
        exit(0);
    }

    IN_Music = readWAV(input, IN_Music);

    while (1){
        system("cls");

        switch (menu_state) {

            case 48:
                printf("Menu de Selecao:\n\n    1 - Exibe informacoes audio original.\n    2 - Executa o audio original.\n    3 - Para a execucao de qualquer audio.\n    4 - Corta audio original");
                if (cropped == 1){
                printf("\n    5 - Exibe informacoes sobre o audio cortado.\n    6 - Executa o audio cortado.");
                }
                printf("\n    9 - Sai do codigo.");
                menu_state = getch();
                if (menu_state != 49 && menu_state != 50 && menu_state != 51 && menu_state != 52 && menu_state != 53 && menu_state != 54 && menu_state != 57){
                    menu_state = 48;
                }
                system("cls");
                break;

            case 49:
                mostraentrada(IN_Music);
                system("PAUSE");
                menu_state = 48;
                break;


            case 50:
                PlaySound(files[user_input],0,SND_FILENAME|SND_ASYNC);
                menu_state = 48;
                break;

            case 51:
                PlaySound(NULL,NULL,NULL);
                menu_state = 48;
                break;

            case 52:
                OUT_Music = cortar(new_file,IN_Music);
                cropped = 1 ;
                menu_state = 48;
                break;

            case 53:
                mostrasaida(OUT_Music);
                system("PAUSE");
                menu_state = 48;
                break;

            case 54:
                PlaySound(new_file,0,SND_FILENAME|SND_ASYNC);
                menu_state = 48;
                break;

            case 57:
                exit(0);

        }
    }
}
