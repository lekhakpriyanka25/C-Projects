#include<stdio.h>
#include<conio.h>
int t=0,id1,found=0,confirm;
long userId;
char name[100];
FILE *fp,*fv,*fs,*fi;
struct books
{
int id,price;
char name[100];
char author[100];
int quantity;
};
struct books b;
void Top_message()
{
printf("\t################################################################");
printf("\n\t##########                                         #############");
printf("\n\t##########        Library management System        #############");
printf("\n\t##########                                         #############");
printf("\n\t################################################################");
}
void welcome()
{
int n;
printf("\n\n\n\n");
printf("\n\t **_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**\n");
printf("\n\t           =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
printf("\n\t           =                 WELCOME                     =");
printf("\n\t           =                   TO                        =");
printf("\n\t           =                 LIBRARY                     =");
printf("\n\t           =               MANAGEMENT                    =");
printf("\n\t           =                 SYSTEM                      =");
printf("\n\t           =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
printf("\n\t **_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**\n");
printf("\n\t Enter any key to continue....");
scanf("%s",&n);
}
void new_add()
{
int more;
clrscr();
repeat:
fp=fopen("hardik.txt","ab+");
if(fp==NULL)
{
printf("\n\n\t File Not Found  ");
exit(1);
}
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_** ");
printf("\n\n\t\t\t\tAdding New Books \n\n");
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_** ");
printf("\n\n* Enter Book ID : ");
fflush(stdin);
scanf("%d",&b.id);
printf("\n\n* Enter Book Name :");
fflush(stdin);
gets(b.name);
printf("\n\n* Enter Author's Name :");
fflush(stdin);
gets(b.author);
printf("\n\n* Enter the quantity : ");
scanf("%d",&b.quantity);
printf("\n\n* Enter the price :");
fflush(stdin);
scanf("%d",&b.price);
fwrite(&b,sizeof(b),1,fp);
printf("\n\n\t   Record Added Successfully...");
fclose(fp);
printf("\n\n\t  Want To Add More Record (Press 1) : \t");
fflush(stdin);
scanf("%d",&more);
clrscr();
if(more==1)
{
goto repeat;
}
}
void view()
{
clrscr();
fv= fopen("hardik.txt","rb");
if(fv==NULL)
{
printf("\n\n\t\t  File Not Found  \n\n");
exit(1);
}
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**\n ");
printf("\n \t\t\t AVAILABLE_BOOKS_ARE :\n\n");
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**\n ");
printf("\n\tBook Id  Book Name \t Name Of Author    Quantity    Price \n");
while(fread(&b,sizeof(b),1,fv)!=NULL)
printf("\n\t %d \t %s \t  %s\t %d\t %d",b.id,b.name,b.author,b.quantity,b.price);
fclose(fv);
}
void search()
{
int search;
clrscr();
fs = fopen("hardik.txt","r");
if(fs==NULL)
{
printf("\n\t\t  File not found \n\n");
}
else
{
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_** \n");
printf("\n\t\t\t   Searching Books  \n\n ");
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_** \n");
printf("\n\t\t   Enter 'Book ID' To Search any book : ");
scanf("%d",&search);
while(fread(&b,sizeof(b),1,fs)!=NULL)
{
if(b.id==search)
{
t=1;
printf("\n\tSearch For Book-Id  '%d'  Is Availabe\n",search);
printf("\n\t Book Id   Book Name\t Name Of Author\t   Quantity    Price\t\t\n");
printf("\n\t %d\t %s \t %s \t %d \t %d",b.id,b.name,b.author,b.quantity,b.price);
}
}
if(t==0)
{
printf(" \n\n \t\tSearch For Book-Id '%d' Is Failed ",search);
}
fclose(fs);
}
}
void issue()
{
fp= fopen("hardik.txt","r+");
fi= fopen("issue.txt","w+");
clrscr();
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_** ");
printf("\n\n\t\t\t\tISSUE_SECTION  \n\n");
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_** \n");
printf(" \n \t\t  Enter BOOK ID : ");
scanf("%d",&id1);
fflush(stdin);
while(fread(&b,sizeof(b),1,fp)!=NULL)
{
if(b.id==id1)
{
t=1;
printf("\n \t\t %d Books Of %s Are Availabe\n ",b.quantity,b.name);
found=b.quantity;
}
}
if(t==0)
{
printf(" \t\t\t This Book Is Not Available");
exit(1);
}
printf("\n \t\t Enter 1 To Issue This Book : ");
scanf("%d",&id1);
fflush(stdin);
if(id1==1)
{
printf("\n\t\t\t\t ISSUE-SLIP \t\n\n");
printf("\n \t\t# Enter Your ID : ");
scanf("%ld",&userId);
fflush(stdin);
printf("\n \t\t# Enter Your Name : ");
scanf("%s",&name);
fflush(stdin);
printf("\n\t\t# User Id of the Student is : %ld",userId);
printf("\n\t\t# Name of the Student is : %s",name);
printf("\n\t\t# Issued Book ID : \t%d",b.id);
printf("\n\t\t# Issued Book Is : \t%s by %s",b.name,b.author);
printf("\n\n\t Press Any No < 10 To Confirm : ");
scanf("%d", &confirm);
if(confirm<10)
{
found--;
b.quantity=found;
fwrite(&b,sizeof(b),1,fi);
fclose(fi);
fclose(fp);
printf("\n\n\t\t  BOOK ISSUED. . . ");
}
else
{
printf("\n \t\t\t OOPS!!  Error In Confirmation : ");
exit(1);
}
}
}
void remove_books()
{
clrscr();
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_** \n");
printf("\n\n \t\t\t    REMOVE  BOOKS\n\n");
printf("\t**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_**_** \n");
printf("\n\tEnter The Book ID To Delete : ");
scanf("%d",&id1);
fp = fopen("hardik.txt", "r");
found = 0;
while(fread(&b,sizeof(b),1,fp)!=NULL)
{
if (b.id==id1)
{
found = 1;
break;
}
}
fclose(fp);
if (found == 0)
{
printf(" \n\t File Not Found  '%d' ",id1);
}
else
{
FILE *t;
t=fopen("book.txt", "a");
if (t== NULL)
{
printf("\n\n\t\t\t  Error!  File Not Found  \n\n");
exit(1);
}
fp = fopen("hardik.txt", "r");
while(fread(&b,sizeof(b),1,fp)!=NULL)
{
if (b.id!=id1)
{
fwrite(&b,sizeof(b),1,t);
}
}
fclose(fp);
fclose(t);
remove("hardik.txt");
rename("book.txt", "hardik.txt");
printf("\n\n\t\tSuccess !! This Book Has Been Removed From The Records \n\n\n",id1);
}
}
void menu()
{
int choice=0;
printf("\n-----------------------------------------------------------------------------");
printf("\n\n\t        **_**_**_**_    Main Menu    **_**_**_**_** ");
printf("\n\n-----------------------------------------------------------------------------");
printf("\n\n* Press 1 To Add Books");
printf("\n\n* Press 2 To View Books List");
printf("\n\n* Press 3 To Search Books ");
printf("\n\n* Press 4 To Issue Books");
printf("\n\n* Press 5 To Remove Books");
printf("\n\n* Press 0 To Close Application");
printf("\n\n\n\n Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
new_add();
break;
case 2:
view();
break;
case 3:
search();
break;
case 4:
issue();
break;
case 5:
remove_books();
break;
case 0:
printf("\n\t ########## Thank You ###########");
exit(1);
break;
default:
printf("\n\n\n\t Invalid Input!!! Try again...");
}
}
void main()
{
clrscr();
Top_message();
welcome();
menu();
getch();
}