#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

// Frame design
void topCol();
void bottomCol();
void rightRow();
void leftRow();

// Other functions
void design();
void gotoxy();
void menuDisplay();
void submitInfo();

// Menu functions
void addInfo();
void search();
void donarsList();
void updateInfo();
void deleteInfo();
void sortAgeBasis();

// Global file pointer
FILE *myFile;

// Global structure
typedef struct personInformation
{
    char name[30];
    char fName[30];
    int age;
    char bloodGrp[20];
    char LastDonationTime[20];
    char homeTown[30];
    char number[25];

} personInfo;

personInfo info;

void main()
{
    system("cls"); // stdlib.h
    design();
    submitInfo();
    getch(); // conio.h
    system("cls");
    design();
    menuDisplay();
}

void addInfo()
{
    system("cls");
    design();
    getchar();
    gotoxy(30, 4);
    printf("====== Add Person Info ======");
    FILE *myFile;
    myFile = fopen("data.txt", "a");
    if (myFile == NULL)
    {
        gotoxy(35, 12);
        printf("Empty!");
    }
    else
    {
        gotoxy(6, 8);
        printf("Name: ");
        fgets(info.name, sizeof(info.name), stdin);
        info.name[strcspn(info.name, "\n")] = '\0';
        gotoxy(6, 10);
        printf("Father's Name: ");
        fgets(info.fName, sizeof(info.fName), stdin);
        info.fName[strcspn(info.fName, "\n")] = '\0';
        gotoxy(6, 12);
        printf("Age: ");
        scanf("%d", &info.age);
        getchar();
        gotoxy(6, 14);
        printf("Blood Group: ");
        fgets(info.bloodGrp, sizeof(info.bloodGrp), stdin);
        info.bloodGrp[strcspn(info.bloodGrp, "\n")] = '\0';
        gotoxy(6, 16);
        printf("Last Donation Date: ");
        fgets(info.LastDonationTime, sizeof(info.LastDonationTime), stdin);
        info.LastDonationTime[strcspn(info.LastDonationTime, "\n")] = '\0';
        gotoxy(6, 18);
        printf("Home Town: ");
        fgets(info.homeTown, sizeof(info.homeTown), stdin);
        info.homeTown[strcspn(info.homeTown, "\n")] = '\0';
        gotoxy(6, 20);
        printf("Number: ");
        fgets(info.number, sizeof(info.number), stdin);
        info.number[strcspn(info.number, "\n")] = '\0';

        fwrite(&info, sizeof(info), 1, myFile);
        fclose(myFile);
        gotoxy(31, 24);
        printf("Your information is stored");
        gotoxy(39, 26);
        printf("(THANK YOU)");
        gotoxy(29, 28);
        printf("Press Enter to return main menu\n");
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
    gotoxy(31, 4);
    printf("====== Search Blood ======");
    gotoxy(34, 13);
    printf("Blood Group: ");
    fgets(blood, sizeof(blood), stdin);
    blood[strcspn(blood, "\n")] = '\0';
    gotoxy(34, 15);
    printf("Current location: ");
    fgets(home, sizeof(home), stdin);
    home[strcspn(home, "\n")] = '\0';

    myFile = fopen("data.txt", "r");
    if (myFile == NULL)
    {
        system("cls");
        design();
        gotoxy(35, 14);
        printf("No data is stored!");
    }
    else
    {
        int i = 1;
        int flag = 0;
        system("cls");
        gotoxy(31, 4);
        printf("====== Search Result ======\n\n\n");
        while (fread(&info, sizeof(info), 1, myFile) != 0)
        {
            if (strcmp(blood, info.bloodGrp) == 0 && strcmp(home, info.homeTown) == 0)
            {
                printf("Person no %d\n\n", i);
                printf("Name: %s\nFather's Name: %s\nAge: %d\nBlood Group: %s\nLast Donation Date: %s\nHome Town: %s\nNumber: %s\n", info.name, info.fName, info.age, info.bloodGrp, info.LastDonationTime, info.homeTown, info.number);
                printf("\n");
                i++;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            design();
            gotoxy(35, 15);
            printf("No data is found!");
        }
    }
    fclose(myFile);
}

void donarsList()
{
    system("cls");
    myFile = fopen("data.txt", "rb+");
    if (myFile == NULL)
    {
        system("cls");
        design();
        gotoxy(35, 14);
        printf("No data is stored!");
    }
    else
    {
        gotoxy(28, 2);
        printf("==== Donar's List ====\n\n\n");
        int j = 1;
        while (fread(&info, sizeof(info), 1, myFile) != 0)
        {
            printf("Donar no %d\n\n", j);
            printf("Name: %s\nFather's Name: %s\nAge: %d\nBlood Group: %s\nLast Donation Date: %s\nHome Town: %s\nNumber: %s\n", info.name, info.fName, info.age, info.bloodGrp, info.LastDonationTime, info.homeTown, info.number);
            printf("\n");
            j++;
        }
    }
}

void updateInfo()
{
    int flag = 0;
    system("cls");
    design();
    getchar();
    myFile = fopen("data.txt", "rb+");

    if (myFile == NULL)
    {
        system("cls");
        design();
        gotoxy(35, 14);
        printf("Can't open file!");
    }

    char namE[50];
    gotoxy(28, 6);
    printf("Enter your name: ");
    fgets(namE, sizeof(namE), stdin);
    namE[strcspn(namE, "\n")] = '\0';

    while (fread(&info, sizeof(info), 1, myFile) == 1 && flag == 0)
    {
        if (strcmp(namE, info.name) == 0)
        {
            flag = 1;
            gotoxy(6, 10);
            printf("Father's Name: ");
            fgets(info.fName, sizeof(info.fName), stdin);
            info.fName[strcspn(info.fName, "\n")] = '\0';
            gotoxy(6, 12);
            printf("Age: ");
            scanf("%d", &info.age);
            getchar();
            gotoxy(6, 14);
            printf("Blood Group: ");
            fgets(info.bloodGrp, sizeof(info.bloodGrp), stdin);
            info.bloodGrp[strcspn(info.bloodGrp, "\n")] = '\0';
            gotoxy(6, 16);
            printf("Last Donation Date: ");
            fgets(info.LastDonationTime, sizeof(info.LastDonationTime), stdin);
            info.LastDonationTime[strcspn(info.LastDonationTime, "\n")] = '\0';
            gotoxy(6, 18);
            printf("Home Town: ");
            fgets(info.homeTown, sizeof(info.homeTown), stdin);
            info.homeTown[strcspn(info.homeTown, "\n")] = '\0';
            gotoxy(6, 20);
            printf("Number: ");
            fgets(info.number, sizeof(info.number), stdin);
            info.number[strcspn(info.number, "\n")] = '\0';

            //fseek(myFile, ftell(myFile)-sizeof(info), 0);
            fseek(myFile, ftell(myFile)-sizeof(info), 0);
            fwrite(&info, sizeof(info), 1, myFile);
            gotoxy(39, 22);
            printf("Updated");
            gotoxy(29, 28);
            printf("Press Enter to return main menu\n");
            getch();
        }
    }

    fclose(myFile);
    system("cls");
    design();
    menuDisplay();
}

void sortAgeBasis()
{
    system("cls");
    // design();
    getchar();
    
    personInfo arr[500];
    personInfo temp;
    unsigned flag = 0;
    myFile = fopen("data.txt", "r");

    if (myFile == NULL)
    {
        system("cls");
        design();
        gotoxy(35, 14);
        printf("Can't open file!");
    }

    int i = 0, k = 0;
    while (fread(&arr[i], sizeof(arr[i]), 1, myFile) == 1)
    {
        i++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k - i - 1; j++)
        {
            if (arr[j].age > arr[j + 1].age)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


    int j = 1;
    printf("====== Age Basis Result ======\n\n\n");
    for (int i = 0; i < k; i++)
    {
        printf("Donar no %d\n\n", j);
        printf("Name: %s\nFather's Name: %s\nAge: %d\nBlood Group: %s\nLast Donation Date: %s\nHome Town: %s\nNumber: %s\n", arr[i].name, arr[i].fName, arr[i].age, arr[i].bloodGrp, arr[i].LastDonationTime, arr[i].homeTown, arr[i].number);
        printf("\n");
        j++;
    }

    fclose(myFile);
}

void menuDisplay()
{
    time_t t;
    time(&t);
    gotoxy(50, 2);
    printf("Date: %s", ctime(&t));
    int select;
    gotoxy(33, 5);
    printf(" =================");
    gotoxy(35, 6);
    printf("FIND NEAR BLOOD");
    gotoxy(33, 7);
    printf(" =================");
    gotoxy(31, 11);
    printf("[1] Add Information");
    gotoxy(31, 13);
    printf("[2] Search Blood");
    gotoxy(31, 15);
    printf("[3] Donar's List");
    gotoxy(31, 17);
    printf("[4] Update Information");
    gotoxy(31, 19);
    printf("[5] Age Basis Donar List");
    gotoxy(31, 21);
    printf("[6] Exit");
    gotoxy(31, 24);
    printf("Enter your choice: ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
    {
        system("cls");
        design();
        addInfo();
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
        updateInfo();
        break;
    }

    case 5:
    {
        system("cls");
        design();
        sortAgeBasis();
        break;
    }
    case 6:
        system("cls");
        gotoxy(30, 15);
        printf("Thank you for visiting us");
        design();
        exit(1);
    }
}

void submitInfo()
{
    // Presented By
    gotoxy(13, 10);
    printf("Presented By");
    gotoxy(9, 11);
    printf(" =================");
    gotoxy(33, 3);
    printf(" =================");
    gotoxy(37, 4);
    printf("INFORMATION");
    gotoxy(33, 5);
    printf(" =================");
    gotoxy(6, 14);
    printf("Name: Awal Hossain Munna");
    gotoxy(6, 16);
    printf("ID: 0242310005101840");
    gotoxy(6, 18);
    printf("Section: J");
    gotoxy(6, 20);
    printf("Batch: 64");

    // Presented To
    gotoxy(57, 10);
    printf("Presented To");
    gotoxy(53, 11);
    printf(" =================");
    gotoxy(53, 15);
    printf("Abdullah Al Mamun(AAM)");
    gotoxy(53, 17);
    printf("Designation: Lecturer");
    gotoxy(47, 19);
    printf("Office Address:505/1,AB-04,DSC, DIU");
    gotoxy(31, 26);
    printf("(Press Enter to continue)");
}

// Design call function
void design()
{
    topCol();
    bottomCol();
    rightRow();
    leftRow();
}
// LeftRow column stars line
void leftRow()
{
    for (int i = 30; i >= 1; i--)
    {
        gotoxy(0, i);
        printf("*");
    }
}
// RightRow column stars line
void rightRow()
{
    for (int i = 1; i <= 30; i++)
    {
        gotoxy(85, i);
        printf("*");
    }
}
// Bottom Column stars line
void bottomCol()
{
    for (int i = 0; i <= 85; i++)
    {
        gotoxy(i, 30);
        printf("*");
    }
}
// Top Column stars line
void topCol()
{
    for (int i = 0; i <= 85; i++)
    {
        gotoxy(i, 0);
        printf("*");
    }
}

// Mouse cursor position function
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    // Handle is a datatype which holds the numeric value
    // for getting the handle of output screne we use another function (GetStdHandle). For getting handle we will use identifier(STD_OUTPUT_HANDLE)
    // COORD- it is a structure which holds the coedinate of the output screne x and y
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

