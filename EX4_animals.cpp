#include<stdio.h> 
#include<stdint.h>
#include<math.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
class animals
{
private:
    char Name[25];
    int8_t Age;
    double Weight;
    double Height;
public:
    animals(char Name[], int8_t Age, double Weight, double Height); //contractor

    char *getName(){
        return Name;
    }
    double getAge(){
        return Age;
    }
    double getWeight(){
        return Weight; 
    }
    double getHeight(){
        return Height;
    }

    double BMI();

};

animals::animals(char Name[], int8_t Age, double Weight, double Height){
    strcpy(animals::Name, Name);
    animals::Age = Age;
    animals::Weight = Weight;
    animals::Height = Height;
}

double animals::BMI(){
     double calc_BMI;
     calc_BMI = animals::Weight/(animals::Height * animals::Height);
    return calc_BMI;
}

void compare_Age_Animals(animals a1, animals a2){
    if (a1.getAge() > a2.getAge() )
    {
        printf("%s is older than %s \n", a1.getName(), a2.getName());
    }else if (a1.getAge() < a2.getAge() )
    {
        printf("%s is older than %s \n", a1.getName(), a2.getName());
    }else{
        printf("both is equal: Age \n");
    }
}

void compare_Weight_Animals(animals a1, animals a2){
    if (a1.getWeight() > a2.getWeight())
    {
        printf("%s is heavier than %s \n ", a1.getName(), a2.getName());
    }else if (a1.getWeight() < a2.getWeight())
    {
        printf("%s is heavier than %s \n ", a1.getName(), a2.getName());
    }else{
        printf("both is equal: Weight \n");
    }
    
}

int main(int argc, char const *argv[])
{   
    animals a1((char *)"Dog", 40, 60.5, 2.1);
    printf("Index BMI of %s : %lf\n", a1.getName(), a1.BMI());
    
    animals a2((char *)"meo", 28, 60, 1.9);
    printf("Index BMI of %s : %lf\n", a2.getName(), a2.BMI());

    compare_Age_Animals(a1, a2);
    compare_Weight_Animals(a1, a2);
    return 0;
}





