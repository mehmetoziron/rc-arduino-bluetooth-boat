# rc-arduino-bluetooth-boat
Arduino-basiertes RC-Boot-Projekt, das von Android gesteuert wird.
# RC Bluetooth-gesteuertes Boot 🚤📡

Dieses Projekt ist ein RC-Boot (ferngesteuertes Boot), das über ein Android-Telefon per Bluetooth gesteuert wird. Das Boot empfängt Befehle über ein HC-05-Bluetooth-Modul und steuert Motoren mit Hilfe eines Arduino Nano.

---

## 📌 Merkmale

- Drahtlose Steuerung mit der Android-App „Arduino Car“
  (https://play.google.com/store/apps/details?id=com.electro_tex.bluetoothcar&pcampaignid=web_share)
- Bluetooth-Kommunikation mit HC-05 Modul
- Steuerung von zwei DC-Motoren und einem Servo (vorwärts, rückwärts, rechts, links)
- Einfache und leichte Arduino-Codebasis
- Leicht aufzubauen mit gängigen Elektronikkomponenten

---

## 🛠 Verwendete Hardware

- Arduino Nano (auch andere Arduino-Modelle möglich)
- HC-05 Bluetooth-Modul
- L298N Motortreiber
- 2x DC Motor (R390)
- 1x SG90 Servomotor
- 4x 18650 Lithium-Akku (12–16V)
- Bootsgehäuse (3D-gedruckt oder handgefertigt)
- 5000µF Kondensator (> 5V)
- Ein/Aus-Schalter

---

## 📱 Android-App

- Verwendete App: `Arduino Car`  
  Play Store Link: https://play.google.com/store/apps/details?id=com.electro_tex.bluetoothcar&pcampaignid=web_share

### Tastenbelegung:

- Vorwärts (D): 'M'
- Rückwärts (R): 'm'
- Gasstufe: "J0-8"
- Links: 'L'
- Rechts: 'R'
- Geradeaus: 'S' (wird gesendet, wenn Links-/Rechts-Taste losgelassen wird)
- Kalibrierung: 'X' & 'Y'
- Kalibrierung zurücksetzen: 'N' & 'n'

> Hinweis: Zusätzliche Funktionen können mit Tasten wie Q, F, E, Z, G, C, K0–8 hinzugefügt werden.

---

## 🧠 Funktionsweise

1. Die Android-App sendet Steuerzeichen über Bluetooth (z. B. 'M', 'R', 'L', "J0-8")
2. Der Arduino liest diese Zeichen über die serielle Schnittstelle
3. Entsprechend steuert der Arduino den L298N-Motortreiber
4. Das Boot bewegt sich gemäß den erhaltenen Befehlen

---

## 🔌 Schaltplan

> (Hier ein Bild des Verdrahtungsplans einfügen)

![Schaltplan](resources/wiring_diagram.png)

---

## 🚀 Einrichtung

1. Die Datei `bluetooth_boat.ino` auf den Arduino hochladen
2. Verkabelung gemäß Schaltplan vornehmen
3. Android-App "Arduino Car" öffnen und mit dem HC-05 koppeln (PIN ist normalerweise `1234` oder `0000`)
4. Im Menü die Tastencodes prüfen
5. Jetzt kann die Fahrt beginnen!

---

## 📸 Projektbilder

> (Hier ein Bild vom fertigen Boot einfügen)

![Bootsbild](resources/boat_image.jpg)

---

## 📄 Lizenz

Copyright (c) 2025 Mehmet Özdemir

Die Nutzung dieser Software ist unter der MIT-Lizenz erlaubt:

Die Software darf kostenlos verwendet, kopiert, verändert, zusammengeführt, veröffentlicht, verteilt, unterlizenziert und/oder verkauft werden. Es ist nur notwendig, diesen Lizenztext beizufügen und den Urheber zu nennen.

DIE SOFTWARE WIRD OHNE JEDE GARANTIE ZUR VERFÜGUNG GESTELLT.

Für weitere Informationen siehe die Datei [LICENSE].

---

## ✨ Entwickler

**Name:** Mehmet Özdemir  
**GitHub:** [https://github.com/mehmetoziron](https://github.com/mehmetoziron)
