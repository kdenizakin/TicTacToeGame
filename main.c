#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct {
    char name_vs_name[40];
    int first_score;
    int second_score;

}player;

void define_grid(int x, int y, char row1[], char row2[], char row3[]);
void game1vs1();
int check(char row1[], char row2[], char row3[]);
int file_operations_pre(player *players, int *score1, int *score2); //For pre-game.
int file_operations_post(char *winner); //For post-game.
int displayScores(char *firstname ,char *secondname);//Scan a file in order to determine if current player names are in the list.
//void displayScores(char *firstname ,char *secondname);

int main()
{
    player *players = (player*) malloc(sizeof(player)*2); //Creates a pointer which holds player names in a bin file.
    int inp;

    printf("Welcome to TicTacToe!\n");
    printf("Type '1' for 1 vs 1\n");
    printf("Type '2' for 1 vs Computer\n");

    scanf("%d",&inp);
    if(inp == 1)
        file_operations_pre(players);

    return 0;
}



void define_grid(int x, int y, char row1[], char row2[], char row3[]){

    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("  %c  |  %c  |  %c  ", row1[0], row1[1], row1[2]);

    coord.Y = ++y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf(" _______________");

    coord.Y = ++y;
    coord.Y = ++y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("  %c  |  %c  |  %c  \n", row2[0], row2[1], row2[2]);

    coord.Y = ++y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf(" _______________");

    coord.Y = ++y;
    coord.Y = ++y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("  %c  |  %c  |  %c  \n", row3[0], row3[1], row3[2]);

}

void game1vs1(){

    char r1[4] = "   ",r2[4]= "   ",r3[4]= "   ";
    char inp;
    int next = 0;
    int won;
    COORD coord;
    coord.X = 0;
    coord.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("                                    \n                                                \n                                     \n                                ");

    coord.X = 0; //Grid reset.
    coord.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

    define_grid(6, 8, r1,r2,r3);

    while(inp != 10)
    {
        COORD coord;

        if(next == 0){
            coord.X = 0;
            coord.Y = 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            printf("                                    \n                                                                         ");
            printf("                                      \n                                     \n                                ");
            //Reset the console.

            coord.X = 0;
            coord.Y = 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            printf("For 'X' Type a number:\n");
            scanf("%c",&inp);

            if(inp == '7' && r1[0] != 'O' && r1[0] != 'X'){
                r1[0] = 'X';
                next = 1;
            }
            else if(inp == '8' && r1[1] != 'O'&& r1[1] != 'X'){
                r1[1] = 'X';
                next = 1;
            }
            else if(inp == '9' && r1[2] != 'O'&& r1[2] != 'X'){
                r1[2] = 'X';
                next = 1;
            }
            else if(inp == '4' && r2[0] != 'O'&& r2[0] != 'X'){
                r2[0] = 'X';
                next = 1;
            }
            else if(inp == '5' && r2[1] != 'O'&& r2[1] != 'X'){
                r2[1] = 'X';
                next = 1;
            }
            else if(inp == '6' && r2[2] != 'O'&& r2[2] != 'X'){
                r2[2] = 'X';
                next = 1;
            }
            else if(inp == '1' && r3[0] != 'O'&& r3[0] != 'X'){
                r3[0] = 'X';
                next = 1;
            }
            else if(inp == '2' && r3[1] != 'O'&& r3[1] != 'X'){
                r3[1] = 'X';
                next = 1;
            }
            else if(inp == '3' && r3[2] != 'O'&& r3[2] != 'X'){
                r3[2] = 'X';
                next = 1;
            }
            else{
                printf("xd");
                inp = ' ';
                continue;
            }
            define_grid(6, 8, r1,r2,r3);
            won= check(r1,r2,r3);
            if(won == 10)
                break;
            else if(won == 1)
                break;
        }
        if(next == 1){
            coord.X = 0;
            coord.Y = 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            printf("                                    \n                                                                         ");
            printf("                                      \n                                     \n                                ");
            printf("                                    \n                                                                         ");
            printf("                                      \n                                     \n                                ");//Reset the console.
            coord.X = 0;
            coord.Y = 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            printf("For 'O' Type a number:\n");
            scanf("%c",&inp);
            if(inp == '7' && r1[0] != 'X'&& r1[0] != 'O'){
                r1[0] = 'O';
                next = 0;
            }
            else if(inp == '8' && r1[1] != 'X'&& r1[1] != 'O'){
                r1[1] = 'O';
                next = 0;
            }
            else if(inp == '9' && r1[2] != 'X'&& r1[2] != 'O'){
                r1[2] = 'O';
                next = 0;
            }
            else if(inp == '4' && r2[0] != 'X'&& r2[0] != 'O'){
                r2[0] = 'O';
                next = 0;
            }
            else if(inp == '5' && r2[1] != 'X'&& r2[1] != 'O'){
                r2[1] = 'O';
                next = 0;
            }
            else if(inp == '6' && r2[2] != 'X'&& r2[2] != 'O'){
                r2[2] = 'O';
                next = 0;
            }
            else if(inp == '1' && r3[0] != 'X'&& r3[0] != 'O'){
                r3[0] = 'O';
                next = 0;
            }
            else if(inp == '2' && r3[1] != 'X'&& r3[1] != 'O'){
                r3[1] = 'O';
                next = 0;
            }
            else if(inp == '3' && r3[2] != 'X'&& r3[2] != 'O'){
                r3[2] = 'O';
                next = 0;
            }
            else{
                printf("xd");
                inp = ' ';
                continue;
            }

        }

        define_grid(6, 8, r1,r2,r3);
        won= check(r1,r2,r3);
        if(won == 5)
            break;
        else if(won == 1)
            break;

    }

    if(won == 10){
        coord.X = 12;
        coord.Y = 16;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
        printf("X WON!\n");
    }
    else if(won == 5){
        coord.X = 12;
        coord.Y = 16;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
        printf("O WON!\n");
    }
     else if(won == 1){
        coord.X = 12;
        coord.Y = 16;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
        printf("DRAW!\n");
    }
}

int check(char row1[], char row2[], char row3[]) //Decides if the game is over.
{
    //Return 10 shows X won the game.
    if       (row1[0] == 'X' && row1[1] == 'X'&& row1[2] == 'X')  return 10;
    else if  (row2[0] == 'X' && row2[1] == 'X'&& row2[2] == 'X')  return 10;
    else if  (row3[0] == 'X' && row3[1] == 'X'&& row3[2] == 'X')  return 10;
    else if  (row1[0] == 'X' && row2[0] == 'X'&& row3[0] == 'X')  return 10;
    else if  (row1[1] == 'X' && row2[1] == 'X'&& row3[1] == 'X')  return 10;
    else if  (row1[2] == 'X' && row2[2] == 'X'&& row3[2] == 'X')  return 10;
    else if  (row1[0] == 'X' && row2[1] == 'X'&& row3[2] == 'X')  return 10;
    else if  (row1[2] == 'X' && row2[1] == 'X'&& row3[0] == 'X')  return 10;

    //Return 5 shows O won the game.
    if       (row1[0] == 'O' && row1[1] == 'O'&& row1[2] == 'O')  return 5;
    else if  (row2[0] == 'O' && row2[1] == 'O'&& row2[2] == 'O')  return 5;
    else if  (row3[0] == 'O' && row3[1] == 'O'&& row3[2] == 'O')  return 5;
    else if  (row1[0] == 'O' && row2[0] == 'O'&& row3[0] == 'O')  return 5;
    else if  (row1[1] == 'O' && row2[1] == 'O'&& row3[1] == 'O')  return 5;
    else if  (row1[2] == 'O' && row2[2] == 'O'&& row3[2] == 'O')  return 5;
    else if  (row1[0] == 'O' && row2[1] == 'O'&& row3[2] == 'O')  return 5;
    else if  (row1[2] == 'O' && row2[1] == 'O'&& row3[0] == 'O')  return 5;

    if       (row1[0] != ' ' && row1[0] != ' '&& row1[1] != ' ' && row1[1] != ' '&&  row1[2] != ' ' && row1[2] != ' '
              && row2[0] != ' ' && row2[0] != ' '&& row2[1] != ' ' && row2[1] != ' '&&  row2[2] != ' ' && row2[2] != ' '
              && row3[0] != ' ' && row3[0] != ' '&& row3[1] != ' ' && row3[1] != ' '&&  row3[2] != ' ' && row3[2] != ' ')
        return 1;


}
int file_operations_pre(player *players)
{
    char x;
    int count = 0; //Size of trimmer_first_name.
    int score1, score2;
    char score_char1[5], score_char2[5];

    FILE *fpwrite, *fpread;
    fpwrite = fopen("Scoreboard.txt","a+"); //It creates a new file if it doesn't exist.

    char *firstnameinp = (char*) malloc(sizeof(char)*10);
    char *secondnameinp = (char*) malloc(sizeof(char)*100);
    char *temp1 = (char*) malloc(sizeof(char)*20); //Hold keyboard input first name.
    char *temp2 = (char*) malloc(sizeof(char)*20); //Hold keyboard input second name.

    printf("Enter a name for Player 1: ");
    scanf("%s",firstnameinp);

    printf("Enter a name for Player 2: ");
    scanf("%s",secondnameinp);

    char *trimmer_first_name = (char*) malloc(sizeof(char)*100);
    for(int i = 0; i<strlen(firstnameinp); i++){

        if(firstnameinp[i] != ' '){
            trimmer_first_name[count++] = firstnameinp[i];
        }

    }
    trimmer_first_name[count] = '\0';

    char *trimmer_second_name = (char*) malloc(sizeof(char)*100);
    count = 0;
    for(int i = 0; i<strlen(secondnameinp); i++){

        if(secondnameinp[i] != ' '){
            trimmer_second_name[count++] = secondnameinp[i];
        }

    }
    trimmer_second_name[count] = '\0';

    strcpy(temp1, trimmer_first_name);
    strcpy(temp2, trimmer_second_name);
    int scan_file_result = displayScores(trimmer_first_name ,trimmer_second_name);

    if(scan_file_result == 0){
        players->first_score = 0;
        players->second_score = 0;
        strcat(temp1,"/");
        strcat(temp1,temp2); //Now the first name and the second name are appended to each other separated by"/".
        strcpy(players->name_vs_name,temp1);
        strcat(temp1,":");

        itoa(players->first_score,score_char1,10);
        strcat(temp1,score_char1);


        strcat(temp1, "-");
        itoa(players->second_score,score_char2,10);
        strcat(temp1,score_char2);

        strcat(temp1,"\n");

        fputs(temp1,fpwrite);
        fclose(fpwrite);
    }
    else if (scan_file_result == 1){
        system("cls");
        displayScores(trimmer_first_name ,trimmer_second_name);
    }

    game1vs1();


}

int displayScores(char *firstname ,char *secondname){

    char all_line[100];
    char *read_first_name;
    char *read_second_name;
    char *read_score1;
    char *read_score2;
    read_first_name = (char*)malloc(sizeof(char)*100);
    read_second_name = (char*)malloc(sizeof(char)*100);
    char *status;
    FILE *fpread;
    fpread = fopen("Scoreboard.txt","r+");

    for(status = fgets(all_line, 100, fpread); status != 0; status = fgets(all_line, 100, fpread)){

        if(all_line[strlen(all_line)-1] == '\n'){
            all_line[strlen(all_line)-1] = '\0';
            read_first_name = strtok(all_line,"/");
            read_second_name = strtok(NULL,":");
            read_score1 = strtok(NULL,"-");
            read_score2 = strtok(NULL,"\n");
        }

        if(read_first_name!= NULL && read_second_name != NULL && strcmp(strupr(firstname),strupr(read_first_name)) == 0
           && strcmp(strupr(secondname),strupr(read_second_name)) == 0){

            system("cls");
            COORD coord;
            coord.X = 0;
            coord.Y = 0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            printf("Current score: %s-%s (%s-%s)",firstname,secondname,read_score1,read_score2);

            return 1;
       }else if (read_first_name!= NULL && read_second_name != NULL && strcmp(strupr(secondname),strupr(read_first_name)) == 0
           && strcmp(strupr(firstname),strupr(read_second_name)) == 0){
            system("cls");
            COORD coord;
            coord.X = 0;
            coord.Y = 0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
            printf("Current scorexd: %s-%s (%s-%s)",firstname,secondname,read_score2,read_score1);
            return 1;
           }


    }
    system("cls");
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    printf("Current score: %s-%s (%s-%s)",strupr(firstname),strupr(secondname),"0","0");
    fclose(fpread);
    return 0; // Means that there is no info about first player vs second player.

}










