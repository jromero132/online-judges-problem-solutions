// Problem name: Fibonacci Words
// Problem link: https://codeforces.com/gym/101205/problem/D
// Submission link: https://codeforces.com/gym/101205/submission/34334370

using System;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main()
        {
            Fibonacci();

            int n, c = 0;
            string p;
            while( ( p = Console.ReadLine() ) != null )
            {
                n = int.Parse( p );
                p = Console.ReadLine();
                Console.WriteLine( $"Case {++c}: {Solve( n, p )}" );
            }
        }


        const int MAX = 101;
        static ulong[] fib;

        static void Fibonacci()
        {
        	fib = new ulong[ MAX ];
            fib[ 0 ] = 0;
            fib[ 1 ] = 1;
            for( int i = 2 ; i < MAX ; i++ )
                fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
        }

        static ulong Solve( int n, string p )
        {
            int last = p.Length - 1;

            if( n == 0 && last > 0 )
                return 0UL;

            if( last == 0 )
            {
                if( p[ 0 ] == '0' )
                    return ( n == 0 ? 1 : fib[ n - 1 ] );
                return fib[ n ];
            }

            if( p[ 0 ] == '0' )
            {
                p = '1' + p;
                last++;
            }

            string s1 = "", s2 = "";
            for( int i = 0 ; i < last ; i++ )
            {
                if( p[ i ] == '0' )
                {
                    return 0UL;
                }
                else
                {
                    if( p[ i + 1 ] == '0' )
                    {
                        s1 += '1';
                        i++;
                    }
                    else
                    {
                        s1 += '0';
                    }
                }
            }

            if( p[ last ] == '0' && p[ last - 1 ] == '0' )
                return 0UL;

            if( p[ last ] == '1' )
            {
                s2 = s1 + '1';
                s1 = s1 + '0';
            }

            return Solve( n - 1, s1 ) + ( s2 == "" ? 0UL : Solve( n - 1, s2 ) );
        }
    }
}