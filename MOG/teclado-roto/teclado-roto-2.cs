// Problem name: B - Teclado roto
// Problem link: https://matcomgrader.com/problem/236/teclado-roto/
// Submission link: https://matcomgrader.com/submission/62170/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 * Name: Jose Ariel Romero Costa
 * Class: ¿?
 * Problem: B - Teclado roto
 */

namespace B___Teclado_roto
{
    class Program
    {
        static void Main(string[] args)
        {
            string text, textResult, add;
            int len,donde;
            while ((text = Console.ReadLine()) != null)
            {
                textResult = "";
                add = "";
                len = text.Length;
                donde = 1;
                for (int i = 0; i < len; i++)
                {
                    if (text[i] != ']' && text[i] != '[')
                        add += text[i];
                    else
                    {
                        if (donde == 1)
                            textResult += add;
                        else
                            textResult = add + textResult;
                        if (text[i] == ']')
                            donde = 1;
                        else
                            donde = 0;
                        add = "";
                    }
                }
                if (donde == 1)
                    textResult += add;
                else
                    textResult = add + textResult;
                Console.WriteLine(textResult);
            }
        }
    }
}