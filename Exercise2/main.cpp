#include <iostream>
#include <fstream>
#include <string>

//function that maps points from [1, 5] in the interval [−1, 2].
double MapFunction(double Value)
{
    return(3.0/4.0*Value-7.0/4.0);
}

int main()
{
    std::string FileName = "data.csv"; //accedo ai singoli caratteri
    std::ifstream ifstr(FileName); //legge il contenuto del file
    std::ofstream ofstr("result.csv"); //creo un nuovo file
    ofstr << "# N Mean \n";

//se l'apertura del file non avviene correttamente, stampa errore
    if (ifstr.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    //dichiarazione e inizializzazione
    double SumValue = 0;
    double Value=0;
    unsigned int count= 0;

    while (ifstr >> Value)
    {
        double MappedValue = MapFunction(Value);
        SumValue += MappedValue;
        double MeanValue = SumValue/++count; //calcolo media
        ofstr << count << " " << std::scientific << std::setprecision(16) << MeanValue << std::endl;
    }

    ifstr.close();
    ofstr.close();
    return 0;
}
