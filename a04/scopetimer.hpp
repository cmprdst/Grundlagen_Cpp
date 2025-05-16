#pragma once

#include <ctime> // Use the function std::clock() to measure time.

// The ScopeTimer measures the time between construction and
// destruction and writes it formatted with its name to the console.
class ScopeTimer {
public:
    // Define the constructor and destructor in scopetimer.cpp
    ScopeTimer(const char *name);

    ~ScopeTimer();

private:
    // ToDo: Data members?
    const char *name = "noname"; // Inhalt const, Zeiger nicht → Zeiger wird bei Initialisierung verändert
    std::clock_t time_stamp = 0;
    int instance_num = 0;
    static int max_instances;
};

/** Klassen-Invarianten (Bedingungen, die bei Konstruktion einer Instanz und während ihrer Existenz erfüllt sein müssen)
 *  const char *name != nullptr (sonst NullPointerException) → verhindert durch Abfrage in Konstruktor
 *  int time_stamp wird durch std::clock() auf sinnvollen Wert gesetzt
 *  static int max_instances >= 0 (weniger als 0 Instanzen unsinnig) → default 0, wird in Konstruktor nur inkrementiert
 *      → weniger als 0 Instanzen nicht möglich (Overflow ausgenommen)
 *      → int instance_num orientiert sich an max_instances, kann also auch nur >= 0 sein.
 *
 *  Außerdem: Timer(w01) + Timer(w02) + Timer(w03) < Timer(main) (Timer(main) als 1. erzeugt und als letztes gelöscht)
*/
