# VU-OP-Nr.2-Studentu-pazymiai

Ši programa nuskaito vartotojo įvedamus duomenis apie studentus ir juos išveda į konsolę kartu su jų galutiniu balu (kuris gali būti apskaičiuotas su mediana arba vidurkiu).

## Versijos

* [v0.1](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.1): pirmoji programos versija, kurioje nuskaitomi studentų duomenys bei išvedamas jų galutinis balas. Šiam skaičiavimui gali būti pasitelkta mediana arba vidurkis. Pažymių įvedimo metu programa veikia net ir nežinant pažymių skaičiaus, jų įvedimą galima sustabdyti įvedant -1. Pažymiai taip pat gali būti generuojami atsitiktinai. Be to, yra dvi šios programos versijos, kurios skiriasi duomenų saugojimu - vienoje duomenys saugojami masyvuose, kitoje - vektoriuose.
* [v0.2](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.2.1): antroji programos versija, kurioje galima pasirinkti, ar norima nuskaityti duomenis iš failo (tuomet jie bus išvedami į failą "rez.txt". Studentų duomenys yra surūšiuojami pagal jų vardus (jei jie vienodi, tada pagal pavardę).
* [v0.3](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.3.1): trečioji programos versija, kurioje funkcijos ir struktūros perkeltos į atitinkamus .h arba .cpp failus. Taip pat panaudotas išimčių valdymas (su try/catch, std::vector.at()).
* [v0.4](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.4): ketvirtoji programos versija, kurioje studentai rūšiuojami į dvi grupes (geriečius ir blogiečius) pagal jų balus. Taip pat nuo šios versijos galima atlikti programos veikimo spartos testą (t.y. sugeneruojamas 10^n (n ∈ [3,7]) įrašų failas su studentais ir jų pažymiais; tuomet tie duomenys nuskaitomi ir apdorojami. Toliau seka studentų rūšiavimas į dvi minėtas grupes. Galiausiai abi šios grupės išvedamos į atitinkamus failus.).
* [v0.5](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.5): penktoji programos versija, kurioje galima atlikti bandymus su įvairiais konteinerių tipais (t.y. atlikti ketvirtoje versijoje implementuotą programos veikimo spartos testą su konteineriais std::list bei std::deque (prieš tai testas buvo atliekamas su std::vector tipo konteineriu). Testo rezultatus ir komentarus galima peržiūrėti žemiau (žr. [Programos spartos veikimo testas](#greitis)).
* [v1.0](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v1.0): šioje versijoje pridėtas makefile, taip pat patobulintas konteinerių spartos testavimas - dabar galima pasirinkti, kurį iš dviejų metodų naudos programa; t.y. ar studentai bus skirstomi į du naujus (geriečių ir blogiečių) konteinerius, ar į naują konteinerį bus perkelti tik blogiečiai. Šie metodai buvo pratestuoti, rezultatus galima peržiūrėti žemiau (žr. [Testo rezultatai (1 variantas)](#greitis1) bei [Testo rezultatai (2 variantas)](#greitis2)).

## Diegimas

Atsisiųskite norimą versiją iš repozitorijos releas'ų (prireikus iškelkite .cpp ir .h failus iš aplanko su pasirinkta programa, pvz. WinRar). Tuomet sukompiliuokite norimoje programoje ar aplinkoje (arba su kitais įrankiais):
```shell
g++ -o program main.cpp funkcijos.cpp -O2
```
Nuo versijos [v1.0](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v1.0) galima naudotis makefile komandomis:
```shell
mingw32-make
```
Svarbu, kad aplinkoje būtų palaikomas C++11 standartas. Galiausiai lieka tik paleisti .exe failą:
```shell
.\program.exe
```

## Programos spartos veikimo testas

Paleidus programą vartotojo klausiama, ar jis norėtų atlikti programos veikimo spartos testą:
```shell
Ar norite atlikti programos veikimo spartos testa? Iveskite t/n:
t
```
Jei vartotojas pasirinktų atlikti šį testą, jo bus klausiama, kurį konteinerio tipą jis norėtų naudoti testavimui:
```shell
Su kokiu konteineriu norite atlikti si testa?

0 - vektorius
1 - list'as
2 - deque
3 - atsaukti testa
Iveskite sveikaji skaiciu nuo 0 iki 3:
0
```
Pasirinkus norimą konteinerio tipą, vartotojo bus klausiama, kokį studentų skirstymo būdą naudotų programa:
```shell
Kokia strategija norite naudoti rusiavimui?
0 - Studentai ikeliami i du naujus konteinerius (blogieciai/gerieciai)
1 - Studentai ikeliami tik i blogieciu konteineri, gerieciai paliekami studentu konteineryje
Iveskite 0 arba 1:
0
```
Tuomet būtų pradėtas testavimas su 1000 studentų failo generavimu (jei failas nesugeneruotas iš anksto), nuskaitymu, apdorojimu bei dviejų studentų grupių išvedimu.
Vartotojas galės pasirinkti ar jis nori tęsti darbą su 10 kartų didesniu failu (max dydis - 10000000), ar baigti programos darbą.

Štai kaip atrodytų pavyzdinis tokio testo variantas, kai vartotojas pasirenka testuoti programos spartą tik su 1000 įrašų:
```shell
Ar norite atlikti programos veikimo spartos testa? Iveskite t/n:
t
Su kokiu konteineriu norite atlikti si testa?

0 - vektorius
1 - list'as
2 - deque
3 - atsaukti testa
Iveskite sveikaji skaiciu nuo 0 iki 3:
0

Kokia strategija norite naudoti rusiavimui?
0 - Studentai ikeliami i du naujus konteinerius (blogieciai/gerieciai)
1 - Studentai ikeliami tik i blogieciu konteineri, gerieciai paliekami studentu konteineryje
Iveskite 0 arba 1:
0

Programos veikimo spartos testas su 1000 studentu pradetas.

Sugeneruotas 1000 dydzio failas.
1000 studentu failo generavimas uztruko 0.00744258 s.
Duomenys nuskaityti.
Duomenu (1000 studentu) nuskaitymas is failo uztruko 0.00431587 s.
1000 studentu rusiavimas (kartu su pirmojo vektoriaus panaikinimu) uztruko 0.000255042 s.
Duomenys isvesti i faila 'Atsakymai/rez_gerieciai1000.txt'.
1000 studentu (gerieciu) isvedimas i faila 'Atsakymai/rez_gerieciai1000.txt' uztruko 0.000867968 s.
Duomenys isvesti i faila 'Atsakymai/rez_blogieciai1000.txt'.
1000 studentu (blogieciu) isvedimas i faila 'Atsakymai/rez_blogieciai1000.txt' uztruko 0.000743896 s.

1000 irasu testas uztruko 0.0137102 s.

Ar norite toliau testuoti (kitas testas - su 10000 irasu)? Iveskite t/n: 
n
Programos darbas baigtas.
```

### <a name="greitis1"></a>Testo rezultatai (1 variantas)

Testavimas (abiem atvejais) atliktas su:
* CPU - Intel Core i5-4670 @3.40GHz
* RAM - 8 GB (1333 MHz)
* SSD - ADATA SP900 (120 GB)

Nuo v1.0 versijos galima rinktis, kaip skirstomi studentai, **čia pavaizduotas pirmasis variantas, t.y. kai studentai skirstomi į du naujus konteinerius**.
Žemiau pateikiami tokio atlikto testo rezultatai.

#### Vector

| Programos etapas        | 1000 (10^3)   | 10000 (10^4) | 100000 (10^5) | 1000000 (10^6) | 10000000 (10^7) |
| :---------------------- | :------------ | :----------- | :------------ | :------------- | :-------------- |
| Nuskaitymas iš failo    | 0.00799       | 0.05696      | 0.50371       | 4.28454        | 41.8797         |
| Studentų rūšiavimas     | 0.00299       | 0.01700      | 0.20788       | 2.37043        | 29.1623         |
| Abiejų grupių išvedimas | 0.05295       | 0.06400      | 0.25704       | 2.01785        | 23.6764         |
| **Galutinis laikas**    | 0.06696       | 0.14191      | 0.97344       | 8.67282        | 94.7203         |

#### List

| Programos etapas        | 1000 (10^3)   | 10000 (10^4) | 100000 (10^5) | 1000000 (10^6) | 10000000 (10^7) |
| :---------------------- | :------------ | :----------- | :------------ | :------------- | :-------------- |
| Nuskaitymas iš failo    | 0.00997       | 0.06496      | 0.52670       | 4.39255        | 43.2343         |
| Studentų rūšiavimas     | 0.00100       | 0.02498      | 0.15590       | 1.88865        | 23.3856         |
| Abiejų grupių išvedimas | 0.05899       | 0.14591      | 0.35767       | 2.88077        | 32.5636         |
| **Galutinis laikas**    | 0.07294       | 0.24086      | 1.04439       | 9.16367        | 99.1942         |

#### Deque

| Programos etapas        | 1000 (10^3)   | 10000 (10^4) | 100000 (10^5) | 1000000 (10^6) | 10000000 (10^7) |
| :---------------------- | :------------ | :----------- | :------------ | :------------- | :-------------- |
| Nuskaitymas iš failo    | 0.00897       | 0.06096      | 0.51370       | 4.32669        | 42.7790         |
| Studentų rūšiavimas     | 0.00299       | 0.02399      | 0.20584       | 2.62122        | 31.6244         |
| Abiejų grupių išvedimas | 0.00981       | 0.03780      | 0.28783       | 2.41950        | 27.1984         |
| **Galutinis laikas**    | 0.02297       | 0.12393      | 1.00839       | 9.39640        | 101.605         |

### <a name="greitis2"></a>Testo rezultatai (2 variantas)
Žemiau pavaizduoti testo rezultatai, kai tik blogiečiai perkeliami iš studentų konteinerio, geriečiai paliekami.

#### Vector

| Programos etapas        | 1000 (10^3)   | 10000 (10^4) | 100000 (10^5) | 1000000 (10^6) | 10000000 (10^7) |
| :---------------------- | :------------ | :----------- | :------------ | :------------- | :-------------- |
| Nuskaitymas iš failo    | 0.00898       | 0.07995      | 0.53269       | 4.36868        | 43.1222         |
| Studentų rūšiavimas     | 0.00199       | 0.00309      | 0.19589       | 2.20774        | 27.4975         |
| Abiejų grupių išvedimas | 0.07301       | 0.08515      | 0.23112       | 1.97343        | 21.1550         |
| **Galutinis laikas**    | 0.01299       | 0.20085      | 0.96057       | 8.55309        | 91.2388         |

#### List

| Programos etapas        | 1000 (10^3)   | 10000 (10^4) | 100000 (10^5) | 1000000 (10^6) | 10000000 (10^7) |
| :---------------------- | :------------ | :----------- | :------------ | :------------- | :-------------- |
| Nuskaitymas iš failo    | 0.00802       | 0.05958      | 0.53067       | 4.38568        | 43.3456         |
| Studentų rūšiavimas     | 0.00096       | 0.01000      | 0.16592       | 1.69839        | 21.5926         |
| Abiejų grupių išvedimas | 0.05890       | 0.06738      | 0.31328       | 2.72738        | 28.1675         |
| **Galutinis laikas**    | 0.07089       | 0.14253      | 1.01388       | 8.81446        | 93.1082         |

#### Deque

| Programos etapas        | 1000 (10^3)   | 10000 (10^4) | 100000 (10^5) | 1000000 (10^6) | 10000000 (10^7) |
| :---------------------- | :------------ | :----------- | :------------ | :------------- | :-------------- |
| Nuskaitymas iš failo    | 0.00799       | 0.05795      | 0.51474       | 4.31153        | 42.7905         |
| Studentų rūšiavimas     | 0.00199       | 0.01999      | 0.23086       | 2.29339        | 29.6391         |
| Abiejų grupių išvedimas | 0.00697       | 0.03626      | 0.27864       | 2.34456        | 24.2487         |
| **Galutinis laikas**    | 0.02000       | 0.11731      | 1.02569       | 8.95246        | 96.6800         |

*Pora pastabų.* 
* Testai atlikti su -O2 optimizavimo flag'u.
* Nuskaitymas iš failo šiuo atveju kartu reiškia ir duomenų apdorojimą, kadangi nuskaitymo funkcija iš karto apdoroja kiekvieno studento duomenis (joje atliekami ir egzamino balo skaičiavimai). 

## Programos veikimas (kai pasirinkta neatlikti testo)

Jeigu vartotojas pasirinktų neatlikti testo, programos darbas tęstųsi taip: 

Vartotojo būtų klausiama, ar jis norėtų duomenis nuskaityti iš failo "kursiokai.txt": 
```shell
Ar noretumete studentu duomenis nuskaityti is failo 'kursiokai.txt'? Iveskite t/n:
n
```
Jei vartotojas įvestų t, tuomet duomenys būtų automatiškai nuskaitomi (jei failas egzistuoja) ir išvedami į dokumentą "rez.txt".

Kitu atveju, vartotojo prašoma įvesti studento vardą ir pavardę:
```shell
Iveskite studento varda:
Mantas
Iveskite studento pavarde:
Mačiukas
```
Tuomet vartotojas gali pasirinkti ar sugeneruoti studento egzamino rezultatą ir namų darbų pažymius (šiame pavyzdyje pasirenkama, kad pažymiai būtų sugeneruoti):
```shell
Ar sugeneruoti studento namu darbu pazymius ir egzamino rezultata? Iveskite t/n:
t
Egzamino pazymys: 7 
Pazymiu skaicius: 18 
Pazymiai: 1 3 3 8 6 6 4 2 10 7 6 2 2 3 2 5 10 9
```
Jei vartotojas įrašytų n, atitinkamai tektų visus šiuos pažymius suvesti ranka. Kad ir kaip pasirinktų, vartotojas toliau gali rinktis - ar jis nori, kad galutinis balas būtų skaičiuojamas su namų darbų pažymių vidurkiu arba jų mediana:
```shell
Ar galutiniam balui naudoti namu darbu rezultatu vidurki? (t - vidurkis, n - mediana)
t
```
Galiausiai vartotojas gali pasirinkti ar dar bus daugiau studentų. Jei įves raidę t, tuomet procesas bus kartojamas, o jei n, tai bus tiesiog išvesti jau turimų studentų duomenys kartu su jų galutiniais balais.

Taigi, pavyzdinis šios programos veikimo variantas (be programos spartos veikimo testo ir duomenų nuskaitymo iš failo) galėtų atrodyti taip:

```shell
Iveskite studento varda: 
Mantas
Iveskite studento pavarde: 
Mačiukas
Ar sugeneruoti studento namu darbu pazymius ir egzamino rezultata? Iveskite t/n:
t
Egzamino pazymys: 7 
Pazymiu skaicius: 18 
Pazymiai: 1 3 3 8 6 6 4 2 10 7 6 2 2 3 2 5 10 9 
Ar galutiniam balui naudoti namu darbu rezultatu vidurki? (t - vidurkis, n - mediana)
t
Ar bus daugiau studentu? Iveskite t/n: 
t
Iveskite studento varda: 
Vardenis
Iveskite studento pavarde: 
Pavardenis
Ar sugeneruoti studento namu darbu pazymius ir egzamino rezultata? Iveskite t/n:
b
Iveskite is naujo.
n
Iveskite studento egzamino rezultata (sveikaji skaiciu nuo 0 iki 10): 
9
Ar zinomas namu darbu pazymiu skaicius? Iveskite t/n:
n
Iveskite namu darbu pazymius (jei ivedete visus pazymius, iveskite -1):
7
6
5
-1
Ar bus daugiau studentu? Iveskite t/n: 
n
Vardas       Pavarde        Galutinis (Vid.)
---------------------------------------------
Mantas       Mačiukas       6.18
Vardenis     Pavardenis      7.8
```
