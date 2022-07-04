#include <iostream>
#include <vector>
#include <algorithm>
#define CANTIDAD_OFTS 5
using namespace std;



class persona {

    private: 
        string nombrePersona;

    public: 
        persona(){};
        ~persona(){};
        void setNombre ( string nombre = "nombre no valido"){
            this->nombrePersona = nombre;
        };
        string getNombrePersona() const { return this->nombrePersona; }      
};


class oferta {

    private:
        int monto; 
        persona ofertante;

    public:
        oferta(){};
        ~oferta(){};
        void setOferta(persona& ofertante, int monto){
            this->ofertante = ofertante;
            this->monto = monto;
        };
        int getMonto() const {
            return this->monto;
        }

        persona getPersona () const {
            return this->ofertante;
        }
};

// VERSION CON VECTORES
class lote {

    private:
        int numeroLote;
        string nombreLote;
        oferta ofertaMayor;

    public: 
        lote(){};
        ~lote(){};
        void setLote( int numeroLote = 0, string nombreLote = "lote x"){
            this->numeroLote = numeroLote;
            this->nombreLote = nombreLote;
        };

        
        void ingresarOfertas( vector <oferta> & of ){
    
            vector<int> montos;
            
            for(int i = 0; i < of.size() ; i++){
                
                montos.push_back( of.at(i).getMonto() );

            }
            
            /*      
            montos.push_back((*(of+1)).getMonto());
            montos.push_back((*(of+2)).getMonto());
            montos.push_back((*(of+3)).getMonto());
            montos.push_back((*(of+4)).getMonto());
            */
            
            int monto_max = *max_element( montos.begin() , montos.end() );

            for(int i = 0; i < CANTIDAD_OFTS ; i++)
                if ( monto_max == of.at(i).getMonto()) ofertaMayor = of.at(i);

        }

        int getNumeroLote () const {return this->numeroLote;}
        string getNombreLote () const {return this->nombreLote;}
        oferta getOfertaMayor() const {return this->ofertaMayor;}

};

// VERSION CON PUNTEROS
class lote2 {

    private:
        int numeroLote;
        string nombreLote;
        oferta ofertaMayor;

    public: 
        lote2(){};
        ~lote2(){};
        void setLote( int numeroLote = 0, string nombreLote = "lote x"){
            this->numeroLote = numeroLote;
            this->nombreLote = nombreLote;
        };

        
        void ingresarOfertas( oferta* of ){
            
            
            vector<int> montos;
            
            for(int i = 0; i < CANTIDAD_OFTS ; i++){
                
                montos.push_back( (*(of+i)).getMonto() );
                cout << montos.at(i) << endl;
              
            }
            
            /*      
            montos.push_back((*(of+1)).getMonto());
            montos.push_back((*(of+2)).getMonto());
            montos.push_back((*(of+3)).getMonto());
            montos.push_back((*(of+4)).getMonto());
            */
            
            int monto_max = *max_element( montos.begin() , montos.end() );

            for(int i = 0; i < CANTIDAD_OFTS; i++)
                if ( monto_max == (*(of+i)).getMonto()) ofertaMayor = (*(of+i));
                
        }

        int getNumeroLote () const {return this->numeroLote;}
        string getNombreLote () const {return this->nombreLote;}
        oferta getOfertaMayor() const {return this->ofertaMayor;}

};

class subasta {

    private: 
        vector <lote2> lotes;
        int cantidadLotes = 3; 

    public:
        subasta(){};
        ~subasta(){};
     
        void ingresarLote(lote2& lot){
            if (lotes.size() == cantidadLotes){
                cout << "no es posible ingresar mas lotes" << endl;
                return;
            } 
            lotes.push_back(lot);
            
        }


        ostream& operator << ( ostream& salida ){

            cout << "lotes de la subasta" << endl;

            for (int i = 0; i < lotes.size() ; i++)
            {   
                cout << "lote : " << lotes.at(i).getNombreLote() << " " << lotes.at(i).getNumeroLote() << " " 
                     << "monto mayor ofertado : " << lotes.at(i).getOfertaMayor().getMonto() << endl;            
            }
            
	        return salida;
        }


        void imprimirLotes ( ){

            cout << "lotes finales de la subasta" << endl;

            for (int i = 0; i < lotes.size() ; i++)
            {   
                cout << "lote : " << lotes.at(i).getNombreLote() << " numero de lote : " << lotes.at(i).getNumeroLote() << " " 
                     << "monto mayor ofertado : " << lotes.at(i).getOfertaMayor().getMonto() <<
                     " ofertante : " << lotes.at(i).getOfertaMayor().getPersona().getNombrePersona() << endl;            
            }   
        }
};



int main(int argc, char const *argv[])
{
    oferta arr [5];
    oferta* off = arr;
    
    //vector<oferta> ofertas;
    persona p1,p2,p3,p4,p5;
    p1.setNombre("p1");
    p2.setNombre("p2");
    p3.setNombre("p3");
    p4.setNombre("p4");
    p5.setNombre("p5");
    oferta of1 , of2, of3, of4 ,of5;
    of1.setOferta(p1, 200);
    of2.setOferta(p2, 300);
    of3.setOferta(p3, 1000);
    of4.setOferta(p4, 90);
    of5.setOferta(p5, 210);

    
    *(off+0) = of1;
    *(off+1) = of2;
    *(off+2) = of3;
    *(off+3) = of4;
    *(off+4) = of5;
    
    /*
    ofertas.push_back(of1);
    ofertas.push_back(of2);
    ofertas.push_back(of3);
    ofertas.push_back(of4);
    ofertas.push_back(of5);
    */
    
    lote2 l;
    l.setLote( 0001 , "lote 1 " );
    l.ingresarOfertas( off );

    subasta s;
    s.ingresarLote( l );
    s.imprimirLotes();

    return 0;
}
