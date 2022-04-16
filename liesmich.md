# intervalTimer
Arduino millis() based intervalTimer library

Diese Bibliothek implementiert eine C++ Klasse welche es ermöglicht, den Aufruf von Codeteilen
oder Funktionen in zeitlichen Abständen zu steuern. Die Arduino Funktion millis() wird benötigt.

Zur Parametrisierung werden vier Attribute verwendet:

* uint32_t time - Die Zeit zwischen zwei Intervallen in Millisekunden. (Standardwert 1000)
* bool active - Aktiviert und deaktiviert den Intervalltimer. (Standardwert false)
* int count - Die Anzahl der Zyklen. -1 für eine unbegrenzte Anzahl. (Standardwert -1)
* void call - Ein Zeiger auf eine Funktion. (Standard nullptr)

Folgende Methoden werden unterstützt:

* constructor(time,active,count,call)
* enable() - Setzt active auf true.
* disable() - Setzt active auf false.
* reset() - Die Intervallzeit und der Wiederholungszähler werden auf den Startwert gesetzt.
* set(time,active,count,call)
* check() - Prüft ob das nächste Intervall erreicht wurde. Gibt true oder false zurück. Ruft eine Funktion auf wenn call kein nullptr ist.

### Einfaches Beispiel
Gibt einmal pro Sekunde "exampleOne" auf der seriellen Schnittstelle aus.

    #include "intervalTimer.h"
    
    void doExampleOne() { Serial.println("exampleOne"); }
    
    intervalTimer exampleOne(1000,true,-1,doExampleOne);
    
    void setup() { Serial.begin(115200); }
    
    void loop() { exampleOne.check(); }