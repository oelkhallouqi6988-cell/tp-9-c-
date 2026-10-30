
#include <iostream>
#include <string>
using namespace std;

// Classe de base Utilisateur
class Utilisateur {
protected:
    int identifiant;
    string login;

public:
    Utilisateur(int id, string l) {
        identifiant = id;
        login = l;
    }

    void afficherUtilisateur() {
        cout << "Identifiant : " << identifiant << endl;
        cout << "Login : " << login << endl;
    }
};

// Classe Administrateur
class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;

public:
    Administrateur(int id, string l, string droits)
        : Utilisateur(id, l) {
        droitsAcces = droits;
    }

    void gererSysteme() {
        cout << "L'administrateur gere le systeme." << endl;
        cout << "Droits d'acces : " << droitsAcces << endl;
    }
};

// Classe Moderateur
class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;

public:
    Moderateur(int id, string l, int niveau)
        : Utilisateur(id, l) {
        niveauModeration = niveau;
    }

    void modererContenu() {
        cout << "Le moderateur gere le contenu." << endl;
        cout << "Niveau de moderation : "
             << niveauModeration << endl;
    }
};

// Classe SuperUtilisateur
class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    SuperUtilisateur(int id, string l, string droits, int niveau)
        : Utilisateur(id, l),
          Administrateur(id, l, droits),
          Moderateur(id, l, niveau) {
    }

    void afficherTousLesDetails() {
        cout << "\n===== INFORMATIONS DU SUPER UTILISATEUR ====="
             << endl;

        Utilisateur::afficherUtilisateur();

        Administrateur::gererSysteme();

        Moderateur::modererContenu();
    }
};

// Programme principal avec menu
int main() {
    int choix;

    int id;
    string login;
    string droits;
    int niveau;

    SuperUtilisateur* superUser = nullptr;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Creer un SuperUtilisateur" << endl;
        cout << "2. Afficher les informations" << endl;
        cout << "3. Gerer le systeme" << endl;
        cout << "4. Moderer le contenu" << endl;
        cout << "5. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {

        case 1:
            delete superUser;

            cout << "Donner l'identifiant : ";
            cin >> id;

            cout << "Donner le login : ";
            cin >> login;

            cout << "Donner les droits d'acces : ";
            cin >> droits;

            cout << "Donner le niveau de moderation : ";
            cin >> niveau;

            superUser = new SuperUtilisateur(
                id, login, droits, niveau
            );

            cout << "SuperUtilisateur cree avec succes !"
                 << endl;
            break;

        case 2:
            if (superUser != nullptr) {
                superUser->afficherTousLesDetails();
            } else {
                cout << "Veuillez creer un SuperUtilisateur d'abord."
                     << endl;
            }
            break;

        case 3:
            if (superUser != nullptr) {
                superUser->gererSysteme();
            } else {
                cout << "Aucun utilisateur cree !" << endl;
            }
            break;

        case 4:
            if (superUser != nullptr) {
                superUser->modererContenu();
            } else {
                cout << "Aucun utilisateur cree !" << endl;
            }
            break;

        case 5:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 5);

    delete superUser;

    return 0;
}
