#include <iostream>
using namespace std;

struct Employee
{
   string name;
   double jobKnowledge;
   double communicationSkills;
   double teamwork;
   double problemSolving;
   double productivity;
};

void evaluateEmployee(const Employee &employee)
{
   double overallScore = (employee.jobKnowledge +
                          employee.communicationSkills +
                          employee.teamwork +
                          employee.problemSolving +
                          employee.productivity) /
                         5.0;

   cout << "Evaluation Results for " << employee.name << endl;
   cout << "Job Knowledge: " << employee.jobKnowledge << endl;
   cout << "Communication Skills: " << employee.communicationSkills << endl;
   cout << "Teamwork: " << employee.teamwork << endl;
   cout << "Problem Solving: " << employee.problemSolving << endl;
   cout << "Productivity: " << employee.productivity << endl;
   cout << "Overall Score: " << overallScore << endl;
   cout << endl;
}

int main()
{
   Employee emp1 = {"John Doe", 8.5, 9.0, 7.5, 8.0, 9.0};
   Employee emp2 = {"Jane Smith", 9.0, 8.0, 8.5, 9.0, 8.5};
   Employee emp3 = {"Mike Johnson", 7.0, 7.5, 8.0, 7.5, 7.0};

   evaluateEmployee(emp1);
   evaluateEmployee(emp2);
   evaluateEmployee(emp3);

   return 0;
}
