#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
typedef struct
{
    int id ;
    int state ;
    int movieCode ;
    int releaseYear ;
    int mainActorID ;
    char title [51] ;
    char genre [51] ;
} sMovie;
typedef struct
{
    int id ;
    int state ; // 1 - filled / 0 - empty / -1 deleted
    char name [51];
    char origin [51];
} sActor ;
//movie functios
void initMovies ( sMovie* , int);
static int newMovieId (void);
void createMovie ( sMovie* movieList, int lenght, sActor* actorList , int actorLenght );
int getEmptySpace ( sMovie* movieList, int lenght );
int getMovieGenre ( char* retGenre );
int getMovieCode ( sMovie* movieList, int lenght, int* retCode);
int getMovieYear ( int* retYear );
int getActorID ( sActor* actorList , int lenght , int* actorId );
int alreadyExist (sMovie* movieList, int lenght, int code);
int getOption ( int maxOption );
int deleteMovie (sMovie* movieList , int lenght);
void hardCodeMovies (sMovie* movieList);
int getMovieByID ( sMovie* movieList , int lenght , int movieID );
void modifyMovieMenue ( sMovie* movieList , int lenght , sActor* actorList , int actorLenght );
void movieModification(sMovie* movieList , int moviesLenght , int index , sActor* actorList , int actorLenght);
void sortMovies( sMovie* movieList, int lenght, int field, int order );
int getOrder (void);
void printSortMovieMenu ( sMovie* movieList , int lenght , sActor* actorList, int actorLenght );
void sortMoviesByGenre ( sMovie* movieList, int lenght, int order  );
void sortMoviesByTitle ( sMovie* movieList, int lenght, int order  );
void sortMoviesByYear ( sMovie* movieList, int lenght, int order  );
void sortMoviesByCode ( sMovie* movieList, int lenght, int order  );
void printMovieListNoActor (sMovie* movieList , int lenght);
//actor functions
void hardCodeActors (sActor* actorList);
int getFreeSpace(sActor* actorList , int listLenght);
void printOneActor (sActor actorData);
static int newActorID (void);
void printActorList (sActor* actorList ,int lenght);
void sortActorsByOrigin (sActor* actorList , int lenght);
//get data functions
int getInt(const char* message,const char* errMessage, int* retNumber , int tries);
int getFloat(char* message, char* errMessage, float* retNumber , int tries);
int getName(char* message, char* errMessage, char* retString, int tries);
int getTitle(char* retString , int tries);
//print functions
void printMenu ( char* , int , int );
void printPPLmenu(void);
void printGenreMenu(void);
void printMovieList (sMovie* movieList , int lenght , sActor* actorList, int actorLenght );
void printOneMovie ( sMovie movie ,char* actor );
int printDeleteMenu ( sMovie* movieList , int lenght , sActor* actorList , int actorLenght );
void printListMenu (sMovie* movieList , int lenght , sActor* actorList , int actorsLenght);
//validation functions
int isNumber( char ) ;
int isLetter( char ) ;
int isNaL( char ) ;
int isNaN( char ) ;
int isFloat( char* ) ;
int isInt( char* ) ;
int hasOnlyLetters( char* ) ;
int isName( char* ) ;
int isTitle ( char* ) ;

int main()
{
    sMovie movieList[LEN];
    sActor actorList[LEN];
    hardCodeActors(actorList);
    initMovies(movieList,LEN);
    hardCodeMovies(movieList);
    int option = 0;
    do
    {
        system("cls");
        printPPLmenu();
        option = getOption(5);
        switch(option)
        {
        case 1:
            createMovie(movieList,LEN,actorList,LEN);
            break;
        case 2:
            printDeleteMenu(movieList,LEN,actorList,LEN);
            break;
        case 3:
            modifyMovieMenue(movieList,LEN,actorList,LEN);
            break;
        case 4:
            printListMenu(movieList,LEN,actorList,LEN);
            break;
        }

    } while (option!=5);
    return 0;
}
void hardCodeActors (sActor* actorList)
{
    char names [5][31] = {"Julieta roberto" ,"Richard darin" ,"Nicole Kidman" ,"Tita merello" ,"Natalia Oreiro"};
    char origins [5][21] = {"EEUU" ,"Argentina" ,"Australia" ,"Argentina" ,"Uruguay"};
    int i;
    int newID;
    for (i=0;i<5;i++)
    {
        newID = newActorID();
        actorList[i].id = newID;
        strcpy(actorList[i].name,names[i]);
        strcpy(actorList[i].origin,origins[i]);
        actorList[i].state = 1;
    }
}
int getFreeSpace(sActor* actorList , int listLenght)
{
    int i;
    for (i = 0 ; i<listLenght ; i++)
    {
        if (actorList[i].state == 0)
        {
            break;
        }
    }
    return i;
}
void printOneActor (sActor actorData)
{
    printf("\n __________");
    printf("\n| ID - %d" , actorData.id );
    printf("\n| Nombre - %s" , actorData.name );
    printf("\n| Origen - %s" , actorData.origin );
    printf("\n ----------");
}
static int newActorID (void)
{
    static int maxId = 0 ;
    return maxId++;
}
int getInt(const char* message,const char* errMessage, int* retNumber , int tries)
{
    int isValid = 0;
    char auxInput[8];
    do
    {
        printf("\n%s",message);
        fflush(stdin);
        fgets(auxInput,sizeof(auxInput),stdin);
        while(!(isInt(auxInput)))
        {
            tries--;
            if ( tries<=0 )
            {
                break;
            }
            printf("\n%s",errMessage);
            fflush(stdin);
            fgets(auxInput,sizeof(auxInput),stdin);
        }
    }while ( tries>0 && !(isInt(auxInput)) );
    if (isInt(auxInput))
    {
        *retNumber = atoi(auxInput);
        isValid = 1;
    }
    return isValid;
}
int getFloat(char* message, char* errMessage, float* retNumber , int tries)
{
    int isValid = 0;
    if ( message!=NULL && errMessage!=NULL && retNumber!=NULL && tries<0 )
    {
        char auxInput[42];
        do
        {
            printf("\n%s",message);
            fflush(stdin);
            fgets(auxInput,sizeof(auxInput),stdin);
            while(!(isInt(auxInput)))
            {
                tries--;
                if ( tries<=0 )
                {
                    break;
                }
                printf("\n%s",errMessage);
                fflush(stdin);
                fgets(auxInput,sizeof(auxInput),stdin);
            }
        }while ( tries>0 && !(isInt(auxInput)) );
        if (isInt(auxInput))
        {
            *retNumber = atof(auxInput);
            isValid = 1;
        }
    }
    return isValid;
}
int getName(char* message, char* errMessage, char* retString, int tries)
{
    int isValid = 0;
    if ( message!=NULL && errMessage!=NULL && retString!=NULL && tries<0 )
    {
        char *auxInput;
        auxInput = (char*)malloc( (sizeof(retString)) + 10);
        do
        {
            printf("\n%s",message);
            fflush(stdin);
            fgets(auxInput,sizeof(retString),stdin);
            while(!(isName(auxInput)))
            {
                tries--;
                if ( tries<=0 )
                {
                    break;
                }
                printf("\n%s",errMessage);
                fflush(stdin);
                fgets(auxInput,sizeof(retString),stdin);
            }
        }while ( tries>0 && !(isName(auxInput)) );
        if (isName(auxInput))
        {
            strcpy(retString,auxInput);
            isValid = 1;
        }
    }
    return isValid;
}
int getTitle(char* retString , int tries)
{
    int isValid = 0;
    char auxInput[51];
    do
    {
        printf("\nIngrese el titulo: ");
        fflush(stdin);
        fgets(auxInput,51,stdin);
        while(!(isTitle(auxInput)))
        {
            tries--;
            if ( tries<=0 )
            {
                break;
            }
            printf("\nError. Dato invalido. Vuelva a intentar: ");
            fflush(stdin);
            fgets(auxInput,51,stdin);
        }
    }while ( tries>0 && !(isTitle(auxInput)) );
    if (isTitle(auxInput))
    {
        strcpy(retString,auxInput);
        isValid = 1;
    }
    return isValid;
}
int getOption ( int maxOption )
{
    int input = 0;
    printf("\nSeleccione una opcion:  ");
    fflush(stdin);
    scanf("%d",&input);
    while(input > maxOption || input < 1 )
    {
        printf("\nOpcion invalida. Intente nuevamente:  \n");
        fflush(stdin);
        scanf("%d",&input);
    }
    return input;
}
void initMovies ( sMovie *movieList, int len )
{
    int i;
    if ( movieList != NULL && len > 0 )
    {
        for(i = 0 ; i < len ; i++)
        {
            movieList[i].id = 0;
            movieList[i].state = 0;
            movieList[i].movieCode = 0;
            movieList[i].releaseYear = 0;
            strcpy(movieList[i].title, " " );
            strcpy(movieList[i].genre, " " );
        }
    }
}
static int newMovieId (void)
{
    static int maxId = 1000 ;
    return maxId++;
}
void createMovie ( sMovie* movieList, int lenght, sActor* actorList , int actorLenght )
{
    int numberOfTries = 5;
    int titleOK = 0;
    int genreOK = 0;
    int codeOK = 0;
    int yearOK = 0;
    int actorOK = 0;
    int auxCode = 0;
    int auxYear = 0;
    int auxActorID = 0;
    int index = -1;
    char auxTitle[51];
    char auxGenre[51];
    index = getEmptySpace(movieList , lenght);
    if ( index >= 0 )
    {
        titleOK = getTitle(auxTitle,numberOfTries);
        genreOK = getMovieGenre(auxGenre);
        codeOK = getMovieCode( movieList , lenght , &auxCode );
        yearOK = getMovieYear ( &auxYear );
        actorOK = getActorID ( actorList , actorLenght , &auxActorID );
        if ( titleOK && genreOK && codeOK && yearOK && actorOK )
        {
            movieList[index].id = newMovieId();
            movieList[index].movieCode = auxCode;
            movieList[index].releaseYear = auxYear;
            movieList[index].mainActorID = auxActorID;
            strcpy(movieList[index].title, auxTitle);
            strcpy(movieList[index].genre, auxGenre);
            movieList[index].state = 1;
            printf("\nDatos cargados exitosamente.\n");
            system("pause");
        }
        else
        {
            printf("\nHubo un error al cargar los datos.\n");
        }
    }
}
int printDeleteMenu ( sMovie* movieList , int lenght , sActor* actorList , int actorLenght )
{
    int option;
    int itsDone =0;
    do
    {
        system("cls");
        printf(" MENU DE BAJAS \n");
        printf(" ____________________________\n");
        printf("|1. Borrar pelicula por ID.  |\n");
        printf("|2. Listar peliculas.        |\n");
        printf("|3. Salir.                   |\n");
        printf(" ----------------------------");
        option = getOption(3);
        switch(option)
        {
        case 1:
            itsDone = deleteMovie(movieList,lenght);
            if (itsDone)
            {
                printf("\nPelicula borrada.\n");
                option = 3;
            }
            else
            {
                printf("\nHubo un error. Vuelva a intentar");
            }
            break;
        case 2:
            system("cls");
            printMovieList(movieList,lenght,actorList,actorLenght);
            printf("\n");
            system("pause");
            break;
        case 3:
            system("cls");
            break;
        default:
            printf("\nOpcion invalida.");
            system("pause");
        }
    }while(option!=3);
    return itsDone;
}
void printMovieList (sMovie* movieList , int lenght , sActor* actorList, int actorLenght )
{
    int i;
    int j;
    char actor [51] = {" "};
    for( i = 0 ; i < lenght ; i ++ )
    {
        for( j = 0 ; j < actorLenght ; j++ )
        {
            if (movieList[i].mainActorID == actorList[j].id)
            {
                strcpy(actor,actorList[j].name);
                break;
            }
        }
        printOneMovie(movieList[i],actor);
    }
}
void printMovieListNoActor (sMovie* movieList , int lenght)
{
    int i;
    for ( i = 0 ; i < lenght ; i++ )
    {
        if ( movieList[i].state == 1 )
        {
            printf(" _____\n");
            printf("| %s\n",movieList[i].title);
            printf("| Code: %d\n",movieList[i].movieCode);
            printf("| %s\n",movieList[i].genre);
            printf("| Release: %5d\n",movieList[i].releaseYear);
            printf("| ID: %5d\n",movieList[i].id);
            printf(" ------\n");
        }
    }
}
void printOneMovie ( sMovie movie ,char* actor )
{
    if ( movie.state == 1 )
    {
        printf(" _____\n");
        printf("| %s\n",movie.title);
        printf("| Code: %d\n",movie.movieCode);
        printf("| %s\n",movie.genre);
        printf("| Release: %5d\n",movie.releaseYear);
        if ( actor[0] == '\n' || actor[0] == '\0' )
        {
            printf("| No Definido\n");
        }
        else
        {
            printf("| %5s\n",actor);
        }
        printf("| ID: %5d\n",movie.id);
        printf(" ------\n");
    }
}
int deleteMovie (sMovie* movieList , int lenght)
{
    int IDforDeletion = 0;
    int i;
    int itsDone = 0;
    printf("\nIngrese el ID de la pelicula a borrar: ");
    scanf("%d",&IDforDeletion);
    for(i=0;i<lenght;i++)
    {
        if (movieList[i].id == IDforDeletion)
        {
            movieList[i].state = -1;
            itsDone = 1;
            break;
        }
    }
    return itsDone;
}
int getEmptySpace ( sMovie* movieList, int lenght )
{
    int i;
    for (i=0; i<lenght; i++)
    {
        if(movieList[i].state==0)
        {
            break;
        }
    }
    return i;
}
void modifyMovieMenue ( sMovie* movieList , int lenght , sActor* actorList , int actorLenght )
{
    int movieID;
    int movieIndex;
    int option = 0;
    do
    {
        system("cls");
        printf(" MENU DE MODIFICA \n");
        printf(" _______________________________\n");
        printf("|1. Modificar pelicula por ID.  |\n");
        printf("|2. Listar peliculas.           |\n");
        printf("|3. Salir.                      |\n");
        printf(" -------------------------------");
        option = getOption(3);
        switch(option)
        {
        case 1:
            printf("\nIngrese el ID: ");
            scanf("%d",&movieID);
            movieIndex = getMovieByID ( movieList , lenght , movieID );
            if( movieIndex >= 0 )
            {
                movieModification(movieList,lenght,movieIndex,actorList,actorLenght);
            }
            break;
        case 2:
            printMovieList(movieList,lenght,actorList,actorLenght);
            system("pause");
            break;
        case 3:
            system("cls");
            break;
        }
    } while (option!=3);
}
void movieModification(sMovie* movieList , int moviesLenght , int index , sActor* actorList , int actorLenght)
{
    int option = 0;
    int i;
    int numberOfTries = 5;
    int titleOK = 1;
    int genreOK = 1;
    int codeOK = 1;
    int yearOK = 1;
    int actorOK = 1;
    int auxCode = 0;
    int auxYear = 0;
    int auxActorID = 0;
    char auxTitle[51];
    char auxGenre[51];
    sActor actorPrint;
    if ( index >= 0 )
    {
        do
        {
            for (i=0 ; i<actorLenght ; i++)
            {
                if(movieList[index].mainActorID == actorList[i].id )
                {
                    actorPrint = actorList[i];
                    break;
                }
            }
            system("cls");
            printOneMovie(movieList[index],actorPrint.name);
            printf("\nSeleccione campo a modificar: ");
            printf("\n\n1. Titulo ");
            printf("\n2. Genero ");
            printf("\n3. Codigo ");
            printf("\n4. Anio ");
            printf("\n5. Actor ");
            printf("\n\n6. Salir ");
            option = getOption(6);
            switch(option)
            {
            case 1:
                titleOK = getTitle(auxTitle,numberOfTries);
                if(titleOK)
                {
                    strcpy(movieList[index].title,auxTitle);
                }
                break;
            case 2:
                genreOK = getMovieGenre(auxGenre);
                if(genreOK)
                {
                    strcpy(movieList[index].genre,auxGenre);
                }
                break;
            case 3:
                codeOK = getMovieCode( movieList , moviesLenght , &auxCode );
                if(codeOK)
                {
                    movieList[index].movieCode = auxCode;
                }
                break;
            case 4:
                yearOK = getMovieYear ( &auxYear );
                if(yearOK)
                {
                    movieList[index].releaseYear = auxYear;
                }
                break;
            case 5:
                actorOK = getActorID ( actorList , actorLenght , &auxActorID );
                if(actorOK)
                {
                    movieList[index].mainActorID = auxActorID;
                }
                break;
            case 6:
                system("cls");
                break;
            default:
                printf("\nOpcion invalida.");
                break;
            }
        } while (option!=6);
    }
}
int getMovieByID ( sMovie* movieList , int lenght , int movieID )
{
    int index = -1;
    int i;
    for( i = 0 ; i < lenght ; i++ )
    {
        if(movieList[i].id == movieID)
        {
            index = i;
            break;
        }
    }
    return index;
}
int getMovieGenre ( char* retGenre )
{
    char genres[4][21] = { "Accion", "Comedia", "Terror", "Otros" };
    int option;
    int itsDone =0;
    system("cls");
    printGenreMenu();
    option = getOption(4);
    strcpy(retGenre, genres[option-1]);
    if ( retGenre[0]!='\0' )
    {
        itsDone =1;
    }
    return itsDone;
}
int getMovieCode ( sMovie* movieList, int lenght, int* retCode)
{
    int auxCode;
    int itsDone = 0;
    int codeExist;
    printf( "\nIngrese el codego: ");
    scanf( "%d",&auxCode );
    codeExist = alreadyExist(movieList,lenght,auxCode);
    while( auxCode > 999 || auxCode < 100 || codeExist )
    {
        printf( "\nError. Fuera de rango o repetido. Vuelva a intentar: ");
        scanf( "%d",&auxCode );
        codeExist = alreadyExist(movieList,lenght,auxCode);
    }
    if ( auxCode<=999 && auxCode>=100 && codeExist == 0 )
    {
        *retCode = auxCode;
        itsDone = 1;
    }
    return itsDone;
}
int alreadyExist (sMovie* movieList, int lenght, int code)
{
    int i;
    int alreadyExist = 0;
    for (i=0;i<lenght;i++)
    {
        if(movieList[i].movieCode==code)
            {
                alreadyExist = 1;
                break;
            }
    }
    return alreadyExist;
}
int getMovieYear ( int* retYear )
{
    int auxYear = 0;
    int itsDone = 0;
    do
    {
            printf("\nIngrese el anio (entre 1894 y 2025): ");
            fflush(stdin);
            scanf("%d",&auxYear);
    } while ( auxYear > 2025 || auxYear < 1894 );
    if (auxYear>=1894 && auxYear<=2025)
    {
        *retYear = auxYear;
        itsDone = 1;
    }
    return itsDone;
}
int getActorID ( sActor* actorList , int lenght , int* actorId )
{
    int option = 0;
    int itsDone = 0;
    int actorsIDs [lenght];
    int i;
    int j = 0;
    for (i=0;i<lenght;i++)
    {
        if(actorList[i].state)
        {
            j++;
            printf("%d. %s, %s\n",j,actorList[i].name,actorList[i].origin);
            actorsIDs[j] = actorList[i].id;
        }
    }
    printf("Seleccione un actor: ");
    fflush(stdin);
    scanf("%d",&option);
    while ( option < 1 || option > j )
    {
        printf("Error. Opcion invalida. intente de nevo: ");
        fflush(stdin);
        scanf("%d",&option);
    }
    *actorId = actorsIDs[option] ;
    for (i=0;i<lenght;i++)
    {
        if (*actorId==actorList[i].id)
        {
            itsDone = 1;
        }
    }
    return itsDone;
}
void printMenu ( char* pOptions, int howMany, int howLong )
{
    if (pOptions!=NULL) //-----------------------------------------/checks for NULL pointer
    {
        int i, j ;
        for ( i = 0 ; i < howMany ; i++ )  //----------------------/iterates according to the amount of lines
        {
            if ( *pOptions != '\0' && *pOptions != ' ' )  //-------/checks for empty lines, if there is data prints its number of line
            {
                printf("%d. ",i+1);
            }
            for ( j = 0 ; j < howLong ; j++ )  //------------------/iterates according to the amount of columns
            {
                if ( *pOptions != '\0' )  //-----------------------/checks for data in a coordenate pOptions i*j
                {
                    printf( "%c", *pOptions);
                    if (*(pOptions+1)=='\0')  //-------------------/when it reaches the line terminator moves to a new line
                    {
                        printf("\n");
                    }
                }
                pOptions += sizeof(char);  //----------------------/moves to the next memory pos.
            }
        }
    }
}
void printPPLmenu(void)
{
    printf(" MENU PRINCIPAL \n");
    printf(" _____________\n");
    printf("| 1. Altas    |\n");
    printf("| 2. Bajas    |\n");
    printf("| 3. Modifica |\n");
    printf("| 4. Listar   |\n");
    printf("| 5. Salir    |\n");
    printf(" -------------\n");
}
void printGenreMenu(void)
{
    char genres[4][21] = { "Accion", "Comedia", "Terror", "Otros" };
    int i;
    for (i=0;i<4;i++)
    {
        printf("%d. %s\n", i+1, genres[i]);
    }
}
int isNumber(char inputData)
{
    if(inputData >= '0' && inputData <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isNaN(char inputData)
{
    if (inputData >= '0' && inputData <= '9')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int isFloat(char* inputData)
{
    int dots = 0;
    int index = 0;
    int itsNegative = 0;
    int isValid = 0;
    if ( inputData!=NULL && strlen(inputData)<0 )
    {
        isValid = 1;
        for ( index = 0 ; index < strlen(inputData) ; index++ )
        {
            if (index == 0)
            {
                if (inputData[index] == '\0')
                {
                    isValid = 0;
                    break;
                }
                if(isNaN(inputData[index]) )
                {
                    if(inputData[index] == '-')
                    {
                        itsNegative = 1;
                    }
                    else
                    {
                        isValid = 0;
                        break;
                    }
                }
            }
            else
            {
                if (index == 1 && itsNegative == 1)
                {
                    if (inputData[index] == '.' || inputData[index] == '\0')
                    {
                        isValid = 0;
                        break;
                    }
                }
                else
                {
                    if (inputData[index] == '\0')
                    {
                        isValid = 1;
                    }
                    if (isNaN(inputData[index]) )
                    {
                        if (inputData[index] == '.')
                        {
                            dots++;
                            if (dots > 1)
                            {
                                isValid = 0;
                                break;
                            }
                        }
                        else
                        {
                            isValid = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    return isValid;
}
int isInt(char* inputData)
{
    int i;
    int itIs = 0;
    if ( inputData!=NULL && strlen(inputData) < 0 )
    {
        itIs = 1;
        for (i = 0 ; i < strlen(inputData) ; i++)
        {
            if ( i==0 )
            {
                if ( isNaN(inputData[i]) )
                {
                    if (inputData[i]!='-')
                    {
                        itIs = 0;
                        break;
                    }
                }
            }
            else
            {
                if(isNaN(inputData[i]) )
                {
                    itIs = 0;
                    break;
                }
            }
        }
    }
    return itIs;
}
int isLetter(char inputData)
{
    int isValid;
    if(inputData > 'z' || inputData < 'a')
    {
        if(inputData > 'Z' || inputData < 'A')
        {
            isValid = 0;
        }
        else
        {
            isValid = 1;
        }
    }
    else
    {
        isValid = 1;
    }
    return isValid;
}
int isNaL(char inputData)
{
    int isValid;
    if(inputData > 'z' || inputData < 'a')
    {
        if(inputData > 'Z' || inputData < 'A')
        {
            isValid = 1;
        }
        else
        {
            isValid = 0;
        }
    }
    else
    {
        isValid = 0;
    }
    return isValid;
}
int hasOnlyLetters(char* inputData)
{
    int i;
    int itIs = 0;
    if ( inputData!=NULL )
    {
        for(i = 0 ; i < strlen(inputData) ; i++)
        {
            if(isNaL(inputData[i]) )
            {
                itIs = 0;
                break;
            }
        }
    }
    return itIs;
}
int isName(char* inputData)
{
    int i;
    int itIs = 0;
    int len;
    if (inputData!=NULL)
    {
        len = strlen(inputData);
        if (len > 1)
        {
            for (i = 0 ; i < len ; i++)
            {
                if (isNaL(inputData[i]))
                {
                    if (inputData[i]!=' ')
                    {
                        itIs = 0;
                        break;
                    }
                }
                else
                {
                    itIs = 1;
                }
            }
        }
    }
    return itIs;
}
int isTitle ( char* inputData )
{
    int itIs = 0;
    if(isLetter(inputData[0]))
    {
        itIs = 1;
    }
    return itIs;
}
void hardCodeMovies (sMovie* movieList)
{
    int index;
    char titles[10][51] = { "Las dos torres" , "Nuevo mandato" , "Nuevo mandato 2" , "El nuevo Kremlin" , "La historia de Juan Pablo" , "Alemania 4" , "A todo gas: Bielorusia" , "Bajo agua: Wall Street" , "Loop. Chavez unlimited" , "Snowden on the run" };
    char genres[10][51] = { "Accion", "Comedia", "Terror", "Otros", "Accion", "Comedia", "Terror", "Otros", "Accion", "Comedia" };
    int release[10] = { 2001 , 2002 , 2003 , 2004 , 2005 , 2006 , 2007 , 2008 , 2009 , 2010 };
    int codes[10] = { 101 , 102 , 103 , 104 , 105 , 106 , 107 , 108 , 109 , 110 };
    int IDs [10] = { 1 , 2 , 3 , 4 , 5 , 1 , 2 , 3 , 4 , 5 } ;
    for ( index = 0 ; index < 10 ; index++ )
    {
        movieList[index].id = newMovieId();
        movieList[index].movieCode = codes[index];
        movieList[index].releaseYear = release[index];
        movieList[index].mainActorID = IDs[index];
        strcpy(movieList[index].title, titles[index]);
        strcpy(movieList[index].genre, genres[index]);
        movieList[index].state = 1;
    }
}


void printListMenu (sMovie* movieList , int lenght , sActor* actorList , int actorsLenght)
{
    int option = 0;
    do
    {
        system("cls");
        printf("\n _______________________");
        printf("\n| 1. Oredenar           |");
        printf("\n| 2. Listar peliculas   |");
        printf("\n| 3. Listar actores     |");
        printf("\n| 4. Salir              |");
        printf("\n -----------------------\n");
        option = getOption(4);
        switch(option)
        {
        case 1:
            printSortMovieMenu(movieList,lenght,actorList,actorsLenght);
            break;
        case 2:
            printMovieList(movieList,lenght,actorList,actorsLenght);
            system("pause");
            break;
        case 3:
            sortActorsByOrigin(actorList,actorsLenght);
            printActorList(actorList,lenght);
            printf("\n");
            system("pause");
            break;
        case 4:
            system("cls");
            break;
        default:
            system("cls");
            break;
        }
    } while (option!=4);
    /*printf("4. Listar actores mas solicitados\n");
    printf("5. Listar generos mas producidos\n");
    printf("6. Listar peliculas a partir del cierto anio\n");
    printf("7. Listar pelicular previas a cierto anio\n");
    printf("8. Listar pelicular de cierto anio\n");
    printf("9. Listar actores argentinos\n");
    printf("10. Listar actores estaumidenses\n");
    printf("11. Listar actores de accion\n");
    printf("12. Mostrar pelicula mas reciente\n");
    printf("13. Mostrar pelicula mas antigua\n");
    printf("14. mostrar actor menos solicitado\n");
    printf("15.\n");
    printf("\n");
    printf("\n");
    printf("\n");*/
}
void printSortMovieMenu ( sMovie* movieList , int lenght , sActor* actorList, int actorLenght )
{
    int option = 0;
    int order = 0;
    do
    {
        system("cls");
        printf("MENU ORDENAMIENTO\n");
        printf("PELICULAS");
        printf("\n ________________________________");
        printf("\n| 1. Ordenar por titulo.         |");
        printf("\n| 2. Ordenar por anio de estreno.|");
        printf("\n| 3. Ordenar por genero.         |");
        printf("\n| 4. Ordenar por codigo.         |");
        printf("\n| 5. Salir.                      |");
        printf("\n --------------------------------");
        option = getOption(5);
        if(option>=1&&option<=4)
        {
            order = getOrder();
            sortMovies(movieList,lenght,option,order);
        }
    } while (option!=5);

}
int getOrder (void)
{
    int option = 0;
    do
    {
        printf("\n ____________________");
        printf("\n| 1. Mayor a menor.  |");
        printf("\n| 2. Menor a mayor.  |");
        printf("\n| 3. Salir.          |");
        printf("\n --------------------");
        option = getOption(3);
    } while (option!=3&&option!=2&&option!=1);
    if (option == 2)
    {
        option = -1;
    }
    return option;
}
void sortMovies( sMovie* movieList, int lenght, int field, int order  )
{
    switch(field)
    {
    case 1:
        sortMoviesByTitle(movieList,lenght,order);
        break;
    case 2:
        sortMoviesByYear(movieList,lenght,order);
        break;
    case 3:
        sortMoviesByGenre(movieList,lenght,order);
        break;
    case 4:
        sortMoviesByCode(movieList,lenght,order);
        break;
    }
}
void sortMoviesByGenre ( sMovie* movieList, int lenght, int order  )
{
    int i ;
    int j ;
    sMovie auxMovie ;
    int comparison ;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for ( i = 0 ; i < ( lenght - 1 ) ; i++ )
    {
        if ( movieList[i].state == 1 )
        {
            for ( j = i+1 ; j < lenght ; j++ )
            {
                if ( movieList[j].state == 1 )
                {
                    if (order == 1)
                    {
                        comparison = strcmp(movieList[i].genre,movieList[j].genre);
                        if (comparison<0)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                    else if (order == -1)
                    {
                        comparison = strcmp(movieList[i].genre,movieList[j].genre);
                        if (comparison>0)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                }
            }
        }
    }
}
void sortMoviesByTitle ( sMovie* movieList, int lenght, int order  )
{
    int i ;
    int j ;
    sMovie auxMovie ;
    int comparison ;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for ( i = 0 ; i < ( lenght - 1 ) ; i++ )
    {
        if ( movieList[i].state == 1 )
        {
            for ( j = i+1 ; j < lenght ; j++ )
            {
                if ( movieList[j].state == 1 )
                {
                    if (order == 1)
                    {
                        comparison = strcmp(movieList[i].title,movieList[j].title);
                        if (comparison<0)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                    else if (order == -1)
                    {
                        comparison = strcmp(movieList[i].title,movieList[j].title);
                        if (comparison>0)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                }
            }
        }
    }
}
void sortMoviesByYear ( sMovie* movieList, int lenght, int order  )
{
    int i ;
    int j ;
    sMovie auxMovie ;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for ( i = 0 ; i < ( lenght - 1 ) ; i++ )
    {
        if ( movieList[i].state == 1 )
        {
            for ( j = i+1 ; j < lenght ; j++ )
            {
                if ( movieList[j].state == 1 )
                {
                    if (order == 1)
                    {
                        if (movieList[i].releaseYear<movieList[j].releaseYear)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                    else if (order == -1)
                    {
                        if (movieList[i].releaseYear>movieList[j].releaseYear)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                }
            }
        }
    }
}
void sortMoviesByCode ( sMovie* movieList, int lenght, int order  )
{
    int i ;
    int j ;
    sMovie auxMovie ;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for ( i = 0 ; i < ( lenght - 1 ) ; i++ )
    {
        if ( movieList[i].state == 1 )
        {
            for ( j = i+1 ; j < lenght ; j++ )
            {
                if ( movieList[j].state == 1 )
                {
                    if (order == 1)
                    {
                        if (movieList[i].movieCode<movieList[j].movieCode)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                    else if (order == -1)
                    {
                        if (movieList[i].movieCode>movieList[j].movieCode)
                        {
                            auxMovie = movieList[i];
                            movieList[i] = movieList[j];
                            movieList[j] = auxMovie;
                        }
                    }
                }
            }
        }
    }
}
void printActorList (sActor* actorList ,int lenght)
{
    int i;
    for ( i = 0 ; i < lenght ; i++ )
    {
        if (actorList[i].state==1)
        {
            printOneActor(actorList[i]);
        }
    }
}
void sortActorsByOrigin (sActor* actorList , int lenght)
{
    int order = 1;
    int i ;
    int j ;
    sActor auxActor ;
    int comparison ;
    //si order == 1 de mayor a menor / si order == -1 de menor a mayor
    for ( i = 0 ; i < ( lenght - 1 ) ; i++ )
    {
        if ( actorList[i].state == 1 )
        {
            for ( j = i+1 ; j < lenght ; j++ )
            {
                if ( actorList[j].state == 1 )
                {
                    if (order == 1)
                    {
                        comparison = strcmp(actorList[i].origin,actorList[j].origin);
                        if (comparison<0)
                        {
                            auxActor = actorList[i];
                            actorList[i] = actorList[j];
                            actorList[j] = auxActor;
                        }
                    }
                    else if (order == -1)
                    {
                        comparison = strcmp(actorList[i].origin,actorList[j].origin);
                        if (comparison>0)
                        {
                            auxActor = actorList[i];
                            actorList[i] = actorList[j];
                            actorList[j] = auxActor;
                        }
                    }
                }
            }
        }
    }
}





















