#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include<stdlib.h>


struct
{
    int acc;
    char frist_name[100];
    char last_name[100];
    int age;
    int pin;
    char dob[100];
    char address[100];
    long long int phone;
    int money;
}add,upd,che,del;


void loading();
void check_admin();
void check_staff();
void check_user();
void admin_menu();
void staff_menu();
void user_menu();
void create_staff();
void create_user();
void update_staff();
void update_user();
void staff_list();
void user_list();
void check_balance();
void deposits();
void withdraw();
void transfer_money();
void check_your_history();
void check_history();
void delete_staff();
void delete_user();





int main()
{
    
    printf("\t\t\tWelcom to THEFR BANK\n\n\n");
    printf("1. Admin\n\n2.Staff\n\n3.User\n\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    loading();
    system("cls");
    switch(choice)
    {
        case 1:
        {
            check_admin();
            break;
        }

        case 2:
        {
            check_staff();
            break;
        }
        case 3:
        {
            check_user();
            break;
        }
    }
}

void check_admin()
{
    admin_pass:
    printf("Enter admin password: ");
    char check_admin_passs[100];
    scanf("%s",check_admin_passs);
    if(strcmp(check_admin_passs,"fahim")==0)
    {
        printf("\n\nPassword Match!!\nLOADING ");
        for(int i=1;i<=6;i++)
        {
            Sleep(100);
            printf(".");
        }
        system("cls");
        admin_menu();
    }
        
    else
    {
        printf("\nWrong password!!\n");
        int choice;
        printf("Enter 1 for try again\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            system("cls");
            goto admin_pass;
            break;
            
        }
    }
}


void check_staff()
{
    FILE *fptr;
    fptr=fopen("staff.txt","r");
    int flag=0;
    system("cls");
    printf("Enter account number for staff: ");
    int check_staff_acc;
    scanf("%d",&check_staff_acc);
    while(fscanf(fptr,"%d %s %s %d %d %s %lld %s",&che.acc,che.frist_name,che.last_name,&che.pin,&che.age,che.dob,&che.phone,che.address)!=EOF)
    {
        if(check_staff_acc==che.acc)
        {
            check_staff_pin:
            flag=1;
            printf("Enter PIN: ");
            int check_pin;
            scanf("%d",&check_pin);
            if(check_pin==che.pin)
            {
                printf("\n\nPassword Match!!\nLOADING ");
                for(int i=1;i<=6;i++)
                {
                    Sleep(100);
                    printf(".");
                }
                system("cls");
                fclose(fptr);
                staff_menu();
            }
                else
                {
                    printf("PIN is wrong");
                    goto check_staff_pin;
                }            
        }
    }
    if(flag==0)
    {
        printf("Account numbeer is wrong\n");
    }
    fclose(fptr);
}

void check_user()
{
    FILE *fptr;
    fptr=fopen("useracc.txt","r");
    int flag=0;
    system("cls");
    printf("Enter account number for user: ");
    int check_user_acc;
    scanf("%d",&check_user_acc);
    while(fscanf(fptr,"%d %d",&che.acc,&che.pin)!=EOF)
    {
        
        if(check_user_acc==che.acc)
        {
            check_user_pin:
            flag=1;
            printf("Enter PIN: ");
            int check_pin;
            scanf("%d",&check_pin);
            if(check_pin==che.pin)
            {
                printf("\n\nPassword Match!!\nLOADING ");
                for(int i=1;i<=6;i++)
                {
                    Sleep(100);
                    printf(".");
                }
                system("cls");
                fclose(fptr);
                user_menu();
            }
            else
            {
                printf("PIN is wrong");
                goto check_user_pin;
            }
        }
    }
    fclose(fptr);
    if(flag==0)
    {
        printf("Account number is wrong\n");
    }

}




void loading()
{
    printf("\nLOADING ");
    for(int i=1;i<=6;i++)
    {
        Sleep(100);
        printf(".");
    }
}

void admin_menu()
{
    system("cls");
    printf("\t\t\tWELCOME TO ADMIN PANEL\n\n");
    printf("1.Create Staff account\n\n2.Create User account\n\n3.Update Staff account\n\n4.Update User account\n\n5.View Staff lists\n\n6.View User lists\n\n7.Check User Transaction History\n\n8.Check ALL User Transaction History\n\n9.Delete Staff Account\n\n10.Delete User Account\n\n0.For Quit\n\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        create_staff();
        break;

        case 2:
        create_user();
        admin_menu();
        break;

        case 3:
        update_staff();
        break;

        case 4:
        update_user();
        admin_menu();
        break;

        case 5:
        staff_list();
        break;

        case 6:
        user_list();
        break;

        case 7:
        check_your_history();
        break;

        case 8:
        check_history();
        break;

        case 9:
        delete_staff();
        break;

        case 10:
        delete_user();
        admin_menu();
        break;

        case 0:
        exit(0);
    }
    exit:
        printf("Enter 0 to return to admin menu: ");
        int choice_gg;
        scanf("%d",&choice_gg);
        if(choice_gg==0)
        {
            admin_menu();
        }

        else
        {
            goto exit;
        }
}

void staff_menu()
{
    system("cls");
    printf("\t\t\tWELCOME TO STAFF PANEL\n\n");
    printf("1.Create User account\n\n2.Update User account\n\n3.View User lists\n\n4.Check User Transaction History\n\n5.Check All User Transaction History\n\n6.Delete User Account\n\n0.For Quit\n\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        create_user();
        staff_menu();
        break;

        case 2:
        update_user();
        staff_menu();
        break;

        case 3:
        user_list();
        break;
    
        case 4:
        check_your_history();
        break;

        case 5:
        check_history();
        break;

        case 6:
        delete_user();
        staff_menu();

        case 0:
        exit(0);
    }
    exit:
    printf("Enter 0 to return to staff menu: ");
    int choice_gg;
    scanf("%d",&choice_gg);
    if(choice_gg==0)
    {
        staff_menu();
    }

    else
    {
        goto exit;
    }
    
}


void user_menu()
{
    system("cls");
    printf("\t\t\tWELCOME TO USER PANEL\n\n");
    printf("1.Check Balance\n\n2.Deposit money\n\n3.Withdraw\n\n4.Transfer money\n\n5.Your Transaction History\n\n0.For Quit\n\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        check_balance();
        break;
        
        case 2:
        deposits();
        break;

        case 3:
        withdraw();
        break;

        case 4:
        transfer_money();
        break;

        case 5:
        check_your_history();
        break;

        case 0:
        exit(0);
    }
    exit:
        printf("Enter 0 to return to User menu: ");
        int choice_gg;
        scanf("%d",&choice_gg);
        if(choice_gg==0)
        {
            user_menu();
        }

        else
        {
            goto exit;
        }
}

void create_staff()
{
    system("cls");
    FILE *fptr;
    printf("Enter account numner: ");
    scanf("%d",&add.acc);
    printf("Enter frist name: ");
    scanf("%s",add.frist_name);
    printf("Enter last name: ");
    scanf("%s",add.last_name);
    fflush(stdin);
    printf("Enter pin: ");
    scanf("%d",&add.pin);
    printf("Enter age: ");
    scanf("%d",&add.age);
    printf("Enter date of birth: ");
    scanf("%s",add.dob);
    fflush(stdin);
    phone:
    printf("Enter phone number(880): ");
    scanf("%lld",&add.phone);
    int num=log10(add.phone);
    if(num!=9)
    {
        printf("You entered invalid phone number\n");
        goto phone;
    }
    printf("Enter address: ");
    scanf("%s",add.address);

    fptr=fopen("staff.txt","a+");
    fprintf(fptr,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t880%lld\t\t%s\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address);
    fclose(fptr);
    printf("\n\nStaff account created\n");
    printf("Gonint to main menu\n");
    loading();
    admin_menu();
}


void create_user()
{
    system("cls");
    FILE *fptr;
    printf("Enter account numner: ");
    scanf("%d",&add.acc);
    printf("Enter frist name: ");
    scanf("%s",add.frist_name);
    printf("Enter last name: ");
    scanf("%s",add.last_name);
    fflush(stdin);
    printf("Enter pin: ");
    scanf("%d",&add.pin);

    FILE *f;
    f=fopen("useracc.txt","a+");
    fprintf(f,"%d %d\n",add.acc,add.pin);
    fclose(f);

    printf("Enter age: ");
    scanf("%d",&add.age);
    printf("Enter date of birth: ");
    scanf("%s",add.dob);
    fflush(stdin);
    phone:
    printf("Enter phone number(880): ");
    scanf("%lld",&add.phone);
    int num=log10(add.phone);
    if(num!=9)
    {
        printf("You entered invalid phone number\n");
        goto phone;
    }
    printf("Enter address: ");
    scanf("%s",add.address);
    printf("Initial deposit: ");
    scanf("%d",&add.money);

    fptr=fopen("user.txt","a+");
    fprintf(fptr,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t880%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,add.money);
    fclose(fptr);
    printf("\n\nUser account created\n");
    printf("Gonint to main menu\n");
    loading();
}


void update_staff()
{
    system("cls");
    FILE *old,*new;
    old=fopen("staff.txt","r");
    new=fopen("new.txt","w");
    printf("Enter account number: ");
    scanf("%d",&upd.acc);
    while(fscanf(old,"%d %s %s %d %d %s %lld %s",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address)!=EOF)
    {
        if(add.acc==upd.acc)
        {
            system("cls");
            printf("What you want to update?\n");
            printf("1.PIN\n\n2.Address\n\n3.Phone number\n\nEnter your choice: ");
            int choice;
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                printf("Enter new PIN: ");
                scanf("%d",&upd.pin);
                fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\n",add.acc,add.frist_name,add.last_name,upd.pin,add.age,add.dob,add.phone,add.address);
                break;

                case 2:
                printf("Enter new Address: ");
                scanf("%s",&upd.address);
                fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,upd.address);
                break;

                case 3:
                printf("Enter new phone: ");
                scanf("%d",&upd.phone);
                fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t880%lld\t\t%s\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,upd.phone,add.address);
                break;

            }
        }
        else
        {
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address);
        }
    }
    fclose(old);
    fclose(new);
    remove("staff.txt");
    rename("new.txt","staff.txt");
    admin_menu();
}


void update_user()
{
    system("cls");
    FILE *old,*new;
    old=fopen("user.txt","r");
    new=fopen("new.txt","w");
    printf("Enter account number: ");
    scanf("%d",&upd.acc);
    while(fscanf(old,"%d %s %s %d %d %s %lld %s %d",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address,&add.money)!=EOF)
    {
        if(add.acc==upd.acc)
        {
            system("cls");
            printf("What you want to update?\n");
            printf("1.PIN\n\n2.Address\n\n3.Phone number\n\n4.Add Balance\n\nEnter your choice: ");
            int choice;
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                printf("Enter new PIN: ");
                scanf("%d",&upd.pin);
                fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,upd.pin,add.age,add.dob,add.phone,add.address,add.money);
                FILE *f;
                f=fopen("useracc.txt","a+");
                fprintf(f,"%d %d\n",add.acc,upd.pin);
                fclose(f);
                
                break;

                case 2:
                printf("Enter new Address: ");
                scanf("%s",&upd.address);
                fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,upd.address,add.money);
                
                break;

                case 3:
                printf("Enter new phone: ");
                scanf("%d",&upd.phone);
                fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t880%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,upd.phone,add.address,add.money);
                
                break;
                
                case 4:
                printf("Enter amount to add: ");
                scanf("%d",&upd.money);
                fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,(add.money+upd.money));
            }
        }
        else
        {
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,add.money);
        }
    }
    fclose(old);
    fclose(new);
    remove("user.txt");
    rename("new.txt","user.txt");
    
}


void staff_list()
{
    system("cls");
    FILE *list;
    list=fopen("staff.txt","r");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    
    printf("| %-10s | %-15s | %-15s | %-10s | %-3s | %-15s | %-15s | %-15s |\n","Account No", "First Name", "Last Name", "PIN", "Age", "DOB", "Phone", "Address");
    
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");

    while(fscanf(list,"%d %s %s %d %d %s %lld %s",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address)!=EOF)
    {
        printf("| %-10d | %-15s | %-15s | %-10d | %-3d | %-15s | %-15lld | %-15s |\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address);
        printf("\n");
    }
    fclose(list);
    exit:
    printf("Enter 0 to return to admin menu: ");
    int choice;
    scanf("%d",&choice);
    if(choice==0)
    {
        admin_menu();
    }

    else
    {
        goto exit;
    }
}


void user_list()
{
    system("cls");
    FILE *list;
    list=fopen("user.txt","r");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    
    printf("| %-10s | %-15s | %-15s | %-10s | %-3s | %-15s | %-15s | %-15s | %-10s |\n","Account No", "First Name", "Last Name", "PIN", "Age", "DOB", "Phone", "Address", "Balance");
    
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");

    while(fscanf(list,"%d %s %s %d %d %s %lld %s %d",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address,&add.money)!=EOF)
    {
        printf("| %-10d | %-15s | %-15s | %-10d | %-3d | %-15s | %-15lld | %-15s | %-10d |\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,add.money);
        printf("\n");
    }
    fclose(list);
    
}

void check_balance()
{
   system("cls");
   FILE *fptr;
   fptr=fopen("user.txt","r");
   int check_user_acc;
   printf("Enter your account number: ");
   scanf("%d",&check_user_acc);
   while(fscanf(fptr,"%d %s %s %d %d %s %lld %s %d",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address,&add.money)!=EOF)
   {
        if(check_user_acc==add.acc)
        {
            printf("\nYour balance is:%d\n\n",add.money);
        }
   }
   fclose(fptr);
   exit:
   printf("Enter 0 to goto user menu: ");
   int go;
   scanf("%d",&go);
   if(go==0)
   {
        user_menu();
   }
   else
   {
        goto exit;
   }
}


void deposits()
{
    system("cls");
    FILE *old,*new;
    old=fopen("user.txt","r");
    new=fopen("new.txt","w");
    printf("Enter account number: ");
    scanf("%d",&upd.acc);
    while(fscanf(old,"%d %s %s %d %d %s %lld %s %d",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address,&add.money)!=EOF)
    {
        if(add.acc==upd.acc)
        {
           
            printf("Enter amount to add: ");
            scanf("%d",&upd.money);
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,(add.money+upd.money));
            
            FILE *h;
            h=fopen("history.txt","a+");
            fprintf(h,"%d\tCr\t%d\t%d\n",add.acc,upd.money,add.acc);
            fclose(h);
            
        }
        else
        {
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,add.money);
        }
    }
    fclose(old);
    fclose(new);
    remove("user.txt");
    rename("new.txt","user.txt");
    printf("Deposits copmleted\n");
    loading();
    user_menu();
}

void withdraw()
{
    system("cls");
    FILE *old,*new;
    old=fopen("user.txt","r");
    new=fopen("new.txt","w");
    printf("Enter account number: ");
    scanf("%d",&upd.acc);
    while(fscanf(old,"%d %s %s %d %d %s %lld %s %d",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address,&add.money)!=EOF)
    {
        if(add.acc==upd.acc)
        {
           
            int with;
            printf("Enter withdrawl amount: ");
            scanf("%d",&with);
            if(add.money<with)
            {
                printf("Insufficient balance");
            }
            else
            {
                fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,(add.money-with));
                FILE *h;
                h=fopen("history.txt","a+");
                fprintf(h,"%d\tDr\t%d\t%d\n",add.acc,with,add.acc);
                fclose(h);
            }
            
        }
        else
        {
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,add.money);
        }
    }
    fclose(old);
    fclose(new);
    remove("user.txt");
    rename("new.txt","user.txt");
    printf("Withdral completed\n");
    loading();
    user_menu();
}
void transfer_money()
{
    system("cls");
    int rec_acc;
    int tra_amount;
    FILE *old,*new;
    old=fopen("user.txt","r");
    new=fopen("new.txt","w");
    printf("Enter your account number: ");
    scanf("%d",&upd.acc);
    while(fscanf(old,"%d %s %s %d %d %s %lld %s %d",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address,&add.money)!=EOF)
    {
        if(add.acc==upd.acc)
        {
            printf("Enter recipient account number: ");
            scanf("%d",&rec_acc);
            printf("Enter transfer amount: ");
            scanf("%d",&tra_amount);
            if(add.money<tra_amount)
            {
                printf("Insufficient balance");
            }
            else
            {
                fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,(add.money-tra_amount));

                FILE *h;
                h=fopen("history.txt","a+");
                fprintf(h,"%d\tDr\t%d\t%d\n",add.acc,tra_amount,rec_acc);
                fprintf(h,"%d\tCr\t%d\t%d\n",rec_acc,tra_amount,add.acc);
                fclose(h);
            }
        }
        else
        {
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,add.money);
        }
    }
    fclose(old);
    fclose(new);
    remove("user.txt");
    rename("new.txt","user.txt");

    old=fopen("user.txt","r");
    new=fopen("new.txt","w");
    while(fscanf(old,"%d %s %s %d %d %s %lld %s %d",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address,&add.money)!=EOF)
    {
        if(add.acc==rec_acc)
        {
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,(add.money+tra_amount));
        }
        else
        {
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,add.money);
        }

    }
    fclose(old);
    fclose(new);
    remove("user.txt");
    rename("new.txt","user.txt");

    printf("Transfer completed\n");
    loading();
    user_menu();
}

void check_history()
{
    system("cls");
    FILE *h;
    int acc,amount,rec;
    char type[100];
    h=fopen("history.txt","r");
    printf("---------------------------------------------\n");
    
    printf("| %-10s | %-4s | %-10s | %-8s |\n","Account No", "Type", "Amount", "From/To");
    
    printf("---------------------------------------------\n");

    while(fscanf(h,"%d %s %d %d",&acc,type,&amount,&rec)!=EOF)
    {
        printf("| %-10d | %-4s | %-10d | %-8d |\n",acc,type,amount,rec);
        printf("\n");
    }
    fclose(h);
}

void check_your_history()
{
    system("cls");
    int che_acc;
    printf("Enter account number: ");
    scanf("%d",&che_acc);
    system("cls");
    FILE *h;
    int acc,amount,rec;
    char type[100];
    h=fopen("history.txt","r");
    printf("---------------------------------------------\n");
    
    printf("| %-10s | %-4s | %-10s | %-8s |\n","Account No", "Type", "Amount", "From/To");
    
    printf("---------------------------------------------\n");

    while(fscanf(h,"%d %s %d %d",&acc,type,&amount,&rec)!=EOF)
    {
        if(acc==che_acc)
        {
            printf("| %-10d | %-4s | %-10d | %-8d |\n",acc,type,amount,rec);
            printf("\n");
        }
    }
    fclose(h);

}


void delete_staff()
{
    system("cls");
    int del;
    printf("Enter account number for delete: ");
    scanf("%d",&del);
    FILE *old,*new;
    old=fopen("staff.txt","r");
    new=fopen("new.txt","w");
    while(fscanf(old,"%d %s %s %d %d %s %lld %s",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address)!=EOF)
    {
        if(add.acc==del)
        {
            continue;
        }
        else
        {
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address);
        }
    }
    fclose(old);
    fclose(new);
    remove("staff.txt");
    rename("new.txt","staff.txt");
    admin_menu();
}



void delete_user()
{
    system("cls");
    int del;
    printf("Enter account number for delete: ");
    scanf("%d",&del);
    FILE *old,*new;
    old=fopen("user.txt","r");
    new=fopen("new.txt","w");
    while(fscanf(old,"%d %s %s %d %d %s %lld %s %d",&add.acc,add.frist_name,add.last_name,&add.pin,&add.age,add.dob,&add.phone,add.address,&add.money)!=EOF)
    {
        if(add.acc==del)
        {
            continue;
        }
        else
        {
            fprintf(new,"%d\t\t%s %s\t\t%d\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\n",add.acc,add.frist_name,add.last_name,add.pin,add.age,add.dob,add.phone,add.address,add.money);
        }
    }
    fclose(old);
    fclose(new);
    remove("user.txt");
    rename("new.txt","user.txt");
}
