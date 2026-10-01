// Supported OS: debian, ubuntu, mint, fedora, arch, manjaro, endeavouros
#include <iostream>
#include <string>
using namespace std;
string ver = "v0.2";
string selectedOS;
string selectedParagraph;

int main() {
    cout << "Supported OS: debian, ubuntu, mint,\n";
    cout << " fedora, arch, manjaro, endeavouros\n";
    cout << "Select OS: ";
    cin >> selectedOS;
    cout << "PROTONIUM " << ver << endl;
    cout << "=-=-=-=-=-=-=-=-=-=" << endl;

    if (selectedOS == "debian" || selectedOS == "ubuntu" || selectedOS == "mint") {
        cout << "[1] - Install Chrome\n";
        cout << "[2] - Install GIMP\n";
        cout << "[3] - Install OBS Studio\n";
        cout << "[4] - Install Libreoffice\n";
        cout << "[5] - Install Steam\n";
        cout << "[6] - Install Telegram\n";
        cout << "> ";
        cin >> selectedParagraph;
        switch (selectedParagraph[0]) {
            case '1':
                system("wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb");
                system("sudo dpkg -i google-chrome-stable_current_amd64.deb");
                break;
            case '2':
                system("sudo apt-get install -y gimp");
                break;
            case '3':
                system("sudo add-apt-repository ppa:obsproject/obs-studio");
                system("sudo apt install -y obs-studio");
                break;
            case '4':
                system("sudo apt-get install -y libreoffice");
                break;
            case '5':
                system("sudo apt install -y steam-installer");
                break;
            case '6':
                system("sudo apt install -y telegram-desktop");
                break;
        }
    }
    else if (selectedOS == "fedora") {
        cout << "[1] - Install Chrome\n";
        cout << "[2] - Install GIMP\n";
        cout << "[3] - Install OBS Studio\n";
        cout << "[4] - Install Steam\n";
        cout << "[5] - Install Telegram\n";
        cout << "> ";
        cin >> selectedParagraph;
        switch (selectedParagraph[0]) {
            case '1':
//                system("wget https://dl.google.com/linux/direct/google-chrome-stable_current_x86_64.rpm");
                system("sudo dnf install -y https://dl.google.com/linux/direct/google-chrome-stable_current_x86_64.rpm");
                break;
            case '2':
                system("sudo dnf install -y gimp");
                break;
            case '3':
                system("sudo dnf install -y obs-studio");
                break;
            case '4':
                system("sudo dnf install -y steam");
                break;
            case '5':
                system("sudo dnf install -y telegram-desktop");
                break;
        }
    }
    else if (selectedOS == "arch" || selectedOS == "manjaro" || selectedOS == "endeavouros") {
        cout << "[1] - Install Firefox\n";
        cout << "[2] - Install GIMP\n";
        cout << "[3] - Install OBS Studio\n";
        cout << "[4] - Install Steam (multilib required)\n";
        cout << "[5] - Install Telegram\n";
        cout << "[6] - Install yay\n";
        cout << "> ";
        cin >> selectedParagraph;
        switch (selectedParagraph[0]) {
            case '1':
                system("sudo pacman -S firefox");
                break;
                case '2':
                system("sudo pacman -S gimp");
                break;
                case '3':
                system("sudo pacman -S obs-studio");
                break;
                case '4':
                system("sudo pacman -S steam");
                break;
                case '5':
                system("sudo pacman -S telegram-desktop");
                break;
                case '6':
                system("sudo pacman -S git base-devel");
                system("git clone https://aur.archlinux.org/yay.git");
                system("cd yay");
                system("makepkg -i");
                break;
        }
    }
    else {
        cout << "Unfortunately, " << ver << " does not support " << selectedOS << " :(" << endl;
        exit(1);
    }

    return 0;
}