#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"
#include <ctype.h>

/**
 * \brief To indicate that all position in the array are empty,
 *		   this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
*/
int initEmployees(Employee* list, int len)
{
	int value = -1;
	if(list != NULL)
	{
		int i = 0;
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		value = 0;
	}
	return value;
}

/**
 *\brief Add in a existing list of employees the values received as parameters
 *          in the first empty position
 *
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *         free space] - (0) if Ok
 *
*/
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int freeSpaceIndex = -1;
	int i = 0;
	for(i = 0; i < len; i++)
	{
		if(list[i].isEmpty == 1)
		{
			freeSpaceIndex = i;
			break;
		}
	}

	int value = -1;
	if(list != NULL && freeSpaceIndex != -1)
	{
		list[freeSpaceIndex].id = id;
		strcpy(list[freeSpaceIndex].name, name);
		strcpy(list[freeSpaceIndex].lastName, lastName);
		list[freeSpaceIndex].salary = salary;
		list[freeSpaceIndex].sector = sector;
		list[freeSpaceIndex].isEmpty = 0;
		value = 0;
	}
	return value;
}

/**
 * \brief find an Employee by Id and returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 *          pointer received or employee not found]
 *
*/
int findEmployeeById(Employee* list, int len, int id)
{
	int value = -1;
	int _employeeIndexFound = -1;
	if(list != NULL && _employeeIndexFound == -1)
	{
		int i = 0;
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id)
			{
				_employeeIndexFound = i;
				break;
			}
		}
		value = _employeeIndexFound;
	}
	return value;
}

/**
 * \brief Verify that there is at least one charged employee.
 *
 * \param list Employee*
 * \param len int
 * \return Return (0) if employee is built-in or (-1) if [NULL
 *          pointer received or employee not is not built-in]
 *
*/
int verifyBuiltInEmployee(Employee* list, int len)
{
	int value = -1;
	if(list != NULL)
	{
		int i = 0;
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				value = 0;
				break;
			}
		}
	}
	return value;
}

/**
 * \brief Perform an employee's low logic
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Returns (0) if the employee has been removed and (-1) if the null pointer has been received or the employee's id has not been found.
 *
*/
int removeEmployee(Employee* list, int len, int id)
{
	int value = -1;
	int _employeeIndexFound = -1;
	if(list != NULL && _employeeIndexFound == -1)
	{
		int i = 0;
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id)
			{
				_employeeIndexFound = i;
				break;
			}
		}
		if(_employeeIndexFound != -1)
		{
			list[_employeeIndexFound].isEmpty = 1;
			value = 0;
		}
	}
	return value;
}

/**
 * \brief Sort the elements in the array of employees, the argument order
 *		   indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
*/
int sortEmployees(Employee* list, int len, int order)
{
	int value = -1;
	int i, j;
	Employee auxiliaryEmployee;
	if(list != NULL)
	{
		//Ordenamiento por sector de menor a mayor
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				if(list[i].sector > list[j].sector)
				{
				auxiliaryEmployee = list[i];
				list[i] = list[j];
				list[j] = auxiliaryEmployee;
				}
			}
		}
		//Ordenamiento por apellido
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				if(list[i].sector == list[j].sector)
				{
					switch(order)
					{
						case 1: //Ascendentes
						if(strcmp(list[i].lastName, list[j].lastName) > 0)
						{
						auxiliaryEmployee = list[i];
						list[i] = list[j];
						list[j] = auxiliaryEmployee;
						}
						value = 0;
						break;

						case 2: //Descendente
						if(strcmp(list[i].lastName, list[j].lastName) < 0)
						{
						auxiliaryEmployee = list[i];
						list[i] = list[j];
						list[j] = auxiliaryEmployee;
						}
						value = 0;
						break;
					}
				}
			}
		}
	}
	return value;
}

/** \brief Count the number of employees that exceed the average employee.
 *
 * \param list Employee*
 * \param len int
 * \param averageSalary
 *
*/
int employeesExceedAverageSalary(Employee* list, int len, float averageSalary)
{
	int _averageExcessSalaryCounter = 0;
	if(list != NULL)
	{
		int i = 0;
		for(i = 0; i < len; i++)
		{
			if(list[i].salary > averageSalary)
				_averageExcessSalaryCounter++;
		}
	}
	return _averageExcessSalaryCounter;
}

/**
 * \brief Show the main menu and allow the entry of an option.
 *
 * \param This function does not receive any parameters
 * \return This function returns the selected option
 *
*/
int mainMenu(void)
{
	system("cls");
	printf("\n*************************************");
	printf("\n*****    NOMINA DE EMPLEADOS    *****");
	printf("\n*************************************");
	printf("\n* 1 - Alta                          *");
	printf("\n*************************************");
	printf("\n* 2 - Modificacion                  *");
	printf("\n*************************************");
	printf("\n* 3 - Baja                          *");
	printf("\n*************************************");
	printf("\n* 4 - Informar                      *");
	printf("\n*************************************");
	printf("\n* 5 - Salir                         *");
	printf("\n*************************************\n");
	int _mainSelectedOption;
	getInt(&_mainSelectedOption, "Ingrese una opcion: ", "Error, vuelva a intentarlo! ", 1, 5, 5);
	return (_mainSelectedOption);
}

/**
 * \brief Show the add employee menu.
 *
 * \param This function does not receive any parameters
 * \return This function does not return any value
 *
*/
void addEmployeeMenu (void)
{
	system("cls");
	printf("\n*************************************");
	printf("\n*****      Alta de empledo      *****");
	printf("\n*************************************\n");
}

/**
 * \brief Show the menu of employee reports
 *
 * \param This function receives a character to select the menu to display
 * \return This function does not return any value
 *
*/
void reportsMenu(char _menuCaseOption)
{
	switch(_menuCaseOption)
	{
		case '1':
		system("cls");
		printf("\n*****************************************************************************");
		printf("\n*****                         Reportes                                 ******");
		printf("\n*****************************************************************************");
		printf("\n* 10 - Listado de empleados ordenados alfabeticamente por apellido y sector *");
		printf("\n*****************************************************************************");
		printf("\n* 11 - Total, promedio y cantidad que superan el salario promedio           *");
		printf("\n*****************************************************************************");
		printf("\nOpcion selecccionada: ");
		break;

		case '2':
		system("cls");
		printf("\n**************************");
		printf("\n*****   Reportes    ******");
		printf("\n**************************");
		printf("\n* 12 - Orden ascendente  *");
		printf("\n**************************");
		printf("\n* 13 - Orden descendente *");
		printf("\n**************************");
		printf("\nOpcion selecccionada: ");
		break;
	}
}

/**
 * \brief Display the menu to terminate an employee
 *
 * \param This function does not receive any parameters
 * \return This function does not return any value
 *
*/
void subtractEmployeeMenu (void)
{
	system("cls");
	printf("\n*************************************");
	printf("\n*****    Baja de empleado       *****");
	printf("\n*************************************\n");
	printf("Ingrese el id del empleado: ");
}

/**
 * \brief Displays the menu to modify an employee
 *
 * \param This function receives a character to select the menu to display
 * \return This function does not return any value
 *
*/
void modifyEmployeeMenu (int _modifySelectedOption)
{
	switch(_modifySelectedOption)
	{
	case 1:
	system("cls");
	printf("\n*************************************");
	printf("\n***** Modificacion de empleado  *****");
	printf("\n*************************************");
	printf("\nIngrese el id del empleado: ");
	break;

    case 2:
	system("cls");
	printf("\n*************************************");
	printf("\n*       Que desea modificar         *");
	printf("\n*************************************");
	printf("\n* 6 - Nombre                        *");
	printf("\n*************************************");
	printf("\n* 7 - Apellido                      *");
	printf("\n*************************************");
	printf("\n* 8 - Salario                       *");
	printf("\n*************************************");
	printf("\n* 9 - Sector                        *");
	printf("\n*************************************\n");
	break;
	}
}

/**
 * \brief Displays the status menu.
 *
 * \param This function receives a character to select the menu to display
 * \return This function does not return any value
 *
*/
void statusMessages (char statusCode)
{
	switch(statusCode)
	{
		case '1':
		printf("\n*************************************");
		printf("\n*       Built-in employee           *");
		printf("\n*************************************\n");
		break;

		case '2':
		printf("\n*************************************");
		printf("\n*       Employee removed            *");
		printf("\n*************************************\n");
		break;

		case '3':
		printf("\n***************************************");
		printf("\n* Employees sorted in ascending order *");
		printf("\n***************************************\n");
		break;

		case '4':
		printf("\n****************************************");
		printf("\n* Employees sorted in descending order *");
		printf("\n****************************************\n");
		break;
	}
}


/**
 * \brief Displays the error's menu.
 *
 * \param This function receives a character to select the menu to display
 * \return This function does not return any value
 *
*/
void errorMessages (char errorCode)
{
	switch(errorCode)
	{
		case '1':
		system("cls");
		printf("\n*************************************");
		printf("\n*   Error! NULL pointer received    *");
		printf("\n*************************************");
		break;

		case '2':
		system("cls");
		printf("\n***********************************************");
		printf("\n* NULL pointer received or Without free space *");
		printf("\n***********************************************\n");
		break;

		case '3':
		printf("\n****************************************");
		printf("\n* Error! Payroll array not initialized *");
		printf("\n****************************************\n");
		break;

		case '4':
		system("cls");
		printf("\n******************************************************");
		printf("\n* Error! NULL pointer received or Employee not found *");
		printf("\n******************************************************\n");
		break;

		case '5':
		system("cls");
		printf("\n*************************************");
		printf("\n*   Error! Not built-in employee    *");
		printf("\n*************************************\n");
		break;
	}
}

/**
 * \brief Print the list of employees sorted from lowest to highest by sector and ascending by last name
 *
 * \param list Employee*
 * \param length int
 * \return int Returns (0)
 *
*/
int printEmployees(Employee* list, int len)
{
	int value = 0;
	int i;
    char output;
    int auxiliaryOutput;
	do
    {
        if(list != NULL)
        {
            system("cls");
            printf("\n***************************************************************");
            printf("\n ID  \tNOMBRE\t\tAPELLIDO\tSALARIO\t    SECTOR");
            printf("\n***************************************************************");

            for(i = 0; i < len; i ++)
            {
                if(list[i].isEmpty == 0)
                {
                    printf("\n%d\t%s\t\t%s\t\t%.2f\t%d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
                }
            }
        }

    printf("\n\nPresione ENTER para continuar!\n");
    fflush(stdin);
    scanf("%c", &output);
    auxiliaryOutput = output;
    }
    while(iscntrl(auxiliaryOutput) == 0);

	return value;
}
/** \brief Print the report options menu
*
* \param This function receives the accumulated salary, the average salary and the number of employees that exceeds the average salary.
 * \return This function does not return any value
*
*/
void printReports(float _totalSalaryAccumulator, float _averageSalary, int _averageExcessSalaryCounter)
{
    char output;
    int auxiliaryOutput;
    do
    {
		system("cls");
		printf("\n*******************************************");
		printf("\n*****           Reportes              *****");
		printf("\n*******************************************");
		printf("\n* Sumatoria de los salarios: $%.2f", _totalSalaryAccumulator);
		printf("\n*******************************************");
        printf("\n\n* Promedio de los salarios: $%.2f", _averageSalary);
		printf("\n*******************************************");
		printf("\n\n* Superan el salario promedio: %d empleados\n", _averageExcessSalaryCounter);
		printf("\n*******************************************");

    printf("\n\nPresione ENTER para continuar!\n");
    fflush(stdin);
    scanf("%c", &output);
    auxiliaryOutput = output;
    }
    while(iscntrl(auxiliaryOutput) == 0);
}

