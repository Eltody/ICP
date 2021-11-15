<div align="center">
    <h1>VUT FIT ISA</h1>
</div>

# Síťové aplikace a správa sítí - Projekt č.1, varianta č.1
* **Klient POP3 s podporou TLS**

## Zadanie projektu
* **Program po spustení stiahne správy uložené na serveri a uloží ich do zadaného adresára. Na štandardný výstup vypíše počet stiahnutých správ. Pomocou dodatočných parametrov je možné funkcionalitu meniť. Podporovaná je nešifrovaná komunikácia, šifrovaná komunikácia a komunikácia s podporou TLS.**

## Informácie a obmedzenia projektu
* **Povinný parameter <server> (IP adresa, alebo doménové jméno) je nutné zadať ako prvý parameter pri spúšťaní programu.**
* **Program nedokáže správne spracovať parameter -n, pri ktorom sa pracuje len s novými správami.**

## Autor projektu:
* **Tomáš Zaťko (xzatko02)**

## Zoznam odovzdaných súborov:
* **popcl.cpp - zdrojový kód**
* **Makefile - pre preklad zdrojového kódu**
* **manual.pdf - dokumentácia projektu**

## Spustenie programu:
* **$ ./popcl <server> [-p <port>] [-T|-S [-c <certfile>] [-C <certaddr>]] [-d] [-n] -a <auth_file> -o <out_dir>**

## Príklady spustenia:
* **$ make	- pre preklad zdrojového kódu**
* **$ ./popcl --help 	- pre zobrazenie nápovedy**
* **$ ./popcl pop3.seznam.cz -o out_dir -a auth_file 	- pre nešifrovanú komunikáciu**
* **$ ./popcl pop3.seznam.cz -o out_dir -a auth_file -T 	- pre šifrovanú komunikáciu**
* **$ ./popcl pop3.seznam.cz -o out_dir -a auth_file -S		- pre komunikáciu s podporou TLS**
