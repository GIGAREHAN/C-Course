#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define MAX_TRANS 10

struct Account {
    int accNo;
    char name[50];
    char password[20];
    float balance;

    float loanAmount;
    float emi;
    int loanActive;

    int locked;
    int wrongAttempts;

    char transactions[MAX_TRANS][100];
    int transCount;
};

struct Account users[MAX];
int totalUsers = 5;

/* ================= INITIAL USERS ================= */

void loadInitialUsers() {
    users[0] = (struct Account){1001,"Rahul","1111",50000,0,0,0,0,0,{},0};
    users[1] = (struct Account){1002,"Priya","2222",40000,20000,2000,1,0,0,{},0};
    users[2] = (struct Account){1003,"Amit","3333",60000,0,0,0,0,0,{},0};
    users[3] = (struct Account){1004,"Sneha","4444",30000,15000,1500,1,0,0,{},0};
    users[4] = (struct Account){1005,"Karan","5555",70000,0,0,0,0,0,{},0};
}

/* ================= UTILITIES ================= */

void line() {
    printf("\n====================================================\n");
}

void addTransaction(struct Account *u, char msg[]) {
    if(u->transCount < MAX_TRANS) {
        strcpy(u->transactions[u->transCount], msg);
        u->transCount++;
    }
}

int findUser(int accNo) {
    for(int i=0;i<totalUsers;i++)
        if(users[i].accNo == accNo)
            return i;
    return -1;
}

/* ================= USER FEATURES ================= */

void withdraw(struct Account *u) {
    float amt;
    printf("Enter Amount to Withdraw: ");
    scanf("%f",&amt);

    if(amt <=0 || amt > u->balance) {
        printf("Invalid / Insufficient Balance!\n");
        return;
    }

    u->balance -= amt;

    char msg[100];
    sprintf(msg,"Withdrawn: %.2f",amt);
    addTransaction(u,msg);

    printf("Withdrawal Successful!\n");
}

/* ================= LOAN ================= */

void applyLoan(struct Account *u) {

    if(u->loanActive) {
        printf("Loan Already Active!\n");
        return;
    }

    float amt;
    printf("Enter Loan Amount: ");
    scanf("%f",&amt);

    if(amt > u->balance * 2) {
        printf("Loan Rejected! (Max 2x Balance Allowed)\n");
        return;
    }

    u->loanAmount = amt;
    u->emi = (amt/10) + (amt*0.05);
    u->loanActive = 1;

    char msg[100];
    sprintf(msg,"Loan Approved: %.2f",amt);
    addTransaction(u,msg);

    printf("Loan Approved!\nEMI: %.2f\n",u->emi);
}

void payEMI(struct Account *u) {

    if(!u->loanActive) {
        printf("No Active Loan!\n");
        return;
    }

    if(u->balance < u->emi) {
        printf("Insufficient Balance!\n");
        return;
    }

    u->balance -= u->emi;
    u->loanAmount -= u->emi;

    char msg[100];
    sprintf(msg,"EMI Paid: %.2f",u->emi);
    addTransaction(u,msg);

    printf("EMI Paid Successfully!\n");

    if(u->loanAmount <= 0) {
        u->loanActive = 0;
        printf("Loan Fully Repaid!\n");
    }
}

void showHistory(struct Account *u) {
    line();
    printf("Transaction History:\n");

    for(int i=0;i<u->transCount;i++)
        printf("%d. %s\n",i+1,u->transactions[i]);

    if(u->transCount==0)
        printf("No Transactions Yet.\n");
}

/* ================= USER LOGIN ================= */

void userDashboard(int index) {

    struct Account *u = &users[index];
    int choice;

    do {
        line();
        printf("Welcome %s\n",u->name);
        printf("Balance: %.2f\n",u->balance);
        line();
        printf("1. Withdraw\n");
        printf("2. Apply Loan\n");
        printf("3. Pay EMI\n");
        printf("4. Transaction History\n");
        printf("5. Logout\n");
        line();
        printf("Choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: withdraw(u); break;
            case 2: applyLoan(u); break;
            case 3: payEMI(u); break;
            case 4: showHistory(u); break;
            case 5: printf("Logged Out!\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while(choice!=5);
}

void login() {

    int accNo;
    char pass[20];

    printf("Enter Account Number: ");
    scanf("%d",&accNo);

    int index = findUser(accNo);

    if(index==-1) {
        printf("Account Not Found!\n");
        return;
    }

    if(users[index].locked) {
        printf("Account Locked!\n");
        return;
    }

    printf("Enter Password: ");
    scanf("%s",pass);

    if(strcmp(users[index].password,pass)==0) {
        users[index].wrongAttempts=0;
        userDashboard(index);
    } else {
        users[index].wrongAttempts++;
        printf("Wrong Password!\n");

        if(users[index].wrongAttempts>=3) {
            users[index].locked=1;
            printf("Account Locked due to 3 wrong attempts!\n");
        }
    }
}

/* ================= ADMIN ================= */

void adminDeposit() {

    int accNo;
    float amt;

    printf("Enter Account Number: ");
    scanf("%d",&accNo);

    int index = findUser(accNo);

    if(index==-1) {
        printf("Account Not Found!\n");
        return;
    }

    printf("Enter Amount to Deposit: ");
    scanf("%f",&amt);

    if(amt<=0) {
        printf("Invalid Amount!\n");
        return;
    }

    users[index].balance += amt;

    char msg[100];
    sprintf(msg,"Deposited by Admin: %.2f",amt);
    addTransaction(&users[index],msg);

    printf("Deposit Successful!\n");
}

void createAccount() {

    if(totalUsers>=MAX) {
        printf("User Limit Reached!\n");
        return;
    }

    struct Account newUser;

    printf("Enter 4-digit Account Number: ");
    scanf("%d",&newUser.accNo);

    if(findUser(newUser.accNo)!=-1) {
        printf("Account Already Exists!\n");
        return;
    }

    printf("Enter Name: ");
    scanf("%s",newUser.name);

    printf("Set Password: ");
    scanf("%s",newUser.password);

    printf("Enter Initial Balance: ");
    scanf("%f",&newUser.balance);

    newUser.loanActive=0;
    newUser.loanAmount=0;
    newUser.emi=0;
    newUser.locked=0;
    newUser.wrongAttempts=0;
    newUser.transCount=0;

    users[totalUsers++] = newUser;

    printf("Account Created Successfully!\n");
}

void adminDashboard() {

    int choice;

    do {
        line();
        printf("ADMIN PANEL\n");
        line();
        printf("1. View All Accounts\n");
        printf("2. Deposit to Account\n");
        printf("3. Total Bank Balance\n");
        printf("4. Total Loan Issued\n");
        printf("5. Loan Deposit Ratio\n");
        printf("6. New User Registration\n");
        printf("7. Logout\n");
        line();
        printf("Choice: ");
        scanf("%d",&choice);

        float totalBalance=0,totalLoan=0;

        for(int i=0;i<totalUsers;i++) {
            totalBalance+=users[i].balance;
            totalLoan+=users[i].loanAmount;
        }

        switch(choice) {

            case 1:
                for(int i=0;i<totalUsers;i++)
                    printf("Acc:%d | %s | Balance: %.2f | Loan: %.2f\n",
                    users[i].accNo,users[i].name,
                    users[i].balance,users[i].loanAmount);
                break;

            case 2: adminDeposit(); break;
            case 3: printf("Total Balance: %.2f\n",totalBalance); break;
            case 4: printf("Total Loan Issued: %.2f\n",totalLoan); break;
            case 5:
                if(totalBalance>0)
                    printf("Loan Deposit Ratio: %.2f%%\n",(totalLoan/totalBalance)*100);
                else
                    printf("No Deposits!\n");
                break;
            case 6: createAccount(); break;
            case 7: printf("Admin Logged Out!\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while(choice!=7);
}

void adminLogin() {

    char id[20],pass[20];

    printf("Enter Admin ID: ");
    scanf("%s",id);

    printf("Enter Admin Password: ");
    scanf("%s",pass);

    if(strcmp(id,"admin")==0 && strcmp(pass,"admin123")==0)
        adminDashboard();
    else
        printf("Invalid Credentials!\n");
}

/* ================= MAIN ================= */

int main() {

    loadInitialUsers();

    int choice;

    do {
        line();
        printf("BANK MANAGEMENT SYSTEM\n");
        line();
        printf("1. User Login\n");
        printf("2. Admin Login\n");
        printf("3. Exit\n");
        line();
        printf("Choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: login(); break;
            case 2: adminLogin(); break;
            case 3: printf("Thank You!\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while(choice!=3);

    return 0;
}
