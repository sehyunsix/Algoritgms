#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &v, cpx w) {
    int n = v.size();
    if(n == 1) return;

    vector<cpx> even(n/2), odd(n/2);
    for(int i=0; i<n; i++) {
        if(i % 2 == 0) even[i/2] = v[i];
        else odd[i/2] = v[i];
    }

    FFT(even, w*w);
    FFT(odd, w*w);

    cpx z(1, 0);
    for(int i=0; i<n/2; i++) {
        v[i] = even[i] + z*odd[i];
        v[i + n/2] = even[i] - z*odd[i];

        z *= w;
    }
}


vector<int> multiply(vector<int> v, vector<int> u) {
    vector<int> w(v.size() + u.size() - 1);

    int n = 1;
    while(n <= v.size() || n <= u.size()) n *= 2;
    n *= 2;

    v.resize(n);
    u.resize(n);

    vector<cpx> v_(n), u_(n);
    for(int i=0; i<n; i++) {
        v_[i] = cpx(v[i], 0);
        u_[i] = cpx(u[i], 0);
    }
    cpx unit(cos(2*PI/n), sin(2*PI/n));

    FFT(v_, unit);
    FFT(u_, unit);

    vector<cpx> w_(n);
    for(int i=0; i<n; i++) w_[i] = v_[i] * u_[i];

    FFT(w_, cpx(1, 0)/unit);
    for(int i=0; i<n; i++) w_[i] /= cpx(n, 0);

    for(int i=0; i<w.size(); i++) w[i] = round(w_[i].real());

        return w;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> v = {1, 2};
    vector<int> u = {1, 3};

    vector<int> w = multiply(v, u);
    for(int i=0; i<w.size(); i++) cout << w[i] << " ";
}