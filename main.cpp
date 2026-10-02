// Supported OS: debian, ubuntu, mint, fedora, arch, manjaro, endeavouros, opensuse, freebsd
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string ver = "b0.4(build-3)";
string selectedOS;
string selectedParagraph;
string selectedNameOfPackage;

int main() {
    cout << "Supported OS: debian, ubuntu, mint, opensuse,\n";
    cout << " fedora, arch, manjaro, endeavouros, freebsd\n";
    cout << "Select OS: ";
    cin >> selectedOS;
    cout << "PROTONIUM " << ver << endl;
    cout << "=-=-=-=-=-=-=-=-=-=" << endl;

    if (selectedOS == "debian" || selectedOS == "ubuntu" || selectedOS == "mint") {
        cout << "[1] - Install from APT\n";
        cout << "[2] - Search package from APT\n";
        cout << "[3] - Update the system\n";
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
                string command = "apt search " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '3': {
                system("sudo apt update && sudo apt upgrade");
                break;
            }
        }
    }
    else if (selectedOS == "fedora") {
        cout << "[1] - Install from DNF\n";
        cout << "[2] - Search package from DNF\n";
        cout << "[3] - Update the system\n";
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
                string command = "dnf search " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '3': {
                system("sudo dnf update");
                break;
            }
        }
    }
    else if (selectedOS == "arch" || selectedOS == "manjaro" || selectedOS == "endeavouros") {
        cout << "[1] - Install from PACMAN\n";
        cout << "[2] - Search package from PACMAN\n";
        cout << "[3] - Update the system\n";
        cout << "[4] - Install yay (recommended for arch)\n";
        cout << "> ";
        cin >> selectedParagraph;

        switch (selectedParagraph[0]) {
            case '1': {
                cout << "Enter the name of the package: ";
                cin >> selectedNameOfPackage;
                string command = "sudo pacman -S --noconfirm " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '2': {
                cout << "Enter the name of the package: ";
                cin >> selectedNameOfPackage;
                string command = "pacman -Ss " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '3': {
                system("sudo pacman -Syu");
                break;
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
    else if (selectedOS == "opensuse") {
        cout << "[1] - Install from ZYPPER\n";
        cout << "[2] - Search package from ZYPPER\n";
        cout << "[3] - Update the system\n";
        cout << "> ";
        cin >> selectedParagraph;

        switch (selectedParagraph[0]) {
            case '1': {
                cout << "Enter the name of package... ";
                cin >> selectedNameOfPackage;
                string command = "sudo zypper -n install " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '2': {
                cout << "Enter the name of the package: ";
                cin >> selectedNameOfPackage;
                string command = "zypper search " + selectedNameOfPackage;
                system(command.c_str());
                break;
            }
            case '3': {
                string selectedOpenSUSE;
                cout << "Enter your OS (tumbleweed, leap): ";
                cin >> selectedOpenSUSE;
                if (selectedOpenSUSE == "tumbleweed") {
                    system("sudo zypper dup");
                } else {
                    system("sudo zypper update");
                }
                break;
            }
        }
    }
    else if (selectedOS == "freebsd") {
        string doasMode;
        cout << "Use doas? (yes/no): ";
        cin >> doasMode;

        cout << "[1] - Install from PKG\n";
        cout << "[2] - Search package from PKG\n";
        cout << "[3] - Update the system\n";
        cout << "> ";
        cin >> selectedParagraph;

        switch (selectedParagraph[0]) {
            case '1': {
                cout << "Enter the name of package... ";
                cin >> selectedNameOfPackage;
                string command;
                if (doasMode == "yes") {
                    command = "doas pkg install -y " + selectedNameOfPackage;
                } else {
                    command = "pkg install -y " + selectedNameOfPackage;
                }
                system(command.c_str());
                break;
            }
            case '2': {
                cout << "Enter the name of the package: ";
                cin >> selectedNameOfPackage;
                string command;
                if (doasMode == "yes") {
                    command = "doas pkg search " + selectedNameOfPackage;
                } else {
                    command = "pkg search " + selectedNameOfPackage;
                }
                system(command.c_str());
                break;
            }
            case '3': {
                if (doasMode == "yes") {
                    system("doas pkg upgrade -y");
                } else {
                    system("pkg upgrade -y");
                }
                break;
            }
        }
    }
    else {
        cout << "Unfortunately, " << ver << " does not support " << selectedOS << " :(\n";
        exit(1);
    }
    return 0;
}
