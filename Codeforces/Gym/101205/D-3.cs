// Problem name: Fibonacci Words
// Problem link: https://codeforces.com/gym/101205/problem/D
// Submission link: https://codeforces.com/gym/101205/submission/34334362

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

        const int MAX = 29, MAX_N = 101, MAX_LENGTH = 100000;
        static int[] fail;
        static ulong[] fib, C;
        static string[] Fib;

        static void Fibonacci()
        {
            fib = new ulong[ MAX_N ];
            Fib = new string[ MAX ];
            fib[ 0 ] = 0UL;
            fib[ 1 ] = 1UL;
            Fib[ 0 ] = "0";
            Fib[ 1 ] = "1";
            for( int i = 2 ; i < MAX ; i++ )
            {
                fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
                Fib[ i ] = Fib[ i - 1 ] + Fib[ i - 2 ];
            }
            for( int i = MAX ; i < MAX_N ; i++ )
                fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
        }

        static void PreKMP( string p )
        {
            int len = p.Length;
            fail = new int[ len ];
            for( int i = 1, j = 0 ; i < len ; )
            {
                if( p[ i ] == p[ j ] )
                    fail[ i++ ] = ++j;
                else
                {
                    if( j > 0 )
                        j = fail[ j - 1 ];
                    else
                        fail[ i++ ] = 0;
                }
            }
        }

        static void Ocurrences( string p, int m )
        {
            PreKMP( p );
            C = new ulong[ 4 ];
            int len_p = p.Length, len = Math.Min( (int)fib[ m ] + len_p - 1, (int)fib[ m + 1 ] ), len_c0 = (int)fib[ m - 1 ] + len_p;
            for( int i = 0, j = 0 ; i < len ; )
            {
                if( Fib[ m ][ i ] == p[ j ] )
                {
                    i++;
                    j++;
                    if( j == len_p )
                    {
                        if( i < len_c0 )
                        {
                            if( i <= (int)fib[ m - 1 ] )
                                C[ 0 ]++;
                            else
                                C[ 2 ]++;
                            C[ 1 ]++;
                        }
                        else
                        {
                            if( i <= (int)fib[ m ] )
                                C[ 1 ]++;
                            else
                                C[ 3 ]++;
                        }
                        j = fail[ j - 1 ];
                    }
                }
                else if( j > 0 )
                    j = fail[ j - 1 ];
                else
                    i++;
            }
        }

        static ulong Solve( int n, string p )
        {
            ulong len_p = (ulong)p.Length;
            if( len_p == 1 )
            {
                if( p[ 0 ] == '0' )
                    return n == 0 ? 1UL : fib[ n - 1 ];
                return fib[ n ];
            }
            int m;
            for( m = 3 ; len_p > fib[ m - 2 ] ; m++ ) ;
            if( m > n )
            {
                if( m - 3 > n )
                    return 0UL;
                m = n;
            }
            PreKMP( p );
            Ocurrences( p, m );
            n -= m - 1;
            for( int i = 1 ; i <= n ; i++ )
            {
                ulong temp = C[ 0 ];
                C[ 0 ] = C[ 1 ];
                C[ 1 ] += temp + C[ i % 2 + 2 ];
            }
            return C[ 1 ];
        }
    }
}