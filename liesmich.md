# intervalTimer
Arduino millis() based intervalTimer library

Diese Bibliothek implementiert eine C++ Klasse welche es ermöglicht, innerhalb von Funktionen den Aufruf
von Codeteilen in zeitlichen Abständen zu steuern. Die Arduino Funktion millis() wird benötigt.

Zur Parametrierung werden drei Attribute verwendet:

* uint32_t time - Die Zeit zwischen zwei Intervallen in Millisekunden.
* bool active - Aktiviert und deaktiviert den Intervalltimer.
* int count - Die Anzahl der Zyklen. -1 für eine unbegrenzte Anzahl.

Folgende Methoden werden unterstützt:

* constructor - Keine Parameter, Standardwerte: time 1000; active false; count -1.
* constructor(time) - Setzt time, Standardwerte: active false; count -1.
* constructor(time,active) - Setzt time und active, Standardwerte: count -1.
* constructor(time,active,count) - Setzt time, active und count.
* enable() - Setzt active auf true.
* disable() - Setzt active auf false.
* reset() - Die Intervallzeit und der Wiederholungszähler werden auf den Startwert gesetzt.
* set(time) - Setzt time.
* set(time,active) - Setzt time und active.
* set(time,active,count) - Setzt time, active und count.
* check() - Prüft ob das nächste Intervall erreicht wurde. Gibt true oder false zurück.