#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "car.h"
#include "conio2.h"
#include <time.h>
int main()
{
    gotoxy(32,8);
    textcolor(14);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(28,10);
    textcolor(LIGHTGREEN);
    printf("*RENT A CAR AND GO WHEREVER YOU NEED*");
    _getch();
    textcolor(14);
    addAdmin();
    User *usr;
    int result;
    int car_result;
    int choice,type,i;
    while(1)
    {
        clrscr();
        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR RENTAL SYSTEM");
        gotoxy(1,8);
        textcolor(14);
        for(i=0;i<80;i++)
        printf("*");
        gotoxy(1,16);
        textcolor(14);
        for(i=0;i<80;i++)
        printf("*");
            gotoxy(32,10);
            textcolor(14);
            printf("1.ADMIN");
            gotoxy(32,12);
            printf("2.EMPOLOYEE");
            gotoxy(32,14);
            textcolor(WHITE);
            int k;
            printf("select your role :");
             do
             {
                 scanf("%d",&type);
                 k=0;
                 if(type==1)                                            //code for handling admin login
                 {
                     do
                     {
                         usr=getInput();
                         if(usr!=NULL)
                         {
                           k=checkUserExist(*usr,"admin");                                             // code for vaildating userid and pwd
                         }
                         else
                         {
                             break;
                         }
                     }while(k==0);

                 if (k==1)
                 {
                     gotoxy(30,14);
                     textcolor(LIGHTGREEN);
                     printf("Login Accepted!");
                     gotoxy(1,20);
                     textcolor(WHITE);
                     printf("Press any key to continue");
                     _getch();
                     while(1)
                     {
                          clrscr();
                          choice=adminMenu();
                          if(choice==7)
                          {
                              clrscr();
                              break;
                          }
                          switch(choice)
                          {
                           case 1:
                            clrscr();
                            addEmployee();
                           break;
                          case 2:
                              clrscr();
                          addCarDetails();
                           break;
                          case 3:
                              clrscr();
                              viewEmployee();
                            break;
                          case 4:
                              clrscr();
                             showCarDetails();
                            break;
                          case 5:
                              clrscr();
                              result=deleteEmp();
                              if(result==0)
                              {
                                  gotoxy(15,14);
                                  textcolor(LIGHTRED);
                                  printf("sorry! no employee found with the given employee id");
                                  textcolor(15);
                                  printf("\n\npress any key to go back to the main menu");
                                  _getch();
                              }
                                  else if(result==1)
                                  {
                                      gotoxy(25,14);
                                      textcolor(LIGHTGREEN);
                                      printf("record deleted successfully");
                                      textcolor(WHITE);
                                      printf("\n\npress any key to go back to the main menu");
                                      _getch();
                                  }

                              break;
                          case 6:
                            clrscr();
                            car_result=deleteCarModel();
                              if(car_result==0)
                              {
                                  gotoxy(15,14);
                                  textcolor(LIGHTRED);
                                  printf("sorry! no car found with the given car id");
                                  textcolor(15);
                                  printf("\n\npress any key to go back to the main menu");
                                  _getch();
                              }
                                  else if(car_result==1)
                                  {
                                      gotoxy(25,14);
                                      textcolor(LIGHTGREEN);
                                      printf("record deleted successfully");
                                      textcolor(WHITE);
                                      printf("\n\npress any key to go back to the main menu");
                                      _getch();
                                  }
                            break;
                            default:
                            printf("Incorrect Choice:");
                            _getch();

                          }//switch close
                     }
                 }

                 }
                 else if(type==2)   //code for hadling empo login
                 {

                         do
                     {
                         usr=getInput();
                         if(usr!=NULL)
                         {
                           k=checkUserExist(*usr,"emp");                                             // code for vaildating userid and pwd
                         }
                         else
                         {
                             break;
                         }
                     }while(k==0);


                if (k==1)
                 {
                     gotoxy(30,14);
                     textcolor(LIGHTGREEN);
                     printf("Login Accepted!");
                     gotoxy(1,20);
                     textcolor(WHITE);
                     printf("Press any key to continue");
                     _getch();

                     while(1)
                     {
                          clrscr();
                          choice=empMenu();
                          if(choice==5)
                          {
                              clrscr();
                              break;
                          }
                    switch(choice)
                        {
                         case 1:
                             clrscr();
                             int j;
                         do
                             {
                               clrscr();
                               j=rentCar();
                         if(j==0)
                               printf("Booking Cancelled\nTry again");
                               _getch();
                             }while (j==0);

                              _getch();
                            break;
                          case 2:
                              clrscr();
                              bookedCarDetails();
                              _getch();
                            break;
                          case 3:
                              clrscr();
                               carDetails();
                              _getch();
                            break;
                          case 4:
                              clrscr();
                              showCarDetails();
                              _getch();
                          break;
                            default :
                            printf("wrong choice:");
                          }

                     }
                 }
            }
                  else
                       {
                     textcolor(12);
                     gotoxy(30,20);
                     printf("inviled User type");
                          _getch();
                         gotoxy(30,20);
                         printf("\t\t\t");
                         gotoxy(50,14);
                         printf("\t");
                         gotoxy(50,14);
                        textcolor(WHITE);
                      }

                 }while(type!=1&&type!=2);

             }

   return 0;
 }
