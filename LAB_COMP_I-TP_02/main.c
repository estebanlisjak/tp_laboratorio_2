#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"
#define QUANTITYOFEMPLOYEES 1000

int main()
{
    /* Declaración de variables */

	//Banderas de estado
	int payrollInitializationFlag;
	int builtInEmployeeFlag;
	int removeEmployeeFlag;
	int sortEmployeeFlag;
	int employeeIdIndexFound;

    //Variables relacionadas con la estructura Employee
	int id = 0;
	int idAuxiliary;
	char name[51];
	char lastName[51];
	float salary;
	int sector;

    //Variables que reciben las opciones selecionadas de los menues.
	int mainSelectedOption;
	int modifySelectedOption;
	int reportsSelectedOption;
	int sortSelectedOption;

    //Varible acumulador
	float totalSalaryAccumulator = 0;

	//Variable contador
	int builtInEmployeeCounter = 0;
	int averageExcessSalaryCounter = 0;

	//Variable que guarda el promedio de salario
	float averageSalary = 0;

	//Declaración del vector de estructuras
	Employee payroll[QUANTITYOFEMPLOYEES];

    //Variable de control para finalizar el programa
    char exit = 'n';

//Hardcodeo para prueba de informes
/*
	payrollInitializationFlag = 0;
	float totalSalaryAccumulator = 379505.6;
	int builtInEmployeeCounter = 11;
	Employee payroll[] = { {0, "Alberto", "Perez", 37000.50, 1, 0},
						   {1, "Pedro", "Gomez", 36000.70, 1, 0},
						   {2, "Cecilia", "Moro", 40000.60, 2, 0},
					       {3, "Lucas", "Fuentes", 38000.90, 2, 0},
					       {4, "Pablo", "Diaz", 26000.55, 3, 0},
					       {5, "Maria", "Silva", 45000.10, 3, 0},
					       {6, "Juan", "Poso", 32000.75, 4, 0},
					       {7, "Daniel", "Caceres", 33000.40, 4, 0},
					       {8, "Mariana", "Falucho", 28000.30, 5, 0},
					       {9, "Andrea", "Chichi", 29500.60, 5, 0},
					       {10, "Luciana", "Andrade", 35000.20, 6, 0} };

*/

	/* Comienzo del programa */

	//Array Initialization
	payrollInitializationFlag = initEmployees(payroll, QUANTITYOFEMPLOYEES);
	if(payrollInitializationFlag == -1)
		errorMessages('1');

	do
    {
	    mainSelectedOption = mainMenu();

		switch(mainSelectedOption)
        {
            case 1: //Add employee
			if(payrollInitializationFlag != -1)
			{
				addEmployeeMenu();
				fflush(stdin);
				getString(name, "Ingrese nombre: ", "Error, vuelva a intentarlo! ", 3, 51, 5);
				fflush(stdin);
                getString(lastName, "Ingrese apellido: ", "Error, vuelva a intentarlo! ", 3, 51, 5);
				fflush(stdin);
				getFloat(&salary, "Ingrese salario: ", "Error, vuelva a intentarlo! ", 0.001, 1000000.00, 5);
				fflush(stdin);
				getInt(&sector, "Ingrese sector: ", "Error, vuelva a intentarlo! ", 1, 10, 5);
				fflush(stdin);
				builtInEmployeeFlag = addEmployee(payroll, QUANTITYOFEMPLOYEES, id, name, lastName, salary, sector);
				if(builtInEmployeeFlag != -1)
				{
					statusMessages('1');
					totalSalaryAccumulator+=salary;
					builtInEmployeeCounter++;
					id++;
				}
				else
					errorMessages('2');
			}
			else
				errorMessages('3');

			break;

            case 2: //Modify employee
			builtInEmployeeFlag = verifyBuiltInEmployee(payroll, QUANTITYOFEMPLOYEES);

			if(builtInEmployeeFlag != -1)
			{
				modifyEmployeeMenu(1);
				scanf("%d", &idAuxiliary);
				employeeIdIndexFound = findEmployeeById(payroll, QUANTITYOFEMPLOYEES, idAuxiliary);
				if(employeeIdIndexFound != -1)
				{
				    modifyEmployeeMenu(2);
				    fflush(stdin);
				    getInt(&modifySelectedOption, "Ingrese una opcion: ", "Opcion incorrecta, vuelva a intentarlo! ", 6, 9, 5);

					switch(modifySelectedOption)
					{
						case 6:
                            getString(payroll[employeeIdIndexFound].name, "Ingrese el nuevo nombre: ", "Largo incorrecto, vuelva a intentarlo! ", 3, 51, 5);
						break;

						case 7:
                            getString(payroll[employeeIdIndexFound].lastName, "Ingrese el nuevo apellido: ", "Largo incorrecto, vuelva a intentarlo! ", 3, 51, 5);
						break;

						case 8:
						    getFloat(&payroll[employeeIdIndexFound].salary, "Ingrese el nuevo salario: ", "Valor incorrecto, vuelva a intentarlo! ", 0.001, 1000000.00, 5);
						break;

						case 9:
						    getInt(&payroll[employeeIdIndexFound].sector, "Ingrese el nuevo sector: ", "Valor incorrecto, vuelva a intentarlo! ", 1, 10, 5);
						break;
					}
				}
				else
					errorMessages('4');
			}
			else
				errorMessages('5');
            break;

            //Baja de empleados.
            case 3:
			builtInEmployeeFlag = verifyBuiltInEmployee(payroll, QUANTITYOFEMPLOYEES);

			if(builtInEmployeeFlag != -1)
			{
				subtractEmployeeMenu();
				fflush(stdin);
                scanf("%d", &idAuxiliary);
				removeEmployeeFlag = removeEmployee(payroll, QUANTITYOFEMPLOYEES, idAuxiliary);

				if(removeEmployeeFlag != -1)
					statusMessages('2');
				else
					errorMessages('4');
			}
			else
				errorMessages('5');

			break;

			//Employee Reports
            case 4:
			builtInEmployeeFlag = verifyBuiltInEmployee(payroll, QUANTITYOFEMPLOYEES);

			if(builtInEmployeeFlag != -1)
			{
				reportsMenu('1');
				getInt(&reportsSelectedOption, "Ingrese una opcion: ", "Opcion incorrecta, vuelva a intentarlo! ", 10, 11, 5);

				switch(reportsSelectedOption)
				{
					case 10:
                        reportsMenu('2');
                        getInt(&sortSelectedOption, "Ingrese una opcion: ", "Opcion incorrecta, vuelva a intentarlo! ", 12, 13, 5);
                        switch(sortSelectedOption)
                        {
                            case 12:
                            sortEmployeeFlag = sortEmployees(payroll, QUANTITYOFEMPLOYEES, 1);
                            if(sortEmployeeFlag != -1)
                                printEmployees(payroll, QUANTITYOFEMPLOYEES);
                            statusMessages('3');
                            break;

                            case 13:
                            sortEmployeeFlag = sortEmployees(payroll, QUANTITYOFEMPLOYEES, 2);
                            if(sortEmployeeFlag != -1)
                                printEmployees(payroll, QUANTITYOFEMPLOYEES);
                            statusMessages('4');
                            break;
                        }
                        break;

					case 11:
                        averageSalary = (totalSalaryAccumulator / builtInEmployeeCounter);

                        averageExcessSalaryCounter = employeesExceedAverageSalary(payroll, QUANTITYOFEMPLOYEES, averageSalary);

                        printReports(totalSalaryAccumulator, averageSalary, averageExcessSalaryCounter);

                        break;

				}
			}
			else
				errorMessages('5');
			break;

            //Exit
            case 5:
            exit = 's';
            break;
		}
	}
	while(exit != 's');

return 0;
}
