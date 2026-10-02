// Supported OS: debian, ubuntu, mint, fedora, arch, manjaro, endeavouros
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string ver = "v0.3(1)";
string selectedOS;
string selectedParagraph;
string selectedNameOfPackage;

int main() {
    cout << "Supported OS: debian, ubuntu, mint,\n";
    cout << " fedora, arch, manjaro, endeavouros\n";
    cout << "Select OS: ";
    cin >> selectedOS;
    cout << "PROTONIUM " << ver << endl;
    cout << "=-=-=-=-=-=-=-=-=-=" << endl;

    if (selectedOS == "debian" || selectedOS == "ubuntu" || selectedOS == "mint") {
        cout << "[1] - Install from APT\n";
        cout << "[2] - Search package from APT\n ";
        cout << "[3] - Update the system)\n";
        cout << "> ";
        cin >> selectedParagraph;

        switch (selectedParagraph[0]) {
            case '1': {
                cout << "Enter a name of package... ";
                cin >> selectedNameOfPackage;
                string command = "sudo apt install -y " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '2': {
                cout << "Enter a name of package... ";
                cin >> selectedNameOfPackage;
                string command = "sudo apt search " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '3': {
                system("sudo apt update && sudo apt upgrade");
            }
        }
    }
    else if (selectedOS == "fedora") {
        cout << "[1] - Install from DNF\n";
        cout << "[2] - Search package from DNF\n ";
        cout << "[3] - Update the system)\n]";
        cout << "> ";
        cin >> selectedParagraph;

        switch (selectedParagraph[0]) {
            case '1': {
                cout << "Enter the name of the package: ";
                cin >> selectedNameOfPackage;
                string command = "sudo dnf install -y " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '2': {
                cout << "Enter the name of the package: ";
                cin >> selectedNameOfPackage;
                string command = "sudo dnf search " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
          case '3': {
              system("sudo dnf update");
          }
        }
    }
    else if (selectedOS == "arch" || selectedOS == "manjaro" || selectedOS == "endeavouros") {
        cout << "[1] - Install from PACMAN\n";
        cout << "[2] - Search package from PACMAN\n ";
        cout << "[3] - Update the system)\n]";
        cout << "[4] - Install yay (recommended for arch)\n";
        cout << "> ";
        cin >> selectedParagraph;

        switch (selectedParagraph[0]) {
            case '1': {
                cout << "Enter the name of the package: ";
                cin >> selectedNameOfPackage;
                string command = "sudo pacman -Sy --noconfirm " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '2': {
                cout << "Enter the name of the package: ";
                cin >> selectedNameOfPackage;
                string command = "sudo pacman -Ss " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '3': {
                system("sudo pacman -Syu");
            }
            case '4': {
                int result = system("sudo pacman -S --needed --noconfirm git base-devel");
                if (result == 0) {
                    cout << "[OK] - Install dependencies\n";
                } else {
                    cout << "[FAIL] - Install dependencies\n";
                    exit(1);
                }
                result = system("git clone https://aur.archlinux.org/yay.git /tmp/yay");
                if (result == 0) {
                    cout << "[OK] - Clone the repository\n";
                } else {
                    cout << "[FAIL] - Clone the repository\n";
                    exit(1);
                }
                result = system("cd /tmp/yay && makepkg -si --noconfirm");
                if (result == 0) {
                    cout << "[OK] - Compiling\n";
                } else {
                    cout << "[FAIL] - Compiling\n";
                    exit(1);
                }
                break;
            }
        }
    }
    else {
        cout << "Unfortunately, " << ver << " does not support " << selectedOS << " :(" << endl;
        exit(1);
    }
    return 0;
}