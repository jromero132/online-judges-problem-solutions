// Problem name: A - Anniversary Cake
// Problem link: https://matcomgrader.com/problem/9217/anniversary-cake/
// Submission link: https://matcomgrader.com/submission/120584/

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int h, w, x1, y1, x2, y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2)
        cout << "0 " << min(y1, y2) << " " << w << " " << max(y1, y2);
    else
        cout << min(x1, x2) << " 0 " << max(x1, x2) << " " << h << endl;
	return 0;
}