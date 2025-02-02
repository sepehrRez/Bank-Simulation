#include<iostream>
#include<vector>
#include"tavabe.h"                //all tavabe and class
using namespace std;

int main()
{
    start();
    int n;
    string name="";
    char jense;
    long int mojodi;
    bankimon temp;
    cin>>n;

    while(cin)
    {
        if((n>=1)&&(n<=6))
        {
            switch (n)
            {
                case (1):                                          //add customer
                {
                    cin.ignore();
                    cout<<" enter name and jense and mojodi just in a line \n";
                    cin>>name;
                    cin>>jense;
                    cin>>mojodi;
                    if(fexist(name,jense))
                    {
                        bankimon vorodi(name,jense,mojodi);
                        moshtari.push_back(vorodi);
                        cout<<"the operation finished sucssefully \n";
                        hesabcode++;
                    }
                    else 
                        cout<<"the user with this inf is existing please try again\n";
                }break;

                case (2):                                         //show customer detail
                {
                    cin.ignore();
                    cout<<"enter name && jense && shomare hesab just in a line\n";
                    cin>>name;
                    cin>>jense;
                    cin>>mojodi;
                    if(is_exist(name,jense,mojodi))
                    {
                        temp=search(name,jense,mojodi);
                        Display(temp);
                    }
                    else
                        cout<<"user not found\n";
                    
                }break;

                case (3):                                         //edit customer
                {
                    cin.ignore();
                    cout<<"enter the name && shomarehesab of user that you want to eddit just in a line \n";
                    cin>>name>>mojodi;
                    if (search_name_hesabcode(name,mojodi))
                    {
                        long int shomare_hesab=mojodi;
                       cin.ignore();
                        string name2;
                        cout<<"enter new_name & jense & mojodi just in a line\n";
                        cin>>name2>>jense>>mojodi;
                        eddit(name,name2,jense,mojodi,shomare_hesab);
                        cout<<"the operation finished sucssefully \n";
                    }
                    else
                        cout<<"user not found\n";
                }break;

                case (4):                                          //remove customer
                {
                    cin.ignore();
                    cout<<"enter the name && shomare_hesab of the user that you want to delet just in a line \n";
                    cin>>name>>mojodi;
                    if(search_name_hesabcode(name,mojodi))
                    {
                        delet(name,mojodi);
                        cout<<"the operation finished sucssefully \n";
                    }
                    else
                        cout<<"user not found\n";
                }break;

                case (5):                                       //to transaction
                {
                    cin.ignore();
                    string name2;
                    long int shomare_hesab1,shomare_hesab2;
                    cout<<"enter first and 2end name then shomare_hesab of first & 2end user that you want to transfer then enter the payment that you want to transaction\n";
                    cin>>name>>name2>>shomare_hesab1>>shomare_hesab2>>mojodi;
                    if((search_name_hesabcode(name,shomare_hesab1)&&(search_name_hesabcode(name2,shomare_hesab2))))
                    {
                        entegal(name,name2,mojodi,shomare_hesab1,shomare_hesab2);
                    }
                    else
                        cout<<" input informations are fale pelase try again like name or jense (user not found)\n";
                }break;

                case (6):                                       //to withdraw/deposit from account
                {
                    cin.ignore();
                    cout<<"enter name and jense and shomare_hesab of the user that you want to withdraw/deposit from just in a line  \n";
                    cin>>name;
                    cin>>jense;
                    cin>>mojodi;
                    if(is_exist(name,jense,mojodi))
                    {
                        char keyword;
                        long int payment;
                        cout<<"enter the payment that you want to transfer && enter d to deposit and w to withdraw just in a line \n";
                        cin>>payment;
                        cin>>keyword;
                        varizbardasht(name,jense,mojodi,keyword,payment);
                        
                    }
                    else
                        cout<<"user not found\n";
                } break;

                default: cout<<"     !!!!its never happen!!! \n" ; break;
            }
        }
        else
            cout<<"the code is not exist please try again\n\n\n";
    cout<<"ENTER NEXT NUMBER FOR YOUR NEXT REQUEST :\n";
    start();
    cin>>n;
    }

    return 0;
}

