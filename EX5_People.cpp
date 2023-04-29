#include <stdio.h>

class People{
    private:
    char name[20];
    long yearofBirth;
    char address[20];
    long age;
    public:
    void setPeople();
    void calculateAge();
    void printInformation();
};
#define CURRENTYEAR 2023

void People::setPeople(){
    printf("enter your name:\n");
    scanf("%s",People::name);
    printf("enter your address:\n");
    scanf("%s",People::address);
    printf("enter your year of Birth:\n");
    scanf("%d",&(People::yearofBirth));
}

void People::printInformation(){
    printf("Name is %s:\n",People::name);
    printf("Year of birth is %d\n",People::yearofBirth);
    printf(" Address is %s\n",People::address);
    printf("%d years old\n",People::age);
}

void People::calculateAge(){
    People::age = CURRENTYEAR - People::yearofBirth;
}

int main(int argc, char const *argv[])
{
    People people;
    people.setPeople();
    people.calculateAge();
    people.printInformation();
    return 0;
}