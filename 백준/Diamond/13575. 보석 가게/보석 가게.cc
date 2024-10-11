#include <bits/stdc++.h>
#define ll long long
using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &v, bool inv) {
    int S = v.size();

    for(int i = 1, j = 0; i < S; i++) {
        int bit = S/2;

        while(j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if(i < j) swap(v[i], v[j]);
    }

    for(int k = 1; k < S; k *= 2) {
        double angle = (inv ? PI/k : -PI/k);
        cpx w(cos(angle), sin(angle));

        for(int i = 0; i < S; i += k*2) {
            cpx z(1, 0);

            for(int j=0; j<k; j++) {
                cpx even = v[i+j];
                cpx odd = v[i+j+k];

                v[i+j] = even + z*odd;
                v[i+j+k] = even - z*odd;

                z *= w;
            }
        }
    }

    if(inv)
        for(int i=0; i<S; i++) v[i] /= S;
}

vector<ll> mul(vector<ll> &v, vector<ll> &u) {
    vector<cpx> vc(v.begin(), v.end());
    vector<cpx> uc(u.begin(), u.end());

    ll S = 2;
    while(S < v.size() + u.size()) S *= 2;

    vc.resize(S); FFT(vc, false);
    uc.resize(S); FFT(uc, false);

    for(int i = 0; i < S; i++) vc[i] *= uc[i];
    FFT(vc, true);

    vector<ll> w(S);
    for(int i = 0; i < S; i++) w[i] = round(vc[i].real());
    for(int i = 0; i < w.size(); i++) if(w[i]) w[i] = 1;
    return w;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;
    cin >> n >> k;
    vector<ll> v(1024);
    while(n--){
        ll a;
        cin >> a;
        v[a] = 1;
    }
    vector<ll> w = v;
    k--;
    while(k){
        if(k&1) w = mul(w,v);
        k >>= 1;
        v = mul(v,v);
    }
    for(int i = 0; i < w.size(); i++) if(w[i]) cout << i << ' ';
}