#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void gaussianElimination(vector<vector<double>>& a, vector<double>& b) {
    int n = a.size();

    
    for (int i = 0; i < n; i++) {
        
        int pivotRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(a[k][i]) > abs(a[pivotRow][i])) {
                pivotRow = k;
            }
        }

        
        if (pivotRow != i) {
            swap(a[i], a[pivotRow]);
            swap(b[i], b[pivotRow]);
        }

        
        for (int k = i + 1; k < n; k++) {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j < n; j++) {
                a[k][j] -= factor * a[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    
    for (int i = n - 1; i >= 0; i--) {
        for (int k = i + 1; k < n; k++) {
            b[i] -= a[i][k] * b[k];
        }
        b[i] /= a[i][i];
    }
}

int main() {
    
    vector<vector<double>> a = {
        {2, 1, 1},
        {4, 3, 3},
        {8, 7, 9}
    };
    vector<double> b = {1, 2, 4};

    gaussianElimination(a, b);

    cout << fixed << setprecision(6);
    cout << "Solution:" << endl;
    for (int i = 0; i < b.size(); i++) {
        cout << "x" << i + 1 << " = " << b[i] << endl;
    }

    return 0;
}