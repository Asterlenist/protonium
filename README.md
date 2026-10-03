<img width="2000" height="1000" alt="gtrs" src="https://github.com/user-attachments/assets/079b22b2-df02-478b-9265-e179eae79632" />

# Protonium

A simple package installer for Linux and FreeBSD. Install, search, and update packages using your distribution's native package manager — all from one menu.

## Supported OS

- Debian / Ubuntu / Mint (APT)
- Fedora (DNF)
- Arch / Manjaro / EndeavourOS (PACMAN + AUR)
- openSUSE (ZYPPER)
- FreeBSD (PKG, doas/root)

## Features

- Install packages via native package manager (APT, DNF, PACMAN, ZYPPER, PKG)
- Search packages
- Update the system
- Install via Flatpak (Debian, Fedora, Arch, openSUSE)
- Install yay on Arch (AUR helper)
- Support `doas` on FreeBSD

## Requirements

- C++ compiler (`g++` or `clang++`)
- Git (for installing yay on Arch)
- Flatpak (optional, for Flatpak installation)

## Build

```bash
git clone https://github.com/Asterlenist/protonium.git
cd protonium
g++ main.cpp -o protonium
./protonium
