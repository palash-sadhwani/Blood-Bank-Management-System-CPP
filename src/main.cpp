#include<iostream>
#include<fstream>
#include <string>
using namespace std;

class Blood
{
	public:
		
		string firstname,lastname,gender,address,contact,bloodgroup,disease;
		int age,age2,bp;
		float weight,height;
    	
    	void donate();
        
	        virtual void gd()
	        {
	        	system("cls");
				cout<<endl<<endl;
				cout<<"\t\t\t\t\t\t\t\t                      Enter Donor Information                           "<<endl;
				cout<<"\t\t\t\t\t\t\t\t========================================================================"<<endl;
	        	cout<<"\t\t\t\t\t\t\t\tEnter you Details"<<endl<<endl;
	            cout<<"\t\t\t\t\t\t\t\tFirst Name :";
	            cin>>firstname;
	            cout<<"\n\t\t\t\t\t\t\t\tLast Name :";
	            cin>>lastname;
	            Age:
	            cout<<"\n\t\t\t\t\t\t\t\tAge :";
    			cin>>age;
    			try
			    {
			    	if(age==age2)
			    	{
						cout<<".";	
					}
					else
						throw age;
				}
				catch(int i)
				{
					cout<<"\t\t\t\t\t\t\t\tError! at Age :"<<i<<endl;
					goto Age;	
				}
	            cout<<"\n\t\t\t\t\t\t\t\tGender :";
	            cin>>gender;
	            cout<<"\n\t\t\t\t\t\t\t\tWeight :";
	            cin>>weight;
	            cout<<"\n\t\t\t\t\t\t\t\tHeight :";
	            cin>>height;
	            cout<<"\n\t\t\t\t\t\t\t\tBlood Group :";
	            cin>>bloodgroup;
	            cout<<"\n\t\t\t\t\t\t\t\tContact :";
	            cin>>contact;
	            cout<<"\n\t\t\t\t\t\t\t\tAddress :";
			    cin>>address;
	    	}
};

class Tblood : public Blood
{
	public:

		friend void recipient();
		void gd()
	    {
		    system("cls");
		    cout<<endl<<endl;
		    cout<<"\t\t\t\t\t\t\t\t                         Enter Recipient Information                         "<<endl;
		    cout<<"\t\t\t\t\t\t\t\t============================================================================="<<endl;
		    cout<<"\n\t\t\t\t\t\t\t\tFirst Name :";
            cin>>firstname;
            cout<<"\n\t\t\t\t\t\t\t\tLast Name :";
            cin>>lastname;
            cout<<"\n\t\t\t\t\t\t\t\tAge :";
   			cin>>age;
	        cout<<"\n\t\t\t\t\t\t\t\tGender :";
	        cin>>gender;
            cout<<"\n\t\t\t\t\t\t\t\tAddress :";
			cin>>address;
		    cout<<"\n\t\t\t\t\t\t\t\tContact No :";
		    cin>>contact;
			cout<<"\n\t\t\t\t\t\t\t\tEnter Blood Group you want :";
		    cin>>bloodgroup;
		    cout<<"\n\t\t\t\t\t\t\t\tHow Many Blood Packets Do you want (1 Packet contains 500ml ) :";
		    cin>>bp;
			cout<<endl;
		}		   
};

Blood b ;	//  Base Class object
Blood *bptr=&b;	// Pointer object	

fstream fout;	// File object 

void donordata()	// Function For writing donor data in File
{
	fout.open("dektop.txt",ios::out|ios::app);   // Open Function for opening file 
	bptr->gd();
	fout<<"First Name :"<<b.firstname<<endl;
	fout<<"Last Name :"<<b.lastname<<endl;
	fout<<"Age :"<<b.age<<endl;
	fout<<"Gender :"<<b.gender<<endl;
    fout<<"Weight :"<<b.weight<<endl;
	fout<<"Height :"<<b.height<<endl;
	fout<<"Blood Group :"<<b.bloodgroup<<endl;
    fout<<"Any Disease :"<<b.disease<<endl;
    fout<<"Contact :"<<b.contact<<endl;
    fout<<"Address :"<<b.address<<endl<<endl;
	fout.close();
}

void display_ddata()	// Functiom For reading donor data from File
{
	system("cls");
	int n=100000;
	char str[n];
	cout<<"\n\t\t\t\t\t\t\t\t                       Displaying Donor Information                     "<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t========================================================================"<<endl<<endl;
	fout.open("dektop.txt",ios::in|ios::app);
	if (!fout)
    {

        cout<<"\t\t\t\t\t\t\t\tNo Data Is Present...";
        fout.close();
    }
    else
    {
		while(fout)
		{
			fout.getline(str,n);
			cout<<"\t\t\t\t\t\t\t\t"<<str<<endl;
		}
	}
	fout.close();
	system("pause");	
}

void Blood::donate()	// Base Class Function for Donor  data
{
	system("cls");
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t                      Enter Donor Information                           "<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t========================================================================"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\tEnter Details For Checking That You Are Eligible For Donation Or Not"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t\t\t\t\tAge :";
	cin>>bptr->age2;
	cout<<endl;
    cout<<"\t\t\t\t\t\t\t\tYou Can't Donate Blood if you have one of this :"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t1: You have a Recent Piercing or Tattoo "<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t2: You have a Bad Cold or the Flu "<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t3: You Were Recently Treated With Antibiotics "<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t4: You Don't Weigh Enough "<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t5: You Have a New Sexual Partner "<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\tYes Or No :";
    cin>>bptr->disease;
    if(bptr->age2<=16 || bptr->age2>=55 )
    {
    	cout<<"\n\t\t\t\t\t\t\t\tYou are not Eligible"<<endl;
		system("pause"); 
	}
	if(bptr->disease=="yes")
	{
        cout<<"\n\t\t\t\t\t\t\t\tYou are not Eligible"<<endl;
		system("pause");
	}
    else	system("pause");
    {
        donordata();
        cout<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\tPerfect Your registration is done successfully"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t====================================="<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\tDonor Inforamation"<<endl;
    	cout<<"\t\t\t\t\t\t\t\tName :"<<bptr->firstname<<" "<<bptr->lastname<<endl;
    	cout<<"\t\t\t\t\t\t\t\tAge :"<<bptr->age2<<endl;
    	cout<<"\t\t\t\t\t\t\t\tGender :"<<bptr->gender<<endl;
    	cout<<"\t\t\t\t\t\t\t\tBlood Group :"<<bptr->bloodgroup<<endl;
    	cout<<"\t\t\t\t\t\t\t\tDate of donation :12.12.2022 "<<endl<<endl;
    	cout<<"\t\t\t\t\t\t\t\t====================================="<<endl;
    	system("pause");
    }   
}

Tblood b1;	// Derived Class object

fstream file;	// file object

void recipient_data()	// Function for writing recipient data in file
{
	file.open("dektop2.txt",ios::out|ios::app);	// Open Function for opening file
	b1.gd();
	file<<"First Name :"<<b1.firstname<<endl;
	file<<"Last Name :"<<b1.lastname<<endl;
	file<<"Age :"<<b1.age<<endl;
	file<<"Gender :"<<b1.gender<<endl;
	file<<"Address :"<<b1.address<<endl;
	file<<"Contact No :"<<b1.contact<<endl;
	file<<"Blood recipient want :"<<b1.bloodgroup<<endl;
	file<<"Quantity :"<<b1.bp<<endl<<endl;
	file.close();
}

void display_rdata()	// Function for reading recipient data from file
{
	system("cls");
	int m=100000;
	char str[m];
	cout<<"\n\t\t\t\t\t\t\t\t                    Displaying Recipient Information                    "<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t========================================================================"<<endl<<endl;
	file.open("dektop2.txt",ios::in|ios::app);
	if (!file)
    {

        cout<<"\t\t\t\t\t\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
		while(file)
		{
			file.getline(str,m);
			cout<<"\t\t\t\t\t\t\t\t"<<str<<endl;
		}
	}
	file.close();	
	system("pause");
}

void recipient()	// Base Class Function 
{
	recipient_data();
	cout<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\tPerfect Your registration is done successfully"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t====================================="<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\tRecipient Information"<<endl;
    	cout<<"\t\t\t\t\t\t\t\tName :"<<b1.firstname<<" "<<b1.lastname<<endl;
    	cout<<"\t\t\t\t\t\t\t\tAge :"<<b1.age<<endl;
    	cout<<"\t\t\t\t\t\t\t\tGender :"<<b1.gender<<endl;
    	cout<<"\t\t\t\t\t\t\t\tBlood Group Want :"<<b1.bloodgroup<<endl;
    	cout<<"\t\t\t\t\t\t\t\tBlood Quantity :"<<b1.bp<<endl;
    	cout<<"\t\t\t\t\t\t\t\tDate Of Taking Blood :12.12.2022 "<<endl<<endl;
    	cout<<"\t\t\t\t\t\t\t\t====================================="<<endl;
	system("pause");
}

void admin()
{
	system("cls");
	int password,ch1;
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t========================================================================"<<endl<<endl;
	password:
	cout<<"\t\t\t\t\t\t\t\tPassword :";
	cin>>password;
	if(password==2107053)
	{
		system("cls");
		cout<<"\t\t\t\t\t\t\t\t========================================================================"<<endl;
	    cout<<"\t\t\t\t\t\t\t\t                             WELCOME SIR                                "<<endl;
	    cout<<"\t\t\t\t\t\t\t\t========================================================================"<<endl;
	    cout<<"\t\t\t\t\t\t\t\t1: Donor Data \n\n\t\t\t\t\t\t\t\t2: Recipient Data"<<endl;
	    cin>>ch1;
		switch(ch1)
		{
		    case 1:
		    	display_ddata();
		    	break;
			case 2:
			    display_rdata();
			    break;
		   	default:
		   		cout<<"\t\t\t\t\t\t\t\tOOPS! you pressed wrong button"<<endl;
	            break;
		}
	}
	else
	{
		cout<<"\t\t\t\t\t\t\t\tOOPS! Wrong Password"<<endl;
		goto password;
	}
}

int Main_menu()
{
    int ch=0;
    while(ch != 4)
    {
    	system("cls");
    	cout<<endl<<endl<<endl;
	    cout<<"\t\t\t\t\t\t\t\t========================================================================"<<endl;
	    cout<<"\t\t\t\t\t\t\t\t                                WELCOME                                 "<<endl;
	    cout<<"\t\t\t\t\t\t\t\t========================================================================"<<endl;
	    cout<<"\t\t\t\t\t\t\t\t1: Donor "<<endl<<endl;
	    cout<<"\t\t\t\t\t\t\t\t2: Recipient "<<endl<<endl;
	    cout<<"\t\t\t\t\t\t\t\t3: Admin"<<endl<<endl;
	    cout<<"\t\t\t\t\t\t\t\t4: Exit"<<endl<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                bptr->donate();
                break;
            case 2:
                recipient();
                break;
            case 3:
        		admin();
        		break;
        	case 4:
        		return 0;
            default:
                cout<<"\t\t\t\t\t\t\t\tOOPS! you pressed wrong button"<<endl;
                break;
        }
    }
}

int main()
{
	Main_menu();
	return 0;
}
