#include "headeriai.h"
#include "struktura.h"
#include "laikas.h"

//funkcija simboliu isvalymui, kai irasytas netinkamas simbolis
void NeteisingasIvedimas()
{
  cin.clear();
  cin.ignore(10000, '\n'); //"isvalo" paskutinius 10000 simboliu - kazin ar vartotojas prirasys daugiau nei tiek
}

//tikrinimui, ar ivesti vien skaitmenys
bool ArVienSkaiciai(const string s)
{
  return s.find_first_not_of( "0123456789" ) == string::npos;
}

//tikrinimui, ar egzistuoja failas
bool ArEgzistuoja (string DuomFailas)
{
  ifstream failas(DuomFailas);
  bool ArEgzistuoja = failas.good();
  return ArEgzistuoja;
}

//tikrinimui, ar ivesta t/n
string AtsakymoIvedimas()
{
  string TaipNe;
  do
  {
    cin>>TaipNe;
    if (TaipNe!="t" && TaipNe!="n")
      {
        cout<<"Iveskite is naujo."<<endl;
      }
  } while (TaipNe!="t" && TaipNe!="n");
  return TaipNe;
}

//funkcija tikrinimui ar ivestas skaicius priklauso tam tikram (reikalingui intervalui)
int IvedimasIntervale(int pradzia, int pabaiga, bool Breakinimui) //bool kintamasis tam kad zinociau ar reikia breakint po -1 irasymo
{
  string ivestis; //tikrinimui, ar ivestas skaicius
  bool ArSkaicius;

  int skaicius=-1;
  
  while (skaicius < pradzia || skaicius > pabaiga)
  {
    cin>>ivestis;
    if (ivestis == "-1" && Breakinimui) return -1;
    else 
    {
      ArSkaicius = ArVienSkaiciai(ivestis);
      if(ArSkaicius) skaicius = std::stoi(ivestis);
    }
    if (skaicius == -1 || skaicius > pabaiga) cout<<"Iveskite skaiciu is naujo."<<endl;
  }
  return skaicius;
}

//funkcija vidurkiui apskaiciuoti
double RaskVidurki (vector<int> pazymiai, int pazymiuSk)
{
  double vidurkis=0;
  double suma; //pazymiu suma (double, kadangi reikes dalint)
  for (int i=0;i<pazymiuSk;i++)
  {
    suma = suma + pazymiai.at(i);
  }
  if (pazymiuSk!=0)
  {
    vidurkis = suma / pazymiuSk;
  }
  return vidurkis;
}

//funkcija medianai apskaiciuoti
double RaskMediana (vector<int> pazymiai, int pazymiuSk)
{
  int temp;
  double mediana=0;

  //rusiavimas
  std::sort(pazymiai.begin(),pazymiai.end());

  if (pazymiuSk!=0)
  {
    if (pazymiuSk % 2 == 1)
    {
      mediana = pazymiai[pazymiuSk/2];
    }
    else mediana = (pazymiai[pazymiuSk/2] + pazymiai[pazymiuSk/2-1])/2;
  }
  return mediana;
}

//funkcija galutiniam balui apskaiciuoti
double GalutinisBalas(double ndRez, int egzaminas)
{
  double galutinis;
  galutinis = 0.4 * ndRez + 0.6 * egzaminas;
  return galutinis;
}

//funkcija atsitiktiniams pazymiams (ir ju skaiciui) generuoti
void GeneruokPazymius(Studentas &s) //pradzia/pabaiga - intervalo reziai
{
  mt19937 mt(static_cast<int>(Laikas::now().time_since_epoch().count()));
  intDistribution Paskirstyk(0, 10);

  s.egzaminas = Paskirstyk(mt);
  s.pazymiuSk = Paskirstyk(mt)*2;
  for (int i = 0; i < s.pazymiuSk; i++)
  {
    s.pazymiai.push_back(Paskirstyk(mt));
  }
}

//funkcija duomenu nuskaitymui is failo
void NuskaitykDuomenis(string DuomFailas, vector <Studentas>&studentai, bool &ArReikiaIvesti)
{
  ifstream failas(DuomFailas);
  if (failas.is_open())
  {
    ArReikiaIvesti = false;
    string eilute;
    getline(failas,eilute); //pirma eilute nereikalinga

    while (getline(failas,eilute))
    {
      istringstream ivedimas(eilute);

      Studentas s; //cia bus saugomi studento duomenys, pabaigoj bus pushinami i studentu vektoriu

      ivedimas>>s.vardas;
      ivedimas>>s.pavarde;

      string ivestasSk; //tikrinimui, ar ivestas tinkamas skaicius
      int pazymys=0;
      while (ivedimas>>ivestasSk)
      {
        if (ArVienSkaiciai(ivestasSk))
        {
          pazymys = std::stoi(ivestasSk);
          if((pazymys>=0)&&(pazymys<=10)) s.pazymiai.push_back(pazymys);
        }
      }
      s.egzaminas = pazymys;
      s.pazymiai.pop_back();

      s.pazymiuSk = s.pazymiai.size();

      s.ndVid = RaskVidurki(s.pazymiai, s.pazymiuSk);
      s.mediana = RaskMediana(s.pazymiai, s.pazymiuSk);

      s.galutinis = GalutinisBalas(s.ndVid, s.egzaminas);
      s.galutinisMed = GalutinisBalas(s.mediana, s.egzaminas);

      studentai.push_back(s);
    }
    failas.close();
    cout<<"Duomenys nuskaityti."<<endl;
  }
  else if (ArReikiaIvesti)
  {
    cout<<"Nepavyko nuskaityti duomenu."<<endl;
    cout<<"Ar norite ranka ivesti duomenis? (t - ivesti duomenis, n - uzbaigti programos darba) Iveskite t/n:"<<endl;
    string ProgramosTesinys = AtsakymoIvedimas();
    if (ProgramosTesinys == "n") exit(1);
  }
  else throw std::runtime_error("Nepavyko atidaryti failo");
}

//funkcija rusiavimui pagal vardus (jei vardai sutampa, tai pagal pavardes)
bool PagalVardus(Studentas s1, Studentas s2)
{
  if (s1.vardas < s2.vardas) return true;
  else if (s1.vardas == s2.vardas && s1.pavarde < s2.pavarde) return true;
  else return false;
}

//funkcija duomenu isvedimui i faila
void DuomenuIsvedimasFaile (vector <Studentas>studentai, string failas)
{
  ostringstream Isvedimas;
  Isvedimas<<"Vardas          Pavarde            Galutinis (Vid.)    Galutinis (Med.)\n";
  Isvedimas<<"-----------------------------------------------------------------------\n";
  for (auto s : studentai)
  {
    Isvedimas<<left<<setw(16)<<s.vardas<<setw(19)<<s.pavarde<<setw(20)<<setprecision(3)  <<s.galutinis<<setprecision(3)<<s.galutinisMed<<endl;
  }
  std::ofstream Rezultatas(failas);
  Rezultatas<<Isvedimas.str();
  Rezultatas.close();
  cout<<"Duomenys isvesti i faila '"<<failas<<"'."<<endl;
}

//funkcija duomenu isvedimui i ekrana
void IprastinisDuomIsvedimas (vector <Studentas>studentai)
{
  std::sort(studentai.begin(),studentai.end(), PagalVardus);
  cout<<left<<setw(16)<<"Vardas"<<setw(19)<<"Pavarde"<<setw(20)<<"Galutinis (Vid.)"<<"Galutinis (Med.)"<<endl;
  
  cout<<"-------------------------------------------------------------------------"<<endl;

  for (auto s : studentai)
  {
    cout<<left<<setw(16)<<s.vardas<<setw(19)<<s.pavarde<<setw(20)<<setprecision(3)  <<s.galutinis<<setprecision(3)<<s.galutinisMed<<endl;
  }
}

//failu generavimo funkcija
void GeneruokFaila(int dydis)
{
  Studentas s;

  ostringstream duomenys;
  duomenys<<left<<setw(16)<<"Vardas"<<setw(25)<<"Pavarde"<<endl;
  
  for (int i = 1; i <= dydis; i++)
  {
    s.vardas = "Vardas"+to_string(i);
    s.pavarde = "Pavarde"+to_string(i);

    duomenys<<left<<setw(16)<<s.vardas<<setw(25)<<s.pavarde;

    s.pazymiai.clear();
    GeneruokPazymius(s);
    for (int j = 0; j<s.pazymiuSk;j++)
    {
      duomenys<<left<<setw(4)<<s.pazymiai[j];
    }
    duomenys<<setw(4)<<s.egzaminas<<endl;
  }

  string DuomFailas = "Sugeneruotas" + to_string(dydis) + ".txt";
  std::ofstream Isvedimas(DuomFailas);
  Isvedimas<<duomenys.str();
  Isvedimas.close();
  cout<<"Sugeneruotas "<<dydis<<" dydzio failas."<<endl;
}

//programos benchmark (programos spartos nustatymo) funkcija
void ProgramosSparta()
{
  vector <Studentas>studentai;
  double visasLaikas; //galutiniam testo laikui pateikti
  bool temp=false; //kintamasis kad veiktu funkcija
  string rezFailas; //isvedimui gerieciu/blogieciu
  string ProgramosTesinys; //tikrinimui, ar vartotojas nori pratesti testa
  LaikoMatavimas laikas;
  for (int i = 1000; i<=10000000; i*=10)
  {
    visasLaikas = 0;
    cout<<"\nProgramos veikimo spartos testas su "<<i<<" studentu pradetas.\n"<<endl;

    laikas.reset();
    studentai.reserve(i);
    
    //failo generavimas
    GeneruokFaila(i);
    cout<<i<<" studentu failo generavimas uztruko "<<laikas.elapsed()<<" s."<<endl;
    visasLaikas+=laikas.elapsed();
    laikas.reset();
    //failo generavimas

    //failo nuskaitymas
    string DuomFailas="Sugeneruotas"+to_string(i)+".txt";
    NuskaitykDuomenis(DuomFailas, studentai, temp);
    cout<<"Duomenu ("<<i<<" studentu) nuskaitymas is failo uztruko "<<laikas.elapsed()<<" s."<<endl;
    visasLaikas+=laikas.elapsed();
    laikas.reset();
    //failo nuskaitymas

    //studentu rusiavimas i dvi grupes
    vector <Studentas>gerieciai;
    vector <Studentas>blogieciai;
    gerieciai.reserve(i);
    blogieciai.reserve(i);
    for (int j = 0; j<i; j++)
    {
      if(studentai[j].galutinis < 5)
      {
        blogieciai.push_back(studentai[j]);
      }
      else gerieciai.push_back(studentai[j]);
    }
    studentai.clear();
    cout<<i<<" studentu rusiavimas (kartu su pirmojo vektoriaus panaikinimu) uztruko "<<laikas.elapsed()<<" s."<<endl;
    visasLaikas+=laikas.elapsed();
    laikas.reset();
    //studentu rusiavimas i dvi grupes

    //"gerieciu" isvedimas i faila
    rezFailas = "Atsakymai/rez_gerieciai"+to_string(i)+".txt";
    DuomenuIsvedimasFaile(gerieciai, rezFailas);
    cout<<i<<" studentu (gerieciu) isvedimas i faila '"<<rezFailas<<"' uztruko "<<laikas.elapsed()<<" s."<<endl;
    visasLaikas+=laikas.elapsed();
    laikas.reset();
    //"gerieciu" isvedimas i faila

    //"blogieciu" isvedimas i faila
    rezFailas = "Atsakymai/rez_blogieciai"+to_string(i)+".txt";
    DuomenuIsvedimasFaile(blogieciai, rezFailas);
    cout<<i<<" studentu (blogieciu) isvedimas i faila '"<<rezFailas<<"' uztruko "<<laikas.elapsed()<<" s."<<endl<<endl;
    visasLaikas+=laikas.elapsed();
    //"blogieciu" isvedimas i faila

    //viso testo laiko Isvedimas
    cout<<i<<" irasu testas uztruko "<<visasLaikas<<" s."<<endl<<endl;
    //viso testo laiko Isvedimas

    if (i!=10000000)
    {
      int a = i*10;
      cout<<"Ar norite toliau testuoti (kitas testas - su "<<a<<" irasu)? Iveskite t/n: "<<endl;
      ProgramosTesinys = AtsakymoIvedimas();
      if (ProgramosTesinys=="n")
      {
        cout<<"Programos darbas baigtas."<<endl;
        break;
      }
      else
      {
        blogieciai.clear();
        gerieciai.clear();
      }
    }
  }
}
