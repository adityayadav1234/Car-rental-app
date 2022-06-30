#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
#include<stdlib.h>
struct User
{
    char userid[20];
    char pwd[20];
    char name[20];
};

struct Car
{
    char car_id[20];
    char car_name[20];
    int capacity ;
    int car_count;
    int price;
};

struct Customer_Car_Details
{
    char car_id[20];
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd;
    struct tm ed;
};
typedef struct User User;
typedef struct Car Car;
typedef struct Customer_Car_Details Customer_Car_Details;


void addAdmin();
User* getInput();
int checkUserExist(User,char*);
int adminMenu();
void addEmployee();
void viewEmployee();
void addCarDetails();
void showCarDetails();
void carDetails();
// deleteemp()
int deleteEmp();
 //deletecarmodal()
int deleteCarModel();
void  sub_str(char*,char*,char);

int empMenu();
int rentCar();
int selectCarModel();
void bookedCarDetails();
char *getCarName( char []);
int isValidDate(sd);
void updateCarCount(int);

int againConf(sd,sd);
#endif // CAR_H_INCLUDED
