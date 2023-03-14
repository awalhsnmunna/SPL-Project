#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
//Outlook design 
void topCol();
void bottomCol();
void rightRow();
void leftRow();

//Other functionsu
void design();
void gotoxy();
void menuDisplay();

//Menu functions
void invailInfo();
void donarsList();
void search();
void updateInfo();
void deleteInfo();

FILE *myFile;

typedef struct personInformation
{
    char name[30];
    char fName[30];
    int  age;
    char bloodGrp[20];
    float hemo;
    char homeTown[30];
    char number[25];

}personInfo;

personInfo info;

void main()
{
  system("cls");
  design();
  menuDisplay(); 
}

void invailInfo()
{
    system("cls");
    design();
    getchar();
    gotoxy(30,4);printf("====== Add Person Info ======");
    FILE *myFile;
    myFile=fopen("data.txt","a");
    if (myFile==NULL)
    {
        gotoxy(35,12);printf("Error!");
    }
    else
    {
    gotoxy(6,8);printf("Name: ");
    fgets(info.name,sizeof(info.name),stdin);
    info.name[strcspn(info.name,"\n")]='\0';
    gotoxy(6,10);printf("Father's Name: ");
    fgets(info.fName,sizeof(info.fName),stdin);
    info.fName[strcspn(info.fName,"\n")]='\0';
    gotoxy(6,12);printf("Age: ");
    scanf("%d",&info.age);
    getchar();
    gotoxy(6,14);printf("Blood Group: ");
    fgets(info.bloodGrp,sizeof(info.bloodGrp),stdin);
    info.bloodGrp[strcspn(info.bloodGrp,"\n")]='\0';
    gotoxy(6,16);printf("Hemoglobin: ");
    scanf("%f",&info.hemo);
    getchar();
    gotoxy(6,18);printf("Home Town: ");
    fgets(info.homeTown,sizeof(info.homeTown),stdin);
    info.homeTown[strcspn(info.homeTown,"\n")]='\0';
    gotoxy(6,20);printf("Number: ");
    fgets(info.number,sizeof(info.number),stdin);
    info.number[strcspn(info.number,"\n")]='\0';
    
    fwrite(&info,sizeof(info),1,myFile);
    fclose(myFile);
    gotoxy(31,24);printf("Your information is stored");
    gotoxy(39,26);printf("(THANK YOU)");
    gotoxy(29,28);printf("Press Enter to return main menu\n");
    getch();
    system("cls");
    design();
    menuDisplay();
    }
}

void search()
{
    char blood[10];
    char home[15];  
    system("cls");
    getchar();
    design();
    gotoxy(31,4);printf("====== Search Blood ======");
    gotoxy(34,13);printf("Blood Group: ");
    fgets(blood,sizeof(blood),stdin);
    blood[strcspn(blood,"\n")]='\0';
    gotoxy(34,15);printf("Home Town: ");
    fgets(home,sizeof(home),stdin);
    home[strcspn(home,"\n")]='\0';

    myFile= fopen("data.txt","r");
    if (myFile==NULL)
    {
        system("cls");
        design();
        gotoxy(35,14);printf("No data is stored!");
    }
    else
    {
        int i=1;
        int flag=0; 
        system("cls");
        gotoxy(31,4);printf("====== Search Result ======\n\n\n");
        while(fread(&info,sizeof(info),1,myFile)!=0)
        {
            if(strcmp(blood,info.bloodGrp)==0 && strcmp(home,info.homeTown)==0){
            printf("Person no %d\n\n",i);
            printf("Name: %s\nFather's Name: %s\nAge: %d\nBlood Group: %s\nHemoglobin: %.1f\nHome Town: %s\nNumber: %s\n",info.name,info.fName,info.age,info.bloodGrp,info.hemo,info.homeTown,info.number);
            printf("\n");
            i++;
            flag=1;
            }
        } 
        if(flag==0){
            design();
            gotoxy(35,15);printf("No data is found!");
        }
    } 
    fclose(myFile);
}

void donarsList()
{
    system("cls");
    myFile= fopen("data.txt","r");
    if (myFile==NULL)
    {
        system("cls");
        design();
        gotoxy(35,14);printf("No data is stored!");
    }
    else
    {
        int i=1;
        gotoxy(28,2);printf("==== Donar's List ====\n\n\n");
        while(fread(&info,sizeof(info),1,myFile)!=0)
        {
            printf("Donar no %d\n\n",i);
            printf("Name: %s\nFather's Name: %s\nAge: %d\nBlood Group: %s\nHemoglobin: %.1f\nHome Town: %s\nNumber: %s\n",info.name,info.fName,info.age,info.bloodGrp,info.hemo,info.homeTown,info.number);
            printf("\n");
            i++;
        }
        fclose(myFile);
    }
}

void updateInfo()
{

}
void deleteInfo()
{

}

void menuDisplay() 
{
    int select;
    gotoxy(33,3);printf(" =================");
    gotoxy(35,4);printf("FIND NEAR BLOOD");
    gotoxy(33,5);printf(" =================");
    gotoxy(31,10);printf("[1] Add Information");
    gotoxy(31,12);printf("[2] Search Blood");
    gotoxy(31,14);printf("[3] Donar's List");
    gotoxy(31,16);printf("[4] Update Information");
    gotoxy(31,18);printf("[5] Delete Information");
    gotoxy(31,20);printf("[6] Exit");
    gotoxy(31,24);printf("Enter your choice: ");
    scanf("%d",&select);
    
    switch(select)
    {
    case 1:
    {  
        system("cls");
        design();
        invailInfo();
        break;
    }
    case 2:
    {
        system("cls");
        design(); 
        search(); 
        break;
    }
    case 3:
    {
        system("cls");
        design();
        donarsList();
        break;
    }
    case 4:
    {
        system("cls");
        design();
        deleteInfo();
        break;
    }
    case 5:
        exit(1);
    default :
        main();
    }
}

//Design call function
void design()
{
    topCol();
    bottomCol();
    rightRow();
    leftRow();
}
//LeftRow column stars line
void leftRow()
{
    for(int i=30; i>=1; i--)
    {
        gotoxy(0,i);
        printf("*");
    }
}
//RightRow column stars line
void rightRow()
{
    for(int i=1; i<=30; i++)
    {
        gotoxy(85,i);
        printf("*");
    }
}
//Bottom Column stars line
void bottomCol()
{
    for(int i=0; i<=85; i++)
    {
        gotoxy(i,30);
        printf("*");
    }
}
//Top Column stars line
void topCol()
{
    for(int i=0; i<=85; i++)
    {
        gotoxy(i,0);
        printf("*");
    }
}

//Mouse cursor position deside function
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

