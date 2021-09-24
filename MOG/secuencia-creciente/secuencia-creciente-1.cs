// Problem name: C - Secuencia creciente
// Problem link: https://matcomgrader.com/problem/4472/secuencia-creciente/
// Submission link: https://matcomgrader.com/submission/72364/

using System;

namespace I___Secuencia_Creciente
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] aux = Console.ReadLine().Split();
            int n = int.Parse(aux[0]), d = int.Parse(aux[1]),cantd=0;
            double p,now;
            aux = Console.ReadLine().Split();
            int[] nums = new int[n];
            nums[0] = int.Parse(aux[0]);
            for (int i = 1; i < n; i++)
            {
                now = int.Parse(aux[i]);
                if (now <= nums[i - 1])
                {
                    p = Math.Ceiling((nums[i - 1] - now + 1) / d);
                    cantd += (int)(p);
                    now += ((int)(p)) * d;
                }
                nums[i] = (int)now;
            }
            Console.WriteLine(cantd);
        }
    }
}