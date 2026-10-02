// Supported OS: debian, ubuntu, mint, fedora, arch, manjaro, endeavouros
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string ver = "v0.3";
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
        cout << "[3] - Install Chrome\n";
        cout << "[4] - Install GIMP\n";
        cout << "[5] - Install OBS Studio\n";
        cout << "[6] - Install Libreoffice\n";
        cout << "[7] - Install Steam\n";
        cout << "[8] - Install Telegram (Flatpak)\n";
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
                system("wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb");
                int result = system("sudo dpkg -i google-chrome-stable_current_amd64.deb");
                if (result == 0) {
                    cout << "[OK] - Install Chrome\n";
                } else {
                    cout << "[FAIL] - Install Chrome\n";
                    exit(1);
                }
                break;
            }
            case '4': {
                int result = system("sudo apt-get install -y gimp");
                if (result == 0) {
                    cout << "[OK] - Install GIMP\n";
                } else {
                    cout << "[FAIL] - Install GIMP\n";
                    exit(1);
                }
                break;
            }
            case '5': {
                int result = system("sudo add-apt-repository -y ppa:obsproject/obs-studio");
                if (result == 0) {
                    cout << "[OK] - Add Repository OBS Studio\n";
                } else {
                    cout << "[FAIL] - Add Repository OBS Studio\n";
                    exit(1);
                }
                result = system("sudo apt install -y obs-studio");
                if (result == 0) {
                    cout << "[OK] - Install OBS Studio\n";
                } else {
                    cout << "[FAIL] - Install OBS Studio\n";
                    exit(1);
                }
                break;
            }
            case '6': {
                int result = system("sudo apt-get install -y libreoffice");
                if (result == 0) {
                    cout << "[OK] - Install Libreoffice\n";
                } else {
                    cout << "[FAIL] - Install Libreoffice\n";
                    exit(1);
                }
                break;
            }
            case '7': {
                int result = system("sudo apt install -y steam-installer");
                if (result == 0) {
                    cout << "[OK] - Install Steam\n";
                } else {
                    cout << "[FAIL] - Install Steam\n";
                    exit(1);
                }
                break;
            }
            case '8': {
                int result = system("flatpak install flathub org.telegram.desktop");
                if (result == 0) {
                    cout << "[OK] - Install Telegram\n";
                } else {
                    cout << "[FAIL] - Install Telegram\n";
                    exit(1);
                }
                break;
            }
        }
    }
    else if (selectedOS == "fedora") {
        cout << "[1] - Install from DNF\n";
        cout << "[2] - Search package from DNF\n ";
        cout << "[3] - Install Chrome\n";
        cout << "[4] - Install GIMP\n";
        cout << "[5] - Install OBS Studio\n";
        cout << "[6] - Install Steam\n";
        cout << "[7] - Install Telegram (Flatpak)\n";
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
                int result = system("sudo dnf install -y https://dl.google.com/linux/direct/google-chrome-stable_current_x86_64.rpm");
                if (result == 0) {
                    cout << "[OK] - Install Chrome\n";
                } else {
                    cout << "[FAIL] - Install Chrome\n";
                    exit(1);
                }
                break;
            }
            case '4': {
                int result = system("sudo dnf install -y gimp");
                if (result == 0) {
                    cout << "[OK] - Install GIMP\n";
                } else {
                    cout << "[FAIL] - Install GIMP\n";
                    exit(1);
                }
                break;
            }
            case '5': {
                int result = system("sudo dnf install -y obs-studio");
                if (result == 0) {
                    cout << "[OK] - Install OBS Studio\n";
                } else {
                    cout << "[FAIL] - Install OBS Studio\n";
                    exit(1);
                }
                break;
            }
            case '6': {
                int result = system("sudo dnf install -y steam");
                if (result == 0) {
                    cout << "[OK] - Install Steam\n";
                } else {
                    cout << "[FAIL] - Install Steam\n";
                    exit(1);
                }
                break;
            }
            case '7': {
                int result = system("flatpak install flathub org.telegram.desktop");
                if (result == 0) {
                    cout << "[OK] - Install Telegram\n";
                } else {
                    cout << "[FAIL] - Install Telegram\n";
                    exit(1);
                }
                break;
            }
        }
    }
    else if (selectedOS == "arch" || selectedOS == "manjaro" || selectedOS == "endeavouros") {
        cout << "[1] - Install from PACMAN\n";
        cout << "[2] - Search package from PACMAN\n ";
        cout << "[3] - Install Firefox\n";
        cout << "[4] - Install GIMP\n";
        cout << "[5] - Install OBS Studio\n";
        cout << "[6] - Install Steam (multilib required)\n";
        cout << "[7] - Install Telegram\n";
        cout << "[8] - Install yay (recommended for arch)\n";
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
                int result = system("sudo pacman -S --noconfirm firefox");
                if (result == 0) {
                    cout << "[OK] - Install Firefox\n";
                } else {
                    cout << "[FAIL] - Install Firefox\n";
                    exit(1);
                }
                break;
            }
            case '4': {
                int result = system("sudo pacman -S --noconfirm gimp");
                if (result == 0) {
                    cout << "[OK] - Install GIMP\n";
                } else {
                    cout << "[FAIL] - Install GIMP\n";
                    exit(1);
                }
                break;
            }
            case '5': {
                int result = system("sudo pacman -S --noconfirm obs-studio");
                if (result == 0) {
                    cout << "[OK] - Install OBS Studio\n";
                } else {
                    cout << "[FAIL] - Install OBS Studio\n";
                    exit(1);
                }
                break;
            }
            case '6': {
                int result = system("sudo pacman -S --noconfirm steam > /dev/null");
                if (result == 0) {
                    cout << "[OK] - Install Steam\n";
                } else {
                    cout << "[FAIL] - Install Steam\n";
                    exit(1);
                }
                break;
            }
            case '7': {
                int result = system("sudo pacman -S --noconfirm telegram-desktop");
                if (result == 0) {
                    cout << "[OK] - Install Telegram\n";
                } else {
                    cout << "[FAIL] - Install Telegram\n";
                    exit(1);
                }
                break;
            }
            case '8': {
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