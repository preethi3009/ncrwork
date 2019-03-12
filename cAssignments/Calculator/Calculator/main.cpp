/*Develop a calculator program with 4 functionalities namely addition, substraction,
multiplication and division. Use multifile program and also use storage class specifiers
wherver required.*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int add(int, int);
int sub(int, int);
double mul(int, int);
double div1(int, int);

double result = -1;

int main()
{
	int iOperand1 = 0, iOperand2 = 0;
	char cCont, cOperation;
	printf("\nenter expression\n");
	if (scanf("%d", &iOperand1))   //checks whetehr the first operand is integer or not
	{
		result = iOperand1;

		//continuously takes inputs till \n is encountered
		while (1)
		{
			if (scanf("%c", &cOperation))//checks if the operation is valid or not
			{
				if (cOperation == '\n')
				{
					printf("\nRESULT = %f", result);
					break;
				}
				else //scans the other operand if the operation is valid
				{
					if (scanf("%d", &iOperand2))
					{
						switch (cOperation)
						{
						case '+': result = add(result, iOperand2);
							break;
						case '-': result = sub(result, iOperand2);
							break;
						case '*': result = mul(result, iOperand2);
							break;
						case '/': result = div1(result, iOperand2);
							break;
						default: printf("\nInvalid operation");
						}
					}
					else //If operand 2 is invalid
					{
						printf("\ninvalid input");
						break;
					}
				}

			}
			else
				//when the operator entered is other than character
			{
				printf("\nInvalid input");
				break;
			}
		}
	}
	//if input is other than integer
	else
		printf("\nInvalid input");
	return 0;
}