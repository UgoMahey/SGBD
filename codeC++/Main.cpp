#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <stdlib.h>
#include <regex>

using namespace std;

bool estValide(string l1){
	if(l1 == "}" && regex_match(l1,regex("[0-99]\-[0-99]\-[0-99]\,"))){
		return true;
	}
	
	
	
	
	
	return false;
}






/**
Recupere les lignes d'un fichier texte et les stock dans un vector de string
*/
vector<string> recupere(string nom){

    char* nomchar;

    nomchar = (char*)nom.c_str();


    ifstream fichier(nomchar, ios::in);
    vector<string> tabLigne;
    if(fichier){
        string ligne;
		
        while(getline(fichier,ligne)){

            
            if(estValide(ligne)){
            	//cout<<ligne<<endl;
            	tabLigne.push_back(ligne);
            }
           

        }

        fichier.close();
    }
    else {
        cout<<"Erreur fichier introuvable !"<<endl;
    }
   return tabLigne;
}

/**
Ecrit un vector de string dans un fichier texte
*/
void ecrit(const vector<string> &tab, string nom){

    char* nomchar;
    nomchar = (char*)nom.c_str();

    ofstream fichier(nomchar, ios::out | ios::trunc);
    if (fichier){

        for (unsigned int i=0;i<tab.size();++i){
            fichier << tab[i] <<endl;
        }
    fichier.close();

    }


}



int main(){
	
	vector<string> res = recupere("fichier_query2.csv");
	
	cout<<res[1]<<endl;
	
	ecrit(recupere("fichier_query2.csv"),"fichier_query_transf2.csv");
	
	




return 0;
}

