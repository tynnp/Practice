using System;
namespace tynnp {
    class program {
        static void Main(string[] args) {
            double sale1, sale2, commissionRate;
            double.TryParse(Console.ReadLine(), out sale1);
            double.TryParse(Console.ReadLine(), out sale2);
            double.TryParse(Console.ReadLine(), out commissionRate);
            Console.WriteLine((sale1 + sale2)* commissionRate);
        }
    }
}