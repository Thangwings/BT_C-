#include<iostream>
#include<string>
#include<vector>
#include<string.h>

using namespace std;

typedef enum{
    GOOD,
    PRETTY,
    MEDIUM,
    WEAK
}RANK;

class Student{
    private:
        int Id;
        string Name;
        int Age;
        float Math_grade;
        float Physic_grade;
        float Chemistry_grade;
        double Average_grade = 0;
        string Rank;
    public:
        Student();

        virtual void Input();
        virtual void Output();

        string Get_name(){ return this->Name;};
        int Get_age(){ return this->Age;};
        float Get_math(){ return this->Math_grade;}; 
        float Get_physic(){ return this->Physic_grade;};
        float Get_chemistry(){ return this->Chemistry_grade;};
        int Get_id(){return this->Id;};

        double Get_Averagegrade();
        string Get_rank();
};
Student::Student(){
    static int id = 100;
    this->Id = id;
    id++;

    this->Name = "";
    this->Age = 0;
    this->Math_grade =0;
    this->Physic_grade =0;
    this->Chemistry_grade = 0;
}

void Student::Input(){
    cin.ignore();
    cout<<"- Name : ";
    getline(cin,Name);
    cout<<"- Age: ";
    cin>>Age;
    cout<<"- Math grade: ";
    cin>>Math_grade;
    cout<<"- Physic grade: ";
    cin>>Physic_grade;
    cout<<"- Chemistry grade: ";
    cin>>Chemistry_grade;
    cout<<endl;
}

void Student::Output(){
    cout<<Id<<"   ";
    cout<<Name<<"   ";
    cout<<Age<<"   ";
    cout<<Get_Averagegrade()<<"   ";
    cout<<Get_rank()<<endl;
}

double Student::Get_Averagegrade(){
    Student::Average_grade = (Get_math() + Get_physic() + Get_chemistry())/3;
    return Student::Average_grade;
}

string Student::Get_rank(){
    if(Get_Averagegrade() >= 8){
        Student::Rank = "GOOD";
    }
    else if (Get_Averagegrade() >= 6.5 && Get_Averagegrade() < 8){
        Student::Rank = "PRETTY";
    }
    else if(Get_Averagegrade() >= 5 && Get_Averagegrade() < 6.5){
        Student::Rank = "MEDIUM";
    }
    else {
        Student::Rank = "WEAK";
    }
    return this->Rank;
}

class Program: public Student{
    private:
        vector<Student> databaseSTUDENT;
    public:

        void Add_student();
        void Update_student();
        void Delete_student();
        void Find_student();
        void Arrange_student_AVERAGE();
        void Arrange_student_NAME();
        void Show_list();
};

void Program::Add_student(){
    Student new_student;
    new_student.Input();
    databaseSTUDENT.push_back(new_student);
}

void Program::Update_student(){
    Student update_student;
    int id;
    bool check_id = false;
    cout<<"Enter ID of student want UPDATE: ";
    cin>>id;
    for (int i = 0; i < databaseSTUDENT.size(); i++)
    {
        if(databaseSTUDENT.at(i).Get_id() == id){
            databaseSTUDENT.at(i).Input();
            i = databaseSTUDENT.size();
            cout<<"Update complete!"<<endl;
            check_id = true;
        }
    }
    if (check_id == false){
        cout<<" ID not correct!"<<endl;
    }
}

void Program::Delete_student(){
    int id;
    bool check_id = false;
    cout<<"Enter ID of student you want DELETE: ";
    cin>>id;
    for (int i = 0; i < databaseSTUDENT.size(); i++)
    {
        if (databaseSTUDENT.at(i).Get_id() == id){
            databaseSTUDENT.erase(databaseSTUDENT.begin()+i);
            cout<<"Delete compelete!"<<endl;
            i = databaseSTUDENT.size();
            check_id = true;
        }
    }
    if (check_id = false){
        cout<<"ID not correct!"<<endl;
    }
}


void Program::Arrange_student_AVERAGE(){
    Student S;
        for (int i = 0; i < databaseSTUDENT.size(); i++)
        {
            for (int j = i + 1; j < databaseSTUDENT.size(); j++)
            {
                if(databaseSTUDENT[i].Get_Averagegrade()>databaseSTUDENT[j].Get_Averagegrade()){
                  S = databaseSTUDENT[i];
                  databaseSTUDENT[i] = databaseSTUDENT[j];
                  databaseSTUDENT[j] = S;    
                }
            }
        }
        cout<<" Arrange student follow AVERAGE is complete!"<<endl;
    }

void Program::Find_student(){
    string name;
    bool check_name =false;
    cout<<"Enter name of student you want to FIND: ";
    getline(cin,name);
    cin.ignore();
    for (int i = 0; i < databaseSTUDENT.size(); i++)
    {
        if (databaseSTUDENT.at(i).Get_name() == name){
            cout<<"Student you want to find :"<<endl;
            databaseSTUDENT.at(i).Output();
            i = databaseSTUDENT.size();
            check_name = true;
        }
    }
    if (check_name == false){
        cout<<"Name : "<<name<<" is NOT have in the list student!"<<endl;
    }
}

void Program::Arrange_student_NAME(){
    Student tempStudent;
    for(int i = 0; i < databaseSTUDENT.size(); i++){
        for (int j =0; j < databaseSTUDENT.size() - 1; j++){
        if(strcmp(databaseSTUDENT[j].Get_name().c_str(),databaseSTUDENT[j + 1].Get_name().c_str()) > 0){
            tempStudent = databaseSTUDENT[j];
            databaseSTUDENT[j] = databaseSTUDENT[j + 1];
            databaseSTUDENT[j + 1] = tempStudent;
        }
        else {
            continue;
        }
    }
    }
    cout<<" Arrange student follow NAME is complete!"<<endl;
}

void Program::Show_list(){
    int count = 1;
    cout<<"SHOW LIST DATA STUDENT"<<endl;
    cout<<"STT - ID -  NAME  - AGE - AVERAGE - RANK "<<endl;
    for (int i = 0; i < databaseSTUDENT.size(); i++)
    {
        cout<<count<<"   ";
        databaseSTUDENT.at(i).Output();
        count++;
    }
}


int main(int argc, char const *argv[])
{
    int Key ;
    Program RUN;
    do
    {
        cout<<endl<<"-----PROGRAM STUDENT-----"<<endl;
        cout<<" [1] Add Student!"<<endl;
        cout<<" [2] Update Student!"<<endl;
        cout<<" [3] Delete Student!"<<endl;
        cout<<" [4] Find Student!"<<endl;
        cout<<" [5] Arrange Student - AVERAGE!"<<endl;
        cout<<" [6] Arrange Student - NAME!"<<endl;
        cout<<" [7] Show list student!"<<endl;
        cout<<" [0] EXIT!"<<endl;
        cout<<endl<<"  - Enter Key: ";
        cin>>Key;
        switch (Key)
        {
        case 1:
            RUN.Add_student();
            break;
        case 2:
            RUN.Update_student();
            break;
        case 3:
            RUN.Delete_student();
            break;
        case 4:
            RUN.Find_student();
            break;
        case 5:
            RUN.Arrange_student_AVERAGE();
            break;
        case 6:
            RUN.Arrange_student_NAME();
            break;
        case 7:
            RUN.Show_list();
            break;
        
        default:
            cout<<"EXIT"<<endl;
            break;
        }
        
    } while(Key);
    

    return 0;
}