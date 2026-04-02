#include <iostream>
#include <iomanip>
using namespace std;
class DivSales
{
    private:
       double quarterlySales[4];
       static double totalCorporateSales;
    public:
       void setSales(double q1, double q2, double q3, double q4)
        {
           if (q1 < 0 || q2 < 0 || q3 < 0 || q4 < 0)
            {
               cout << "Error: Sales figures must be positive." << endl;
               exit(EXIT_FAILURE);
           }
           quarterlySales[0] = q1;
           quarterlySales[1] = q2;
           quarterlySales[2] = q3;
           quarterlySales[3] = q4;
           totalCorporateSales += q1 + q2 + q3 + q4;
       }
       double getQuarterlySale(int quarter) const
        {
           if (quarter < 0 || quarter > 3)
            {
               cout << "Error: Invalid quarter index." << endl;
               exit(EXIT_FAILURE);
           }
           return quarterlySales[quarter];
       }
       static double getTotalCorporateSales()  
        {
           return totalCorporateSales;
       }
};
    double DivSales::totalCorporateSales = 0;
int main()
{
   const int DIVISIONS = 6;
   DivSales divisions[DIVISIONS];
   double q[4];
   for (int i = 0; i < DIVISIONS; i++)
    {
       cout << "Enter sales for Division " << (i + 1) << ":\n";
       for (int j = 0; j < 4; j++)
        {
           do
            {
               cout << "  Quarter " << (j + 1) << ": $";
               cin >> q[j];
               if (q[j] < 0)
                {
                   cout << "    Please enter a positive value.\n";
               }
           } while (q[j] < 0);
       }
       divisions[i].setSales(q[0], q[1], q[2], q[3]);
       cout << endl;
   }
   cout << fixed << setprecision(2);
   cout << "\nDivision Sales Report\n";
   cout << "----------------------\n";
   for (int i = 0; i < DIVISIONS; i++)
    {
       cout << "Division " << (i + 1) << ":\n";
       for (int j = 0; j < 4; j++)
        {
           cout << "  Quarter " << (j + 1) << ": $" << divisions[i].getQuarterlySale(j) << endl;
       }
       cout << endl;
   }
   cout << "Total Corporate Sales for the Year: $"
       << DivSales::getTotalCorporateSales() << endl;
return 0;
}



