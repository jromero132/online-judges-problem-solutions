// Problem name: To Add or to Multiply
// Problem link: https://codeforces.com/gym/101175/problem/A
// Submission link: https://codeforces.com/gym/101175/submission/34259239

using System;

namespace ConsoleApplication1
{
    class Program
    {

        static void Main()
        {
            long a, m, p, q, r, s;
            string[] line;
            for( int caseNumber = 1 ; ( line = Console.ReadLine().Split() )[ 0 ] != "0" ; caseNumber++ )
            {
                a = long.Parse( line[ 0 ] );
                m = long.Parse( line[ 1 ] );
                p = long.Parse( line[ 2 ] );
                q = long.Parse( line[ 3 ] );
                r = long.Parse( line[ 4 ] );
                s = long.Parse( line[ 5 ] );
                Console.WriteLine( $"Case {caseNumber}: {Solve( a, m, p, q, r, s )}" );
            }
        }

        static string ToString( int n )
        {
            string ans = "";
            do
            {
                ans = (char)( n % 10 + '0' ) + ans;
                n /= 10;
            } while( n > 0 );
            return ans;
        }

        static bool IsLess( string a, string b )
        {
            int value_a = 0, value_b = 0, len = Math.Min( a.Length, b.Length ), p1 = 0, p2;
            while( p1 < len && a[ p1 ] == b[ p1 ] )
                p1++;
            p2 = p1;
            while( --p1 >= 0 && a[ p1 ] != ' ' ) ;
            while( --p2 >= 0 && a[ p2 ] != ' ' ) ;
            p1++;
            p2++;
            while( a[ p1 ] != 'A' && a[ p1 ] != 'M' )
            {
                value_a *= 10;
                value_a += a[ p1++ ] - '0';
            }
            while( b[ p2 ] != 'A' && b[ p2 ] != 'M' )
            {
                value_b *= 10;
                value_b += b[ p2++ ] - '0';
            }
            return ( a[ p1 ] == b[ p2 ] ? ( a[ p1 ] == 'A' ? value_a > value_b : value_a < value_b ) : a[ p1 ] == 'A' );
        }

        const int MAX = 30;
        const int MAX_NUMBER = 1000000000;

        static string Solve( long a, long m, long p, long q, long r, long s )
        {
            if( r <= p && s >= q )
                return "empty";

            long left, right, sum;
            long[] pot = new long[ MAX ];
            pot[ 0 ] = 1;
            for( int i = 1 ; i < MAX && ( pot[ i ] = pot[ i - 1 ] * m ) <= MAX_NUMBER ; i++ ) ;

            int ope, aux, len_ans = 0, len_now;
            string ans = "", now;
            for( int i = 0 ; i < MAX && ( right = s - q * pot[ i ] ) >= 0 ; i++ )
            {
                sum = len_now = ope = 0;
                left = r - p * pot[ i ];
                left = left / a + ( ( left <= 0 || left % a == 0 ) ? 0 : 1 );
                left = Math.Max( left, 0L );
                right /= a;
                now = "";
                for( int j = 0 ; j <= i ; j++ )
                {
                    if( sum + pot[ i - j ] > right )
                    {
                        if( j != 0 )
                            ope++;
                        continue;
                    }
                    aux = (int)Math.Min( ( right - sum ) / pot[ i - j ], ( left - sum ) / pot[ i - j ] + ( ( left - sum ) % pot[ i - j ] == 0 ? 0 : 1 ) );
                    if( aux == 0 )
                    {
                        if( j != 0 )
                            ope++;
                        continue;
                    }
                    if( j != 0 )
                    {
                        now += ToString( ope + 1 ) + "M ";
                        len_now += ope + 1;
                    }
                    ope = aux;
                    now += ToString( ope ) + "A ";
                    sum += ope * pot[ i - j ];
                    len_now += ope;
                    ope = 0;
                    if( sum >= left )
                    {
                        if( j != i )
                        {
                            now += ToString( i - j ) + "M ";
                            len_now += i - j;
                        }
                        break;
                    }
                }
                if( sum >= left )
                {
                    if( ope > 0 )
                    {
                        now += ToString( ope ) + "M ";
                        len_now += ope;
                    }
                    now = now.Substring( 0, now.Length - 1 );
                    if( ans == "" || ( len_now < len_ans ) || ( len_now == len_ans && IsLess( now, ans ) ) )
                    {
                        ans = now;
                        len_ans = len_now;
                    }
                }
            }
            return ans == "" ? "impossible" : ans;
        }
    }
}
