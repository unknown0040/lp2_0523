#include <iostream>
using namespace std;

// Function to evaluate employee performance based on criteria
string evaluatePerformance(float productivity, float quality, float teamwork)
{
   // Set thresholds for performance evaluation
   const float productivityThreshold = 7;
   const float qualityThreshold = 8;
   const float teamworkThreshold = 7;

   // Evaluate performance based on criteria
   if (productivity >= productivityThreshold && quality >= qualityThreshold && teamwork >= teamworkThreshold)
   {
      return "Excellent";
   }
   else if ((productivity >= productivityThreshold && quality >= qualityThreshold) || (productivity >= productivityThreshold && teamwork >= teamworkThreshold) || (quality >= qualityThreshold && teamwork >= teamworkThreshold))
   {
      return "Great";
   }
   else if (productivity >= productivityThreshold || quality >= qualityThreshold || teamwork >= teamworkThreshold)
   {
      return "Satisfactory";
   }
   else
   {
      return "Poor";
   }
}

int main()
{
   // Input employee performance criteria
   float productivity, quality, teamwork;
   cout << "Enter productivity score (0-10): ";
   cin >> productivity;
   cout << "Enter quality score (0-10): ";
   cin >> quality;
   cout << "Enter teamwork score (0-10): ";
   cin >> teamwork;

   // Evaluate performance
   string performance = evaluatePerformance(productivity, quality, teamwork);

   // Output performance evaluation
   cout << "Employee performance: " << performance << endl;

   return 0;
}