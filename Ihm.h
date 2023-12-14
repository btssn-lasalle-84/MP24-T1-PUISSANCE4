#ifndef IHM_H
#define IHM_H

#include <string>

class Joueur;
class IHM
{
  private:
    static int nbLignesASupprimer;

  public:
    static std::string saisieNomJoueur(int numeroJoueur);
    static void        afficherMessageTour(const Joueur& joueur);
    static void        afficherVictoire(Joueur* joueur);
    static void        afficherMenu();
    static std::string saisirCommandeDeJeu();
    static void        attendreRetourMenu();
    static void        afficherDynamiquement(const std::string& message);
    static void        effacerTout();
    static void        effacerLignes();
    static void        effacerLignes(int nombreDeLignes);
    static void        effacerSaisie();
    static void        compterNbLignes(const std::string& texte);
    static void        mettreZeroNbLignesASupprimer();
    static void        afficherTexte(const std::string& texte);
};

#endif // IHM_H
