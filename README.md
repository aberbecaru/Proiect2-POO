# Documentatie

Pentru acest proiect am creat clasa mama Complex_Locuinte, cu variabile protected deoarece le vom accesa in cele 2 clase copil. Dupa aceea am implementat clasele Apartament si Casa.

1. Clasa Complex_Locuinte:
    - este clasa mama
    - am implementat constructori, destructori, set-eri si get-eri
    - am supraincarcat operatorii de citire, de scriere si de atribuire
    - am creat functia virtuala pura **CalculChirie**
    - variabile protected pentru a putea fi accesate in clasele copil
    - de asemenea avem variabila statica, tot protected si ea, pentru a putea fi folosita in functiile statice din clasele copil

Inainte sa inceapa clasa Apartament am setat variabila statica **CumparaMP** la 1200.40.
    
2. Clasa Apartament:
    - clasa copil, are variabile din clasa mama cat si inca 2 variabile separate
    - am implementat constructori, destructori, set-eri si get-eri
    - am supraincarcat operatorii de citire, de scriere si de atribuire
    - am implementat functia CalculChirie pentru aceasta clasa
    - am implementat functia statica CumparaApartament, care are in componenta ei variabila statica setata anterior

3. Clasa Casa:
     -clasa copil, are variabile din clasa mama cat si inca o variabila separata
    - am implementat constructori, destructori, set-eri si get-eri
    - am supraincarcat operatorii de citire, de scriere si de atribuire
    - am implementat functia CalculChirie pentru aceasta clasa
    - am implementat functia statica CumparaCasa, care are in componenta ei variabila statica setata anterior

Dupa aceea urmeaza main-ul, in care am declarat numarul de blocuri(n), numarul de case(m), vectorul baze_de_date din stl de tipul Complex_Locuinta, variabilele mp si AplicareDiscount, care ne vor trebui pentru functia CalculChirie, cat si niste variabile auxiliare. Dupa aceea incepe programul propriu-zis.
Utilizatorul este rugat sa introduca de la tastatura n, numarul de blocuri apoi n date despre aceste blocuri, date ce vor fi memorate in vectorul baze_de_date. La fel procedam si pentru case.
Dupa aceea urmeaza meniul, cu 7 optiuni, ce testeaza toate functiile pe care le-am implementat, cat si afisarea datelor introduse.
Upcasting-ul se realizeaza atunci cand memoram in vectorul de tip Complex_Locuinte date de tip Apartament si Casa
Downcasting-ul se realizaeaza la afisari, atunci cand din vectorul de tip Complex_Locuinte vrem sa afisam doar datele de tip Apartament si Casa.
Folosim tratarea exceptiilor(try-catch) pentru functia CalculChirie, cand ni se cere sa introduce de la tastatura pretul pe mp(care nu poate fi negativ) si AplicareDiscount(1 daca aplicam sau 0 daca nu, dar de la tastatura se pot introduce si alte numere); dar si pentru functia CumparaCasa, unde parametrul functiei, daca este 0, ar insemna ca s-ar realiza o impartire la 0.
