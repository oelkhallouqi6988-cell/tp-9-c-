
#include <iostream>
#include <string>
using namespace std;

// Classe de base Vehicule
class Vehicule {
protected:
    string marque;
    string modele;

public:
    Vehicule(string m, string mod) {
        marque = m;
        modele = mod;
    }
};

// Classe Thermique
class Thermique : virtual public Vehicule {
protected:
    double consommation;

public:
    Thermique(string m, string mod, double c)
        : Vehicule(m, mod) {
        consommation = c;
    }
};

// Classe Electrique
class Electrique : virtual public Vehicule {
protected:
    double autonomie;

public:
    Electrique(string m, string mod, double a)
        : Vehicule(m, mod) {
        autonomie = a;
    }
};

// Classe Hybride
class Hybride : public Thermique, public Electrique {
public:
    Hybride(string m, string mod, double c, double a)
        : Vehicule(m, mod),
          Thermique(m, mod, c),
          Electrique(m, mod, a) {
    }

    void afficherCaracteristiques() {
        cout << "Marque : " << marque << endl;
        cout << "Modele : " << modele << endl;
        cout << "Consommation carburant : "
             << consommation << " L/100km" << endl;
        cout << "Autonomie batterie : "
             << autonomie << " km" << endl;
    }
};

// Fonction principale
int main() {

    Hybride v1("Toyota", "Prius", 4.5, 50);

    v1.afficherCaracteristiques();

    return 0;
}
