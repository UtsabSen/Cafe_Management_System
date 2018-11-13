#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<fstream>
#include<conio.h>
#include<windows.h>
using namespace std;

class login
{

public:
    string my_file,username,filename,change_pass;
    int trigger_logged_in=0,trigger_registration=0,trigger_A=0,i,lock=0;

    void user_name()
    {
        system ("cls");
        system("color 02");
        cout<<"\nLOG IN:\n";
        cout<<"\nEnter username: ";
        cin>>ws;
        getline(cin,username);
        my_file=username+"_details.txt";
        change_pass=username+"_pass.txt";
        pass_word();

    }
    void pass_word()
    {
        string password;
        char ch;
        int p;
        filename=username+"_pass.txt";

        ifstream file;
        file.open(filename.c_str());
        string passcode;
        getline(file,passcode);

        file.close();

        if(file==NULL)
        {
            Beep(800,250);
            cout<<"\nYou've not registered yet"<<endl<<"At first register\n";
            trigger_registration=1;
        }
        else
        {
            cout<<"Enter Password: ";
            ch= _getch();
            while(ch!=13)
            {
                password.push_back(ch);
                cout<<'*';
                ch=_getch();
            }

            if(password==passcode)
            {
                system("cls");
                cout<<"\nLogging in";
                Sleep(1000);
                for(i=0;i<3;i++)
                {
                    cout<<".";
                    Beep(1200,50);
                Sleep(1000);
                }
                    Beep(1500,50);
                cout<<"\nYou're successfully logged in...\n";
                password.clear();
                Sleep(1000);
                system("cls");
                trigger_logged_in=1;
            }
            else
            {
                lock++;
                Beep(800,250);
                cout<<"\n\nWrong Password\n";
                if(lock==3)
                {
                    lock=0;
                    cout<<"\nYou've entered wrong password 3 times\n";
                    Sleep(2000);
                    system("cls");
                    for(i=5;i>=0;i--)
                    {
                        cout<<"\nWait for "<<i<<" seconds...";
                        Beep(1200,50);
                        Sleep(1000);
                        system("cls");
                    }
                }
                cout<<"\n1. Try Again\n2. Back\n";
                password.clear();
                cin>>p;
                if(p==1)
                {
                    user_name();
                }
                else if(p==2)
                {
                    lock=0;
                    trigger_A=1;
                }
                else
                {
                    lock=0;
                    Beep(800,250);
                    cout<<"\n\nYou must log in first\n";
                    trigger_A=1;
                }

            }
        }
    }
};

class registration
{


    string user_full_name,filedetails,user_name,email,id,phone,pass,userpass,usercheck;
public:
    char ch;
    int i;

    int trigger_main=0;
    void user_details_in()
    {
        system("cls");
        system("color 02");
        cout<<"\nREGISTRATION:\n";

        cout<< "\nEnter username: ";
        cin>>ws;
        getline(cin,user_name);
        filedetails=user_name+"_details.txt";
        usercheck=user_name+"_pass.txt";

        ifstream file0;
        file0.open(filedetails.c_str());
        if(file0!=NULL)
        {
            Beep(800,250);
            cout<<"\nUsername already taken\n";
            Sleep(2000);
            file0.close();
            user_details_in();
        }
        else
        {
        cout<< "Enter your full name: ";
        getline(cin,user_full_name);
        cout<< "Enter email: ";
        getline(cin,email);
        cout<< "Enter phone number: ";
        getline(cin,phone);
        cout<< "Enter new password: ";
//        getline(cin,pass);
        ch= _getch();
            while(ch!=13)
            {
                pass.push_back(ch);
                cout<<'*';
                ch=_getch();
            }


        userpass=user_name+"_pass.txt";
        id=user_name+"_id.txt";

        ofstream file1,file2,file3;
        file1.open(filedetails.c_str());
        {
            file1<<"Name: "<<user_full_name<<endl<<"Username: "<<user_name<<endl<<"Email: "<<email<<endl<<"Phone No: "<<phone;
        }
        file1.close();
        file2.open(userpass.c_str());
        {
            file2<<pass;
        }
        file2.close();
        file3.open(id.c_str());
        {
            file3<<email;
        }
        file3.close();
        Beep(1500,200);

        cout<<"\n\nYour registration is successful.\nYou can Log In with your new account.\n";
        cout<<"\nPlease Wait. Taking you to the main page";
        Sleep(1000);
        for(i=0;i<3;i++)
            {
                cout<<".";
                Beep(1200,50);
                Sleep(1000);
            }
        pass.clear();
        trigger_main=1;
        }
    }
};

class forget_password
{
    string id_1,id_2,new_pass,username,filename_id,filename_pass;
public:
    char ch;
    int trigger_main=0;
    void forget_username()
    {
        system("cls");
        system("color 02");
        cout<<"\nFORGOT PASSWORD:\n";
        cout<<"\nEnter your username: ";
        cin>>ws;
        getline(cin,username);
        filename_id=username+"_id.txt";
        filename_pass=username+"_pass.txt";
        id();
    }
    void id()
    {
        ifstream file1;
        file1.open(filename_id.c_str());
        getline(file1,id_2);


        if (file1==NULL)
        {
            Beep(800,250);
            cout<<"username doesnot exists.";
        }
        else
        {
            cout<<"Enter your email id: ";
            getline(cin,id_1);
            if(id_1==id_2)
            {
                cout<<"Enter new password: ";
 //               getline(cin,new_pass);
            ch= _getch();
            while(ch!=13)
            {
                new_pass.push_back(ch);
                cout<<'*';
                ch=_getch();
            }
                ofstream file2;
                file2.open(filename_pass.c_str());
                file2<<new_pass;
                file2.close();
                Beep(1500,50);
                cout<<"\n\nPassword changed successfully...\nYou must log in with your new password.\n";
                Sleep(2000);
                new_pass.clear();
                trigger_main=1;
            }
            else
            {
                Beep(800,250);
                cout<<"\nThis email did not registered with this account.\n";
                Sleep(1000);
                trigger_main=1;
            }
        }

    }
};

class member_entry
{
    string member,date,time,show,comment,empt;
    int check,mem_no,i;
public:
    int trigger_member_entry=0;
    void add_new_member()
    {
        cout<<"\nEnter how many members do you want to enter: ";
        cin>>ws;
        cin>>mem_no;
        if(mem_no>0)
        {
        cout<<"Enter date(dd/mm/yyyy): ";
        cin>>ws;
        getline(cin,date);
        cout<<"Enter time(hh:mm AM/PM): ";
        getline(cin,time);
        cout<<"\n";

        ifstream file0;
        file0.open("members.txt");
        getline(file0,empt);
        file0.close();
        if(empt!="EMPTY")
        {
            empt.clear();
        std::fstream file1;
        file1.open("members.txt",std::fstream::in|std::fstream::app);
        file1<<date<<"\t"<<time<<endl;
        cout<<"\nEnter new member name(s): ";
        for(i=0;i<mem_no;i++)
        {
            getline(cin,member);
            file1<<"\t"<<member<<endl;
        }
        file1.close();

        ifstream file2;
        file2.open("members.txt");
         while (!file2.eof())
        {
            getline(file2,show);
            cout<<show<<endl;
        }
        file2.close();
        getch();
        }
        else
        {
            empt.clear();
        ofstream file1;
        file1.open("members.txt");
        file1<<date<<"\t"<<time<<endl;
        cout<<"\nEnter new member name(s): ";
        for(i=0;i<mem_no;i++)
        {
            getline(cin,member);
            file1<<"\t"<<member<<endl;
        }
        file1.close();

        ifstream file2;
        file2.open("members.txt");
         while (!file2.eof())
        {
            getline(file2,show);
            cout<<show<<endl;
        }
        file2.close();
        getch();
        }
        }
        else
        {
            trigger_member_entry=1;
        }
    }

    void show_member()
    {
        ifstream file3;
        file3.open("members.txt");
        if(file3==NULL)
        {
            Beep(800,250);
            cout<<"\nAt first add atleast one member\n";
            trigger_member_entry=1;

        }
        else
        {
         while (!file3.eof())
        {
            getline(file3,show);
            cout<<show<<endl;
        }
        file3.close();
        }
        getch();
    }

    void update()
    {
        ifstream file;
        file.open("members.txt");
        getline(file,empt);
        file.close();
        if(empt!="EMPTY")
        {
        cout<<"\nEnter any comments: ";
        cin>>ws;
        getline(cin,comment);

        std::fstream file4;
        file4.open("members.txt",std::fstream::in|std::fstream::app);
        file4<<endl<<comment<<endl;
        file4.close();
        }
        else
        {
        cout<<"\nEnter any comments: ";
        cin>>ws;
        getline(cin,comment);

        ofstream file4;
        file4.open("members.txt");
        file4<<endl<<comment<<endl;
        file4.close();
        }
    }

    void del()
    {
        Beep(800,250);
        cout<<"\nDo you really want to delete recorded file?\n1. Yes\n2. No\n";
        cin>>ws;
        cin>>check;
        if(check==1)
        {
            ofstream file5;
            file5.open("members.txt");
            file5<<"EMPTY";
            file5.close();
            Beep(1500,50);
            cout<<"\nYour file has been deleted.\n";
            getch();
        }
        else if(check==2)
        {
            cout<<"\nFile delete canceled\n";
            getch();
        }
        else
        {
            del();
        }
    }
};

class computer_entry
{
    string computer,user,date,time,show,comment,empt;
    int check,comp_no,i;
public:
    int trigger_computer_entry=0;
    void add_new_computer()
    {
        cout<<"\nEnter how many members do you want to enter:";
        cin>>ws;
        cin>>comp_no;
        if(comp_no>0)
        {
        cout<<"Enter date(dd/mm/yyyy): ";
        cin>>ws;
        getline(cin,date);
        cout<<"Enter time(hh:mm AM/PM): ";
        getline(cin,time);

        ifstream file0;
        file0.open("computers.txt");
        getline(file0,empt);
        file0.close();

        if(empt!="EMPTY")
        {
            empt.clear();
        std::fstream file1;
        file1.open("computers.txt",std::fstream::in|std::fstream::app);
        file1<<date<<"\t"<<time<<endl;

        for(i=0;i<comp_no;i++)
        {
            cout<<"\nEnter new member name: ";
            getline(cin,user);
            cout<<"\nEnter alloted computer name: ";
            getline(cin,computer);
            file1<<"\t"<<user<<" is alloted with "<<computer<<" computer."<<endl;
        }
        file1.close();

        ifstream file2;
        file2.open("computers.txt");
         while (!file2.eof())
        {
            getline(file2,show);
            cout<<show<<endl;
        }
        file2.close();
        getch();
        }
        else
        {
            empt.clear();
         ofstream file1;
        file1.open("computers.txt");
        file1<<date<<"\t"<<time<<endl;

        for(i=0;i<comp_no;i++)
        {
            cout<<"\nEnter new member name: ";
            getline(cin,user);
            cout<<"\nEnter alloted computer name: ";
            getline(cin,computer);
            file1<<"\t"<<user<<" is alloted with "<<computer<<" computer."<<endl;
        }
        file1.close();

        ifstream file2;
        file2.open("computers.txt");
         while (!file2.eof())
        {
            getline(file2,show);
            cout<<show<<endl;
        }
        file2.close();
        getch();
        }
    }
    else
    {
        trigger_computer_entry=1;
    }
    }

    void show_computer()
    {
        ifstream file3;
        file3.open("computers.txt");
        if(file3==NULL)
        {
            Beep(800,250);
            cout<<"\nAt first add atleast one member alloted with a computer\n";
            trigger_computer_entry=1;
        }
        else
        {
         while (!file3.eof())
        {
            getline(file3,show);
            cout<<show<<endl;
        }
        file3.close();
        }
        getch();
    }

    void update()
    {
        ifstream file;
        file.open("computers.txt");
        getline(file,empt);
        file.close();
        if(empt!="EMPTY")
        {
            empt.clear();
        cout<<"\nEnter any comments: ";
        cin>>ws;
        getline(cin,comment);

        std::fstream file4;
        file4.open("computers.txt",std::fstream::in|std::fstream::app);
        file4<<endl<<comment<<endl;
        file4.close();
        }
        else
        {
            empt.clear();
            cout<<"\nEnter any comments: ";
        cin>>ws;
        getline(cin,comment);

        ofstream file4;
        file4.open("computers.txt");
        file4<<endl<<comment<<endl;
        file4.close();
        }
    }

    void del()
    {
        Beep(800,250);
        cout<<"\nDo you really want to delete recorded file?\n1. Yes\n2. No\n";
        cin>>ws;
        cin>>check;
        if(check==1)
        {
            ofstream file5;
            file5.open("computers.txt");
            file5<<"EMPTY";
            file5.close();
            Beep(1500,50);
            cout<<"\nYour file has been deleted.\n";
            getch();
        }
        else if(check==2)
        {
            cout<<"\nFile delete canceled\n";
            getch();
        }
        else
        {
            del();
        }
    }
};

class member_booking
{
    string username,filename,usercheck,user_name,userpass,filedetails,member_full_name,nonmember_full_name,email,phone,pass;
public:
    char ch;
    int trigger_booking=0,t,u,flag=0,flag1=0,i,flag3=0;
    void member_login()
    {
        system("cls");
        system("color 02");
        cout<<"MEMBER LOG IN:\n";
        cout<<"\nEnter username: ";
        cin>>ws;
        getline(cin,username);
        member_pass_word();

    }
    void member_pass_word()
    {
        string password;
        filename=username+"_member_pass.txt";

        ifstream file;
        file.open(filename.c_str());
        string passcode;
        getline(file,passcode);

        file.close();

        if(file==NULL)
        {
            Beep(800,250);
            cout<<"\nYou've not registered yet"<<endl<<"At first register\n";
            cout<<"\n1. Register now\n2. Login with other account\n3. Back\n";
            cin>>t;
            if(t==1)
            {
                member_details_in();
            }
            else if(t==2)
            {
                member_login();
            }
            else
            {
                trigger_booking=1;
            }

        }
        else
        {
            cout<<"Enter Password: ";
            //getline(cin,password);
            ch= _getch();
            while(ch!=13)
            {
                password.push_back(ch);
                cout<<'*';
                ch=_getch();
            }
            if(password==passcode)
            {
                system("cls");
                cout<<"\nLogging in";
                Sleep(1000);
                for(i=0;i<3;i++)
                {
                    cout<<".";
                    Beep(1200,50);
                    Sleep(1000);
                }
                Beep(1500,50);
                cout<<"\nYou're successfully logged in...";
                password.clear();
                Sleep(1000);
                flag=1;
                trigger_booking=1;

            }
            else
            {
                Beep(800,250);
                cout<<"\nWrong Password\n1. Try Again\n2. Back\n";
                password.clear();
                cin>>i;
                if(i==1)
                {
                    member_login();
                }
                else if(i==2)
                {
                    trigger_booking=1;
                }
                else
                {
                    cout<<"\nYou must log in with your correct password.\n";
                    trigger_booking=1;
                    getch();
                }


            }
        }
    }

    void member_details_in()
    {
        system("cls");
        cout<<"\nMEMBER REGISTRATION:\n";
        cout<< "\nEnter username: ";
        cin>>ws;
        getline(cin,user_name);
        filedetails=user_name+"_member_details.txt";
        usercheck=user_name+"_member_pass.txt";

        ifstream file0;
        file0.open(filedetails.c_str());
        if(file0!=NULL)
        {
            Beep(800,250);
            cout<<"Username already taken\n";
            file0.close();
            member_details_in();
        }
        else
        {
        cout<< "Enter your full name: ";
        getline(cin,member_full_name);
        cout<< "Enter email: ";
        getline(cin,email);
        cout<< "Enter phone number: ";
        getline(cin,phone);
        cout<< "Enter new password: ";
        //getline(cin,pass);
        ch=_getch();
        while(ch!=13)
        {
            pass.push_back(ch);
            cout<<'*';
            ch=_getch();
        }

        userpass=user_name+"_member_pass.txt";

        ofstream file1,file2;
        file1.open(filedetails.c_str());
        {
            file1<<"Name: "<<member_full_name<<endl<<"Username: "<<user_name<<endl<<"Email: "<<email<<endl<<"Phone No: "<<phone;
        }
        file1.close();
        file2.open(userpass.c_str());
        {
            file2<<pass;
        }
        file2.close();
        pass.clear();

        Beep(1500,50);
        cout<<"\nYour registration is successful.\nYou can Log In with your new account.\n\n";
        Sleep(2000);
        trigger_booking=1;
        }
    }
    void nonmember_login()
    {
        system("cls");
        system("color 02");
        cout<<"\nNON-MEMBER LOG IN:\n";
        cout<<"\nRgister and login\n";
        cout<<"\nEnter username: ";
        cin>>ws;
        getline(cin,username);
        nonmember_details_in();

    }

    void nonmember_details_in()
    {
        filedetails=username+"_nonmember_details.txt";

        cout<< "Enter your full name: ";
        getline(cin,nonmember_full_name);
        cout<< "Enter email: ";
        getline(cin,email);
        cout<< "Enter phone number: ";
        getline(cin,phone);
        cout<< "Enter new password: ";
      //  getline(cin,pass);
      ch=_getch();
      while(ch!=13)
      {
          pass.push_back(ch);
          cout<<'*';
          ch=_getch();
      }

        ofstream file1,file2;
        file1.open(filedetails.c_str());
        {
            file1<<"Name: "<<member_full_name<<endl<<"Username: "<<user_name<<endl<<"Email: "<<email<<endl<<"Phone No: "<<phone<<endl<<"Password: "<<pass;
        }
        file1.close();

        Beep(1500,50);
        cout<<"\nYour registration is successful.\n";
        Sleep(200);
        cout<<"\nLogging in";
        flag3=1;
        Sleep(1000);
        for(i=0;i<3;i++)
        {
            cout<<".";
            Beep(1200,50);
            Sleep(1000);
        }
        Beep(1500,50);
        cout<<"\nYou're successfully logged in...\n\n";
        pass.clear();
        Sleep(1000);
        flag1=1;
        trigger_booking=1;

    }

    void nonmember_del()
    {
        if(flag1==1)
        {
        system("cls");
        system("color 02");
        ofstream file1,file2;
        file1.open(filedetails.c_str());
        {
            file1<<"\0";
        }
        file1.close();
        file2.open(userpass.c_str());
        {
            file2<<"\0";
        }
        file2.close();
        cout<<"\nLogging out";
        Sleep(1000);
        for(i=0;i<3;i++)
        {
            cout<<".";
            Beep(1200,50);
            Sleep(1000);
        }
        Beep(1500,50);
        cout<<"\nYou're successfully logged out...\n";
        }
        Sleep(1000);
        flag1=0;
    }

};

class charge
{
    string username,date,time,show;
    float n,i,ammount,months;
public:
    int trigger_charge=0;
    void take_charges()
    {
        cout<<"\nTAKE CHARGES: \n";
        cout<<"\n\t-:Membership cost:-\nFor <=5 months per month rs. 150\nFor >5 and <=9 months per month rs. 130\nFor >9 months per month rs. 100";
        cout<<"\nEnter from how many members you want to take charges: ";
        cin>>ws;
        cin>>n;
        if(n>0)
        {
        cout<<"Enter date(dd/mm/yyyy): ";
        cin>>ws;
        getline(cin,date);
        cout<<"Enter time(hh:mm AM/PM): ";
        getline(cin,time);

        std::fstream file;
        file.open("charges.txt",std::fstream::in|std::fstream::app);
        file<<date<<"\t"<<time<<"\n";
        for(i=0;i<n;i++)
        {
            cout<<"Enter member name: ";
            cin>>ws;
            getline(cin,username);
            cout<<"Take charges for(in number of months): ";
            cin>>months;
            if(months<=5)
            {
                ammount=months*150;
            }
            else if(months>5 && months<=9)
            {
                ammount=months*130;
            }
            else if(months>9)
            {
                ammount=months*100;
            }
            file<<"\t"<<username<<" paid for "<<months<<" months from "<<date<<" and paid of rs. "<<ammount<<"\n";
        }
        file.close();
        cout<<"\n";
        ifstream file1;
        file1.open("charges.txt");
        while (!file1.eof())
        {
            getline(file1,show);
            cout<<show<<endl;
        }
        trigger_charge=1;
        getch();
        }
        else
        {
            trigger_charge=1;
        }

    }

    void show_charges()
    {
        cout<<"\nSHOWING CHARGES: \n";
        ifstream file3;
        file3.open("charges.txt");
        if(file3==NULL)
        {
            Beep(800,250);
            cout<<"\nAt first add atleast one charge from member\n";

        }
        else
        {
         while (!file3.eof())
        {
            getline(file3,show);
            cout<<show<<endl;
        }
        file3.close();
        }
        getch();
    }


};

class renew
{
    string username,date,time,show;
    float ammount,months,n,i;
public:
    int trigger_cafe_management=0;
    void renewal()
    {
        cout<<"\n\t-:Membership cost:-\nFor <=5 months per month rs. 150\nFor >5 and <=9 months per month rs. 130\nFor >9 months per month rs. 100";
        cout<<"\n\n\t\t10% discount on membership renewal\n";
        cout<<"\nEnter how many members you want to renew membership: ";
        cin>>ws;
        cin>>n;
        if(n>0)
        {
        cout<<"Enter date(dd/mm/yyyy): ";
        cin>>ws;
        getline(cin,date);
        cout<<"Enter time(hh:mm AM/PM): ";
        getline(cin,time);

        std::fstream file;
        file.open("renew.txt",std::fstream::in|std::fstream::app);
        file<<date<<"\t"<<time<<"\n";
        for(i=0;i<n;i++)
        {
            cout<<"Enter member name: ";
            cin>>ws;
            getline(cin,username);
            cout<<"Renew for(in number of months): ";
            cin>>months;
            if(months<=5)
            {
                ammount=months*150;
            }
            else if(months>5 && months<=9)
            {
                ammount=months*130;
            }
            else if(months>9)
            {
                ammount=months*100;
            }
            ammount=ammount-((ammount*10)/100);
            file<<"\t"<<username<<" extended membership for "<<months<<" months from "<<date<<" and paid of rs. "<<ammount<<"\n";
        }
        file.close();
        cout<<"\nSHOWING RENEWALS:\n";
        ifstream file1;
        file1.open("renew.txt");
        while (!file1.eof())
        {
            getline(file1,show);
            cout<<show<<endl;
        }
        getch();
        //trigger_cafe_management=1;
        }
        else
        {
            trigger_cafe_management=1;
        }
    }
};

class my_profile
{
    public:
    string my_pro_file,show;
    void my_profile_details()
    {
        ifstream file;
        file.open(my_pro_file.c_str());
        while (!file.eof())
        {
            getline(file,show);
            cout<<show<<endl;
        }
        file.close();
    }
};

class change_password
{
public:
    string change_user,old_pass,old_pass_file,new_pass;
    int ans,trigger_A=0,trigger_B=0,i;
    char ch1,ch2;
    void change_passcode()
    {
        cout<<"\nEnter old password: ";
        old_pass.clear();
        ch1= _getch();
            while(ch1!=13)
            {
                old_pass.push_back(ch1);
                cout<<'*';
                ch1=_getch();
            }
        ifstream file1;
        file1.open(change_user.c_str());
        getline(file1,old_pass_file);
        file1.close();
        if(old_pass==old_pass_file)
        {
            cout<<"\nEnter new password: ";
            //cin>>ws;
 //           getline(cin,new_pass);
        ch2= _getch();
            while(ch2!=13)
            {
                new_pass.push_back(ch2);
                cout<<'*';
                ch2=_getch();
            }
            ofstream file2;
            file2.open(change_user.c_str());
            file2<<new_pass;
            file2.close();
            Beep(1500,50);
            cout<<"\nPassword successfully changed...\n\n1. Keep me logged in\n2. Logout from all devices\n";
            cin>>ans;
            if(ans==1)
            {
                trigger_B=1;
            }
            else if(ans==2)
            {
                system("cls");
                system("color 02");
                cout<<"\nLogging out";
                Sleep(1000);
                for(i=0;i<3;i++)
                {
                    cout<<".";
                    Beep(1200,50);
                    Sleep(1000);
                }
                Beep(1500,50);
                cout<<"\nYou've successfully logged out...";
                Sleep(1500);
                trigger_A=1;
            }
            else
            {
                cout<<"\nYou must log in\n";
                Sleep(2000);
                trigger_A=1;
            }
        }
        else
        {
            Beep(800,250);
            cout<<"\nWrong password entered\nFailed to change password...\n";
            Sleep(3000);
            trigger_B=1;
        }


    }
};

main()
{
    system("color 1F");
    system("title CYBER CAFE MANAGEMENT BY UTSAB SEN");

    login ob1;
    registration ob2;
    forget_password ob3;
    member_entry ob4;
    computer_entry ob5;
    member_booking ob6;
    charge ob7;
    renew ob8;
    my_profile ob9;
    change_password ob10;
goto A;
   A:
    {
        system("cls");
        system("color 1F");
        int z;
    char s[100]={"WELCOME TO LPU CYBER CAFE"};
    cout<<"\t\t\t\t";
    for(z=0;z<strlen(s);z++)
    {
        cout<<s[z];
    Sleep(50);
    }
    Sleep(1000);
        int t;
        char n1;
        cout<<"\n1. Log In\n2. Registration\n3. Forget Password\n4. About\n5. Exit\n";
        cin>>ws;
        cin>>n1;
        switch(n1)
        {
        case '1':
            {
                ob1.user_name();

                        if(ob1.trigger_A==1)
                        {
                            ob1.trigger_A=0;
                            goto A;
                        }
                if(ob1.trigger_registration==1)
                {
                    ob1.trigger_registration=0;
                    cout<<"\n1. Register now\n2. Login with other account\n3. Back\n";
                    cin>>t;
                    if(t==1)
                    {
                        ob2.user_details_in();
                    }
                    else if(t==2)
                    {
                        ob1.user_name();
                    }
                    else if(t==3)
                    {
                        goto A;
                    }
                    else
                    {
                        goto A;
                    }
                }
                else if(ob1.trigger_logged_in==1)
                {
                    ob1.trigger_logged_in=0;
                    goto B;
                }
                else if(ob2.trigger_main==1)
                {
                    ob2.trigger_main=0;
                    goto A;
                }
                break;
            }
        case '2':
            {
                ob2.user_details_in();
                if(ob2.trigger_main==1)
                {
                    ob2.trigger_main=0;
                    goto A;
                }
                break;
            }
        case '3':
            {
                ob3.forget_username();
                if(ob3.trigger_main==1)
                {
                    ob3.trigger_main=0;
                    goto A;
                }
                break;
            }
        case '4':
            {
                system("color 01");
                system("cls");
                cout<<"\n\n\t\t-:Credits:-\n\n\tName: Utsab Sen\n\tRegistration No: 11709492\n\tSection: K17TC\n\tRoll No: 12\n\tLOVELY PROFESSIONAL UNIVERSITY\n\n";
                getch();
                goto A;
                break;
            }
        case '5':
            {
                system("cls");
                system("color 2F");
                int z;
                char s[100]={"Thank you. Visit Again"};
                cout<<"\n\t\t\t\t";
                for(z=0;z<strlen(s);z++)
                {
                    cout<<s[z];
                    Sleep(50);
                }
                Sleep(500);
                exit(1);
            }
        default:
            {
                system("cls");
                goto A;
                break;
            }
        }
    }
goto X;
X:{
     if(ob1.trigger_registration==1)
                {
                    int t2;
                    ob1.trigger_registration=0;
                    cout<<"\n1. Register now\n2. Login with other account\n3. Back\n";
                    cin>>t2;
                    if(t2==1)
                    {
                        ob2.user_details_in();
                    }
                    else if(t2==2)
                    {
                        ob1.user_name();
                        if(ob1.trigger_registration==1)
                        {
                            goto X;
                        }
                    }
                    else
                    {
                        goto A;
                    }
                }
                else if(ob1.trigger_logged_in==1)
                {
                    ob1.trigger_logged_in=0;
                    goto A;
                }
                else if(ob2.trigger_main==1)
                {
                    ob2.trigger_main=0;
                    goto A;
                }
                if(ob3.trigger_main==1)
                {
                    ob3.trigger_main=0;
                    goto A;
                }
}

    B:
        {
            system("cls");
            system("color F1");
            cout<<"Profile: "<<ob1.username<<"\n";
            int i;
            char n2;
            cout<<"\n1. Master Entry\n2. Cafe Management\n3. My Profile\n4. Change Password\n5. Logout\n";
            cin>>n2;
            switch(n2)
            {
            case '1':
                {
                    goto master_entry;
                    break;
                }
            case '2':
                {
                    goto cafe_management;
                    break;
                }
            case '3':
                {
                    goto my_profile;
                    break;
                }
            case '4':
                {
                    goto change_password;
                    break;
                }
            case '5':
                {
                    system("cls");
                    system("color 02");
                     cout<<"\nLogging out";
                Sleep(1000);
                for(i=0;i<3;i++)
                {
                    cout<<".";
                    Beep(1200,50);
                Sleep(1000);
                }
                Beep(1500,50);
                    cout<<"\nYou've successfully logged out.\n";
                    Sleep(1000);
                    system("cls");
                    goto A;
                }
            default:
                {
                    goto B;
                    break;
                }
            }
        }
        master_entry:
            {
                system("cls");
                system("color 5F");
                char n3;
                cout<<"Profile: "<<ob1.username<<"\n\n"<<"MASTER ENTRY: \n";
                cout<<"\n1. Member Entry\n2. Computer Entry\n3. Back\n";
                cin>>n3;
                switch(n3)
                {
                case '1':
                    {
                        goto member_entry;
                        break;
                    }
                case '2':
                    {
                        goto computer_entry;
                        break;
                    }
                case '3':
                    {
                        goto B;
                    }
                default:
                    {
                        goto master_entry;
                    }
                }
            }

            //.......................master entry start..................................

            member_entry:
                {
                    system("cls");
                    system("color 4F");
                    char m1;
                    cout<<"Profile: "<<ob1.username<<"\n\n"<<"MEMBER ENTRY: \n";
                    cout<<"\n1. Add new mumber\n2. Show member\n3. Update Record\n4. Delete Record\n5. Back\n";
                    cin>>m1;
                    switch(m1)
                    {
                    case '1':
                        {
                            ob4.add_new_member();
                            goto member_entry;
                            break;
                        }
                    case '2':
                        {
                            ob4.show_member();
                            goto member_entry;
                            break;
                        }
                    case '3':
                        {
                            ob4.update();
                            goto member_entry;
                            break;
                        }
                    case '4':
                        {
                            ob4.del();
                            goto member_entry;
                            break;
                        }
                    case '5':
                        {
                            goto master_entry;
                            break;
                        }
                    default:
                        {
                            goto member_entry;
                            break;
                        }
                    }
                }
                 if(ob4.trigger_member_entry==1)
            {
                ob4.trigger_member_entry=0;
                goto member_entry;
            }

            computer_entry:
                {
                    system("cls");
                    system("color 4F");
                    char m2;
                    cout<<"Profile: "<<ob1.username<<"\n\n"<<"COMPUTER ENTRY: \n";
                    cout<<"\n1. Add new computer\n2. Show computer\n3. Update Record\n4. Delete Record\n5. Back\n";
                    cin>>m2;
                    switch(m2)
                    {
                    case '1':
                        {
                            ob5.add_new_computer();
                            goto computer_entry;
                            break;
                        }
                    case '2':
                        {
                            ob5.show_computer();
                            goto computer_entry;
                            break;
                        }
                    case '3':
                        {
                            ob5.update();
                            goto computer_entry;
                            break;
                        }
                    case '4':
                        {
                            ob5.del();
                            goto computer_entry;
                            break;
                        }
                    case '5':
                        {
                            goto master_entry;
                            break;
                        }
                    default:
                        {
                            goto computer_entry;
                            break;
                        }
                    }
                }
                if(ob5.trigger_computer_entry==1)
            {
                ob5.trigger_computer_entry=0;
                goto computer_entry;
            }

            //......................master entry end...................................

            cafe_management:
                {
                    system("cls");
                    system("color 5F");
                    char n4;
                    cout<<"Profile: "<<ob1.username<<"\n\n"<<"CAFE MANAGEMENT: \n";
                    cout<<"\n1. Booking\n2. Charges\n3. Renewal\n4. Back\n";
                    cin>>n4;
                    switch(n4)
                    {
                    case '1':
                        {
                            goto booking;
                            break;
                        }
                    case '2':
                        {
                            goto charges;
                            break;
                        }
                    case '3':
                        {
                            goto renewal;
                            break;
                        }
                    case '4':
                        {
                            goto B;
                            break;
                        }
                    default:
                        {
                            goto cafe_management;
                            break;
                        }
                    }
                }
                //..................cafe management start..............................................

                booking:
                    {
                        system("cls");
                        system("color 4F");
                        cout<<"Profile: "<<ob1.username<<"\n\n"<<"BOOKING: \n";
                        int i;
                        char m3;

                        cout<<"\n1. Member Login\n2. Member Logout\n3. Non member Login\n4. Non member Logout\n5. Back\n";
                        cin>>m3;
                        switch(m3)
                        {
                        case '1':
                            {
                                ob6.member_login();
                                if(ob6.trigger_booking==1)
                                {
                                    ob6.trigger_booking=0;
                                    goto booking;
                                }
                                break;
                            }
                        case '2':
                            {
                                if(ob6.flag==1)
                                {
                                    system("cls");
                                    system("color 02");
                                    cout<<"\nLogging out";
                                    Sleep(1000);
                                    for(i=0;i<3;i++)
                                    {
                                        cout<<".";
                                        Beep(1200,50);
                                        Sleep(1000);
                                    }
                                    Beep(1500,50);
                                    cout<<"\nYou've successfully logged out...\n";
                                    Sleep(1000);
                                    ob6.flag=0;
                                    goto booking;
                                }
                                else
                                {
                                    system("cls");
                                    cout<<"\nYou're alredy logged out.\n";
                                    Sleep(1000);
                                    goto booking;
                                }
                                break;
                            }
                        case '3':
                            {
                                ob6.nonmember_login();
                                if(ob6.trigger_booking==1)
                                {
                                    ob6.trigger_booking=0;
                                    goto booking;
                                }
                                break;
                            }
                        case '4':
                            {
                                if(ob6.flag1==0)
                                {
                                    ob6.flag1=0;
                                    system("cls");
                                    cout<<"\nYou're alredy logged out\n";
                                    Sleep(1000);
                                    goto booking;
                                    break;
                                }
                                else
                                {

                                    ob6.nonmember_del();
                                    goto booking;
                                    break;
                                }
                                break;
                            }
                        case '5':
                            {
                                goto cafe_management;
                                break;
                            }
                        default:
                            {
                                goto booking;
                                break;
                            }
                        }
                    }

                charges:
                    {
                        char m4;
                        system("cls");
                        system("color 4F");
                        cout<<"Profile: "<<ob1.username<<"\n\n"<<"CHARGES: \n";
                        cout<<"\n1. Take Charges\n2. Show Charges\n3. Back\n";
                        cin>>m4;
                        switch(m4)
                        {
                        case '1':
                            {
                                cout<<"Profile: "<<ob1.username;
                                ob7.take_charges();
                                if(ob7.trigger_charge==1)
                                {
                                    ob7.trigger_charge=0;
                                    goto charges;
                                }

                                break;
                            }
                        case '2':
                            {
                                cout<<"Profile: "<<ob1.username;
                                ob7.show_charges();
                                goto charges;
                                break;
                            }
                        case '3':
                            {
                                goto cafe_management;
                                break;
                            }
                        default:
                            {
                                goto charges;
                                break;
                            }
                        }
                    }
                renewal:
                    {
                        system("cls");
                        system("color 4F");
                        cout<<"Profile: "<<ob1.username<<"\n\n"<<"RENEWAL: \n";
                        ob8.renewal();
                        if(ob8.trigger_cafe_management==1)
                        {
                            goto cafe_management;
                        }

                    }


                //..................cafe management end..............................................

            my_profile:
                {
                    system("cls");
                    system("color 01");
                    cout<<"Profile: "<<ob1.username<<"\n\n"<<"MY PROFILE: \n";
                    ob9.my_pro_file=ob1.my_file;
                    ob9.my_profile_details();
                    getch();
                    goto B;
                }
            change_password:
                {
                    system("cls");
                    system("color 02");
                    cout<<"Profile: "<<ob1.username<<"\n\n"<<"CHANGE PASSWORD: \n";
                    ob10.change_user=ob1.change_pass;
                    ob10.change_passcode();
                    if(ob10.trigger_A==1)
                    {
                        ob10.trigger_A=0;
                        goto A;
                    }
                    else if(ob10.trigger_B==1)
                    {
                        ob10.trigger_B=0;
                        goto B;
                    }
                }

}
