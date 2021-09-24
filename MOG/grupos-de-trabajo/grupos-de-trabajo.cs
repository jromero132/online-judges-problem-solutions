// Problem name: G - Grupos de trabajo
// Problem link: https://matcomgrader.com/problem/5886/grupos-de-trabajo/
// Submission link: https://matcomgrader.com/submission/73015/

using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            int t;
            string group;
            string[] groups;
            string[] names;
            List<string> ans,Grupo;
            List<string>[] Nombres;
            while ((t = int.Parse(Console.ReadLine())) != 0)
            {
                group = Console.ReadLine();
                group=group.Remove(group.Length - 1);
                groups = group.Split(':');
                names = groups[1].Split(',');
                ans = names.ToList();
                Nombres = new List<string>[t - 1];
                Grupo = new List<string>();
                for (int i = 1; i < t; i++)
                {
                    group = Console.ReadLine();
                    group=group.Remove(group.Length - 1);
                    groups = group.Split(':');
                    names = groups[1].Split(',');
                    Grupo.Add(groups[0]);
                    Nombres[i-1]=names.ToList();
                }
                int len = ans.Count(),res=0;
                t--;
                for (int i = 0; i < len; i++)
                {
                    for(int j=0;j<t;j++)
                        if (Grupo[j] == ans[i])
                        {
                            res++;
                            int x = Nombres[j].Count();
                            for (int k = 0; k < x; k++)
                                if (ans.IndexOf(Nombres[j][k]) == -1)
                                {
                                    ans.Add(Nombres[j][k]);
                                    len++;
                                }
                            break;
                        }
                }
                Console.WriteLine(ans.Count()-res);
            }
        }
    }
}