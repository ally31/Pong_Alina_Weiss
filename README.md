# PongGame

![PongGame screenshot](/PongGame/screenshot/gameplay.png)

## Über das Projekt

**PongGame** ist eine einfache Implementierung des klassischen Pong-Spiels in C++ unter Verwendung der [Raylib](https://www.raylib.com/) Bibliothek. Dieses Projekt dient dazu, meine Fähigkeiten in C++, Spielentwicklung und der Nutzung von CMake zur Projektverwaltung zu demonstrieren.

## Features

- Einfaches Pong-Gameplay mit zwei Paddles und einem Ball
- Kollisionserkennung zwischen Ball und Paddles/Wänden
- Einfache Benutzeroberfläche mit Raylib-Grafiken

## Voraussetzungen

- **C++ Compiler**: Empfohlen wird GCC, Clang oder MSVC.
- **CMake**: Version 3.11 oder höher.
- **Git**: Für das Klonen des Repositories.

## Installation

1. **Repository klonen**:
   ```bash
   git clone https://github.com/ally31/Pong_Alina_Weiss.git
   cd PongGame

2. **Build-Verzeichnis erstellen und zum Build-Verzeichnis navigieren**:
   ```bash
   mkdir build
   cd build
   
3. **Projekt mit CMake konfigurieren**:
   ```bash
   cmake ..

4. **Projekt bauen**:
   ```bash
   cmake --build .

5. **Ausführen**:
   ```bash
  ./PongGame  # Unix (Linux/macOS)
  
  PongGame.exe  # Windows
