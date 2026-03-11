#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct  Date* ptrDate){
    
};

void printDateOnConsole(struct Date* ptrDate){
    printf("Output: ");
    printf("%d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date* ptrDate){
    printf("Enter Day: ");
    scanf("%d", &ptrDate->day);
    printf("Enter Month: ");
    scanf("%d", &ptrDate->month);
    printf("Enter Year: ");
    scanf("%d", &ptrDate->year);
}


int main(){
    struct Date d;
    initDate(&d);
    acceptDateFromConsole(&d);
    printDateOnConsole(&d);
}