
#include <stdio.h>

/***************************************************************************************************************************
********Function Descriptions********

int getMenuChoice(void);
//Function that displays menu choices. It will trap invalid choices (e.g., characters, symbols, out of range values) and 
  allows user to re-enter 2 floats.

void getValidInput(float*, float*);
//Function that traps non-numeric values (e.g., characters, symbols). It only allows two floats to pass back to getAdd(), 
  getSubtract(), and getMultiply() to perform arithmetic operations.

void getNonZeroDenominator(float*, float*);
//Function that traps non-numeric values (e.g., characters, symbols) and zero denominator. It only allows two floats to 
  pass back to the getDivide() function to perform division operation.

float getAdd(float*, float*);
//Function that performs addition of two floats and returns their sum.

float getSubtract(float*, float*);
//Function that performs subtraction of two floats and returns their difference.

float getMultiply(float*, float*);
//Function that performs multiplication of two floats and returns their product.

float getDivide(float*, float*);
//Function that performs division of two floats and returns their quotient.

****************************************************************************************************************************/

/********Function Prototypes (Declarations)********/
int getMenuChoice(void);
void getValidInput(float*, float*);
void getNonZeroDenominator(float*, float*);
float getAdd(float*, float*);
float getSubtract(float*, float*);
float getMultiply(float*, float*);
float getDivide(float*, float*);

int main()
{
	int op;
	float firstN;
	float secondN;
	char repeat = '\n';

	while (repeat == '\n' || repeat != '\n')	//while loop with newline character condition allows user to display the menu again by pressing the enter key
	{
		if (repeat != '\n')
		{
			printf("\n\tPress ONLY enter key to continue....");		//Snippet that tells user to ONLY press enter key to display the menu again.
			while (getchar() != '\n')
				continue;
			repeat = getchar();
			continue;
		}

		op = getMenuChoice();	//getMenuChoice() takes user to the display menu to select their choices. Once an invalid choice is made, it warns the user to re-enter a valid choice.

		if (op == 1)			//Addition operation of two floats is performed if user selects choice/option 1.
		{
			printf("\n\n\tResult of adding %.2f and %.2f is %.2f.\n",
				firstN, secondN, getAdd(&firstN, &secondN));
		}

		else if (op == 2)		//Subtraction operation of two floats is performed if user selects choice/option 2.
		{
			printf("\n\n\tResult of subtracting %.2f from %.2f is %.2f.\n",
				secondN, firstN, getSubtract(&firstN, &secondN));
		}

		else if (op == 3)		//Multiplication operation of two floats is performed if user selects choice/option 3.
		{
			printf("\n\n\tResult of multiplying %.2f and %.2f is %.2f.\n",
				firstN, secondN, getMultiply(&firstN, &secondN));
		}

		else if (op == 4)		//Division operation of two floats is performed if user selects choice/option 4.
		{
			printf("\n\n\tResult of dividing %.2f by %.2f is %.2f.\n",
				firstN, secondN, getDivide(&firstN, &secondN));
		}

		else if (op == 5)		//Program exits only if user selects choice/option 5.
		{
			printf("\n\n\tThank you for using Kam-Mun Foo's Handy Calculator.\n\n\n");
			break;
		}

		printf("\n\tPress enter key to continue....");		//Snippet that allows user to display the menu again by pressing the enter key.
		while (getchar() != '\n')
			continue;
		repeat = getchar();
	}

	return 0;
}

int getMenuChoice(void)		//Function definition for the function that displays menu choices.
{
	int choice;
	int scanf_return_choice;

	printf("\n\n");
	printf("\tWelcome to Kam-Mun Foo's Handy Calculator\n\n");
	printf("\t\t1. Addition\n");
	printf("\t\t2. Subtraction\n");
	printf("\t\t3. Multiplication\n");
	printf("\t\t4. Division\n");
	printf("\t\t5. Exit\n\n");

	printf("\tWhat would you like to do?: ");
	scanf_return_choice = scanf_s("%d", &choice);
	while (scanf_return_choice != 1 || scanf_return_choice == 1)
	{
		if (scanf_return_choice != 1)		//Snippet that traps non-numeric values (e.g., characters, symbols).
		{
			printf("\tThis is not a valid choice, please re-enter between 1 and 5: ");
			while (getchar() != '\n')
				continue;
			scanf_return_choice = scanf_s("%d", &choice);
			continue;
		}

		if (scanf_return_choice == 1 && (choice < 1 || choice > 5))		//Snippet that traps out of range numeric values (outside the range between 1 and 5).
		{
			printf("\tYou have not entered a number between 1 and 5, please re-enter between 1 and 5: ");
			while (getchar() != '\n')
				continue;
			scanf_return_choice = scanf_s("%d", &choice);
			continue;
		}

		else
			break;
	}
	return (choice);
}

void getValidInput(float *ValidN1, float *ValidN2)		//Function definition for the function that traps non-numeric values for addition, subtraction, and multiplication operations.
{
	while (scanf_s("%f %f", ValidN1, ValidN2) != 2)		//Snippet that traps non-numeric values (e.g., characters, symbols).
	{
		printf("\tError reading your numbers, please re-enter both numbers: ");
		while (getchar() != '\n')
			continue;
	}
}

void getNonZeroDenominator(float *ValidN1, float *ValidN2)		//Function definition for the function that traps non-numeric values and zero denominator for division operation.
{
	int scanf_return_division;

	scanf_return_division = scanf_s("%f %f", ValidN1, ValidN2);
	while (scanf_return_division != 2 || scanf_return_division == 2)
	{
		if (scanf_return_division != 2)		//Snippet that traps non-numeric values (e.g., characters, symbols).
		{
			printf("\tError reading your numbers, please re-enter both numbers: ");
			while (getchar() != '\n')
				continue;
			scanf_return_division = scanf_s("%f %f", ValidN1, ValidN2);
			continue;
		}

		if (scanf_return_division == 2)		//Snippet that traps zero denominator.
		{
			if (*ValidN2 == 0)
			{
				printf("\tYou can't divide by zero, please re-enter both numbers: ");
				while (getchar() != '\n')
					continue;
				scanf_return_division = scanf_s("%f %f", ValidN1, ValidN2);
				continue;
			}

			else
				break;
		}
	}
}

float getAdd(float *N1, float *N2)			//Function definition for getAdd() function that performs addition of two floats and returns their sum.
{
	printf("\n\n\tPlease enter two numbers to add, separated by a space: ");
	getValidInput(N1, N2);

	return (*N1 + *N2);
}

float getSubtract(float *N1, float *N2)		//Function definition for getSubtract() function that performs subtraction of two floats and returns their difference.
{
	printf("\n\n\tPlease enter two numbers to subtract, separated by a space: ");
	getValidInput(N1, N2);

	return (*N1 - *N2);
}

float getMultiply(float *N1, float *N2)		//Function definition for getMultiply() function that performs multiplication of two floats and returns their product.
{
	printf("\n\n\tPlease enter two numbers to multiply, separated by a space: ");
	getValidInput(N1, N2);

	return (*N1 * *N2);
}

float getDivide(float *N1, float *N2)		//Function definition for getDivision() function that performs division of two floats and returns their quotient.
{
	printf("\n\n\tPlease enter two numbers to divide, separated by a space: ");
	getNonZeroDenominator(N1, N2);

	return (*N1 / *N2);
}