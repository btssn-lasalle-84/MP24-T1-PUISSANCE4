// Ihm.cpp
#include "Ihm.h"
#include "Jeton.h"
#include "Joueur.h"
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

string IHM::saisieNomJoueur(int numeroJoueur)
{
    string nom;
    cout << "Entrez le nom/pseudo du Joueur " << numeroJoueur << " : ";
    cin >> nom;
    return nom;
}

void IHM::afficherMessageTour(const Joueur& joueur)
{
    afficherDynamiquement("C'est au tour de ");
    cout << getCouleur(joueur.getJeton());
    afficherDynamiquement(joueur.getNom());
    cout << getCouleur(Jeton(VIDE));
    afficherDynamiquement(" de jouer !");
    cout << endl;
}

void IHM::afficherVictoire(Joueur* joueur)
{
    cout << joueur->getNom() << " remporte la partie !" << endl;
}

void IHM::afficherMenu()
{
    string rouge  = "\033[1;91m";
    string jaune  = "\033[1;93m";
    string violet = "\033[1;95m";
    cout << jaune << "  _____       _                               " << rouge << " _  _   "
         << endl;
    cout << jaune << " |  __ \\     (_)                              " << rouge << "| || |  "
         << endl;
    cout << jaune << " | |__) |   _ _ ___ ___  __ _ _ __   ___ ___  " << rouge << "| || |_ "
         << endl;
    cout << jaune << " |  ___/ | | | / __/ __|/ _` | '_ \\ / __/ _ \\ " << rouge << "|__   _|"
         << endl;
    cout << jaune << " | |   | |_| | \\__ \\__ \\ (_| | | | | (_|  __/ " << rouge << "   | |  "
         << endl;
    cout << jaune << " |_|    \\__,_|_|___/___/\\__,_|_| |_|\\___\\___| " << rouge << "   |_|  "
         << endl;
    cout << jaune << "                                              " << rouge << "        "
         << endl;
    cout << violet << "V1.1" << endl;
    cout << jaune << "                                              " << rouge << "        "
         << endl;

    cout << jaune << "Commandes de jeu à taper :"
         << "\033[0m" << endl;
    cout << " - Jouer une nouvelle partie : " << rouge << "Jouer"
         << "\033[0m" << endl;
    cout << " - Afficher les règles: " << rouge << "Règles"
         << "\033[0m" << endl;
}

string IHM::saisirCommandeDeJeu()
{
    string commande;
    cin >> commande;
    return commande;
}

void IHM::afficherDynamiquement(const string& message)
{
    for(char lettre: message)
    {
        cout << lettre << flush;
        this_thread::sleep_for(chrono::milliseconds(20));
    }
}

void IHM::attendreRetourMenu()
{
    string rouge = "\033[1;91m";

    cout << "Tapez '" << rouge << "menu"
         << "\033[0m' pour revenir au menu principal" << endl;
    string commande = "";
    while(commande != "menu")
    {
        cin >> commande;
    }
}
void IHM::effacerLignes(int nombreDeLignes)
{
    string effacerLigne       = "\x1B[2K";
    string deplacerVersLeHaut = "\x1B[A";
    for(int i = 0; i < nombreDeLignes; ++i)
    {
        cout << effacerLigne;
        if(i < nombreDeLignes - 1)
        {
            cout << deplacerVersLeHaut;
        }
    }
}

void IHM::afficherRegles()
{
    cout << "\033[1;34m" << R"(
   _____            _           
  |  __ \          | |          
  | |__) |___  __ _| | ___  ___ 
  |  _  // _ \/ _` | |/ _ \/ __|
  | | \ \  __/ (_| | |  __/\__ \
  |_|  \_\___|\__, |_|\___||___/
               __/ |            
              |___/              
)" << "\033[0m" << endl;

    cout << "1. Le jeu se joue sur un plateau vertical de 6 lignes et horizontal de 7 colonnes." << endl;
    cout << "" << endl;
    cout << "2. Deux joueurs s'affrontent avec des jetons de couleurs différentes "
                 "(\033[1;91mRouge\033[0m et \033[1;93mJaune\033[0m)."
              << endl;
    cout << "" << endl;
    cout << "3. Les joueurs placent tour à tour un jeton dans l'une des colonnes du plateau."
              << endl;
    cout << "" << endl;
    cout << "4. Le jeton tombe au point le plus bas possible dans la colonne choisie."
              << endl;
    cout << "" << endl;
    cout << "5. Le premier joueur qui parvient à aligner quatre de ses jetons consécutifs "
                 "(horizontalement, verticalement ou en diagonale) remporte la partie."
              << endl;
    cout << "" << endl;
    cout << "6. Si le plateau est rempli sans qu'aucun joueur n'ait aligné quatre "
                 "jetons, la partie est déclarée nulle."
              << endl;
    cout << "" << endl;
}
