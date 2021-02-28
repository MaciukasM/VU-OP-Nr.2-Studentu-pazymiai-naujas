#include "headeriai.h"
#include "struktura.h"

int main() {
  //vektoriuje bus saugomi studentai
  vector <Studentas>studentai;
  //rezervuojam vektoriui vietos spartesniam darbui
  studentai.reserve(1024);

  string DuomFailas = "kursiokai.txt";
  bool ArReikiaIvesti = true;
  
  try
  {
    if (ArEgzistuoja(DuomFailas))
    {
      cout<<"Ar noretumete studentu duomenis nuskaityti is failo 'kursiokai.txt'? Iveskite t/n:"<<endl;
      string ArNuskaityti = AtsakymoIvedimas();
      if (ArNuskaityti == "t")
      {
        NuskaitykDuomenis(DuomFailas, studentai, ArReikiaIvesti);

        std::sort(studentai.begin(),studentai.end(), PagalVardus);
      }
      else cout<<"Tuomet iveskite visus duomenis ranka: "<<endl<<endl;
    }
    if (ArReikiaIvesti)
    {
      string KitasStudentas; //tikrinimui, ar yra kitas studentas
      string kiekNd; //tikrinimui, ar namu darbu pazymiu skaicius zinomas
      string ArGeneruoti; //ar generuoti atsitiktini skaiciu

      do
      {
        Studentas s; //cia bus saugomi studento duomenys, pabaigoj bus pushinami i studentu vektoriu

        cout<<"Iveskite studento varda: "<<endl;
        cin>>s.vardas;

        cout<<"Iveskite studento pavarde: "<<endl;
        cin>>s.pavarde;

        cout<<"Ar sugeneruoti studento namu darbu pazymius ir egzamino rezultata? Iveskite t/n:"<<endl;
        ArGeneruoti = AtsakymoIvedimas();
    
        if (ArGeneruoti == "t")
        {
          cout<<"Egzamino pazymys: ";
          s.egzaminas = GeneruokAtsitiktiniSkaiciu(0,10);
          cout<<endl<<"Pazymiu skaicius: ";
          s.pazymiuSk = GeneruokAtsitiktiniSkaiciu(0,40);
          cout<<endl<<"Pazymiai: ";
          for (int i = 0; i<s.pazymiuSk; i++)
          {
            s.pazymiai.push_back(GeneruokAtsitiktiniSkaiciu(0,10));
          }
          cout<<endl;
        }
        else
        {
          cout<<"Iveskite studento egzamino rezultata (sveikaji skaiciu nuo 0 iki 10): "<<endl;
          s.egzaminas=IvedimasIntervale(0,10,false);

          cout<<"Ar zinomas namu darbu pazymiu skaicius? Iveskite t/n:"<<endl;
          kiekNd = AtsakymoIvedimas();

          if (kiekNd == "t")
          {
            cout<<"Iveskite, kiek namu darbu pazymiu turi studentas (sveikaji skaiciu nuo 0 iki 40): "<<endl;
            s.pazymiuSk=IvedimasIntervale(0,40,false);

            if (s.pazymiuSk!=0)
            {
              cout<<"Iveskite namu darbu pazymius (sveikuosius skaicius nuo 0 iki 10): "<<endl;

              for (int i=0; i<s.pazymiuSk; i++)
              {
                s.pazymiai.push_back(IvedimasIntervale(0,10,false));
              }
            }
          }
          else
          {
            cout<<"Iveskite namu darbu pazymius (jei ivedete visus pazymius, iveskite -1):"<<endl;
            int ivestis; //laikinas kintamasis ivesciai patikrinti
            do
            {
              ivestis = IvedimasIntervale(0,10,true);
              if (ivestis!=-1)
              {
                s.pazymiai.push_back(ivestis);
              }
              else break;
            } while (ivestis!=-1 || ivestis > 10);
            s.pazymiuSk = s.pazymiai.size();
          }
        }
        s.ndVid = RaskVidurki(s.pazymiai, s.pazymiuSk);
        s.galutinis = GalutinisBalas(s.ndVid, s.egzaminas);

        s.mediana = RaskMediana(s.pazymiai, s.pazymiuSk);
        s.galutinisMed = GalutinisBalas(s.mediana, s.egzaminas);

        cout<<"Ar bus daugiau studentu? Iveskite t/n: "<<endl;
        KitasStudentas = AtsakymoIvedimas();
        studentai.push_back(s);
      } while(KitasStudentas == "t");
    }

    //Isvedimas kai duomenys ivedami ranka/nuskaitomi is failo
    if (ArReikiaIvesti) IprastinisDuomIsvedimas(studentai);
    else DuomenuIsvedimasFaile (studentai);

    return 0;
  }
  catch(std::exception &klaida)
  {
    std::cerr << klaida.what() << endl;
  }
}
