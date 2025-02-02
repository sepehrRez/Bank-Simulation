#include<iostream>
#include<vector>

using namespace std;
static long int hesabcode=600000;
class bankimon                                         //shomare hesab ha shoro mishe az 600,000
{
    long int shomarehesab;
     
    friend void Display(bankimon );
    friend bool is_exist(string ,char ,long int );
    friend bankimon search(string ,char ,long  int );
    friend bool search_name_hesabcode(string , long int );
    friend void varizbardasht(string ,char ,long int , char , long int );
    friend void entegal(string ,string ,long int ,long int ,long int );
    friend void delet(string ,long int );
    friend void eddit(string ,string,char ,long int ,long int);
    
    public:
        string name;
         char jens;
        long int mojodi;
bankimon(string ,char ,long  int );
bankimon(){};
};
bankimon::bankimon(string name,char jens,long  int mojodi)
{
    this->name=name;
     this->jens=jens;
     this->mojodi=mojodi;
    shomarehesab=hesabcode;
}
bankimon operator+(bankimon first, bankimon second)
{
    first.mojodi+=second.mojodi;
    return first;
}
bankimon operator-(bankimon first, bankimon second)
{
    first.mojodi-=second.mojodi;
    return first;
}
vector<bankimon> moshtari;

void start()
{
    cout<<"Enter 1 to add customer\n"<<"Enter 2 to show customer detail\n"<<"Enter 3 to edit customer\n"<<"Enter 4 to remove customer\n";
    cout<<"Enter 5 to transaction\n"<<"Enter 6 to withdraw/deposit from account\n"<<"if you want to end program enter any thing exept integeer\n";
}

bankimon search(string name,char jense,long  int shomare_hesab)
{
    bankimon result;
    for(int i=0;i<moshtari.size();i++)
    {
        if((name==moshtari.at(i).name)&&(jense==moshtari.at(i).jens)&&(shomare_hesab==moshtari.at(i).shomarehesab))
        {
              result=moshtari.at(i);
              return result;
        }
    }
   // return result;                                                        //??
}

bool fexist(string name , char jense)
{
    for(int i=0;i<moshtari.size();i++)
    {
        if((name==moshtari.at(i).name)&&(jense==moshtari.at(i).jens))
            return false;
    }
    return true;
}
void Display(bankimon showable)
{
    cout<<"HERE IS THE INFORMATIONS THAT YOU NEED :\n";
    cout<<"NAME IS: "<<showable.name;
    cout<<"\nJENSE IS: "<<showable.jens;
    cout<<"\nSHOMARE HESAB IS : "<<showable.shomarehesab<<endl;
    cout<<"MOJODI IS : "<<showable.mojodi<<endl;
}

bool is_exist(string name,char jense,long int shomare_hesab)
{
    for(int i=0;i<moshtari.size();i++)
        if((name==moshtari.at(i).name)&&(jense==moshtari.at(i).jens)&&(shomare_hesab==moshtari.at(i).shomarehesab))
            return true;
    
    return false;
}

bool search_name_hesabcode(string name, long int shomare_hesab)
{
    for(int i=0;i<moshtari.size();i++)
    {
        if((name==moshtari.at(i).name)&&(shomare_hesab==moshtari.at(i).shomarehesab))
            return true;
    }
     return false;
}

void eddit(string name,string new_name,char jense,long int mojodi,long int shomare_hesab)
{
    for(int i=0;i<moshtari.size();i++)
    {
        if((name==moshtari.at(i).name)&&(shomare_hesab==moshtari.at(i).shomarehesab))
            {
                moshtari.at(i).name=new_name;
                moshtari.at(i).jens=jense;
                moshtari.at(i).mojodi=mojodi;
            }
    }
}

void delet(string name , long int shomare_hesab)
{
    for(int i=0;i<moshtari.size();i++)
    {
        if((name==moshtari.at(i).name)&&(shomare_hesab==moshtari.at(i).shomarehesab))
                moshtari.erase(moshtari.begin()+i);
    }
}

void entegal(string name1,string name2,long int patment,long int shomare_hesab1,long int shomare_hesab2)
{
    int flag1,flag2;
    for(int i=0;i<moshtari.size();i++)
    {
        if((name1==moshtari.at(i).name)&&(shomare_hesab1==moshtari.at(i).shomarehesab))
            flag1=i;
        else if ((name2==moshtari.at(i).name)&&(shomare_hesab2==moshtari.at(i).shomarehesab))
            flag2=i;
    }

    if(moshtari.at(flag1).mojodi<patment)                         //first user dosent have enough money for this transaction
        {
            cout<<"first user dosent have enough money for this transaction\n";
            exit;
        }
    else 
        {
            moshtari.at(flag1).mojodi-=patment;
            moshtari.at(flag2).mojodi+=patment;
            cout<<"the operation finished sucssefully \n";
        }
}

void varizbardasht(string name,char jense,long int shomare_hesab,char keyword,long int payment)
{
    int flag;
    for(int i=0;i<moshtari.size();i++)
    {
        if((name==moshtari.at(i).name)&&(jense==moshtari.at(i).jens)&&(shomare_hesab==moshtari.at(i).shomarehesab))
            flag=i;
    }
    if(keyword=='d')
    {
        moshtari.at(flag).mojodi+=payment;
        cout<<"the operation finished sucssefully \n";
    }
    else if(keyword=='w')
    {
        if (moshtari.at(flag).mojodi>=payment)
        {
            moshtari.at(flag).mojodi-=payment;
            cout<<"the operation finished sucssefully \n";
        }
        else
            cout<<"user dosent have enough money\n";
        
    }
    else
        cout<<"the input code is false pelease try again\n";
}