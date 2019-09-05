#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void checkOut();
double boardCost(int room);
double newspaperCost(int room);
double AgeDiscount(int room);
double roomCost(int room);

int booking = 0;
char BookingID1[32];
char surname1[16];
char forename1[16];
int DOB1[3];
int adults1 = 0;
int children1 = 0;
int boardtype1 = 0;
int lengthofstay1 = 0;
int newspaper1 = 0;

char BookingID2[32];
char surname2[16];
char forename2[16];
int DOB2[3];
int adults2 = 0;
int children2 = 0;
int boardtype2 = 0;
int lengthofstay2 = 0;
int newspaper2 = 0;

char BookingID3[32];
char surname3[16];
char forename3[16];
int DOB3[3];
int adults3 = 0;
int children3 = 0;
int boardtype3 = 0;
int lengthofstay3 = 0;
int newspaper3 = 0;

char BookingID4[32];
char surname4[16];
char forename4[16];
int DOB4[3];
int adults4 = 0;
int children4 = 0;
int boardtype4 = 0;
int lengthofstay4 = 0;
int newspaper4 = 0;

char BookingID[32];
char BookingID1[32];
char BookingID2[32];
char BookingID3[32];
char BookingID4[32];

int rooms[4] = {0,0,0,0};
int available_table[3] = {0,0,0};
int available_table1[3] = {0,0,0};

int checkIn()
{

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);


    int monthdays = 31;
    int unavailable = 0;
    int temp1 =1;
    char* surname;
    char* forename;
    char temprand;
    char fullname[31];
    int DOB[3] = {12984,12984,12984};
    int adults = 12984;
    char charadults[4];                      // IMPORTANT! All of these variables (i.e adults,children,boardtype) are temporary, and will be assigned into the new variables (i.e adults1, DOB3) after the user has chosen a room.
    int children = 12984;
    int boardtype = 0;
    int lengthofstay = 12984;
    int newspaper = 2;
    int guests = 0;
    int x = 0;
    int n = 0; // n is a variable for me to check which statement to output when telling the user their input was invalid
    int j = 0;
    int i = 0; // ^v<---- for loop variables
    int a = 0;
    int chars_only = 1; // just a variable for me to validate fullname as a string containing no digits.
    printf("\n ==================================Name=============================== \n");
    do{
        if (n==0){
            printf("\nPlease enter your full name e.g 'David Smith'\n\nEnter: ");
            fflush(stdin);
            gets(fullname);
        }
        else if (n==2){
            printf("The name you entered was invalid (Name cannot be greater than 31 characters), please enter a valid name to continue:\n\nEnter: ");
            fflush(stdin);
            gets(fullname);
        }
        else if (n==3){
            printf("The name you entered was invalid (Name must contain only alphanumeric characters), please enter a valid name to continue:\n\nEnter: ");
            fflush(stdin);
            gets(fullname);
        }
        else if (n==4){
            printf("Please enter both your first and second name to continue:\n\n Enter: ");
            fflush(stdin);
            gets(fullname);
        }

        n = 0;
        for(a=0;a<strlen(fullname);a++){
            chars_only = isalpha(fullname[a]);
            if (fullname[a] == ' '){
                chars_only = 1;
            }
            else if (fullname[a] == '-' && x==0){
                chars_only = 1;
                x = x+1;
            }
            if (chars_only == 0) break;
        }
        if (strlen(fullname)>31){
            n = 2;
        }
        else if (chars_only== 0){
            n = 3;
        }
        forename = strtok(fullname, " ");
        surname = strtok(NULL, " ");
        if (surname==NULL){
            n = 4;
        }
    }while(strlen(fullname)>31 || chars_only == 0 || surname==NULL); // <---- Validation
    n = 0;
    printf("\n ================================DateOfBirth========================== \n");
    do{
        DOB[1] = 12984;
        DOB[2] = 12984;
        DOB[3] = 12984;
        if (n==1){
            printf("One or more of the characters you entered were not digits. Please enter a valid date containing only digits to continue. (Entering the day, then month, then year and pressing enter between each): ");
            fflush(stdin);
            for (i=0;i<3;i++){
                if(i == 0){printf("\n\nEnter Day: ");}
                else if(i == 1){printf("\nEnter Month: ");}
                else if(i == 2){printf("\nEnter Year: ");}
                scanf("%d",&DOB[i]);
            }
        }
        else if (n==2){
            printf("The date you entered was invalid (Day cannot be greater than %d for that month), please enter a valid date to continue. (Entering the day, then month, then year and pressing enter between each): ",monthdays);
            fflush(stdin);
            for (i=0;i<3;i++){
                if(i == 0){printf("\n\nEnter Day: ");}
                else if(i == 1){printf("\nEnter Month: ");}
                else if(i == 2){printf("\nEnter Year: ");}
                scanf("%d",&DOB[i]);
            }
        }
        else if (n==3){
            printf("The date you entered was invalid (Month cannot be greater than 12), please enter a valid date to continue. (Entering the day, then month, then year and pressing enter between each): ");
            fflush(stdin);
            for (i=0;i<3;i++){
                if(i == 0){printf("\n\nEnter Day: ");}
                else if(i == 1){printf("\nEnter Month: ");}
                else if(i == 2){printf("\nEnter Year: ");}
                scanf("%d",&DOB[i]);
            }
        }
        else if (n==4){
            printf("You must be over 18 to book a room at this hotel. If you are over 18, please enter your real date of birth. (Entering the day, then month, then year and pressing enter between each): ");
            fflush(stdin);
            for (i=0;i<3;i++){
                if(i == 0){printf("\n\nEnter Day: ");}
                else if(i == 1){printf("\nEnter Month: ");}
                else if(i == 2){printf("\nEnter Year: ");}
                scanf("%d",&DOB[i]);
            }
        }
        else if (n==5){
            printf("You aren't 118+ years old... Please enter a more realistic date to continue. (Entering the day, then month, then year and pressing enter between each): ");
            fflush(stdin);
            for (i=0;i<3;i++){
                if(i == 0){printf("\n\nEnter Day: ");}
                else if(i == 1){printf("\nEnter Month: ");}
                else if(i == 2){printf("\nEnter Year: ");}
                scanf("%d",&DOB[i]);
            }
        }
        else if (n==6){
            printf("The date you entered was invalid (Day cannot be less than 1), please enter a valid date to continue. (Entering the day, then month, then year and pressing enter between each): ");
            fflush(stdin);
            for (i=0;i<3;i++){
                if(i == 0){printf("\n\nEnter Day: ");}
                else if(i == 1){printf("\nEnter Month: ");}
                else if(i == 2){printf("\nEnter Year: ");}
                scanf("%d",&DOB[i]);
            }
        }
        else if (n==7){
            printf("The date you entered was invalid (Month cannot be less than 1), please enter a valid date to continue. (Entering the day, then month, then year and pressing enter between each): ");
            fflush(stdin);
            for (i=0;i<3;i++){
                if(i == 0){printf("\n\nEnter Day: ");}
                else if(i == 1){printf("\nEnter Month: ");}
                else if(i == 2){printf("\nEnter Year: ");}
                scanf("%d",&DOB[i]);
            }
        }
        else if (n==8){
            printf("Unless you're from the future, that date is invalid. Please enter a valid date to continue. (Entering the day, then month, then year and pressing enter between each): ");
            fflush(stdin);
            for (i=0;i<3;i++){
                if(i == 0){printf("\n\nEnter Day: ");}
                else if(i == 1){printf("\nEnter Month: ");}
                else if(i == 2){printf("\nEnter Year: ");}
                scanf("%d",&DOB[i]);
            }
        }
        if (n==0){
            printf("\nPlease enter your date of birth (Entering the day, then month, then year and pressing enter between each): ");
            fflush(stdin);
            for (i=0;i<3;i++){
                if(i == 0){printf("\n\nEnter Day: ");}
                else if(i == 1){printf("\nEnter Month: ");}
                else if(i == 2){printf("\nEnter Year: ");}
                scanf("%d",&DOB[i]); // DOB[0] represents the day, DOB[1] the month, and DOB[2] the year.
            }
        }
        n = 0;
        i=0;
        monthdays = 31;
        if(DOB[2] % 4 == 0 && DOB[2] %1000 != 0 && DOB[1] == 2){
            monthdays = 29;
        }
        else if(DOB[1]==1){
            monthdays = 31;
        }
        else if(DOB[1]==2){
            monthdays = 28;
        }
        else if(DOB[1]==3){
            monthdays = 31;
        }
        else if(DOB[1]==4){
            monthdays = 30;
        }
        else if(DOB[1]==5){
            monthdays = 31;
        }
        else if(DOB[1]==6){
            monthdays = 30;
        }
        else if(DOB[1]==7){
            monthdays = 31;
        }
        else if(DOB[1]==8){
            monthdays = 31;
        }
        else if(DOB[1]==9){
            monthdays = 30;
        }
        else if(DOB[1]==10){
            monthdays = 31;
        }
        else if(DOB[1]==11){
            monthdays = 30;
        }
        else if(DOB[1]==12){
            monthdays = 31;
        }

        if (DOB[0]==12984 || DOB[1]==12984 || DOB[2]==12984){
            n = 1;
        }
        else if(DOB[0]>monthdays){
            n = 2;
        }
        else if (DOB[1]>12){
            n = 3;
        }
        else if (DOB[0]<1){
            n = 6;
        }
        else if (DOB[1]<1){
            n = 7;
        }
        else if ((DOB[2] > tm.tm_year + 1882 && DOB[2]< tm.tm_year + 1900)){
            n = 4;
        }
        else if (DOB[2] == (tm.tm_year + 1882) && DOB[1] == (tm.tm_mon + 1) && DOB[0] > (tm.tm_mday)){
            n = 4;
        }
        else if (DOB[2] == (tm.tm_year + 1882) && DOB[1] > (tm.tm_mon + 1)){
            n = 4;
        }
        else if (DOB[2]<tm.tm_year + 1782){
            n = 5;
        }
        else if (DOB[2]> tm.tm_year + 1889){
            n = 8;
        }
    }while(DOB[0]>monthdays || DOB[1]>12 || DOB[2] > tm.tm_year + 1889 || DOB[2]<tm.tm_year + 1782 || DOB[0]<1 || DOB[1]<1 || n == 4); // <---- Validation
    n = 0;
    j = 0;
    printf("\n ==============================Guests(Adults)========================= \n");
    do{
        adults = 12984;
        if (n==0){
            printf("\nPlease enter the number of adults who will be staying in the room including yourself (Maximum number of guests = 4)\n\nEnter: ");
            fflush(stdin);
            scanf("%d",&adults);
        }
        if (n==1){
            printf("The value you entered was not a digit, please enter a valid number of guests containing only digits to continue\n\nEnter: ");
            fflush(stdin);
            scanf("%d",&adults);
        }
        else if (n==2){
            printf("The maximum number of guests per room is 4, please enter a valid number of guests to continue\n\nEnter: ");
            fflush(stdin);
            scanf("%d",&adults);
        }
        else if (n==3){
            printf("You cannot have less than 1 adult staying in a room. Please enter the number of guests staying in the room INCLUDING YOURSELF\n\nEnter: ");
            fflush(stdin);
            scanf("%d",&adults);
        }
        n = 0;
        if (adults==12984){
            n = 1;
        }
        else if (adults>4){
            n = 2;
        }
        else if (adults<1){
            n = 3;
        }
    }while(adults>4 || adults<1); // <---- Validation
    n = 0;
    if (adults!=4){
        printf("\n ==============================Guests(Children)======================= \n");
    }
    if(adults!=4){
        do{
            children = 12984;
            if (n==0){
                printf("\nPlease enter the number of children (16 or below) who will be staying in the room (Maximum number of guests = 4)\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&children);
            }
            if (n==1){
                printf("The value you entered was not a digit, please enter a valid digit to continue\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&children);
            }
            if (n==2){
                printf("Children may not stay in a room without adult supervision. Please try again with a number of children less than 4\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&children);
            }
            if (n==3){
                printf("The number of children you entered exceeds the maximum number of guests per room (4). Please enter a valid number of children to continue\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&children);
            }
            if (n==4){
                printf("The number of children you entered was negative, and is therefore invalid. Please enter a valid number to continue\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&children);
            }
            if (n==5){
                printf("The number of children you entered combined with the number of adults staying in your room exceeds the maximum number of guests per room. Please enter a valid number of children to continue\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&children);
            }
            n = 0;
            guests = adults + children;
            if (children==12984){
                n = 1;
            }
            else if(children==4){
                n = 2;
            }
            else if(children>4){
                n = 3;
            }
            else if(children<0){
                n = 4;
            }
            else if(guests>4){
                n = 5;
            }
        }while(children>3 || children<0 || guests>4); // <---- Validation
    }
    n = 0;
    printf("\n ================================BoardType============================ \n");
    do{
        if(n==0){
            printf("\nPlease choose the board type you would like.\n\n1. Full board \x9C 20 pp\n2. Half board\x9C 15pp\n3. Bed and breakfast \x9C 5pp\n\nEnter: ");
            fflush(stdin);
            scanf("%d",&boardtype); // boardtype == 1 is full board, boardtype == 2 is half board and boardtype == 3 is bed and breakfast
        }
        if (boardtype!=1 && boardtype!=2 && boardtype!=3){
            printf("The value you entered was not '1', '2' or '3'\n\nPlease choose the board type you would like.\n\n1. Full board \x9C 20 pp\n2. Half board\x9C 15pp\n3. Bed and breakfast \x9C 5pp\n\nEnter: ");
            fflush(stdin);
            scanf("%d",&boardtype);
        }
        n = n+1;
    }while(boardtype!=1 && boardtype!=2 && boardtype!=3); // <---- Validation
    n = 0;
    printf("\n ===============================LengthOfStay========================== \n");
    do{
        lengthofstay = 12984;
        if (n==0){
            printf("\nPlease enter the number of days you would like to stay at the hotel for\n\nEnter: ");
            fflush(stdin);
            scanf("%d",&lengthofstay);
        }
        if (n==1){
            printf("The value you enter must contain only digits. Please enter a value consisting of only digits to continue\nEnter: ");
            fflush(stdin);
            scanf("%d",&lengthofstay);
        }
        if (n==3){
            printf("The length of your entered stay cannot exceed the maximum of 100 days. Please enter a number of days less than 100 to continue\nEnter: ");
            fflush(stdin);
            scanf("%d",&lengthofstay);
        }
        if (n==4){
            printf("The length of your entered stay cannot be less than 1 day. Please enter a number of days greater than 0 to continue\nEnter: ");
            fflush(stdin);
            scanf("%d",&lengthofstay);
        }
        n = 0;
        if (lengthofstay==12984){
            n = 1;
        }
        else if (lengthofstay>100){
            n = 3;
        }
        else if (lengthofstay<1){
            n = 4;
        }
    }while(lengthofstay>100 || lengthofstay<1);
    n = 0;
    printf("\n ================================Newspaper============================ \n");
    do{
        if (n==0){
            fflush(stdin);
            printf("\nWould you like a daily newspaper? (One off payment of \x9C5.50)\n\n1. I would like a newspaper\n2. No thanks, I wouldn't like a newspaper.\n\nEnter: ");
            scanf("%d",&newspaper); // 0 is no newspaper, 1 is a newspaper
        }
        else if (n>0){
            fflush(stdin);
            printf("The value you entered must be either '0' or '1'. \n\nWould you like a daily newspaper? (One off payment of \x9C5.50)\n\n1. I would like a newspaper\n2. No thanks, I wouldn't like a newspaper.\n\nEnter: ");
            scanf("%d",&newspaper);
        }
        n = n+1;
    }while(newspaper!=0 && newspaper!=1); // <---- Validation
    printf("\n ================================RoomBooking========================== \n");
    printf("\nThe currently available rooms are:\n");
    if (rooms[0] == 0){
        printf(" ------------------------------\n| Room 1 | Price: \x9C 100 per day|\n ------------------------------\n");
    }
    if (rooms[1] == 0){
        printf("| Room 2 | Price: \x9C 85 per day |\n ------------------------------\n");
    }
    if (rooms[2] == 0){
        printf("| Room 3 | Price: \x9C 75 per day |\n ------------------------------\n");
    }
    if (rooms[3] == 0){
        printf("| Room 4 | Price: \x9C 50 per day |\n ------------------------------\n");
    }
    else if (rooms[0] == 1 && rooms[1] == 1 && rooms[2] == 1 && rooms[3] == 1){
        printf("Sorry for the inconvenience, but we are currently fully booked, please check again at a later date.");
        unavailable = 1;
    }
    n=0;
    if (unavailable == 0){
        do{
            booking=12984;
            if (n==0){
                printf("\nPlease enter the number of the available room you would like to book. (i.e '1','2','3' or '4')\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&booking);
            }
            else if (unavailable==1){
                printf("Room 1 is currently unavailable. Please enter the number of the AVAILABLE room you would like to book\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&booking);
            }
            else if (unavailable==2){
                printf("Room 2 is currently unavailable. Please enter the number of the AVAILABLE room you would like to book\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&booking);
            }
            else if (unavailable==3){
                printf("Room 3 is currently unavailable. Please enter the number of the AVAILABLE room you would like to book\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&booking);
            }
            else if (unavailable==4){
                printf("Room 4 is currently unavailable. Please enter the number of the AVAILABLE room you would like to book\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&booking);
            }
            else if (n>0){
                printf("The value you entered was not '1','2','3' or '4'. Please enter the number of the available room you would like to book\n\nEnter: ");
                fflush(stdin);
                scanf("%d",&booking);
            }
            n = n+1;
            unavailable = 0;
            if (booking==1){
                rooms[0] == 1;
            }
            if (booking==2){
                rooms[1] == 1;
            }
            if (booking==3){
                rooms[2] == 1;
            }
            if (booking==4){
                rooms[3] == 1;
            }
            if (rooms[0]==1 && booking==1){
                unavailable = 1;
            }
            if (rooms[1]==1 && booking==2){
                unavailable = 2;
            }
            if (rooms[2]==1 && booking==3){
                unavailable = 3;
            }
            if (rooms[3]==1 && booking==4){
                unavailable = 4;
            }


        }while((booking!=1 && booking!=2 && booking!=3 && booking!=4) || unavailable>0);
    }
    printf("\n ==================================BookingID=============================== \n");

    if (booking == 1){
        printf("Congratulations, you have been booked into Room 1 for %d days",lengthofstay);
        for (j=0;j<3;j++){

            DOB1[j] = DOB[j];
        }
        rooms[0] = 1;
        strcpy(surname1,surname);
        strcpy(surname1,surname);
        adults1 = adults;
        if (children==12984){
            children = 0;
        }
        children1 = children;
        boardtype1 = boardtype;
        lengthofstay1 = lengthofstay;
        newspaper1 = newspaper;
        srand(time(NULL));
        temprand = (rand() %10) ;
        strcpy(BookingID1,surname);
        sprintf(BookingID1, "%s%d",surname,temprand);
        printf("\nYou have been assigned the booking ID '%s'. Remember this, as it will be used to book meals in the dining room.",BookingID1);
    }
    if (booking == 2){
        printf("Congratulations, you have been booked into Room 2 for %d days",lengthofstay);
        for (j=0;j<3;j++){
            DOB2[j] = DOB[j];
        }
        rooms[1] = 1;
        strcpy(surname2,surname);
        strcpy(surname2,surname);
        adults2 = adults;
        if (children==12984){
            children = 0;
        }
        children2 = children;
        boardtype2 = boardtype;
        lengthofstay2 = lengthofstay;
        newspaper2 = newspaper;
        srand(time(NULL));
        temprand = (rand() %10);
        strcpy(BookingID2,surname);
        sprintf(BookingID2, "%s%d",surname,temprand);
        printf("\nYou have been assigned the booking ID '%s'. Remember this, as it will be used to book meals in the dining room.",BookingID2);
    }
    if (booking == 3){
        printf("Congratulations, you have been booked into Room 3 for %d days",lengthofstay);
        for (j=0;j<3;j++){
            DOB3[j] = DOB[j];
        }
        rooms[2] = 1;
        strcpy(surname3,surname);
        strcpy(surname3,surname);
        adults3 = adults;
        if (children==12984){
            children = 0;
        }
        children3 = children;
        boardtype3 = boardtype;
        lengthofstay3 = lengthofstay;
        newspaper3 = newspaper;
        srand(time(NULL));
        temprand = (rand() %10);
        strcpy(BookingID3,surname);
        sprintf(BookingID3, "%s%d",surname,temprand);
        printf("\nYou have been assigned the booking ID '%s'. Remember this, as it will be used to book meals in the dining room.",BookingID3);
    }
    if (booking == 4){
        printf("Congratulations, you have been booked into Room 4 for %d days",lengthofstay);
        for (j=0;j<3;j++){
            DOB4[j] = DOB[j];
        }
        rooms[3] = 1;
        strcpy(surname4,surname);
        strcpy(surname4,surname);
        adults4 = adults;
        if (children==12984){
            children = 0;
        }
        children4 = children;
        boardtype4 = boardtype;
        lengthofstay4 = lengthofstay;
        newspaper4 = newspaper;
        srand(time(NULL));
        temprand = (rand() %10);
        strcpy(BookingID4,surname);
        sprintf(BookingID4, "%s%d",surname,temprand);
        printf("\nYou have been assigned the booking ID '%s'. Remember this, as it will be used to book meals in the dining room.",BookingID4);

    }
    printf("\n ===================================================================== \n");
}

int dining()
{
    int n = 0;
    int tables = 0;
    int booking = 0;
    int boardtype = 0;
    int booking_true = 0;
    int eligible_to_eat = 0;
    int endor = 0;
    int naboo = 0;
    int tatooine = 0;
    int sevenpm = 0;
    int ninepm = 0;
    int meal_time = 0;
    int time_allowed = 0;
    int unavailable = 0;
    int selected_table;
    int selected_table1;
    char* table_input;

    do
    {
        printf("\n\n=================================Book a Table=============================\n\nPlease input the room number you are staying in\nEnter: ");
        fflush(stdin);
        scanf("%d", &booking);
        if (booking >4)
        {
            printf("We don't have a Room %d. \n", booking);
        }

    }while (booking>4 || booking<1);
    if (booking<=4)
    {
        do
        {
            printf("\n\n==================================BookingID===============================\n\nPlease input your BookingID which you were given at check in\nEnter:  ");
            scanf("%s",BookingID);
            if (booking==1 && strcmp(BookingID,BookingID1) == 0  && boardtype1 != 3)
            {
                printf("Thanks \n");
                booking_true = 1;
            }
            else if (booking==2 && strcmp(BookingID,BookingID2)== 0 && boardtype2 != 3)
            {
                printf("Thanks \n");
                booking_true = 1;
            }
            else if (booking==3 && strcmp(BookingID,BookingID3)==0 && boardtype3 != 3)
            {
                printf("Thanks \n");
                booking_true = 1;
            }
            else if (booking==4 && strcmp(BookingID,BookingID4)==0 && boardtype4 != 3)
            {
                printf("Thanks \n");
                booking_true = 1;
            }
            else
            {
                printf("\nSorry, you are not eligible to book, as you are entitled to only bed and breakfast.\n");
                booking_true = 0;
                break;
            }
        } while (booking_true == 0);

        if (booking_true == 1)
        {
            do
            {
                printf("\n\n====================================Time=================================\n\nWhat time would you like to eat?\n\n1.7PM\n9PM\n\nEnter: ");
                scanf("%d", &meal_time);
                if (meal_time == 7)
                {
                    printf("OK, here are the available tables at 7pm: ");
                    sevenpm = 1;
                    time_allowed = 1;
                }
                else if (meal_time == 9)
                {
                    printf("OK, here are the available tables at 9pm: ");
                    ninepm = 1;
                    time_allowed = 1;
                }
                else
                {
                    printf("Sorry, that wasn't a valid input \n");
                }
            } while (time_allowed == 0);
        }
        if (sevenpm == 1)
        {
            if (available_table[0] == 0){
                printf("\n\n===================================Table=================================\n\n1.Endor \n");
            }
            if (available_table[1] == 0){
                printf("2.Naboo \n");
            }
            if (available_table[2] == 0){
                printf("3.Tatooine \n");
            }
            else if (available_table[0] == 1 && available_table[1] == 1 && available_table[2] == 1){
                printf("Sorry for the inconvenience, but all the tables are currently booked at that time. \n");
            }
            n=0;
            if (unavailable == 0){
                do{
                    if (n==0){
                        printf("\nPlease enter the table you would like\nEnter: ");
                        fflush(stdin);
                        scanf("%d",&selected_table);
                    }
                    else if (unavailable==1){
                        printf("Endor is currently unavailable. Please choose an available table: ");
                        fflush(stdin);
                        scanf("%d",&selected_table);
                    }
                    else if (unavailable==2){
                        printf("Naboo is currently unavailable. Please choose an available table: ");
                        fflush(stdin);
                        scanf("%d",&selected_table);
                    }
                    else if (unavailable==3){
                        printf("Tatooine is currently unavailable. Please choose an available table: ");
                        fflush(stdin);
                        scanf("%d",&selected_table);
                    }
                    else if (n>0){
                        printf("You did not enter the name of an available table. \n \nPlease enter the table you would like, 1 for Endor, 2 for Naboo and 3 for Tatooine:");
                        fflush(stdin);
                        scanf("%d",&selected_table);
                    }
                    n = n+1;
                    unavailable = 0;
                    if (selected_table==1){
                        available_table[0] = 1;
                        printf("Thank you for booking Endor at 7pm. \n");
                    }
                    else if (selected_table==2){
                        available_table[1] = 1;
                        printf("Thank you for booking Naboo at 7pm. \n");
                    }
                    else if (selected_table==3){
                        available_table[2] = 1;
                        printf("Thank you for booking Tatooine at 7pm. \n");
                    }
                    else if (available_table[0]==1 && selected_table==1){
                        unavailable = 1;
                    }
                    else if (available_table[1]==1 && selected_table==2){
                        unavailable = 2;
                    }
                    else if (available_table[2]==1 && selected_table==3){
                        unavailable = 3;
                    }


                }while((selected_table!=1 && selected_table!=2 && selected_table!=3));
            }
        }
        if (ninepm == 1)
        {
            if (available_table1[0] == 0){
                printf("\n\n===================================Table=================================\n\n1.Endor \n");
            }
            if (available_table1[1] == 0){
                printf("2.Naboo \n");
            }
            if (available_table1[2] == 0){
                printf("3.Tatooine \n");
            }
            else if (available_table1[0] == 1 && available_table1[1] == 1 && available_table1[2] == 1){
                printf("Sorry for the inconvenience, but all the tables are currently booked at that time. \n");
            }
            n=0;
            if (unavailable == 0){
                do{
                    if (n==0){
                        printf("\nPlease enter the table you would like, 1 for Endor, 2 for Naboo and 3 for Tatooine: ");
                        fflush(stdin);
                        scanf("%d",&selected_table1);
                    }
                    else if (unavailable==1){
                        printf("Endor is currently unavailable. Please choose an available table: ");
                        fflush(stdin);
                        scanf("%d",&selected_table1);
                    }
                    else if (unavailable==2){
                        printf("Naboo is currently unavailable. Please choose an available table: ");
                        fflush(stdin);
                        scanf("%d",&selected_table1);
                    }
                    else if (unavailable==3){
                        printf("Tatooine is currently unavailable. Please choose an available table: ");
                        fflush(stdin);
                        scanf("%d",&selected_table1);
                    }
                    else if (n>0){
                        printf("You did not enter the name of an available table. \n \nPlease enter the table you would like, 1 for Endor, 2 for Naboo and 3 for Tatooine:");
                        fflush(stdin);
                        scanf("%d",&selected_table1);
                    }
                    else{
                        printf("\nSorry, that's not a valid input.");
                    }
                    n = n+1;
                    unavailable = 0;
                    if (selected_table1==1){
                        available_table1[0] = 1;
                        printf("Thank you for booking Endor at 9pm. \n");
                    }
                    else if (selected_table1==2){
                        available_table1[1] = 1;
                        printf("Thank you for booking Naboo at 9pm. \n");
                    }
                    else if (selected_table1==3){
                        available_table1[2] = 1;
                        printf("Thank you for booking Tatooine at 9pm. \n");
                    }
                    else if (available_table1[0]==1 && selected_table1==1){
                        unavailable = 1;
                    }
                    else if (available_table1[1]==1 && selected_table1==2){
                        unavailable = 2;
                    }
                    else if (available_table1[2]==1 && selected_table1==3){
                        unavailable = 3;
                    }


                }while((selected_table1!=1 && selected_table1!=2 && selected_table1!=3) );
            }
        }





    }
}

void checkOut() {
    char room[32];
    double boardTotal;
    double newspaperTotal;
    double discount;
    double totalRoomCost;
    double total;
    double discountCalc;

    printf("\n==================================Check Out===============================\nThank you for staying at the Kashyyk Hotel.\nPlease enter your BookingID\nEnter:");
    fflush(stdin);
    gets(room);
    //printf("%s", room);
    if(strcmp(room,BookingID1) == 0){
        boardTotal = boardCost(1);
        newspaperTotal = newspaperCost(1);
        discount = AgeDiscount(1);
        totalRoomCost = roomCost(1);
        if(discount == 0){
            discountCalc = 1;
        }
        else{
            discountCalc = 1.1;
        }
        total = (totalRoomCost + boardTotal + newspaperTotal)/(discountCalc);
        printf("\n======================\n\tBill\t\n======================\nRoom cost:\t%.2f\nBoard Cost:\t%.2f\nNewsPaper:\t%.2f\nDiscount:\t%.0f%%\n======================\nTotal:\t\t%.2f\n======================\n",totalRoomCost, boardTotal,newspaperTotal,discount,total);
        rooms[0] = 0;

    }
    else if(strcmp(room,BookingID2) == 0){
        boardTotal = boardCost(2);
        newspaperTotal = newspaperCost(2);
        discount = AgeDiscount(2);
        totalRoomCost = roomCost(2);
        if(discount == 0){
            discountCalc = 1;
        }
        else{
            discountCalc = 1.1;
        }
        total = (totalRoomCost + boardTotal + newspaperTotal)/(discountCalc);
        printf("\n======================\n\tBill\t\n======================\nRoom cost:\t%.2f\nBoard Cost:\t%.2f\nNewsPaper:\t%.2f\nDiscount:\t%.0f%%\n======================\nTotal:\t\t%.2f\n======================\n",totalRoomCost, boardTotal,newspaperTotal,discount,total);
        rooms[1] = 0;

    }
    else if(strcmp(room,BookingID3) == 0){
        boardTotal = boardCost(3);
        newspaperTotal = newspaperCost(3);
        discount = AgeDiscount(3);
        totalRoomCost = roomCost(3);
        if(discount == 0){
            discountCalc = 1;
        }
        else{
            discountCalc = 1.1;
        }
        total = (totalRoomCost + boardTotal + newspaperTotal)/(discountCalc);
        printf("\n======================\n\tBill\t\n======================\nRoom cost:\t%.2f\nBoard Cost:\t%.2f\nNewsPaper:\t%.2f\nDiscount:\t%.0f%%\n======================\nTotal:\t\t%.2f\n======================\n",totalRoomCost, boardTotal,newspaperTotal,discount,total);
        rooms[2] = 0;

    }
    else if(strcmp(room,BookingID4) == 0){
        boardTotal = boardCost(4);
        newspaperTotal = newspaperCost(4);
        discount = AgeDiscount(4);
        totalRoomCost = roomCost(4);
        if(discount == 0){
            discountCalc = 1;
        }
        else{
            discountCalc = 1.1;
        }
        total = (totalRoomCost + boardTotal + newspaperTotal)/(discountCalc);
        printf("\n======================\n\tBill\t\n======================\nRoom cost:\t%.2f\nBoard Cost:\t%.2f\nNewsPaper:\t%.2f\nDiscount:\t%.0f%%\n======================\nTotal:\t\t%.2f\n======================\n",totalRoomCost, boardTotal,newspaperTotal,discount,total);
        rooms[3] = 0;
    }
    else{
        printf("\nThat's not a valid input\n\n Returning to main manu...\n");
    }
}

double roomCost(int room){
    if(room == 1){
        double totalcost = lengthofstay1 * 100;
        return  totalcost;
    }

    else if(room == 2){
        double totalcost = lengthofstay2 * 85;
        return  totalcost;
    }
    else if(room == 3){
        double totalcost = lengthofstay3 * 75;
        return  totalcost;
    }
    else if(room == 4){
        double totalcost = lengthofstay4 * 50;
        return  totalcost;
    }
}

double AgeDiscount(int room){
    int cost = 0;
    if(room == 1){
        if(DOB1[2] <1983){
            cost = 10;
            return cost;
        }
        else{
            return cost;
        }
    }
    else if(room == 2){
        if(DOB2[2] <1983){
            cost = 10;
            return cost;
        }
        else{
            return cost;
        }
    }
    else if(room == 3){
        if(DOB3[2] <1983){
            cost = 10;
            return cost;
        }
        else{
            return cost;
        }
    }
    else if(room == 4){
        if(DOB4[2] <1983){
            cost = 10;
            return cost;
        }
        else{
            return cost;
        }
    }
}

double newspaperCost(int room){
    double cost = 0;
    if (room == 1){
        if(newspaper1 == 1) {
            cost = 5.5;
            return cost;
        }
        else{
            return cost;
        }
    }
    else if (room == 2){
        if(newspaper2 == 1) {
            cost = 5.5;
            return cost;
        }
        else{
            return cost;
        }
    }
    else if (room == 3){
        if(newspaper3 == 1) {
            cost = 5.5;
            return cost;
        }
        else{
            return cost;
        }
    }
    else if (room == 4){
        if(newspaper4 == 1) {
            cost = 5.5;
            return cost;
        }
        else{
            return cost;
        }
    }
}

double boardCost(int room){
    double totalBoardCost;
    int boardPrice;
    if(room == 1){
        if(boardtype1 == 1){
            boardPrice = 20;
        }
        else if(boardtype1 == 2){
            boardPrice = 15;
        }
        else{
            boardPrice = 5;
        }
        totalBoardCost = ((adults1 * boardPrice) + (0.5 * children1* boardPrice))*lengthofstay1;
        return totalBoardCost;
    }

    else if(room == 2){
        if(boardtype2 == 1){
            boardPrice = 20;
        }
        else if(boardtype2 == 2){
            boardPrice = 15;
        }
        else{
            boardPrice = 5;
        }
        totalBoardCost = ((adults2 * boardPrice) + (0.5 * children2 * boardPrice))*lengthofstay2;
        return totalBoardCost;
    }

    else if(room == 3){
        if(boardtype3 == 1){
            boardPrice = 20;
        }
        else if(boardtype3 == 2){
            boardPrice = 15;
        }
        else{
            boardPrice = 5;
        }
        totalBoardCost = ((adults3 * boardPrice) + (0.5 * children3 * boardPrice))*lengthofstay3;
        return totalBoardCost;
    }

    else if(room == 4){
        if(boardtype4 == 1){
            boardPrice = 20;
        }
        else if(boardtype4 == 2){
            boardPrice = 15;
        }
        else{
            boardPrice = 5;
        }
        totalBoardCost =((adults4 * boardPrice) + (0.5 * children4 * boardPrice))*lengthofstay4;
        return totalBoardCost;
    }
}

int main(){
    int usr = 12984, _ = 1;
    while(_) {
        printf("\n===============================\n Welcome to the Kashyyk Hotel!\n===============================\n\tMenu:\n===============================\n\t1.Check in\n\t2.Book a table\n\t3.Check out\n\n\tEnter: ");
        fflush(stdin);
        scanf("%d", &usr);
        if(usr == 12984){
            printf("\nYou entered a non-digit, please enter a valid input.\n");
            fflush(stdin);
        }
        else if(usr == 1){
            checkIn();
        }
        else if( usr == 2){
            dining();
        }
        else if (usr == 3){
            checkOut();
        }
        else{
            printf("\nThat's not a valid input\n\n");
        }
    }
}