#include<iostream>
#include<vector>
using namespace std;

class shabak
{
    
    int zaban;                 //1 or 2
    int nasher_code;            //adad 5 ragami
    int virast;                  //adad 2 ragami
    int esalat;                  // adad 1 ramani
    public:
    
    void get();
    void display();
    
    bool operator==(shabak t)
    {
        if((zaban==t.zaban)&&(nasher_code==t.nasher_code)&&(virast==t.virast)&&(esalat==t.esalat))
            return true;
        
        return false;
    }
};
void shabak::get()
{
    cin.ignore();
    cin>>zaban>>nasher_code>>virast>>esalat;
}
void shabak::display()
{
    cout<<"\nshabak: "<<zaban<<" "<<nasher_code<<" "<<virast<<" "<<esalat<<endl;
}
class book
{
    shabak shabke;
    string title;
    string name_nasher;
    string name_nevisande;
    public:
    friend  void display(book  );
    friend book search_shabak(shabak );
    friend book search_name(string );
    friend bool isexsist(book );

    void get();
    book();
    bool operator==(book vorod)
    {
        if((title==vorod.title)&&(name_nasher==vorod.name_nasher)&&(name_nevisande==vorod.name_nevisande)&&(shabke==vorod.shabke))
            return true;
        else
            return false;
    }
};
void book::get()
{
    cout<<"ENTER TITLE & name_nasher & name_nevisande & shabke\n";
    cin>>title>>name_nasher>>name_nevisande;
    shabke.get();
}
book ::book()
{
    title="";
    name_nasher="";
    name_nevisande="";
}
vector<book> ketab_khone;
       //tavabe
void addbok(book );
void display(book  );
void start();
book search_shabak(shabak );
book search_name(string );
bool isexsist(book );

int main()
{
    start();
    int n;
    cin>>n;
    book ketab;
    while (cin)
    {
        if((n>0)&&(n<=3))
        {
            switch (n)                             //get book info
            {
            case (1):
            {
                ketab.get();
                if(isexsist(ketab))
                    addbok(ketab);
                else
                    cout<<"book is exist\n";
            }break;

            case (2):                          //SEARCH A BOOK BY SHABAK
            {
                shabak ketab_code;
                cout<<"enter shabak :\n";
                ketab_code.get();
                display(search_shabak(ketab_code));
                
            }break;   
            case (3):                               //SEARCH BY NAME OF THE BOOK
            {
                string name;
                cin.ignore();
                cout<<"enter name of Author: \n";
                cin>>name;
                display(search_name(name));
            }break;

            default: cout<<"never happen\n";
                break;
            }
        }
        else 
            cout<<"enter a dorost integeer\n\n";
        start();
        cin>>n;
    }
    
    return 0;
}

void start()
{
    cout<<"ENTER 1 TO ADD A BOOK\nENTER 2 TO SEARCH A BOOK BY SHABAK\nENTER 3 TO SEARCH BY NAME OF THE BOOK\nIF YOU WANT TO END PROGRAM ENTER ANYTHING EXEPT INTEEGER\n";
}

void addbok(book ketab)
    {
        ketab_khone.push_back(ketab);
    }

void display(book ketab_khone )
    {
        if(ketab_khone.name_nasher!="")
        {
            cout<<"BookTitle : "<<ketab_khone.title<<"\nPublisher : "<<ketab_khone.name_nasher<<"\nBookAuthor : "<<ketab_khone.name_nevisande;
            ketab_khone.shabke.display();
        }
        else
            cout<<"book has not found\n";
    }

book search_shabak(shabak code)
{
    for(int i=0;i<ketab_khone.size();i++)
    {
        if(code==ketab_khone.at(i).shabke)
            return ketab_khone.at(i);
    }
   book notexist;
    return notexist;
}

book search_name(string name)             //!!!this function should cheak more info but Q said that !!!! may have some books with same names!!!!
{
    for(int i=0;i<ketab_khone.size();i++)
    {
        if(name==ketab_khone.at(i).name_nevisande)
            return ketab_khone.at(i);
    }
    book notexist;
    return notexist;
}

bool isexsist(book vorod)
{
    for(int i=0;i<ketab_khone.size();i++)
    {
        if(vorod==ketab_khone.at(i))
            return false;
    }
    return true;
}