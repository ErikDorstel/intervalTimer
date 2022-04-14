# intervalTimer
Arduino millis() based intervalTimer library

Diese Bibliothek implementiert eine C++ Klasse welche es ermöglicht, den Aufruf von Codeteilen
oder Funktionen in zeitlichen Abständen zu steuern. Die Arduino Funktion millis() wird benötigt.

Zur Parametrisierung werden vier Attribute verwendet:

* uint32_t time - Die Zeit zwischen zwei Intervallen in Millisekunden. (Standardwert 1000)
* bool active - Aktiviert und deaktiviert den Intervalltimer. (Standardwert false)
* int count - Die Anzahl der Zyklen. -1 für eine unbegrenzte Anzahl. (Standardwert -1)
* void call - Ein Zeiger auf eine Funktion. (Standardwert NULL)

Folgende Methoden werden unterstützt:

* constructor - Keine Parameter, alle Attribute nutzen die Standardwerte.
* constructor(time) - Setzt time.
* constructor(time,active) - Setzt time und active.
* constructor(time,active,count) - Setzt time, active und count.
* constructor(time,active,count,call) - Setzt time, active, count und call.
* enable() - Setzt active auf true.
* disable() - Setzt active auf false.
* reset() - Die Intervallzeit und der Wiederholungszähler werden auf den Startwert gesetzt.
* set(time) - Setzt time.
* set(time,active) - Setzt time und active.
* set(time,active,count) - Setzt time, active und count.
* set(time,active,count,call) - Setzt time, active, count und call.
* check() - Prüft ob das nächste Intervall erreicht wurde. Gibt true oder false zurück. Ruft eine Funktion auf wenn call nicht NULL ist.

### Einfaches Beispiel
Gibt einmal pro Sekunde "exampleOne" auf der seriellen Schnittstelle aus.

    #include "intervalTimer.h"
    
    void doExampleOne() { Serial.println("exampleOne"); }
    
    intervalTimer exampleOne(1000,true,-1,doExampleOne);
    
    void setup() { Serial.begin(115200); }
    
    void loop() { exampleOne.check(); }