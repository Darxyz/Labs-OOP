//За програмски јазик да се употреби C.

//Да се креира структура Employee во која се чуваат податоци за еден вработен. За вработениот се чуваат информации за името на вработениот (низа од карактери), матичен број (ЕМБГ) на вработениот(низа од карактери), име на одделот во кој што работи (низа од карактери), плата (цел број).

//Потоа, да се креира структура Company во која се чуваат податоци за името на компанијата (низа од карактери), низа од вработени во компанијата и број на вработени.

//Да се направи функција:

//void printEmployeesBelowAverageSalary(Company *comp, int numCompanies)

//која што за секоја компанија, ќе ги испечати сите вработени чија што плата е пониска од просекот на платите на сите вработени во таа компанија.

//Да се направи функција: 

//void printHighestSalaryEmployee(Company *comp, int numCompanies, char *department) 

//кoja што за секоја компанија ќе го испечати вработениот со највисока плата во дадениот оддел.

//Напомена: Прво од тастатура се чита бројот на компании, потоа компаниите (името и бројот на вработени), а потоа податоците за нивните вработени соодветно, a на крај се чита одделот кој што ќе биде искористен во printHighestSalaryEmployee функцијата.

//For example:

//Input	Result
//2
//Apple
//3
//Vlatko 111111 IT 150000
//Nikola 222222 IT 125000
//Marko 333333 Accounting 50000
//Google
//2
//Stefan 444444 IT 150000
//John 555555 HR 60000
//IT
//Employees with salaries below the average:
//Marko 333333 Accounting 50000
//John 555555 HR 60000
//Employees with highest salaries for given department: 
//Vlatko 111111 IT 150000
//Stefan 444444 IT 150000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[100];
    char embg[14];
    char department[100];
    int salary;
};

struct Company {
    char name[100];
    int num_employees;
    struct Employee employees[MAX_EMPLOYEES];
};

void printEmployeesBelowAverageSalary(struct Company *comp) {
    int total_salary = 0, num_employees = comp->num_employees;
    for (int i = 0; i < num_employees; i++) {
        total_salary += comp->employees[i].salary;
    }
    double avg_salary = (double)total_salary / num_employees;
    for (int i = 0; i < num_employees; i++) {
        if (comp->employees[i].salary < avg_salary) {
            printf("%s %s %s %d\n", comp->employees[i].name, comp->employees[i].embg,
                   comp->employees[i].department, comp->employees[i].salary);
        }
    }
}

void printHighestSalaryEmployee(struct Company *comp, char *department) {
    int max_salary = -1;
    struct Employee *max_salary_employee = NULL;
    int num_employees = comp->num_employees;
    for (int i = 0; i < num_employees; i++) {
        if (strcmp(comp->employees[i].department, department) == 0 &&
            comp->employees[i].salary > max_salary) {
            max_salary = comp->employees[i].salary;
            max_salary_employee = &comp->employees[i];
        }
    }
    if (max_salary_employee != NULL) {
        printf("%s %s %s %d\n", max_salary_employee->name, max_salary_employee->embg, department,max_salary_employee->salary);
    }
}

int main() {
    int num_companies;
    scanf("%d", &num_companies);

    struct Company companies[num_companies];
    for (int i = 0; i < num_companies; i++) {
        scanf("%s", companies[i].name);
        scanf("%d", &companies[i].num_employees);
        for (int j = 0; j < companies[i].num_employees; j++) {
            scanf("%s %s %s %d", companies[i].employees[j].name, companies[i].employees[j].embg,
                  companies[i].employees[j].department, &companies[i].employees[j].salary);
        }
    }

    char department[100];
    scanf("%s", department);
     printf("Employees with salaries below the average:\n");
    for (int i = 0; i < num_companies; i++) {
        printEmployeesBelowAverageSalary(&companies[i]);
    }
    printf("Employees with highest salaries for given department:\n");
    for (int i = 0; i < num_companies; i++) {
        printHighestSalaryEmployee(&companies[i], department);
    }

    return 0;
}
