// Problem name: A - A clasificar triángulos
// Problem link: https://matcomgrader.com/problem/5880/a-clasificar-triangulos/
// Submission link: https://matcomgrader.com/submission/72753/

using System;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine()),a,b,c;
            string[] aux;
            for (int i = 1; i <= t; i++)
            {
                aux = Console.ReadLine().Split();
                a = int.Parse(aux[0]);
                b = int.Parse(aux[1]);
                c = int.Parse(aux[2]);
                Console.Write("Case #"+i+": ");
                if (a + b <= c || b + c <= a || a + c <= b)
                    Console.WriteLine("invalid!");
                else if (a == b && b == c)
                    Console.WriteLine("equilateral");
                else if (a != b && b != c && a != c)
                    Console.WriteLine("scalene");
                else
                    Console.WriteLine("isosceles");
            }
        }
    }
}