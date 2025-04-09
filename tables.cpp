#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

void random();

void personalised();

int main(){
int choice;

cout<<"Type 0 for Random or 1 for Personalised. \n";
cout<<"Would you like random questions or personalised: \n";
cin>>choice;

while((choice!=0) && (choice!=1)){
cout<<"Invalid input! Type 0 for Random or 1 for Personalised: \n";
cin>>choice;
}

if(choice==0){
    random();
}
else{
    personalised();
}
    return 0;
}

void random(){

srand(time(NULL));
int quest;
int answer;
double Totaltime = 0;
int correct = 0;
int wrong = 0;
string incorrect = "";
cout<<"How many questions should I ask? \n";
cin>>quest;

for(int i = 0; i<quest; i++){
    int x = 12 + (rand() % 19);
    int y = (rand() % 30) + 1;
    cout<<x<<"*"<<y<<"\n";
    auto start = chrono::high_resolution_clock::now(); //starts the timer 
    cin>>answer;
    auto end = chrono::high_resolution_clock::now();   //ends the timer
    chrono::duration<double> elapsed = end - start;    //to get elapsed time
    Totaltime += elapsed.count();                      //adds time of each question
    cout<<fixed<<setprecision(2);                      //to get time upto 2 dp
    if(x*y==answer){
        correct++;
    }
    else{
        wrong++;
        incorrect += to_string(x) + "*" + to_string(y) + "=" + to_string(x*y) + " (Your Answer: " + to_string(answer) + ")\n";
    }
}

cout<<"Total time taken: "<<Totaltime<<" s \n";
cout<<"Average time taken: "<<(Totaltime/quest)<<" s \n";
cout<<"Correct Answers: "<<correct<<"\n";
cout<<"Wrong Answers: "<<wrong<<"\n";
if(wrong==0){
    cout<<"Great Job! You got all answers correct \n";
}
else{
    cout<<"Incorrect Answers: \n"<<incorrect;
}

}

void personalised(){
    int x;
    int quest;
    int answer;
    double Totaltime = 0;
    int correct = 0;
    int wrong = 0;
    string incorrect = "";
    cout<<"Which table should i ask? \n";
    cin>>x;
    cout<<"How many questions should I ask? \n";
    cin>>quest;

    for(int i = 0; i<quest; i++){
        int y = (rand() % 30) + 1;
        cout<<x<<"*"<<y<<"\n";
        auto start = chrono::high_resolution_clock::now(); //starts the timer 
        cin>>answer;
        auto end = chrono::high_resolution_clock::now();   //ends the timer
        chrono::duration<double> elapsed = end - start;    //to get elapsed time
        Totaltime += elapsed.count();                      //adds time of each question
        cout<<fixed<<setprecision(2);                      //to get time upto 2 dp
        if(x*y==answer){
            correct++;
        }
        else{
            wrong++;
            incorrect += to_string(x) + "*" + to_string(y) + "=" + to_string(x*y) + " (Your Answer: " + to_string(answer) + ")\n";
        }
    }
    
    cout<<"Total time taken: "<<Totaltime<<" s \n";
    cout<<"Average time taken: "<<(Totaltime/quest)<<" s \n";
    cout<<"Correct Answers: "<<correct<<"\n";
    cout<<"Wrong Answers: "<<wrong<<"\n";
    if(wrong==0){
        cout<<"Great Job! You got all answers correct \n";
    }
    else{
        cout<<"Incorrect Answers: \n"<<incorrect;
    }
}