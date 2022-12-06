#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>

int main_menu();
int CUSTOMER();
int Cus_create();
int Cus_LOGIN();
int Remaining();
int goto1();
int cus();
int feedback();
int COMPANY();
int COMPANY1();
int Com_create();
int Com_LOGIN();
int p_input();
int ADMIN();
int Feedback();
int Electronics();
int Groceries();
int House_hold();
int detail();
int buy();
int billing();

COORD coord = { 0, 0 };

void gotoxy(int x10, int y10) {
    coord.X = x10; coord.Y = y10;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct patient{

    char name[20];
    char password[20];
    char adress[100];
    char number[20];
    char email[20];
};
struct patient p;

struct input{
    char name[25];
    float price;
    int k;
    int k1;
    float k3;
    int num;
};
struct input in;
struct feedback{
    char name[25];
    char fb[100];

};
struct feedback feed;
struct name{
    char *name6;
};
struct name r1;
int main(){


    main_menu();

    return 0;
}


int main_menu(){

        system("cls");
        int a;
        printf("\t\t\t\t      ****************A3K SHOPPING******************\n\n\n");
        printf("\t\t\t\t\t\t\t1.ADMIN\n\n");
        printf("\t\t\t\t\t\t\t2.CUSTOMER\n\n");
        printf("\t\t\t\t\t\t\t3.COMPANY\n\n");
        printf("\t\t\t\t\t\t\t4.EXIT\n\n\n\n");
        printf("\n\n\t\t\t\t\t\tENTER YOUR CHOICE : ");
        scanf("%d",&a);
        switch(a){
        case 1:
            ADMIN();
            break;
        case 2:
            CUSTOMER();
            break;
        case 3:
            COMPANY();
            break;
        case 4:
            printf("\n\t\t\t\t\t\tTHANKYOU ");
            getch();
            break;
        default:
            printf("\n\t\t\t\tSORRY :~( YOU ENTERED A WRONG OPTION RE-ENTER");
            getch();
            main_menu();
            break;
        }


}


//CUSTOMER-------------------------------------------------------------------------------------------------------------------------------------------------


int CUSTOMER(){

    system("cls");
    int a;
    printf("\n\n\t\t\t\t\t\t1.CREATE ACCOUNT \n\n\t\t\t\t\t\t2.LOGIN\n\n\t\t\t\t\t\t3.EXIT\n\n\n\n");
    printf("\t\t\t\t\t\tENTER YOUR CHOICE : ");
    scanf("%d",&a);
    if(a==1){
        Cus_create();
    }
    else if(a==2){
        Cus_LOGIN();
    }
    else if(a==3){
        main_menu();
    }
    else{
        printf("YOU ENTERED A WRONG OPTION RE-ENTER");
        getch();
        CUSTOMER();
    }
}
int Cus_create(){


    char d[20];
    int b,valid;
    system("cls");

    FILE*f;
    f=fopen("customer_info","a");
    printf("\n\n\n\n\t\t\t\t\t\tEMAIL ID : ");
    scanf("%s",p.email);
    printf("\n\n\n\n\t\t\t\t\t\tADDRESS : ");
    scanf("%s",p.adress);
    E:
    printf("\n\n\n\n\t\t\t\t\t\tPHONE NUMBER : ");
    scanf("%s",p.number);
    for(b=0;b<strlen(p.number);b++){
            if(!isalpha(p.number[b])){
                    valid=1;
                    }
                    else{
                        valid=0;
                        break;
                    }
        }
        if(valid!=1){
            printf("\n\t\t\t\t\tINVALID MOBILE NUMBER\n");
            goto E;
            }

    printf("\n\n\n\n\t\t\t\t\t\tUSERNAME: ");
    scanf(" %s",p.name);
    printf("\n\n\t\t\t\t\t\tPASSWORD: ");
    scanf("%s",p.password);
    D:
    printf("\n\n\t\t\t\t\t\tRE-TYPE PASSWORD: ");
    scanf("%s",d);
    if(strcmp(d,p.password)==0){
        printf("\n\n\t\t\tYOU SUCESSFULLY CREATED YOUR ACCOUNT");
    }
    else{
        printf("\n\n\t\t\tPLEASE RE-ENTER THE PASSWORD");
        goto D;
    }

    fprintf(f,"%s\t%s\t%d\t%s\t%s\n",p.email,p.adress,p.number,p.name,p.password);
    fclose(f);

    CUSTOMER();
    return 0;
}
int Cus_LOGIN(){

    system("cls");

    int k,i;
    char c[50],b[50];
    FILE*f;
    f=fopen("customer_info","r");


        printf("\n\n\n\n\t\t\t\tENTER YOUR USER NAME : ");
        scanf("%s",c);
        while(1){
        k=fscanf(f,"%s\t%s\t%d\t%s\t%s\n",&p.email,&p.adress,&p.number,&p.name,&p.password);
          if(k==-1){
            break;
          }
          if(strcmp(p.name,c)==0){
          C:
            printf("\n\n\t\t\t\t ENTER YOUR PASSWORD: ");
            scanf("%s",b);
            if(strcmp(p.password,b)==0){
                    i=6;
                printf("\n\n\t\t\t\tPASSWORD SUCESS");
                r1.name6=p.name;
                cus();

            }
            else{
                printf("\n\n\t\t\t\tYOUR PASSWORD SHOWS WRONG\n");
                printf("\n\n\t\t\t\tPLEASE RE-ENTER\n");
                goto C;
            }

          }
        }
            if(i==6){
                }

            else{
            printf("\n\t\t\t\t\t\tNO MATCHES FOUND\n");
            char d[10],h[10];
            printf("\n\t\t\t\tDO YOU WANT TO RE-TRY(y/n): ");
            scanf("%s",&d[0]);
            h[0]='y';
            if(d[0]==h[0]){
                Cus_LOGIN();
            }
            else{
                CUSTOMER();
            }}



    fclose(f);
}
int cus(){

    system("cls");
    int d;
     printf("\t\t\t\t      ****************A3K SHOPPING******************\n\n\n");
        printf("\t\t\t\t\t\t\t1.BUY\n\n");
        printf("\t\t\t\t\t\t\t2.FEEDBACK\n\n");
        printf("\t\t\t\t\t\t\t3.FINAL BILL\n\n");
        printf("\t\t\t\t\t\t\t4.EXIT\n\n");
        J:
        printf("\n\n\t\t\t\t\t\tENTER YOUR CHOICE: ");
        scanf("%d",&d);
        switch(d){
        case 1:
            buy();
            break;
        case 2:
            feedback();
            break;
        case 3:
            billing();
            break;
        case 4:
            main_menu();
            break;

        default:
            printf("\n\t\t\t\tSORRY :~( YOU ENTERED A WRONG OPTION ! RE-ENTER");
            getch();
            goto J;
            break;}

}
int feedback(){
    system("cls");
    FILE *f3;
    printf("\t\t\t\t      ****************FEEDBACK******************\n\n\n");

    printf("\n\n\n\t\t\t\tNAME : %s",r1.name6);
    f3=fopen("Feedback","a");

    printf("\n\n\t\t\t\tENTER THE FEEDBACK: \n");
    scanf(" %[^\n]%*c",feed.fb);
    fprintf(f3,"NAME : %s\nFEEDBACK: %s \n\n",r1.name6,feed.fb);
    fclose(f3);
    printf("YOU HAVE SUCESSFULLY ENTERED FEEDBACK");
    getch();
    cus();

}
int buy(){

system("cls");
int s;
printf("\t\t\t\t\t\t\tWHAT DO YOU WANT TO BUY\n");
printf("\n\n\t\t\t\t\t\t\t1.GROCERIES\n");
printf("\n\t\t\t\t\t\t\t2.ELECTRONICS\n");
printf("\n\t\t\t\t\t\t\t3.HOUSE HOLD\n");
printf("\n\t\t\t\t\t\t\t4.EXIT\n");
printf("\n\n\t\t\t\t\tENTER YOUR CHOICE : ");
scanf("%d",&s);
switch(s){
case 1:
    Groceries();
    break;
case 2:
    Electronics();
    break;
case 3:
    House_hold();
    break;
case 4:
    cus();
    break;
default:
    printf("SORRY YOU ENTERED A WRONG CHOICE");
    printf("PLEASE RE-ENTER");
    getch();
    buy();
    break;}

return 0;
}
int billing(){

system("cls");
int l10,l11,lines;
float overall;
FILE*z1;
z1=fopen(r1.name6,"r");
lines=0;
l10=30;
l11=10;
gotoxy(l10,l11);
printf("S.NO");
gotoxy((l10+5),l11);
printf("NAME");
gotoxy((l10+20),l11);
printf("PRICE");
gotoxy((l10+30),l11);
printf("NO  \n\n");
gotoxy((l10+40),l11);
printf("TOTAL ");
while(fscanf(z1,"%s\t%f\t%d\t%f\n",&in.name,&in.price,&in.k1,&in.k3)!=EOF){
    lines++;
    l10++;
    l11++;
    if(lines!=0){
    gotoxy(l10-lines,l11+(lines+1));
    printf("%d",lines);
    gotoxy((l10+5)-lines,l11+(lines+1));
    printf("%s",in.name);
    gotoxy((l10+20)-lines,l11+(lines+1));
    printf("%.2f",in.price);
    gotoxy((l10+30)-lines,l11+(lines+1));
    printf("%d",in.k1);
    gotoxy((l10+40)-lines,l11+(lines+1));
    printf("%f",in.k3);
    overall+=in.k3;
    }

}
printf("\n\n\t\t\t\t\t********************************");
printf("\n\t\t\t\t\t*   Grand total = %.2f     *",overall);
printf("\n\t\t\t\t\t********************************\n");
printf("\n\n\t\t\t\t\tTHANK YOU FOR SHOPPING ");
getch();
main_menu();
fclose(z1);
return 0;
}

int Groceries(){

system("cls");
int k,k1,k2,lines,line,l10,l11;
l10=30;
l11=10;
k=0;
char words[100],word[100];
FILE *p1,*z1,*p8;
p1=fopen("groceries.txt","r");
p8=fopen("g.txt","a");
if(p1==NULL){
    printf("SORRY NO PRODUCTS AVAILABLE");
    getch();
    buy();
}
z1=fopen(r1.name6,"a");
lines=0;
gotoxy(l10,l11);
printf("ID");
gotoxy((l10+5),l11);
printf("NAME");
gotoxy((l10+20),l11);
printf("PRICE");
gotoxy((l10+30),l11);
printf("AVAILABLE PRODUCTS\n\n");


while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    lines++;
    l10++;
    l11++;
    if(lines!=0){
            printf("\n");
    gotoxy(l10-lines,l11+(lines+1));
    printf("%d",lines);
    gotoxy((l10+5)-lines,l11+(lines+1));
    printf("%s",in.name);
    gotoxy((l10+20)-lines,l11+(lines+1));
    printf("%.2f",in.price);
    gotoxy((l10+30)-lines,l11+(lines+1));
    printf("%d",in.num);
    }

}

rewind(p1);
S1:
    //p1=fopen("groceries.txt","r");
    printf("\n\n\t\t\tENTER THE ID YOU WANT TO BUY : ");

scanf("%d",&in.k);

if(in.k>lines ||in.k<0){
    printf("\n\t\t\tWRONG ID PLEASE RE-ENTER");
    getch();
    goto S1;
}

printf("\n\t\t\t\tHOW MANY DO YOU WANT : ");
scanf("%d",&in.k1);
line=0;
rewind(p1);
while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    line++;
    /*printf("%d",in.k);
    printf("%d",line);
    printf("%d",in.k1);*/
    if(in.k==line){

            if(in.k1>0 && in.k1<=in.num){

                in.k3=(in.price*in.k1);
        fprintf(z1,"%s\t%f\t%d\t%f\n",in.name,in.price,in.k1,in.k3);}
        else{
            printf("\n\t\t\t\tYOUR ENTERED AMOUNT OF OBJECTS IS MORE THAN HERE ");
            printf("\n\n\t\t\t\t\tSORRY FOR THAT");
            printf("\n\n\t\t\t\tPLEASE ENTER WITHIN GIVEN AMOUNT\n");
            getch();
            //goto A;
            Groceries();
        }
    }

}
rewind(p1);
line=0;
while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    line++;
    if(in.k==line){
        in.num=in.num-in.k1;
        fprintf(p8,"%s\t%f\t%d\n",in.name,in.price,in.num);
    }
    else{
        fprintf(p8,"%s\t%f\t%d\n",in.name,in.price,in.num);
    }
}

fclose(z1);
fclose(p1);
fclose(p8);
remove("groceries.txt");
rename("g.txt","groceries.txt");
printf("\n\t\t    DO YOU WANT TO SHOP MORE(1-y/0-n): ");
scanf("%d",&k2);
if(k2==1){
    Groceries();
}
else{
    printf("\n\t\t\t\t\t\tTHANK YOU ");
    getch();
    buy();
}

return 0;

}
int Electronics(){

system("cls");
int k,k1,k2,lines,line,l10,l11;
l10=30;
l11=10;
k=0;
char words[100],word[100];
FILE *p1,*z1,*p8;
p1=fopen("electronics.txt","r");
p8=fopen("e.txt","a");
if(p1==NULL){
    printf("SORRY NO PRODUCTS AVAILABLE");
    getch();
    buy();
}
z1=fopen(r1.name6,"a");
lines=0;
gotoxy(l10,l11);
printf("ID");
gotoxy((l10+5),l11);
printf("NAME");
gotoxy((l10+20),l11);
printf("PRICE");
gotoxy((l10+30),l11);
printf("AVAILABLE PRODUCTS\n\n");


while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    lines++;
    l10++;
    l11++;
    if(lines!=0){
            printf("\n");
    gotoxy(l10-lines,l11+(lines+1));
    printf("%d",lines);
    gotoxy((l10+5)-lines,l11+(lines+1));
    printf("%s",in.name);
    gotoxy((l10+20)-lines,l11+(lines+1));
    printf("%.2f",in.price);
    gotoxy((l10+30)-lines,l11+(lines+1));
    printf("%d",in.num);
    }

}

rewind(p1);
S1:
    //p1=fopen("groceries.txt","r");
    printf("\n\n\t\t\tENTER THE ID YOU WANT TO BUY : ");

scanf("%d",&in.k);

if(in.k>lines ||in.k<0){
    printf("\n\t\t\tWRONG ID PLEASE RE-ENTER");
    getch();
    goto S1;
}

printf("\n\t\t\t\tHOW MANY DO YOU WANT : ");
scanf("%d",&in.k1);
line=0;
rewind(p1);
while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    line++;
    /*printf("%d",in.k);
    printf("%d",line);
    printf("%d",in.k1);*/
    if(in.k==line){

            if(in.k1>0 && in.k1<=in.num){

                in.k3=(in.price*in.k1);
        fprintf(z1,"%s\t%f\t%d\t%f\n",in.name,in.price,in.k1,in.k3);
        }
        else{
            printf("\n\t\t\t\tYOUR ENTERED AMOUNT OF OBJECTS IS MORE THAN HERE ");
            printf("\n\n\t\t\t\t\tSORRY FOR THAT");
            printf("\n\n\t\t\t\tPLEASE ENTER WITHIN GIVEN AMOUNT\n");
            getch();
            //goto A;
            Electronics();
        }
    }

}
rewind(p1);
line=0;
while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    line++;
    if(in.k==line){
        in.num=in.num-in.k1;
        fprintf(p8,"%s\t%f\t%d\n",in.name,in.price,in.num);
    }
    else{
        fprintf(p8,"%s\t%f\t%d\n",in.name,in.price,in.num);
    }
}

fclose(z1);
fclose(p1);
fclose(p8);
remove("electronics.txt");
rename("e.txt","electronics.txt");
printf("\n\t\t    DO YOU WANT TO SHOP MORE(1-y/0-n): ");
scanf("%d",&k2);
if(k2==1){
    Electronics();
}
else{
    printf("\n\t\t\t\t\t\tTHANK YOU ");
    getch();
    buy();
}

return 0;
}
int House_hold(){

   system("cls");
int k,k1,k2,lines,line,l10,l11;
l10=30;
l11=10;
k=0;
char words[100],word[100];
FILE *p1,*z1,*p8;
p1=fopen("house hold.txt","r");
p8=fopen("hh.txt","a");
if(p1==NULL){
    printf("SORRY NO PRODUCTS AVAILABLE");
    getch();
    buy();
}
z1=fopen(r1.name6,"a");
lines=0;
gotoxy(l10,l11);
printf("ID");
gotoxy((l10+5),l11);
printf("NAME");
gotoxy((l10+20),l11);
printf("PRICE");
gotoxy((l10+30),l11);
printf("AVAILABLE PRODUCTS\n\n");


while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    lines++;
    l10++;
    l11++;
    if(lines!=0){
            printf("\n");
    gotoxy(l10-lines,l11+(lines+1));
    printf("%d",lines);
    gotoxy((l10+5)-lines,l11+(lines+1));
    printf("%s",in.name);
    gotoxy((l10+20)-lines,l11+(lines+1));
    printf("%.2f",in.price);
    gotoxy((l10+30)-lines,l11+(lines+1));
    printf("%d",in.num);
    }

}

rewind(p1);
S1:
    //p1=fopen("groceries.txt","r");
    printf("\n\n\t\t\tENTER THE ID YOU WANT TO BUY : ");

scanf("%d",&in.k);

if(in.k>lines ||in.k<0){
    printf("\n\t\t\tWRONG ID PLEASE RE-ENTER");
    getch();
    goto S1;
}

printf("\n\t\t\t\tHOW MANY DO YOU WANT : ");
scanf("%d",&in.k1);
line=0;
rewind(p1);
while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    line++;
    /*printf("%d",in.k);
    printf("%d",line);
    printf("%d",in.k1);*/
    if(in.k==line){

            if(in.k1>0 && in.k1<=in.num){

                in.k3=(in.price*in.k1);
        fprintf(z1,"%s\t%f\t%d\t%f\n",in.name,in.price,in.k1,in.k3);}
        else{
            printf("\n\t\t\t\tYOUR ENTERED AMOUNT OF OBJECTS IS MORE THAN HERE ");
            printf("\n\n\t\t\t\t\tSORRY FOR THAT");
            printf("\n\n\t\t\t\tPLEASE ENTER WITHIN GIVEN AMOUNT\n");
            getch();
            //goto A;
            House_hold();
        }
    }

}
rewind(p1);
line=0;
while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    line++;
    if(in.k==line){
        in.num=in.num-in.k1;
        fprintf(p8,"%s\t%f\t%d\n",in.name,in.price,in.num);
    }
    else{
        fprintf(p8,"%s\t%f\t%d\n",in.name,in.price,in.num);
    }
}

fclose(z1);
fclose(p1);
fclose(p8);
remove("house hold.txt");
rename("hh.txt","house hold.txt");
printf("\n\t\t    DO YOU WANT TO SHOP MORE(1-y/0-n): ");
scanf("%d",&k2);
if(k2==1){
    House_hold();
}
else{
    printf("\n\t\t\t\t\t\tTHANK YOU ");
    getch();
    buy();
}

return 0;
}





//COMPANY---------------------------------------------------------------------------------------------------------------------------------------
int COMPANY(){

    system("cls");
    int i;
    char z[20],y[20]="a3k";
    i=0;
    printf("\n\n\n\n\t\t\tENTER THE COMMON CODE FOR ALL COMPANIES TO LOGIN ");
    B:
    printf("\n\n\n\t\t\t\t\t\tCODE:  ");
    scanf("%s",z);
    if(strcmp(z,y)==0){
            COMPANY1();

    }
    else{
        i++;
        if(i==3){
            printf("\n\n\t\t\t\t\t\tYOU TRIED THREE TIMES ");
            getch();
            main_menu();

        }
        else{
        printf("\n\n\t\t\t\t\t\tACESS DENIED\n\n\t\t\t\t\t\tPLEASE RE-TRY");
        goto B;}
    }
}
int COMPANY1(){
    system("cls");
    int a;
    printf("\n\n\t\t\t\t\t\t1.CREATE ACCOUNT \n\n\t\t\t\t\t\t2.LOGIN\n\n\t\t\t\t\t\t3.EXIT\n\n\n\n");
    printf("\t\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&a);
    if(a==1){
        Com_create();
    }
    else if(a==2){
        Com_LOGIN();
    }
    else if(a==3){
        main_menu();
    }
    else{
        printf("YOU ENTERED A WRONG CHOICE");
        getch();
        COMPANY1();
    }
}
int Com_create(){
    char d[20];
    int b,valid;
    system("cls");

    FILE*f1;
    f1=fopen("company_info","a");
    printf("\n\n\n\n\t\t\t\t\t\tEMAIL ID : ");
    scanf("%s",p.email);
    printf("\n\n\n\n\t\t\t\t\t\tADDRESS : ");
    scanf("%s",p.adress);
    E:
    printf("\n\n\n\n\t\t\t\t\t\tPHONE NUMBER : ");
    scanf("%s",p.number);
    for(b=0;b<strlen(p.number);b++){
            if(!isalpha(p.number[b])){
                    valid=1;
                    }
                    else{
                        valid=0;
                        break;
                    }
        }
        if(valid!=1){
            printf("\n\t\t\t\t\tINVALID MOBILE NUMBER\n");
            goto E;
            }

    printf("\n\n\n\n\t\t\t\t\t\tUSERNAME: ");
    scanf(" %s",p.name);
    printf("\n\n\t\t\t\t\t\tPASSWORD: ");
    scanf("%s",p.password);
    D:
    printf("\n\n\t\t\t\t\t\tRE-TYPE PASSWORD: ");
    scanf("%s",d);
    if(strcmp(d,p.password)==0){
        printf("\n\n\t\t\tYOU SUCESSFULLY CREATED AN ACCOUNT");
    }
    else{
        printf("\n\n\t\t\tPLEASE RE-ENTER THE PASSWORD");
        goto D;
    }

    fprintf(f1,"%s\t%s\t%d\t%s\t%s\n",p.email,p.adress,p.number,p.name,p.password);
    fclose(f1);
    COMPANY1();

return 0;
}
int Com_LOGIN(){
    system("cls");

    int k,i;
    char c[50],b[50];
    FILE*f1;
    f1=fopen("company_info","r");


        printf("\n\n\n\n\t\t\t\tENTER THE USER NAME : ");
        scanf("%s",c);
        while(1){
        k=fscanf(f1,"%s\t%s\t%d\t%s\t%s\n",&p.email,&p.adress,&p.number,&p.name,&p.password);
          if(k==-1){
            break;
          }
          if(strcmp(p.name,c)==0){
          L:
            printf("\n\n\t\t\t\t ENTER YOUR PASSWORD: ");
            scanf("%s",b);
            if(strcmp(p.password,b)==0){
                    i=6;
                printf("\n\n\t\t\t\tPASSWORD SUCESS");
                getch();
                p_input();
            }
            else{
                printf("\n\n\t\t\t\tYOUR PASSWORD SHOWS WRONG\n");
                printf("\n\n\t\t\t\tPLEASE RE-ENTER\n");
                goto L;
            }

          }
        }
            if(i==6){
                }

            else{
            printf("\n\t\t\t\t\t\tNO MATCHES FOUND\n");
            char d[10],h[10];
            printf("\n\n\t\t\t\tDO YOU WANT TO RETRY(y/n): ");
            scanf("%s",&d[0]);
            h[0]='y';
            if(d[0]==h[0]){
                Com_LOGIN();
            }
            else{
                COMPANY();
            }}



    fclose(f1);

}
int p_input(){
    system("cls");
    int a4,a2;
    FILE *p1;
    FILE *p2;
    FILE *p3;
    printf("\n\t\t\t\t\t\t\t1.GROCERIES\n\n");
    printf("\t\t\t\t\t\t\t2.ELECTRONICS\n\n");
    printf("\t\t\t\t\t\t\t3.HOUSE HOLD\n\n");
    printf("\n\n\t\t\tWHAT TYPE OF PRODUCT IS THIS: ");
    scanf("%d",&a2);
    switch(a2){
case 1:
    p1=fopen("groceries.txt","a");
    system("cls");
    printf("\t\t\t\t      *****************  GROCERIES  ****************\n\n\n");
    break;
case 2:
    p2=fopen("electronics.txt","a");
    system("cls");
    printf("\t\t\t\t      **************  ELECTRONICS  ****************\n\n\n");
    break;
case 3:
    p3=fopen("house hold.txt","a");
    system("cls");
    printf("\t\t\t\t      *****************  HOUSE HOLD ****************\n\n\n");
    break;
default:
    printf("\t\tYOU ENTERED A WRONG CHOICE\n\t\t\tPLEASE RE-ENTER");
    getch();
    p_input();
    break;
    }
    printf("\n\n\t\tENTER THE PRODUCT NAME(ONLY ONE WORD): ");
    scanf(" %s",in.name);
    printf("\n\t\t\t\tENTER THE PRICE : ");
    scanf("%f",&in.price);
    printf("\n\t\t\t\tENTER THE NO. OF PRODUCTS : ");
    scanf("%d",&in.num);
    switch(a2){
case 1:
    fprintf(p1,"%s\t%f\t%d\n",in.name,in.price,in.num);
    fclose(p1);
    break;
case 2:
    fprintf(p2,"%s\t%f\t%d\n",in.name,in.price,in.num);
    fclose(p2);
    break;
case 3:
    fprintf(p3,"%s\t%f\t%d\n",in.name,in.price,in.num);
    fclose(p3);
    break;}

    X1:
    printf("\n\t\t\t\tDO YOU WANT TO CONTINUE(1-y/0-n): ");
    scanf("%d",&a4);
    if(a4==1){
        p_input();
    }
    else if(a4==0){
        main_menu();
    }
    else{
        printf("\nYOU ENTERED A WRONG CHOICE");
        printf("\nPLEASE RE-ENTER\n");
        getch();
        goto X1;
    }


return 0;
}


//ADMIN---------------------------------------------------------------------------------------------------------------------------------------------------
int ADMIN(){


      system("cls");
      char user[10],pass[20];
      int a11;
      F:

        printf("\n\t\t\t\tENTER THE USER NAME: ");
      scanf(" %s",user);
      printf("\n\n\t\t\t\tENTER THE PASSWORD : ");
      scanf(" %s",pass);
      if (strcmp(user,"admin") == 0 && strcmp(pass,"adminlogin") == 0)
      {
          goto1();

      }
      else{
        printf("\nINVALID ENTRY !!! \n");
        getch();
        goto F;
      }


}
int Feedback(){

system("cls");
printf("\t\t\t\t      **************  ADMIN  ****************\n\n\n");
printf("\t\t\t\t\t\tHERE ARE THE FEEDBACKS");
FILE*P;
P=fopen("feedback","r");

char line[1000];

while(fgets(line , sizeof(line), P)){
    printf("\n\n");
    printf("%s",line);
}
fclose(P);

printf("PRESS ENTER TO RETURN");
getch();
goto1();

return 0;
}
int Remaining(){

int lines,l10,l11,a10;
l10=30;
l11=10;
system("cls");
    int a4,a2;
    FILE *p1;
    FILE *p2;
    FILE *p3;
    printf("\n\t\t\t\t\t\t\t1.GROCERIES\n\n");
    printf("\t\t\t\t\t\t\t2.ELECTRONICS\n\n");
    printf("\t\t\t\t\t\t\t3.HOUSE HOLD\n\n");
    printf("\t\t\t\t\t\t\t4.EXIT\n\n");
    printf("\n\n\t\t\tWHAT TYPE OF PRODUCT IS THIS: ");
    scanf("%d",&a2);
    switch(a2){
case 1:
    p1=fopen("groceries.txt","r");
    system("cls");
    printf("\t\t\t\t      *****************  GROCERIES  ****************\n\n\n");
    lines=0;
gotoxy(l10,l11);
printf("ID");
gotoxy((l10+5),l11);
printf("NAME");
gotoxy((l10+20),l11);
printf("PRICE");
gotoxy((l10+30),l11);
printf("AVAILABLE PRODUCTS\n\n");


while(fscanf(p1,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    lines++;
    l10++;
    l11++;
    if(lines!=0){
            printf("\n");
    gotoxy(l10-lines,l11+(lines+1));
    printf("%d",lines);
    gotoxy((l10+5)-lines,l11+(lines+1));
    printf("%s",in.name);
    gotoxy((l10+20)-lines,l11+(lines+1));
    printf("%.2f",in.price);
    gotoxy((l10+30)-lines,l11+(lines+1));
    printf("%d",in.num);
    }

}
fclose(p1);
printf("\n\n\t\t\t\t\tPRESS ENTER TO RETURN ");
    getch();
    Remaining();
    break;
case 2:
    p2=fopen("electronics.txt","r");
    system("cls");
    printf("\t\t\t\t      **************  ELECTRONICS  ****************\n\n\n");
    lines=0;
gotoxy(l10,l11);
printf("ID");
gotoxy((l10+5),l11);
printf("NAME");
gotoxy((l10+20),l11);
printf("PRICE");
gotoxy((l10+30),l11);
printf("AVAILABLE PRODUCTS\n\n");


while(fscanf(p2,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    lines++;
    l10++;
    l11++;
    if(lines!=0){
            printf("\n");
    gotoxy(l10-lines,l11+(lines+1));
    printf("%d",lines);
    gotoxy((l10+5)-lines,l11+(lines+1));
    printf("%s",in.name);
    gotoxy((l10+20)-lines,l11+(lines+1));
    printf("%.2f",in.price);
    gotoxy((l10+30)-lines,l11+(lines+1));
    printf("%d",in.num);
    }

}
fclose(p2);
printf("\n\n\t\t\t\t\tPRESS ENTER TO RETURN");
    getch();
    Remaining();
    break;

case 3:
    p3=fopen("house hold.txt","r");
    system("cls");
    printf("\t\t\t\t      *****************  HOUSE HOLD ****************\n\n\n");
    lines=0;
gotoxy(l10,l11);
printf("ID");
gotoxy((l10+5),l11);
printf("NAME");
gotoxy((l10+20),l11);
printf("PRICE");
gotoxy((l10+30),l11);
printf("AVAILABLE PRODUCTS\n\n");


while(fscanf(p3,"%s\t%f\t%d\n",&in.name,&in.price,&in.num)!=EOF){
    lines++;
    l10++;
    l11++;
    if(lines!=0){
            printf("\n");
    gotoxy(l10-lines,l11+(lines+1));
    printf("%d",lines);
    gotoxy((l10+5)-lines,l11+(lines+1));
    printf("%s",in.name);
    gotoxy((l10+20)-lines,l11+(lines+1));
    printf("%.2f",in.price);
    gotoxy((l10+30)-lines,l11+(lines+1));
    printf("%d",in.num);
    }

}
fclose(p3);

    printf("\n\n\t\t\t\t\tPRESS ENTER TO RETURN ");
    getch();
    Remaining();
    break;

case 4:
    goto1();
    break;
default:
    printf("\t\tYOU ENTERED A WRONG CHOICE\n\t\t\tPLEASE RE-ENTER");
    getch();
    Remaining();
    break;
    }

    //exit(1);

return 0;

}
int goto1(){
int a11;
system("cls");
          printf("\n\t\t\t\t\t1.REMAINING PRODUCTS");
          printf("\n\t\t\t\t\t2.FEEDBACK");
          printf("\n\t\t\t\t\t3.EXIT");
          printf("\n\n\t\t\t\t\tENTER YOUR CHOICE : ");
          scanf("%d",&a11);
          switch(a11){
        case 1:
            Remaining();
            break;
        case 2:
            Feedback();
            break;
        case 3:
            main_menu();
            break;
        default:
            printf("YOU ENTERED A WRONG CHOICE");
            printf("PLEASE RE-ENTER");
            getch();
            ADMIN();
            break;
                }

                return 0;
}

