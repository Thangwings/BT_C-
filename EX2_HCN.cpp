#include<stdio.h>
#include<stdint.h>
#include<math.h>

class HCN
{
private:
    float CD;
    float CR;
public:
    HCN(float CD , float CR );
    float getCD();
    float getCR();
    float CV();
    float DT();
    float DC();
    bool KTHV();

};

HCN::HCN(float CD , float CR)
{
    HCN::CD = CD;
    HCN::CR = CR;
}

float HCN::getCD(){
    return HCN::CD;
}
float HCN::getCR(){
    return HCN::CR;
}

float HCN::CV(){
    if (HCN::CD != 0 && HCN::CR != 0)
    {
        printf("Chu vi HCN la: %f\n", (CD + CR)*2);
    }else{
        printf("Hinh sai\n");
    }
    
}
float HCN::DT(){
    if (HCN::CD != 0 && HCN::CR != 0)
    {
        printf("Dien tich HCN la: %f\n", CD * CR);
    }else{
        printf("Hinh sai\n");
    }
    
}

float HCN::DC(){
    if (HCN::CD != 0 && HCN::CR != 0)
    {
        printf("Duong cheo HCN la: %f\n", sqrt(HCN::CD * HCN::CD + HCN::CR * HCN::CR));
    }else{
        printf("Hinh sai\n");
    }
    
}
bool HCN::KTHV(){
    if (HCN::CD == HCN::CR)
    {
        printf("Day la hinh vuong\n");
    }else{
        printf("day la hinh chu nhat\n");
    }
    
}


int main(int argc, char const *argv[])
{
    HCN HCN(3.3, 3.3);
    HCN.CV();
    HCN.DT();
    HCN.DC();
    HCN.KTHV();
    return 0;
}