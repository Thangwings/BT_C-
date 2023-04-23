/*Tạo một lớp điểm trong hệ tọa độ 2D và viết các phương thức để tính
khoảng cách giữa hai điểm, tính diện tích của tam giác được tạo bởi ba
điểm.*/

#include<stdio.h>
#include<stdint.h>
#include<math.h>

class Diem
{
private:
    int8_t ToaDoX;
    int8_t ToaDoY;
public:
    Diem(int8_t ToaDoX = 0, int8_t ToaDoY = 0);
    int8_t getToaDoX(); 
    int8_t getToaDoY();
};


Diem::Diem(int8_t ToaDoX, int8_t ToaDoY){
    Diem::ToaDoX = ToaDoX;
    Diem::ToaDoY = ToaDoY;
}

int8_t Diem::getToaDoX(){
    return Diem::ToaDoX;
}
int8_t Diem::getToaDoY(){
    return Diem::ToaDoY;
}


class PhepToanOXY
{
private:
    Diem DiemA;
    Diem DiemB;
    Diem DiemC;


    typedef enum{
        KHOANG_CACH,
        DIEN_TICH
    }PhepToan;
    PhepToan CheckPhepToan; 
public:
    PhepToanOXY(Diem DiemA, Diem DiemB);
    PhepToanOXY(Diem DiemA, Diem DiemB, Diem DiemC);
    double khoangCach2Diem();
    double DienTichTamGiac();
};

PhepToanOXY::PhepToanOXY(Diem DiemA, Diem DiemB)// tinh da hinh
{
    PhepToanOXY::DiemA = DiemA;
    PhepToanOXY::DiemB = DiemB;
    PhepToanOXY::CheckPhepToan = KHOANG_CACH;
}

PhepToanOXY::PhepToanOXY(Diem DiemA, Diem DiemB, Diem DiemC) // tinh da hinh 
{
    PhepToanOXY::DiemA = DiemA;
    PhepToanOXY::DiemB = DiemB;
    PhepToanOXY::DiemC = DiemC;
    PhepToanOXY::CheckPhepToan = DIEN_TICH;
}



double PhepToanOXY::khoangCach2Diem(){
    if (PhepToanOXY::CheckPhepToan == KHOANG_CACH)
    {   
        // tinh khoang cach 2 diem
        
        int8_t deltaX = PhepToanOXY::DiemA.getToaDoX() - PhepToanOXY::DiemB.getToaDoX();
        int8_t deltaY = PhepToanOXY::DiemA.getToaDoY() - PhepToanOXY::DiemB.getToaDoY();
        double OUT_KC = sqrt(deltaX * deltaX + deltaY * deltaY);
        return OUT_KC;
    }else 
    {
        printf("chuong trinh loi\n ");
    }
}


double PhepToanOXY::DienTichTamGiac(){
    if (PhepToanOXY::CheckPhepToan = DIEN_TICH)
    {   
        // tinh dien tich tam giac duoc tao tu 3 điem
        
        int8_t xA = PhepToanOXY::DiemA.getToaDoX();
        int8_t xB = PhepToanOXY::DiemB.getToaDoX();
        int8_t xC = PhepToanOXY::DiemC.getToaDoX();
        int8_t yA = PhepToanOXY::DiemA.getToaDoY();
        int8_t yB = PhepToanOXY::DiemB.getToaDoY();
        int8_t yC = PhepToanOXY::DiemC.getToaDoY();

        double DT = 0.5 * abs((xB-xA)*(yC-yA)-(xC-xA)*(yB-yA));

        return DT;
    }else
    {
        printf("chuong trinh loi\n");
    }
    
}


int main(int argc, char const *argv[]){

    int8_t xA, xB, xC, yA, yB, yC;
    printf("2 diem:");
    scanf("%d %d %d %d" ,&xA ,&yA, &xB, &yB);
    Diem DiemA(xA, yA);
    Diem DiemB(xB, yB);
    PhepToanOXY TinhKhoangCach(DiemA, DiemB);
    printf("khoang cach: %f\n" ,TinhKhoangCach.khoangCach2Diem());


    printf("3 diem:");
    scanf("%d %d %d %d %d %d " ,&xA ,&yA, &xB, &yB, &xC, &yC);
    Diem DiemC(xC, yC);
    PhepToanOXY DienTichTamGiac(DiemA,DiemB,DiemC);
    printf("dt: %f\n", DienTichTamGiac.DienTichTamGiac());

    return 0;
}