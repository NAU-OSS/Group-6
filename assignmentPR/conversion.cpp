#include<stdio.h>

//Author:Group6_Shangyi
//Edit date: Sep 2,2020
//Declare function
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
	int index,midindex = 0,denIndex = 1;
	
	//I use for loop to find the position of '.' in the string
	for(index = 0; index < sizeof(number); index++)
	{
		if(number[index] == '.')
		{
			midindex = index;
		}
	}

	//The temp is the magnitude of denominator
	//Why -2 ? That's because the length of '.' and '\0'
	int temp = sizeof(number) - midindex - 2;
	while(temp >0)
	{
		denominator[denIndex] = '0';
		denIndex++;
		temp--;
	}

	//The judgment and the print action
	if(characteristic(number,midindex)&&mantissa(number,midindex))
	{
		character = characteristic(number,midindex);
		
		numerator = mantissa(number,midindex);
		
		printf("The characteristic for the number %s is %s and the mantissa is %s over %s.\n",
		number,character,numerator,denominator);
	}else
	{
		printf("Error,Please check input\n");
	}
	return 0;
 } 


//Break the string(character array) into the characteristic
char* characteristic(char numString[],int index){
	int charaIndex = 0;
	for(charaIndex; charaIndex < index; charaIndex++)
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
