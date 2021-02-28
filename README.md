# VU-OP-Nr.2-Studentu-pazymiai

Ši programa nuskaito vartotojo įvedamus duomenis apie studentus ir juos išveda į konsolę kartu su jų galutiniu balu (kuris gali būti apskaičiuotas su mediana arba vidurkiu).

## Versijos

* [v0.1](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.1): pirmoji programos versija, kurioje nuskaitomi studentų duomenys bei išvedamas jų galutinis balas. Šiam skaičiavimui gali būti pasitelkta mediana arba vidurkis. Pažymių įvedimo metu programa veikia net ir nežinant pažymių skaičiaus, jų įvedimą galima sustabdyti įvedant -1. Pažymiai taip pat gali būti generuojami atsitiktinai. Be to, yra dvi šios programos versijos, kurios skiriasi duomenų saugojimu - vienoje duomenys saugojami masyvuose, kitoje - vektoriuose.
* [v0.2](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.2.1): antroji programos versija, kurioje galima pasirinkti, ar norima nuskaityti duomenis iš failo (tuomet jie bus išvedami į failą "rez.txt". Studentų duomenys yra surūšiuojami pagal jų vardus (jei jie vienodi, tada pagal pavardę).
* [v0.3](https://github.com/MantasM2001/VU-OP-Nr.2-Studentu-pazymiai/releases/tag/v0.3): trečioji programos versija, kurioje funkcijos ir struktūros perkeltos į atitinkamus .h arba .cpp failus. Taip pat panaudotas išimčių valdymas (su try/catch, std::vector.at()).

## Diegimas

Atsisiųskite norimą versiją iš repozitorijos releas'ų (prireikus iškelkite .cpp ir .h failus iš aplanko su pasirinkta programa, pvz. WinRar). Tuomet sukompiliuokite norimoje programoje ar aplinkoje (arba su kitais įrankiais). Svarbu, kad joje būtų palaikomas C++11 standartas. Galiausiai lieka tik paleisti .exe failą.

## Programos veikimas

Paleidus programą vartotojo klausiama, ar jis norėtų duomenis nuskaityti iš failo "kursiokai.txt": 
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

Taigi, pavyzdinis šios programos veikimo variantas galėtų atrodyti taip:

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
