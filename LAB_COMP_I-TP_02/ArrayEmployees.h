struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;

/**
 * \brief Show the main menu and allow the entry of an option.
 *
 * \param This function does not receive any parameters
 * \return This function returns the selected option
 *
*/
int mainMenu(void);

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
int initEmployees(Employee* list, int len);

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
int addEmployee(Employee* list, int len, int id, char name[], char lastName[],float salary,int sector);

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
int findEmployeeById(Employee* list, int len,int id);

/**
 * \brief Perform an employee's low logic
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Returns (0) if the employee has been removed and (-1) if the null pointer has been received or the employee's id has not been found.
 *
*/
int removeEmployee(Employee* list, int len, int id);

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
int sortEmployees(Employee* list, int len, int order);

/** \brief Count the number of employees that exceed the average employee.
 *
 * \param list Employee*
 * \param len int
 * \param averageSalary
 *
*/
int employeesExceedAverageSalary(Employee* list, int len, float averageSalary);

/**
 * \brief Show the add employee menu.
 *
 * \param This function does not receive any parameters
 * \return This function does not return any value
 *
*/
void addEmployeeMenu (void);

/**
 * \brief Displays the menu to modify an employee
 *
 * \param This function receives a character to select the menu to display
 * \return This function does not return any value
 *
*/
void modifyEmployeeMenu (int _modifySelectedOption);

/** \brief
*
* \param
* \return
*
*/
void subtractEmployeeMenu (void);

/**
 * \brief Show the menu of employee reports
 *
 * \param This function receives a character to select the menu to display
 * \return This function does not return any value
 *
*/
void reportsMenu(char _menuCaseOption);

/**
 * \brief Verify that there is at least one charged employee.
 *
 * \param list Employee*
 * \param len int
 * \return Return (0) if employee is built-in or (-1) if [NULL
 *          pointer received or employee not is not built-in]
 *
*/
int verifyBuiltInEmployee(Employee* list, int len);

/**
 * \brief Displays the error's menu.
 *
 * \param This function receives a character to select the menu to display
 * \return This function does not return any value
 *
*/
void errorMessages (char errorCode);

/**
 * \brief Displays the status menu.
 *
 * \param This function receives a character to select the menu to display
 * \return This function does not return any value
 *
*/
void statusMessages (char statusCode);

/**
 * \brief Print the list of employees sorted from lowest to highest by sector and ascending by last name
 *
 * \param list Employee*
 * \param length int
 * \return int Returns (0)
 *
*/
int printEmployees(Employee* list, int len);

/** \brief Print the report options menu
*
* \param This function receives the accumulated salary, the average salary and the number of employees that exceeds the average salary.
 * \return This function does not return any value
*
*/
void printReports(float _totalSalaryAccumulator, float _averageSalary, int _averageExcessSalaryCounter);

