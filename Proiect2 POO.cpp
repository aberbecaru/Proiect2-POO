#include <iostream>
#include <vector>

class Complex_Locuinte{ ///clasa mama

public:
    Complex_Locuinte(std::string NumeProprietar, double SuprafataLocuinta, unsigned  int numar, double discount);
    Complex_Locuinte(const Complex_Locuinte&);
    Complex_Locuinte();
    ~Complex_Locuinte();
    std::string getNumeProprietar();
    double getSuprafataLocuinta();
    unsigned int getNumar();
    unsigned int getDiscount();
    void setNumeProprietar(std::string);
    void setSuprafataLocuinta(double);
    void setNumar(unsigned int);
    void setDiscount(double);
    friend std::istream& operator >> (std::istream& stream, Complex_Locuinte& complex);
    friend std::ostream& operator << (std::ostream& stream, Complex_Locuinte& complex);
    Complex_Locuinte& operator = (Complex_Locuinte&);
    virtual void CalculChirie(double x, unsigned int y) = 0; ///functie virtuala pura

    ///am facut toate variabilele protected deoarece ma voi folosi de ele in clasele copil
protected:
    std::string NumeProprietar;
    double SuprafataLocuinta;
    unsigned int numar;
    double discount;
    static double CumparaMP; ///variabila statica
};

Complex_Locuinte::Complex_Locuinte(std::string NumeProprietar, double SuprafataLocuinta, unsigned int numar, double discount) {
    this->NumeProprietar = NumeProprietar;
    this->SuprafataLocuinta = SuprafataLocuinta;
    this->numar = numar;
    this->discount = discount;
}

Complex_Locuinte::Complex_Locuinte(const Complex_Locuinte& complex) {
    NumeProprietar = complex.NumeProprietar;
    SuprafataLocuinta = complex.SuprafataLocuinta;
    numar = complex.numar;
    discount = complex.discount;
}

Complex_Locuinte::Complex_Locuinte() {}

Complex_Locuinte::~Complex_Locuinte() {}

std::string Complex_Locuinte::getNumeProprietar() {
    return this->NumeProprietar;
}

double Complex_Locuinte::getSuprafataLocuinta() {
    return this->SuprafataLocuinta;
}

unsigned int Complex_Locuinte::getNumar() {
    return this->numar;
}

unsigned int Complex_Locuinte::getDiscount(){
    return this->discount;
}

void Complex_Locuinte::setNumeProprietar(std::string) {
    this->NumeProprietar = NumeProprietar;
}

void Complex_Locuinte::setSuprafataLocuinta(double) {
    this->SuprafataLocuinta = SuprafataLocuinta;
}

void Complex_Locuinte::setNumar(unsigned int) {
    this->numar = numar;
}

void Complex_Locuinte::setDiscount(double) {
    this->discount = discount;
}

std::istream& operator >> (std::istream& stream, Complex_Locuinte& complex){
    stream>>complex.NumeProprietar>>complex.SuprafataLocuinta>>complex.numar>>complex.discount;
    return stream;
}

std::ostream& operator << (std::ostream& stream, Complex_Locuinte& complex){
    stream<<complex.NumeProprietar<<" "<<complex.SuprafataLocuinta<<" "<<complex.numar<<" "<<complex.discount;
    return stream;
}

///supraincarcarea operatorului de atribuire
Complex_Locuinte& Complex_Locuinte::operator = (Complex_Locuinte& complex){
    this->NumeProprietar = complex.NumeProprietar;
    this->SuprafataLocuinta = complex.SuprafataLocuinta;
    this->numar = complex.numar;
    this->discount=complex.discount;
    return *this;
}

double Complex_Locuinte::CumparaMP = 1200.40; ///declararea variabilei statice

class Apartament: public Complex_Locuinte{ ///clasa copil
public:
    Apartament(std::string , double , unsigned int, double, unsigned int, unsigned int);
    Apartament(const Apartament&);
    ~Apartament();
    unsigned int getEtaje();
    unsigned int getNrApartamente();
    void setEtaje(unsigned int);
    void setNrApartamente(unsigned int);
    friend std::istream& operator >> (std::istream& stream, Apartament& apartament);
    friend std::ostream& operator << (std::ostream& stream, Apartament& apartament);
    Apartament& operator = (Apartament&);
    void CalculChirie(double x, unsigned int y){
        std::cout<<x*SuprafataLocuinta*(1-y*discount/100.00);
    }
    static double CumparaApartament(double x); ///functie statica
private:
    unsigned int nretaje;
    unsigned int nrapartamente;
};

Apartament::Apartament(std::string  NumeProprietar = "Null NumeProprietar", double SuprafataLocuinta = 0.0,
                       unsigned int numar = 0, double discount = 0.0,
                       unsigned int nretaje = 0, unsigned int nrapartamente = 0):
        Complex_Locuinte(NumeProprietar, SuprafataLocuinta, numar, discount) {
    this->nretaje = nretaje;
    this->nrapartamente = nrapartamente;
}

Apartament::Apartament(const Apartament& apartament) {
    nretaje = apartament.nretaje;
    nrapartamente = apartament.nrapartamente;
}

Apartament::~Apartament() {}

unsigned int Apartament::getEtaje() {
    return this->nretaje = nretaje;
}

unsigned int Apartament::getNrApartamente() {
    return this->nrapartamente = nrapartamente;
}

void Apartament::setEtaje(unsigned int) {
    this->nretaje = nretaje;
}

void Apartament::setNrApartamente(unsigned int) {
    this->nrapartamente = nrapartamente;
}

std::istream& operator >> (std::istream& stream,  Apartament& apartament){
    stream>>apartament.NumeProprietar>>apartament.SuprafataLocuinta>>apartament.numar
    >>apartament.discount>>apartament.nretaje>>apartament.nrapartamente;
    return stream;
}

std::ostream& operator << (std::ostream& stream, Apartament& apartament){
    stream<<apartament.NumeProprietar<<" "<<apartament.SuprafataLocuinta<<" "<<
    apartament.numar<<" "<<apartament.discount<<" "<<
    apartament.nretaje<<" "<<apartament.nrapartamente;
    return stream;
}
///supraincarcarea operatorului de atribuire
    Apartament& Apartament::operator = (Apartament& apartament){
    Complex_Locuinte& complex=apartament;
    this->Complex_Locuinte::operator = (complex);
    this->nretaje = apartament.nretaje;
    this->nrapartamente = apartament.nrapartamente;
    return *this;
}

double Apartament::CumparaApartament(double x) {
    return CumparaMP * x;
}

class Casa: public Complex_Locuinte{ ///clasa copil
public:
    Casa(std::string, double, unsigned int, double, double);
    Casa(const Casa&);
    ~Casa();
    double getSuprafataCurte();
    void setSuprafataCurte(double);
    friend std::istream& operator >> (std::istream& stream, Casa& casa);
    friend std::ostream& operator << (std::ostream& stream, Casa& casa);
    Casa& operator = (Casa&);
    void CalculChirie(double x, unsigned int y){
        std::cout<<x*(SuprafataLocuinta + 0.2*SuprafataCurte) + (1-y*discount/100);
    }
    static double CumparaCasa(double x); ///functie statica
private:
    double SuprafataCurte;
};

Casa::Casa(std::string NumeProprietar = "Null NumeProprietar", double PretLocuinta = 0.0,
           unsigned int numar = 0, double discount = 0.0, double SuprafataCurte = 0.0)
        :Complex_Locuinte(NumeProprietar, PretLocuinta, numar, discount) {
    this->SuprafataCurte=SuprafataCurte;
}

Casa::Casa(const Casa& casa) {
    SuprafataCurte=casa.SuprafataCurte;
}

Casa::~Casa() {}

double Casa::getSuprafataCurte() {
    return this->SuprafataCurte;
}

void Casa::setSuprafataCurte(double) {
    this->SuprafataCurte = SuprafataCurte;
}

std::istream& operator >> (std::istream& stream,  Casa& casa){
    stream>>casa.NumeProprietar>>casa.SuprafataLocuinta
    >>casa.numar>>casa.discount>>casa.SuprafataCurte;
    return stream;
}

std::ostream& operator << (std::ostream& stream, Casa& casa){
    stream<<casa.NumeProprietar<<" "<<casa.SuprafataLocuinta
    <<" "<<casa.numar<<" "<<casa.discount<<" "<<casa.SuprafataCurte;
    return stream;
}

Casa& Casa::operator = (Casa& casa){
    Complex_Locuinte& complex = casa;
    this->Complex_Locuinte::operator = (complex);
    this->SuprafataCurte = casa.SuprafataCurte;
    return *this;
}

double Casa::CumparaCasa(double x) { ///declararea functiei statice
    return CumparaMP * x + CumparaMP / x;
}

int main() {
    unsigned int n;
    unsigned int m;
    std::vector<Complex_Locuinte *> baza_de_date; ///vectorul din STL in care retinem toate datele
    int cnt = 0;
    int alegere;
    double mp;
    unsigned int AplicareDiscount;

    ///Programul incepe de aici. Mai intai trebuie sa introducem numarul de blocuri, cat si datele
    ///despre ele. Apoi numarul de case si datele despre ele si imediat dupa aceea suntem
    ///intampinati de meniu.

    std::cout<< "Bine ati venit la Agentia Imobiliara IMOBILIARE NUMBER ONE, agentie ce se ocupa cu administrarea complexului dumneavoastra"<< "\n";
    std::cout << "Introduceti numarul de blocuri din complexul dumneavoastra, ce au numarul locuintei impar" << "\n \n";
    std::cin >> n;
    std::cout<<"Introduceti datele de forma: \n \n";
    std::cout<<"Nume Client, Suprafata Locuinta, Numar, Discount, Numar Etaje, Numar Apartamente \n \n";

    cnt = 0;
    for (int i = 0; i < n; i++) { ///citirea a n date de la tastatura
        cnt++;
        std::cout << cnt << ". ";
        Apartament *apartamente = new Apartament();
        std::cin >> *apartamente;
        baza_de_date.push_back(apartamente); ///Upcasting
    }

    cnt = 0;
    std::cout << "\n Acum intorduceti numarul de case, ce vor avea numarul locuintei par:" << "\n \n";
    std::cin>>m;
    std::cout<<"Introduceti datele de forma: \n \n";
    std::cout<<"Nume Client, Suprafata Locuinta, Numar, Discount, Suprafata Curte \n \n";

    for (int i = 0; i <m; i++) { ///citirea a m date de la tastatura
        cnt++;
        std::cout << cnt << ". ";
        Casa *casa = new Casa();
        std::cin >> *casa;
        baza_de_date.push_back(casa); ///Upcasting
    }

    std::cout<<"\n Ati terminat de introdus datele. Acum alegeti una dintre urmatoarele optiuni \n \n";
    ///Meniul interactiv
    bool program = true;
    while(program != false){
        std::cout<<" 1 - Afisati datele despre blocuri. \n";
        std::cout<<" 2 - Afisati datele despre case. \n";
        std::cout<<" 3 - Calculati chiria pentru un apartament din fiecare bloc \n";
        std::cout<<" 4 - Calculati chiria pentru cate o casa din complex \n";
        std::cout<<" 5 - Calculati pretul unui apartament in fiecare bloc \n";
        std::cout<<" 6 - Calculati pretul caselor din complex \n";
        std::cout<<" 7 - Iesiti din program";

        std::cin>>alegere;

        switch(alegere){

            case 1:
                std::cout<<"Nume Proprietar:  SuprafataLocuinta:   Numar:   Discount:   NumarEtaje:   NumarApartamente: \n";
                for(int i=0; i<baza_de_date.size(); i++){
                    ///Downcasting
                    Apartament* apartament = dynamic_cast<Apartament*>(baza_de_date[i]);
                    if(apartament != NULL)
                        std::cout<<*apartament<<"\n";
                }

                break;

            case 2:
                std::cout<<"Nume Proprietar:  SuprafataLocuinta:   Numar:   Discount:   Suprafata Curte: \n";
                for(int i=0; i<baza_de_date.size(); i++){
                    ///Downcasting
                    Casa* casa = dynamic_cast<Casa*>(baza_de_date[i]);
                    if(casa != NULL)
                        std::cout<<*casa<<"\n";
                }
                break;

            case 3:
                ///Aici urmeaza calculul chiriilor. Am folosit try catch, deoarece, la introducerea
                ///datelor de la tastatura pot aparea mici erori, cum ar fi pretul pe mp sa fie negativ
                ///sau sa se introduca altceva decat 1 sau 0 la aplicarea discountului

               std::cout<<"Va rugam introduceti pretul pe m^2 perceput pentru chirie \n \n";
                try{
                    std::cin>>mp;
                    if(mp<0){
                        throw "error";
                    }
                }
                catch(const char* error){
                    std::cout<<"Ati introdus gresit datele. Programul se va reseta";
                    break;
                }
               std::cout<<"De asemenea va rugam sa apasati 1 daca doriti sa aplicati un discount chiriei sau 0 daca nu \n \n";
                try{
                    std::cin>>AplicareDiscount;
                    if(AplicareDiscount!=0 && AplicareDiscount!=1){
                        throw "error";
                    }
                }
                catch(const char* error){
                    std::cout<<"Ati introdus gresit datele. Programul se va reseta";
                    break;
                }
                for(int i=0; i<baza_de_date.size(); i++) {
                    ///Downcasting
                    Apartament *apartament = dynamic_cast<Apartament *>(baza_de_date[i]);
                    if (apartament != NULL) {
                        std::cout << "Pretul unei chirii in blocul " << apartament->getNumar() << " este de: ";
                        apartament->CalculChirie(mp, AplicareDiscount);
                        std::cout << " de euro pe luna \n";
                    }
                }
                break;
            case 4:
                cnt = 0;
                std::cout<<"Va rugam introduceti pretul pe m^2 perceput pentru chirie \n \n";
                try{
                    std::cin>>mp;
                    if(mp<0){
                        throw "error";
                    }
                }
                catch(const char* error){
                    std::cout<<"Ati introdus gresit datele. Programul se va reseta";
                    break;
                }
                std::cout<<"De asemenea va rugam sa apasati 1 daca doriti sa aplicati un discount chiriei sau 0 daca nu \n \n";
                try{
                    std::cin>>AplicareDiscount;
                    if(AplicareDiscount!=0 && AplicareDiscount!=1){
                        throw "error";
                    }
                }
                catch(const char* error){
                    std::cout<<"Ati introdus gresit datele. Programul se va reseta";
                    break;
                }
                for(int i=0; i<baza_de_date.size(); i++) {
                    ///Downcasting
                    Casa *casa = dynamic_cast<Casa *>(baza_de_date[i]);
                    if (casa != NULL) {
                        cnt += 1;
                        std::cout << "Pretul unei chirii in casa  " << casa->getNumar() << " este de: ";
                        casa->CalculChirie(mp, AplicareDiscount);
                        std::cout << " de euro pe luna \n";
                    }
                }
                break;

            case 5:
                cnt = 0;
                for(int i=0; i<baza_de_date.size(); i++) {
                    ///Downcasting
                    Apartament *apartament = dynamic_cast<Apartament *>(baza_de_date[i]);
                    if (apartament != NULL) {
                        cnt += 1;
                        std::cout << "Pretul unui apartament in blocul " << apartament->getNumar()  << " este de: ";
                        std::cout<<apartament->CumparaApartament(baza_de_date[i]->getSuprafataLocuinta());
                        std::cout << " de euro \n";
                    }
                }

                break;

            case 6:
                for(int i=0; i<baza_de_date.size(); i++) {
                    ///Downcasting
                    Casa *casa = dynamic_cast<Casa *>(baza_de_date[i]);
                    if (casa != NULL) {
                        ///try catch pentru a evita impartirea la 0
                        try {
                            if(baza_de_date[i]->getSuprafataLocuinta() <= 0){
                                throw std::runtime_error("0 division");
                            }
                            else{
                                std::cout << "Pretul casei de la numarul " << casa->getNumar() << " este de: ";
                                std::cout << casa->CumparaCasa(baza_de_date[i]->getSuprafataLocuinta());
                                std::cout << " de euro\n";
                            }
                        }
                        catch(std::runtime_error){
                            std::cout<<"Ati introdus datele despre suprafata casei incorect. Va rugam restartati programul \n";
                            break;
                        }
                    }
                }
                break;

            case 7:
                std::cout<<"Va multumim ca ati utilizat softul nostru. O zi buna!";
                program = false;
                break;


            default:
                std::cout<<"Se pare ca ati apasat o tasta gresita"<<"\n";
                std::cout<<"Va rugam reintroduceti";
                std::cin>>alegere;
                break;

        }

    }

}

///Input

///Andrei 80.00 1 25.04 4 16
///Marius 90.00 3  21.12 5 20
///Mihai 120.00 2 20.01 200.000
///Maria 150.00 4 15.00 150.00
