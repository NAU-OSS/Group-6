#include<stdio.h>
#include<ctype.h>

#define TRUE 1
#define FALSE 0
//Author:Group6_Shangyi Group6_Ziang
//Edit date: Sep 15,2020
//Declare function
int findPoint(char numString[]);
int isRealNumber(char numString[]);
char* characteristic(char numString[],int index);
char* mantissa(char numString[],int index);

//create global array,I know  Global variable is bad, but I am not familiar with stack in C
char number[] = "123.456";
char character[sizeof(number)];
char numerator[sizeof(number)];

//The main function
int main()
{
    //The pointers and array for print
    char* character;
    char* numerator;
    char denominator[sizeof(number)] = "1";
    
    //Declare the indexes used in the main function
    int index,midindex,denIndex = 1;
    
    midindex = findPoint(number);

    //The temp is the magnitude of denominator
    //Why -2 ? That's because the length of '.' and '\0'
    int temp = sizeof(number) - midindex - 2;
    while(temp > 0)
    {
        denominator[denIndex] = '0';
        denIndex++;
        temp--;
    }

    //jusge if the string is real number
    if(isRealNumber(number)){
        printf("The string is not real number. Terminate the program.\n");
        return 0;
    }
    else{
      printf("The string is real number. The program continues.\n");
      //Print what is in the sting
        character = characteristic(number,midindex);
        numerator = mantissa(number,midindex);
        printf("The characteristic for the number %s is %s and the mantissa is %s over %s.\n",
        number,character,numerator,denominator);  
    }
    
    return 0;
 }


//I use for loop to find the position of '.' in the string
 int findPoint(char numString[]){
 	int midindex = 0;
 	int index = 0;
 	for(index; index < sizeof(number); index++)
	{
		if(number[index] == '.')
		{
			midindex = index;
			return midindex;
		}else{
			midindex = index;
		}
	}
	return midindex;
 }



int isRealNumber(char numString[]){
    int index = 0;
    while(numString[index++]){
      if(!isdigit(numString[index-1]) && numString[index-1]!='.' && numString[0]!='-'){
      return TRUE;
      }
    }
    return FALSE;
}

//Break the string(character array) into the characteristic
char* characteristic(char numString[],int index){
    int charaIndex = 0;
    for(charaIndex = 0; charaIndex < index; charaIndex++)
    {
        character[charaIndex] = numString[charaIndex];
    }
    return character;
}

//Break the string(character array) into the mantissa
char* mantissa(char numString[],int index){
    int numeratorIndex = 0;
    for(index; index < sizeof(number); index++)
    {
        numerator[numeratorIndex] = numString[index+1];
        numeratorIndex ++;
    }
    return numerator;
}

//for codeReview
