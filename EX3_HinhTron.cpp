#include<stdint.h>
#include<stdio.h>
#include<math.h>


class HinhTron
{
private:
    double BK;
public:
    HinhTron(double BK);
    double CV();
    double DT();

    
};

HinhTron::HinhTron(double BK)
{
    HinhTron::BK = BK;
}


double HinhTron::CV(){
    printf("Chu vi hinh tron la: %f\n", 2 * 3.14* BK);
}
double HinhTron::DT(){
    printf("Dien tich hinh tron la: %f\n", 3.14 * BK * BK);
}


int main(int argc, char const *argv[])
{
    HinhTron ht(3.25);
    ht.CV();
    ht.DT();


    return 0;
}