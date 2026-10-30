
#include <iostream>
using namespace std;

// Classe Technicien
class Technicien {
protected:
    double salaire;

public:
    Technicien(double s) {
        salaire = s;
    }

    void afficherSalaire() {
        cout << "Salaire Technicien : "
             << salaire << " DH" << endl;
    }
};

// Classe Comptable
class Comptable {
protected:
    double salaire;

public:
    Comptable(double s) {
        salaire = s;
    }

    void afficherSalaire() {
        cout << "Salaire Comptable : "
             << salaire << " DH" << endl;
    }
};

// Classe EmployePolyvalent
class EmployePolyvalent : public Technicien, public Comptable {
public:
    EmployePolyvalent(double salaireTech, double salaireComp)
        : Technicien(salaireTech), Comptable(salaireComp) {
    }

    void afficherTousSalaires() {
        Technicien::afficherSalaire();
        Comptable::afficherSalaire();
    }
};

// Fonction principale
int main() {

    EmployePolyvalent e1(5000, 6000);

    e1.afficherTousSalaires();

    return 0;
}
