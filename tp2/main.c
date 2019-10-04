#include <stdio.h>
#include <stdlib.h>
#define C 1000
#include "empleados.h"
int main()
{
    Employee empleados[C];
    int opcion;
    int estado;
    int id;
    int sector;
    char name[30];
    char lastName[30];
    float salary;
    int baja;
    int modificar;

  initEmployees(empleados,C);



   do {
   printf("1- altas : \n");
   printf("2-modificar  : \n");
   printf("3- la baja   : \n");
   printf("4-  informar   : \n");
   printf("5-   SALIDA    : \n");
   scanf("%d",&opcion);

   switch(opcion)
        {
        case 1 :
        printf("ingrese sector: \n");
        scanf("%d", &sector);
        printf("ingrese su nombre: \n");
        fflush(stdin);
        gets(name);
        printf("ingrese el apellido: \n");
        fflush(stdin);
        gets(lastName);
        printf("ingre se lo que cobra: \n");
        scanf("%f", &salary);
        id = generadorID(empleados,C);
        estado = addEmployee(empleados,C,id,name,lastName,salary,sector);

        break;

        case 2 :
            if (estado== 0)
            {printf("ingrese el id que quiere modificar por favor    : \n");
            scanf("%d",&modificar);
            modificarEmployee(empleados,C,modificar);
            }

              else
            {
                printf("no ingresó  \n");
            }

            break;

        case 3 :
            if (estado == 0)
            {printf("ingrese el nombre que desea dar de baja: \n");
            scanf("%d",&baja);
            removeEmployee(empleados,C,baja);
            }
             else
            {
                printf("no ingreso usario\n");
            }
        break;

        case 4 :
            if (estado == 0)
        {   sortStudentsByNameAndAverage(empleados,C);
            printEmployees (empleados,C);
            mostrarSalaryPromedioSuperiorPromedio(empleados,C);
        }

        else
            {
                printf("no ingreso usario\n");
            }
        break;


        case 5 :
        printf("SALIDA   !!!\n");
        break;


        default :
        printf("Opcion incorrecta!!!\n");


        }

    system("pause");
    system("cls");
   }while (opcion != 5);


    return 0;
}
