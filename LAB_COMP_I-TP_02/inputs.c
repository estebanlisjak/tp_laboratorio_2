#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input, const char message[], const char eMessage[], int lowLimit, int hiLimit, int retries)
{
	int auxiliaryInput;
	int value;

	while(retries > 0)
	{
		printf(message);
		scanf("%d", &auxiliaryInput);

		if(auxiliaryInput >= lowLimit && auxiliaryInput <= hiLimit)
			break;

		retries--;

		if(retries != 0)
			printf(eMessage);
	}

	if(retries == 0)
		value = -1;
	else
	{
		value = 0;
		*input = auxiliaryInput;
	}

	return value;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input, const char message[], const char eMessage[], float lowLimit, float hiLimit, int retries)
{
	float auxiliaryInput;
	int value;

	while(retries > 0)
	{
		printf(message);
		scanf("%f", &auxiliaryInput);

		if(auxiliaryInput >= lowLimit && auxiliaryInput <= hiLimit)
			break;

		retries--;

		if(retries != 0)
			printf(eMessage);
	}

	if(retries == 0)
		value = -1;
	else
	{
		value = 0;
		*input = auxiliaryInput;
	}

	return value;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input, const char message[], const char eMessage[], char lowLimit, char hiLimit, int retries)
{
	char auxiliaryInput;
	int _lowLimit = lowLimit;
	int _hiLimit = hiLimit;
	int value;

	while(retries > 0)
	{
		printf(message);
		fflush(stdin); //fpurge(stdin);
		scanf("%c", &auxiliaryInput); //auxiliaryInput = fgetc(stdin);
		if(auxiliaryInput >= _lowLimit && auxiliaryInput <= _hiLimit)
			break;

		retries--;

		if(retries != 0)
			printf(eMessage);
	}

	if(retries == 0)
		value = -1;
	else
	{
		value = 0;
		*input = auxiliaryInput;
	}

	return value;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input, const char message[], const char eMessage[], int lowLimit, int hiLimit, int retries)
{
	char auxiliaryInput[hiLimit];
	int value;

	while(retries > 0)
	{
		printf(message);
		fflush(stdin); //fpurge(stdin);
		fgets(auxiliaryInput, sizeof(auxiliaryInput), stdin);
		auxiliaryInput[strlen(auxiliaryInput)-1] = '\0';
		if(strlen(auxiliaryInput) >= lowLimit && strlen(auxiliaryInput) <= hiLimit)
			break;

		retries--;

		if(retries != 0)
			printf(eMessage);
	}

	if(retries == 0)
		value = -1;
	else
	{
		value = 0;
		strcpy(input, auxiliaryInput);
	}

	return value;
}

