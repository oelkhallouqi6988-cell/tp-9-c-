
#include <iostream>
#include <string>
using namespace std;

// Classe Personne
class Personne {
protected:
    string nom;
    string prenom;

public:
    Personne(string n, string p) {
        nom = n;
        prenom = p;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Prenom : " << prenom << endl;
    }
};

// Classe Chercheur
class Chercheur {
protected:
    string domaineRecherche;

public:
    Chercheur(string domaine) {
        domaineRecherche = domaine;
    }

    void afficher() {
        cout << "Domaine de recherche : "
             << domaineRecherche << endl;
    }
};

// Classe EnseignantChercheur
class EnseignantChercheur : public Personne, public Chercheur {
public:
    EnseignantChercheur(string n, string p, string domaine)
        : Personne(n, p), Chercheur(domaine) {
    }

    void afficher() {
        Personne::afficher();
        Chercheur::afficher();
    }
};

// Fonction principale
int main() {

    EnseignantChercheur e1(
        "Alami",
        "Ahmed",
        "Informatique"
    );

    e1.afficher();

    return 0;
}
