#include<stdio.h>
#include<math.h>
#include<string.h>
void HexToBin(char *);
void BinToHex(int, char *);
int main()
{	
	char hexdec[100],hex[100];
	int n;
	printf("enter hexadecimal number\n");
	scanf("%s", hexdec); 
	printf("\nequivalent binary value is\n ");
	HexToBin(hexdec);
	printf("\nEnter binary number\n ");
	scanf("%d", &n);
	BinToHex(n, hex);
	printf("\n equivalent Hexadecimal number is %s", hex);
	return 0;
}
void HexToBin(char* hexdec)
{

	long int i = 0;

	while (hexdec[i]) {

		switch (hexdec[i]) {
		case '0':
			printf("0000");
			break;
		case '1':
			printf("0001");
			break;
		case '2':
			printf("0010");
			break;
		case '3':
			printf("0011");
			break;
		case '4':
			printf("0100");
			break;
		case '5':
			printf("0101");
			break;
		case '6':
			printf("0110");
			break;
		case '7':
			printf("0111");
			break;
		case '8':
			printf("1000");
			break;
		case '9':
			printf("1001");
			break;
		case 'A':
		case 'a':
			printf("1010");
			break;
		case 'B':
		case 'b':
			printf("1011");
			break;
		case 'C':
		case 'c':
			printf("1100");
			break;
		case 'D':
		case 'd':
			printf("1101");
			break;
		case 'E':
		case 'e':
			printf("1110");
			break;
		case 'F':
		case 'f':
			printf("1111");
			break;
		default:
			printf("\nInvalid hexadecimal digit %c",
				hexdec[i]);
		}
		i++;
	}
}

void BinToHex(int n, char* hex)
{
	int i = 0, d = 0, rem;
	while (n != 0)
	{
		d += (n % 10)*pow(2, i);
		n /= 10;
		++i;
	}
	i = 0;
	while (d != 0)
	{
		rem = d % 16;
		switch (rem)
		{
		case 10:
			hex[i] = 'A';
			break;
		case 11:
			hex[i] = 'B';
			break;
		case 12:
			hex[i] = 'C';
			break;
		case 13:
			hex[i] = 'D';
			break;
		case 14:
			hex[i] = 'E';
			break;
		case 15:
			hex[i] = 'F';
			break;
		default:
			hex[i] = rem + '0';
			break;
		}
		++i;
		d /= 16;
	}
	hex[i] = '\0';
	strrev(hex);       
}