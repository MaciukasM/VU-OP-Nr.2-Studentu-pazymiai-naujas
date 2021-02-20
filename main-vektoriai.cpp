#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::setfill;
using std::left;
using std::setprecision;
using std::vector;

//atsitiktiniams skaiciams
using std::mt19937;
using Laikas = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> intDistribution;

struct Studentas
{
  string vardas;
  string pavarde;
  int pazymiuSk;
  vector <int>pazymiai; 
  double ndVid; //namu darbu vidurkis
  double mediana; //namu darbu mediana
  int egzaminas; //egzamino rezultatas
  double galutinis;
};

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

int IvedimasIntervale(int pradzia, int pabaiga, bool Breakinimui) //bool kintamasis tam kad zinociau ar reikia breakint po enter paspaudimo
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

double RaskVidurki (vector<int> pazymiai, int pazymiuSk)
{
  double vidurkis=0;
  double suma; //pazymiu suma (double, kadangi reikes dalint)
  for (int i=0;i<pazymiuSk;i++)
  {
    suma = suma + pazymiai[i];
  }
  if (pazymiuSk!=0)
  {
    vidurkis = suma / pazymiuSk;
  }
  return vidurkis;
}

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

double GalutinisBalas(double ndRez, int egzaminas)
{
  double galutinis;
  galutinis = 0.4 * ndRez + 0.6 * egzaminas;
  return galutinis;
}

int GeneruokAtsitiktiniSkaiciu(int pradzia, int pabaiga) //pradzia/pabaiga - intervalo reziai
{
  mt19937 mt(static_cast<int>(Laikas::now().time_since_epoch().count()));
  intDistribution Paskirstyk(pradzia, pabaiga);

  int skaicius = Paskirstyk(mt);
  cout<<skaicius<<" ";
  return skaicius;
}


int main() {
  //vektoriuje bus saugomi studentai
  vector <Studentas>studentai;
  //rezervuojam vektoriui vietos spartesniam darbui
  studentai.reserve(1024);


  string KitasStudentas; //tikrinimui, ar yra kitas studentas
  string Vidurkis; //tikrinimui, ar skaiciavimui naudojamas vidurkis, ar mediana
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
      s.pazymiuSk = GeneruokAtsitiktiniSkaiciu(0,20);
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
        cout<<"Iveskite, kiek namu darbu pazymiu turi studentas (sveikaji skaiciu nuo 0 iki 20): "<<endl;
        s.pazymiuSk=IvedimasIntervale(0,20,false);

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

    if (Vidurkis != "t" && Vidurkis != "n")
    {
      cout<<"Ar galutiniam balui naudoti namu darbu rezultatu vidurki? (t - vidurkis, n - mediana)"<<endl;
      Vidurkis = AtsakymoIvedimas();
    }

    if (Vidurkis == "t")
    {
      s.ndVid = RaskVidurki(s.pazymiai, s.pazymiuSk);
      s.galutinis = GalutinisBalas(s.ndVid, s.egzaminas);
    }
    else 
    {
      s.mediana = RaskMediana(s.pazymiai, s.pazymiuSk);
      s.galutinis = GalutinisBalas(s.mediana, s.egzaminas);
    }
    cout<<"Ar bus daugiau studentu? Iveskite t/n: "<<endl;
    KitasStudentas = AtsakymoIvedimas();
    studentai.push_back(s);
  } while(KitasStudentas == "t");

  //Isvedimas
  cout<<left<<setw(13)<<"Vardas"<<setw(16)<<"Pavarde";
  if(Vidurkis == "t") cout<<"Galutinis (Vid.)"<<endl;
  else cout<<"Galutinis (Med.)"<<endl;
  
  cout<<"---------------------------------------------"<<endl;

  for (auto s : studentai)
  {
    cout<<left<<setw(13)<<s.vardas<<setw(16)<<s.pavarde<<setprecision(3)<<s.galutinis<<endl;
  }

  return 0;
}
