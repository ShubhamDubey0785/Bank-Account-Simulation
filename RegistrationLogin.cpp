#include<bits/stdc++.h>
using namespace std;
class User{
    private:
    string username, password;
    double balance;
    public:
    User(string name, string pass, double amount){
        username = name;
        password = pass;
        balance = amount;
    }
    string getUsername(){
        return username;
    }
    string getPassword(){
        return password;
    }
    double getAmount(){
        return balance;
    }
    void deposit(double amt){
        balance+=amt;
    }
    void withdraw(double amt){
        balance-=amt;
    }

};
class UserManager{
    private:
        vector<User>users; // create object of vector
    public:
    void RegisterUser(){
        string username, password;
        double amount;
        cout<<"\t\tEnter user name: ";
        cin>>username;
        cout<<"\t\tEnter user password: ";
        cin>>password;
        cout<<"Initial Amount Deposit: ";
        cin>>amount;
        User newUser(username, password, amount);
        users.push_back(newUser);
        cout<<"\t\t User registration Successfully......."<<endl;
    }
    bool LoginUser(string &name, string &pass){
        for(int i=0; i<users.size(); i++){
            if(users[i].getUsername()==name && users[i].getPassword()==pass){
                cout<<"\t\tLogin successfully..."<<endl;
                return true;
            }
        }
        cout<<"\tInvalid User Name or Password..."<<endl;
        return false;
    }
    void showList(){
        cout<<"\t\t---Users List---"<<endl;
        for(int i=0; i<users.size(); i++){
            cout<<"\t\t"<<users[i].getUsername()<<" \n";
        }
        cout<<endl;
    }
    void searchUser(string &username){
        for(int i=0; i<users.size(); i++){
            if(users[i].getUsername()==username){
                cout<<"\t\t User Found"<<endl;
                return;
            }
        }
        cout<<"\t\tUser not found"<<endl;
    }
    void deleteUser(string &username, string &password){
        for(int i=0; i<users.size(); i++){
            if(users[i].getUsername()==username && users[i].getPassword()==password){
                users.erase(users.begin()+i);
                cout<<"\t\tUser remove successfully.."<<endl;
                return;
            }
        }
        cout<<"\t\tEnter correct username and password.."<<endl;
    }
    void viewAmount(string &username, string &password){
        for(int i=0; i<users.size(); i++){
            if(users[i].getUsername()==username && users[i].getPassword()==password){
                cout<<"User name: "<<users[i].getUsername()<<endl;
                cout<<"Present Amount: "<<users[i].getAmount()<<endl;
                return;
            }
        }
        cout<<"Invalid username or password try again..."<<endl;
    }
    void depositAmount(string &username, string &password, double &amount){
        for(int i=0; i<users.size(); i++){
            if(users[i].getUsername()==username && users[i].getPassword()==password){
                users[i].deposit(amount);
                cout<<"Amount added successfully\n";
                return;
            }
        }
        cout<<"Invalid username or password try again..."<<endl;
    }
    void withdrawAmount(string &username, string &password, double &amount){
        for(int i=0; i<users.size(); i++){
            if(users[i].getUsername()==username && users[i].getPassword()==password){
                if(users[i].getAmount()>=amount){
                    users[i].withdraw(amount);
                    cout<<"Amount withdraw successfully\n";
                }else{
                    cout<<"Invalid amount\n";
                }
                return;
            }
        }
        cout<<"Invalid username or password try again..."<<endl;
    }
    void sendMoney(string &username, string &password, string &accountHolderName, double &amount){
        for(int i=0; i<users.size(); i++){
            if(users[i].getUsername()==username && users[i].getPassword()==password){
                for(int j=0; j<users.size(); j++){
                    if(users[j].getUsername()==accountHolderName){
                        if(users[i].getAmount()>=amount){
                            users[i].withdraw(amount);
                            users[j].deposit(amount);
                            cout<<"Amount deposit to account: "<<users[j].getUsername()<<" successfully"<<endl;
                            return;
                        }else{
                            cout<<"Invalid amount...\n";
                        }
                    }
                }
                cout<<"Account Holder not found.."<<endl;
            }
        }
        cout<<"User not found..\n";
    }
    void calculateInterest(string &username, string &pass, int &year){
        for(int i=0; i<users.size(); i++){
            if(users[i].getUsername()==username && users[i].getPassword()==pass){
                int P=users[i].getAmount();
                int interest = P*(pow(1+4.0/100, year))-P;
                cout<<"Interest amount after "<<year<<" year is "<<interest<<" and total amount is: "<<interest+users[i].getAmount()<<endl;
                return;
            }
        }
    }
};
int main(){
    UserManager usermanage;
    int op;
    char choice;
    do{
        system("cls");
        cout<<"\n\n\t\t1. Register User"<<endl;
        cout<<"\t\t2. Login"<<endl;
        cout<<"\t\t3. Show user List: "<<endl;
        cout<<"\t\t4. Search User: "<<endl;
        cout<<"\t\t5. Delete User: "<<endl;
        cout<<"\t\t6. View Amount: "<<endl;
        cout<<"\t\t7. Deposit Amount: "<<endl;
        cout<<"\t\t8. Withdrawl Amount: "<<endl;
        cout<<"\t\t9. Send Money: "<<endl;
        cout<<"\t\t10. Interest Calculation: "<<endl;
        cout<<"\t\t11. Exit: "<<endl;
        cout<<"\t\tEnter Your choice: ";
        cin>>op;
        switch(op){
            case 1:{
                usermanage.RegisterUser();
                break;
            }
            case 2:{
                string username, password;
                cout<<"\t\tEnter User: ";
                cin>>username;
                cout<<"\t\tEnter Password: ";
                cin>>password;
                usermanage.LoginUser(username, password);
                break;
            }
            case 3:{
                usermanage.showList();
                break;
            }
            case 4:{
                string username;
                cout<<"Enter user name: ";
                cin>>username;
                usermanage.searchUser(username);
                break;
            }
            case 5:{
                string username, password;
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter user password: ";
                cin>>password;
                usermanage.deleteUser(username, password);
                break;
            }
            case 6:{
                string username, password;
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter user password: ";
                cin>>password;
                usermanage.viewAmount(username, password);
                break;
            }
            case 7:{
                string username, password;
                double amount;
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter user password: ";
                cin>>password;
                cout<<"Enter amount: ";
                cin>>amount;
                usermanage.depositAmount(username, password, amount);
                break;
            }
            case 8:{
                string username, password;
                double amount;
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter user password: ";
                cin>>password;
                cout<<"Enter amount: ";
                cin>>amount;
                usermanage.withdrawAmount(username, password, amount);
                break;
            }
            case 9:{
                string username, password, accountHolder;
                double amount;
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter user password: ";
                cin>>password;
                cout<<"Enter acccountHolder: ";
                cin>>accountHolder;
                cout<<"Enter amount: ";
                cin>>amount;
                usermanage.sendMoney(username, password, accountHolder, amount);
                break;
            }
            case 10:{
                string username, password;
                int year;
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter user password: ";
                cin>>password;
                cout<<"Enter the year for which you want to save your money in the account: ";
                cin>>year;
                usermanage.calculateInterest(username, password, year);
                break;
            }
            case 11:
                cout<<""<<endl;
                exit(1);
        }
        cout<<"Do you want to continue [Y/N] ? :";
        cin>>choice;
    }while(choice=='y' || choice=='Y');
    return 0;
}