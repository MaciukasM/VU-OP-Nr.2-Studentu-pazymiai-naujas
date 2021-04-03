# VU-OP-Nr.2-Studentu-pazymiai

Ši programa nuskaito vartotojo įvedamus duomenis apie studentus ir juos išveda į konsolę kartu su jų galutiniu balu (kuris gali būti apskaičiuotas su mediana arba vidurkiu).

## Versijos

* [v0.1](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.1): pirmoji programos versija, kurioje nuskaitomi studentų duomenys bei išvedamas jų galutinis balas. Šiam skaičiavimui gali būti pasitelkta mediana arba vidurkis. Pažymių įvedimo metu programa veikia net ir nežinant pažymių skaičiaus, jų įvedimą galima sustabdyti įvedant -1. Pažymiai taip pat gali būti generuojami atsitiktinai. Be to, yra dvi šios programos versijos, kurios skiriasi duomenų saugojimu - vienoje duomenys saugojami masyvuose, kitoje - vektoriuose.
* [v0.2](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.2.1): antroji programos versija, kurioje galima pasirinkti, ar norima nuskaityti duomenis iš failo (tuomet jie bus išvedami į failą "rez.txt". Studentų duomenys yra surūšiuojami pagal jų vardus (jei jie vienodi, tada pagal pavardę).
* [v0.3](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.3.1): trečioji programos versija, kurioje funkcijos ir struktūros perkeltos į atitinkamus .h arba .cpp failus. Taip pat panaudotas išimčių valdymas (su try/catch, std::vector.at()).
* [v0.4](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.4): ketvirtoji programos versija, kurioje studentai rūšiuojami į dvi grupes (geriečius ir blogiečius) pagal jų balus. Taip pat nuo šios versijos galima atlikti programos veikimo spartos testą (t.y. sugeneruojamas 10^n (n ∈ [3,7]) įrašų failas su studentais ir jų pažymiais; tuomet tie duomenys nuskaitomi ir apdorojami. Toliau seka studentų rūšiavimas į dvi minėtas grupes. Galiausiai abi šios grupės išvedamos į atitinkamus failus.).
* [v0.5](): penktoji programos versija, kurioje galima atlikti bandymus su įvairiais konteinerių tipais (t.y. atlikti ketvirtoje versijoje implementuotą programos veikimo spartos testą su konteineriais std::list bei std::deque (prieš tai testas buvo atliekamas su std::vector tipo konteineriu). Testo rezultatus galima peržiūrėti žemiau (žr. [Programos spartos veikimo testas](#greitis)).

## Diegimas

Atsisiųskite norimą versiją iš repozitorijos releas'ų (prireikus iškelkite .cpp ir .h failus iš aplanko su pasirinkta programa, pvz. WinRar). Tuomet sukompiliuokite norimoje programoje ar aplinkoje (arba su kitais įrankiais). Svarbu, kad joje būtų palaikomas C++11 standartas. Galiausiai lieka tik paleisti .exe failą.

## <a name="greitis"></a>Programos spartos veikimo testas

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
1
```
Pasirinkus norimą konteinerio tipą, būtų pradėtas testavimas su 1000 studentų failo generavimu (jei failas nesugeneruotas iš anksto), nuskaitymu, apdorojimu bei dviejų studentų grupių išvedimu.
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

### Testo rezultatai

Žemiau pateikiami tokio atlikto testo rezultatai (pateikiamas jų 3 bandymų vidurkis).

| Programos etapas      | 1000 (10^3)   | 10000 (10^4) | 100000 (10^5) | 1000000 (10^6) | 10000000 (10^7) |
| :-------------------- | :------------ | :----------- | :------------ | :------------- | :-------------- |
| Failo generavimas     | 0.00513       | 0.05209      | 0.87965       | 8.99444        | 88.1974         |
| Nuskaitymas iš failo  | 0.00239       | 0.02735      | 0.60435       | 5.23691        | 55.6124         |
| Studentų rūšiavimas   | 0.00027       | 0.00238      | 0.02908       | 0.19607        | 18.9789         |
| "Geriečių" išvedimas  | 0.00080       | 0.00657      | 0.18500       | 1.74966        | 19.1031         |
| "Blogiečių" išvedimas | 0.00075       | 0.00554      | 0.16379       | 1.59890        | 17.6413         |
| **Galutinis laikas**  | 0.00939       | 0.09393      | 1.86187       | 17.7759        | 199.533         |

*Pora pastabų.* 
* Testai atlikti su -O2 optimizavimo flag'u.
* Nuskaitymas iš failo šiuo atveju kartu reiškia ir duomenų apdorojimą, kadangi nuskaitymo funkcija iš karto apdoroja kiekvieno sutdento duomenis (joje atliekami ir egzamino balo skaičiavimai). 
* Surūšiuojant studentus į dvi grupes jie perkeliami į du skirtingus vektorius, o originalus vektorius (t.y. tas kuriame duomenys buvo saugomi iš pradžių) panaikinamas.

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
