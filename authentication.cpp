#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
using namespace std;
class Login_Register{
        string Email,password;
       public:
      bool checkString(string passed,string inFile)
          {
    	int size1=passed.length();
    	int size2=inFile.length();
    	if(size1==size2)
    	{
			for(int i=0;i<size1;i++)
			{
				if(passed[i]!=inFile[i])
				{
					return false;
				}
			}
			return true;
    	}
    	else 
    	return false;
}
            void Register()
            {
               
                ofstream fout("userdata.txt",ios::app);   
                cin.ignore();
                cout<<"Enter Email   : ";getline(cin,Email);
                cout<<"Enter password: ";getline(cin,password);
                fout<<Email<<" "<<password<<" ";
                fout.close();
            }
            void login(string  mail,string pass)
            {
                ifstream fout("userdata.txt",ios::in);
                while(!fout.eof())
                {
                fout>>Email>>password;   
               
                if(checkString(mail,Email) && checkString(pass,password))
                {
                        cout<<"Welcome";             
						break;      
                }         
                }
                
                fout.close();   
            }
};
int main()
{
   
    Login_Register obj1;
    string email, pass;
	int opt=1; //for 1st time 
	cout<<"Press 1 to Login"<<endl;
	cout<<"Press 2 to Register" <<endl;
	cout<<"Press 3 to Exit"<<endl;
	while(opt==1||opt==2)
    {
   
    cout<<"\nEnter choice: ";
    cin>>opt;
    if(opt==1)
    {     cin.ignore();
    	   cout<<" Email    : "; getline(cin,email);
           cout<<" Password : "; getline(cin,pass);
           obj1.login(email,pass);
	}
   else  if(opt==2)
     {
         obj1.Register();
	 } 
    }
  system("pause>0");
}
