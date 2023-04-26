#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;

class Expre
{
private:
    string Exp;
    string Cad;
    int j;
public:
    Expre();
    void getCad(string C);
    void getExp(string E);
    string setExp();
    int tamExp();
    bool Validar();
};

Expre::Expre()
{
    j=0;
}

void Expre::getCad(string C)
{
    Cad=C;
}

void Expre::getExp(string E)
{
    Exp=E;
}

string Expre::setExp()
{
    return Exp;
}

int Expre::tamExp()
{
    return Exp.length();
}

bool Expre::Validar()
{
    j=0;
    for (int i=0;i<Exp.length();i++)
    {
        switch (Exp[i])
        {
        case '+':
            if (Exp[i-1]==Cad[j])
            {
                j++;
                while (Exp[i-1]==Cad[j])
                {
                    j++;
                }
            }
            else
            {
                return false;
            }
            break;
        case '*':
            while (Exp[i-1]==Cad[j])
            {
                j++;
            }
            break;
        case '|':
            if (Exp[i-1]==Cad[j] || Exp[i+1]==Cad[j])
            {
                i++;
                j++;
            }
            else
            {
                return false;
            }
            break;
        case '?':
              if (Exp[i-1]==Cad[j] || Exp[i+1]==Cad[j])
            {
                j++;
            }
            break;
        default:
            if(Exp[i+1]=='+'||Exp[i+1]=='*'||Exp[i+1]=='?'||Exp[i+1]=='|'){
                break;
            }
            if (Exp[i]==Cad[j])
            {
                j++;
            }
            else
            {
                return false;
            }
            break;
        }
    }
    if (Cad.length()==j)
        return true;
    else
        return false;
}


void alumno()
{
    cout<<"\n"<<endl;
    cout<<"Alumno: "<<endl;
    cout<<"\t Valerio López José Eduardo. "<<endl;
    cout<<"\n Fecha de entrega: "<<endl;
    cout<<"\t 02 - 03 - 2023 "<<endl;
    cout<<"\n Grupo: "<<endl;
    cout<<"\t 4CM2 "<<endl;
    cout<<"\n"<<endl;
}

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    system("CLS");
    alumno();
    system("PAUSE");
    system("CLS");
    Expre Ob;
    string E,C;
    int Op;
    do
    {
        system("CLS");
        cout<<"\t \t Menú"<<endl;
        cout<<"1. Ingresar expresion"<<endl;
        cout<<"2. Ingresar cadena"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>Op;
        switch (Op)
        {
            case 1:
                cout<<"Para la concatenación NO usar el punto"<<endl;
                cout<<"Expresion:"<<endl;
                cin>>E;
                Ob.getExp(E);
                break;
            case 2:
                if (Ob.tamExp()==0)
                {
                    cout<<"No ha ingresado una expresión"<<endl;
                }
                else
                {
                   cout<<"Para validar en la expresinón "<<Ob.setExp()<<endl;
				cout<<"Cadena:"<<endl;
	    		cin>>C;
	    		Ob.getCad(C);
	    		if (Ob.Validar()==true)
	    		{
	        		cout<<"Cadena valida"<<endl;
	    		}
	    		else
	    		{
	        		cout<<"cadena invalida"<<endl;
	    		}
	    	}
    		break;
    	case 3:
    		cout<<"Porgrama terminado."<<endl;
    		break;
    	default:
    		cout<<"No es una opcion valida."<<endl;
	}
	system("PAUSE");
	}
	while (Op<3);

    return 0;
}

