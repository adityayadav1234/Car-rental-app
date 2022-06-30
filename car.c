#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.h"
#include "conio2.h"
#include <time.h>
void addAdmin()
{
    FILE *fp;
    fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"admin","abc","Aditya"},{"krish","abc","Krishna"}};
         fwrite(u,sizeof(u),1,fp);
         fclose(fp);
         printf("\nFILE SAVESD!");
         _getch();
    }
    else
    fclose(fp);
    return 0;
}
User* getInput()
{
    int i;
    clrscr();
    textcolor(14);
    gotoxy(32,1);
    printf("CAR REANTAL SYSTEM\n");
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(32,5);
    printf("*LOGIN PANEL*");
    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(1,15);
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(60,8);
    textcolor(15);
    printf("Press 0 to exit");
    gotoxy(25,10);
    textcolor(LIGHTCYAN);
    printf("ENTER USER ID:");
    fflush(stdin);
    textcolor(15);
    static User usr;
    fgets(usr.userid,20,stdin);
    char *pos;
    pos=strchr(usr.userid,'\n');
    *pos='\0';
    if(strcmp(usr.userid,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login cancelled!");
        _getch();
        textcolor(YELLOW);
        return NULL;
    }
    gotoxy(25,11);
    textcolor(LIGHTCYAN);
    printf("ENTER PASSWORD:");
    fflush(stdin);
    i=0;
    textcolor(WHITE);
    for(;;)
    {

        usr.pwd[i]=getch();
        gotoxy((40+i),11);
        if(usr.pwd[i]==8 && i>0)
        {
            i--;
            gotoxy((40+i),11);
            printf("\t");
            gotoxy((40+i),11);
            continue;
        }
        else if(usr.pwd[i]==13)
        {
            break;
        }
        printf("*");
        i++;

    }
    usr.pwd[i]='\0';
    if(strcmp(usr.pwd,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("login cancelled!");
        _getch();
        textcolor(14);
        return NULL;
    }
    return &usr;
}

int checkUserExist(User u,char *usertype)
{
    if(strcmp(u.userid,"")==0||strcmp(u.pwd,"")==0)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("BOTH FIELDS ARE MANDATORY");
        _getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");
        return 0;

    }
    int found=0;
    if(!(strcmp(usertype,"admin")))
    {
        FILE *fp=fopen("admin.bin","rb");
        User user;
        while(fread(&user,sizeof(User),1,fp)==1)
        {
            if(strcmp(u.userid,user.userid)==0 && strcmp(u.pwd,user.pwd)==0)
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            gotoxy(27,20);
            textcolor(LIGHTRED);
            printf("INVALID USERI'D OR PASSWORD");
            _getch();
            fclose(fp);
            return 0;

        }
        fclose(fp);
        return 1;
    }
    else if (!(strcmp(usertype,"emp")))
    {
     FILE *fp=fopen("emp.bin","rb");
        User user;
        while(fread(&user,sizeof(User),1,fp)==1)
        {
            if(strcmpi(u.userid,user.userid)==0&&strcmp(u.pwd,user.pwd)==0)
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            gotoxy(27,20);
            textcolor(LIGHTRED);
            printf("INVALID USERI'D OR PASSWORD");
            _getch();
            fclose(fp);
            return 0;

        }
        fclose(fp);
        return 1;
   //code for reading emp,bin
    }
}
int adminMenu()
{
    int choice ,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);

    gotoxy(35,6);
    printf("ADMIN MANU\n");
    for(i=0;i<80;i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1.Add Employee");
    gotoxy(32,9);
    printf("2.Add car Details");
    gotoxy(32,10);
    printf("3.Show Employee");
    gotoxy(32,11);
    printf("4.Show Car Details");
    gotoxy(32,12);
    printf("5.Delete Employee");
    gotoxy(32,13);
    printf("6.Delete Car Details");
    gotoxy(32,14);
    printf("7.Exit");
    gotoxy(32,16);
    printf("Enter Choice:");
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;
}
void addEmployee()
{
    FILE  *fp=fopen("emp.bin","rb");
    int id;
    char uchoice;
    char emp[10]="EMP-";
    char empid[10];
    User u,ur;
    if (fp==NULL)
    {
        fp=fopen("emp.bin","ab");
        id=1;
        sprintf(empid,"%d",id);
        strcat(emp,empid);
        strcpy(u.userid,emp);
        strcpy(emp,"EMP-");

    }
    else
    {
        fp=fopen("emp.bin","ab+");
        fseek(fp,-60,SEEK_END);
        fread(&ur,sizeof(ur),1,fp);
        char sub[3];
        char str[20];
        strcpy(str,ur.userid);
        sub_str(str,sub,'-');
        id=atoi(sub);
        id++;
        sprintf(empid,"%d",id);
        strcat(emp,empid);
        strcpy(u.userid,emp);
        strcpy(emp,"EMP-");
    }
    do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=0;i<80;i++)
        {
            printf("~");

        }
        textcolor(WHITE);
        gotoxy(25,5);
        printf("***** ADD EMPLOYEE DETAILS *****");
        gotoxy(1,8);
        textcolor(14);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        char *pos;
        pos=strchr(u.name,'\n');
        *pos='\0';
        textcolor(14);
        printf("Please Employee pwd:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd,'\n');
        *pos='\0';
        textcolor(14);
        fseek(fp,0,SEEK_END);
        fwrite(&u,sizeof(User),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("EMPLOYEE ADDED SUCCESSFULLY");
        printf("\n EMPLOYEE ID IS:%s",u.userid);
        _getch();
        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do You Want To More Employee(Y/N) :");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&uchoice);
        id++;
        sprintf(empid,"%d",id);
        strcat(emp,empid);
        strcpy(u.userid,emp);
        strcpy(emp,"EMP-");
    }
     while(uchoice=='y'||uchoice=='y');
            fclose(fp);
}

void sub_str(char *str,char *sub,char c)
{
    int i,f=0,j=0;
    for(i=0;str[i]!=c;i++)
    {
        f++;
    }
    for(i=++f;str[i]!='\0';i++)
    {
        sub[j]=str[i];
        j++;
    }
    sub[j]='\0';
}
void viewEmployee()
{
    FILE *fp=fopen("emp.bin","rb");
    User ur;
    int i;
    textcolor(14);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(31,5);
    textcolor(14);
    printf("* EMPLOYEE DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf(" Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
    printf("%c",247);
    int x=10;
    textcolor(14);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%s",ur.userid);
        gotoxy(33,x);
        printf("%s",ur.name);
        gotoxy(57,x);
        printf("%s",ur.pwd);
        x++;
    }
      fclose(fp);
      _getch();
}


int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    char empid[10];
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(29,5);
    textcolor(YELLOW);
    printf("* DELETE EMPLOYEE RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,12);
    for(i=1; i<80; i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo Employee Added Yet!");
        _getch();
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Employee Id to delete the record:");
    textcolor(WHITE);
    scanf("%s",empid);
    User U;
    int found=0;
    while(fread(&U,sizeof(U),1,fp1)==1)
    {
        if(strcmp(U.userid,empid)!=0)
        {
            fwrite(&U,sizeof(U),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    if(found==1)
	{
    		rewind(fp2);
    		fp1=fopen("emp.bin","wb");
    		while(fread(&U,sizeof(U),1,fp2)==1)
    		{
        	fwrite(&U,sizeof(U),1,fp1);
    		}
	fclose(fp1);
	}
    fclose(fp2);
    remove("temp.bin");
    return found;
}

int empMenu()
{
    int choice ,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=0;i<80;i++)
        printf("*");
    textcolor(14);
    gotoxy(32,8);
    printf("1.REANT A Car");
    gotoxy(32,9);
    printf("2.Booking Car Details");
    gotoxy(32,10);
    printf("3.Available Car Details");
    gotoxy(32,11);
    printf("4.Show All Details");
    gotoxy(32,12);
    printf("5.Exit");
    gotoxy(32,15);
    printf("Enter choice:");
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;
}


int selectCarModel()
{
    int flag;
    FILE *fp=fopen("car.bin","rb");
    Car c;
    char car[10]="CAR-";
    int id;
    char com[10];
    char choice[20],x=9;
    gotoxy(34,x);

    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if(c.car_count>0)
        {
            printf("%s . %s",c.car_id,c.car_name);
            gotoxy(34,++x);
        }
    }
    gotoxy(34,x+2);
    printf("Enter Your choice no: CAR-");
    while(1)
    {
        flag=0;
        scanf("%d",&id);
        sprintf(com,"%d",id);
        strcat(car,com);
        strcpy(choice,car);
        strcpy(car,"CAR-");
        rewind(fp);
        while(fread(&c,sizeof(c),1,fp)==1)
        {
            if((strcmp(c.car_id,choice)==0) && (c.car_count>0))
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            fclose(fp);
            return id;
        }
        else
            {
            gotoxy(37,x+4);
            textcolor(LIGHTRED);
            printf("Wrong Input");
            _getch();
            gotoxy(35,x+4);
            printf("\t\t");
            gotoxy(60,x+2);
            printf("\t");
            gotoxy(60,x+2);
            textcolor(15);


            }
    }
}


int isValidDate(struct tm dt)
{
    if(dt.tm_year >= 2020 && dt.tm_year <= 2022)
    {
        //check month
        if(dt.tm_mon>=1 && dt.tm_mon<=12)
        {
            //check days
            if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
               return (1);
            else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
               return (1);
            else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
                return (1);
            else if(dt.tm_mday==29 && dt.tm_mon==2 && (dt.tm_year%400==0 ||(dt.tm_year%4==0 && dt.tm_year%100!=0)))
               return (1);

            else
               return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}
void updateCarCount(int C)
{
    char carid[10]="CAR-";
    char car_no[10];
    char car_id[20];
    sprintf(car_no,"%d",C);
    strcat(carid,car_no);
    strcpy(car_id,carid);
    FILE *fp=fopen("car.bin","rb+");
    Car c;
    while(fread(&c,sizeof(Car),1,fp)==1)
    {
        if (strcmp(c.car_id,car_id)==0)
        {

            fseek(fp,-8,SEEK_CUR);
            int cc_new=c.car_count-1;
            fwrite(&cc_new,sizeof(cc_new),1,fp);
            break;
        }
    }
    fclose(fp);
}

char * getCarName( char car_id [])
{

    FILE *fp=fopen("car.bin","rb");
    static Car c;
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        if (strcmp(c.car_id,car_id)==0)
        {
            break;

        }
    }
    fclose(fp);
    return c.car_name;
}

void bookedCarDetails()
{
    clrscr();
    FILE *fp=fopen("customer.bin","rb");
    int i;
    Customer_Car_Details cc;
    textcolor(14);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(14);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
       printf("%c",247);
       gotoxy(1,8);
       printf("MOdel\t    cust Name\t  Pick Up\t   Drop\t\t S_Date\t    E_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);

    int x=10;
    textcolor(14);

    while(fread(&cc,sizeof(Customer_Car_Details),1,fp)==1)
    {
        gotoxy(1,x);
        printf("%s",getCarName(cc.car_id));
        gotoxy(13,x);
        printf("%s",cc.cust_name);
        gotoxy(27,x);
        printf("%s",cc.pick);
        gotoxy(44,x);
        printf("%s",cc.drop);
        gotoxy(58,x);
        printf("%d-%d-%d",cc.sd.tm_mday,cc.sd.tm_mon,cc.sd.tm_year);
        gotoxy(70,x);
        printf("%d-%d-%d",cc.ed.tm_mday,cc.ed.tm_mon,cc.ed.tm_year);
        x++;
    }
    fclose(fp);

    _getch();
}

int rentCar()
{
    Customer_Car_Details cc;
    char pick[30] ,drop [30];
    int c,i;
    char car[10]="CAR-";
    char com[10];
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM \n\n\n");
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("*");
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1;i<=80;i++)
        printf("*");
    textcolor(14);
    gotoxy(32,8);
    c=selectCarModel();                       // selectcarmodel
    sprintf(com,"%d",c);
    strcat(car,com);
    strcpy(cc.car_id,car);
    clrscr();
    textcolor(12);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=1;i<=80;i++)
        printf("*");
    gotoxy(1,17);
    for(i=1;i<=80;i++)
        printf("*");
        textcolor(14);
        gotoxy(27,9);
        printf("enter customer name:");
        fflush(stdin);
        textcolor(15);
        fgets(cc.cust_name,30,stdin);
        char *pos;
        pos=strchr(cc.cust_name,'\n');
        *pos='\0';
        gotoxy(27,10);
        textcolor(14);
        printf("enter pickup point:");

        fflush(stdin);
        textcolor(15);
        fgets(cc.pick,30,stdin);
        pos=strchr(cc.pick,'\n');
        *pos='\0';
        gotoxy(27,11);
        textcolor(14);
        printf("enter drop point:");
        fflush(stdin);
        textcolor(15);
        fgets(cc.drop,30,stdin);
        pos=strchr(cc.drop,'\n');
        *pos='\0';
        gotoxy(27,12);
        textcolor(14);
        printf("enter strat date (dd/m/yyyy):");
        textcolor(15);
        do
        {
            scanf("%d/%d/%d",&cc.sd.tm_mday,&cc.sd.tm_mon,&cc.sd.tm_year);
            int datevalid=isValidDate(cc.sd);
            if(datevalid==0)
            {
                gotoxy(27,18);
                textcolor(12);
                printf("wrong date");
                _getch();
                gotoxy(27,18);
                printf("\t\t");
                gotoxy(56,12);
                printf("\t\t\t");
                gotoxy(56,12);
                textcolor(15);
            }
            else
                break;

        }while(1);
        gotoxy(27,13);
        textcolor(14);
        printf("enter end date (dd/m/yyyy):");
        textcolor(15);
        do
        {
         scanf("%d/%d/%d",&cc.ed.tm_mday,&cc.ed.tm_mon,&cc.ed.tm_year);
         int datevalid=isValidDate(cc.ed);
         int againvalid=againConf(cc.sd,cc.ed);
            if(datevalid==0 || againvalid==0)
            {
                gotoxy(27,18);
                textcolor(12);
                printf("wrong date");
                _getch();
                gotoxy(27,18);
                printf("\t\t");
                gotoxy(54,13);
                printf("\t\t\t");
                gotoxy(54,13);
                textcolor(15);
            }
            else
                break;
        }while(1);

         FILE *fp;
         fp=fopen("customer.bin","ab");
         fwrite(&cc,sizeof(Customer_Car_Details),1,fp);
         printf("\npress any key to continue...");
         printf("\ncar %d loaded...",c);
         _getch();
         fclose(fp);
         updateCarCount(c);
         bookedCarDetails();
         return 1;
}


void addCarDetails()
{
    FILE  *fp=fopen("car.bin","rb");
    Car c,cr;
    int id;
    char car[10]="CAR-";
    char carid[10];
    char cchoice;
    if (fp==NULL)
    {
        fp=fopen("car.bin","ab");
        id=1;
        sprintf(carid,"%d",id);
        strcat(car,carid);
        strcpy(c.car_id,car);
        strcpy(car,"CAR-");

    }
    else
    {
        fp=fopen("car.bin","ab+");
        fseek(fp,-52,SEEK_END);
        fread(&cr,sizeof(cr),1,fp);
        char sub[3];
        char str[20];
        strcpy(str,cr.car_id);
        sub_str(str,sub,'-');
        id=atoi(sub);
        id++;
        sprintf(carid,"%d",id);
        strcat(car,carid);
        strcpy(c.car_id,car);
        strcpy(car,"CAR-");
    }
    do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APPLICTION");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=1;i<80;i++)
        {
            printf("~");

        }
        textcolor(WHITE);
        gotoxy(25,5);
        printf("***** ADD CAR DETAILS *****");
        gotoxy(1,8);
        textcolor(14);
        printf("Car id is:");
        textcolor(WHITE);
        printf("%s",c.car_id);
        textcolor(14);
        printf("\nEnter Car Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(c.car_name,20,stdin);
        char *pos;
        pos=strchr(c.car_name,'\n');
        *pos='\0';
        textcolor(14);
        printf("Enter Car capacity:");
        textcolor(WHITE);
        scanf("%d",&c.capacity);
        textcolor(14);
        printf("Enter total Car:");
        textcolor(WHITE);
        scanf("%d",&c.car_count);
        textcolor(14);
        printf("Enter Car price:");
        textcolor(WHITE);
        scanf("%d",&c.price);
        fseek(fp,0,SEEK_END);
        fwrite(&c,sizeof(c),1,fp);
        gotoxy(40,15);
        textcolor(LIGHTGREEN);
        printf("Car Details ADDED SUCCESSFULLY");
        printf("\n car ID IS: %s",c.car_id);
        _getch();
        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do You Want To More Car(Y/N) :");
        textcolor(WHITE);
        fflush(stdin);
        id++;
        sprintf(carid,"%d",id);
        strcat(car,carid);
        strcpy(c.car_id,car);
        strcpy(car,"CAR-");
        scanf("%c",&cchoice);
    }
     while(cchoice=='y'||cchoice=='y');
     fclose(fp);
            return ;
}

void showCarDetails()
{
    FILE *fp=fopen("car.bin","rb");
    Car cr;
    int i;
    textcolor(14);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(31,5);
    textcolor(14);
    printf("* SHOW CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf(" Car_id   Car_Name\tCapacity\tTotal_Car\tPrice/Day\t");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
    printf("%c",247);
    int x=10;
    textcolor(14);
    while(fread(&cr,sizeof(cr),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%s",cr.car_id);
        gotoxy(11,x);
        printf("%s",cr.car_name);
        gotoxy(25,x);
        printf("%d",cr.capacity);
        gotoxy(41,x);
        printf("%d",cr.car_count);
        gotoxy(57,x);
        printf("%d",cr.price);
        gotoxy(73,x);
        x++;
    }
      fclose(fp);
      _getch();
}
int deleteCarModel()
{
 FILE *fp1=fopen("car.bin","rb");
    char carid[10];
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(29,5);
    textcolor(YELLOW);
    printf("* DELETE CAR RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,12);
    for(i=1; i<80; i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo CAR Added Yet!");
        _getch();
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Car_Id to delete the record:");
    textcolor(WHITE);
    scanf("%s",carid);
    Car C;
    int found=0;
    while((fread(&C,sizeof(C),1,fp1)==1 ))
    {
        if(strcmp(C.car_id,carid)!=0)
        {
            fwrite(&C,sizeof(C),1,fp2);

        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    if(found==1)
	{
    		rewind(fp2);
    		fp1=fopen("car.bin","wb");
    		while(fread(&C,sizeof(C),1,fp2)==1)
    		{
        	fwrite(&C,sizeof(C),1,fp1);
    		}
	fclose(fp1);
	}
    fclose(fp2);
    remove("temp.bin");
    return found;
}

void carDetails()
{
    FILE *fp=fopen("car.bin","rb");
    Car cr;
    int i;
    textcolor(14);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(31,5);
    textcolor(14);
    printf("* SHOW CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
        printf("%c",247);
    gotoxy(1,8);
    printf(" Car_id   Car_Name\tCapacity\tTotal_Car\tPrice/Day\t");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
    printf("%c",247);
    int x=10;
    textcolor(14);
    while(fread(&cr,sizeof(cr),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%s",cr.car_id);
        gotoxy(11,x);
        printf("%s",cr.car_name);
        gotoxy(25,x);
        printf("%d",cr.capacity);
        gotoxy(41,x);
        printf("%d",cr.car_count);
        gotoxy(57,x);
        printf("%d",cr.price);
        gotoxy(73,x);
        x++;
    }
      fclose(fp);
      _getch();
}


int againConf(struct tm dt1, struct tm dt2)
{
    if(dt2.tm_year>=dt1.tm_year)
    {
        if(dt2.tm_mon>=dt1.tm_mon)
        {
            if(dt2.tm_mday>=dt1.tm_mday)
            return 1;
            else
                return 0;

        }
        else
            return 0;

    }
    else
        return 0;
}
