#include <bits/stdc++.h>

using namespace std;

double v0, k0, a1, a2, b1, b2;

double v(double t) {
    double result;
    if(t == 0) {
        result = v0 + a2/b2;
    }
    else {
        double term1 = v0 * cos(sqrt(a1*a2)*t);
        double term2 = k0 * (sqrt(a2)*b1) / (b2*sqrt(a1)) * sin(sqrt(a1*a2)*t);
        double term3 = a2/b2;
        result = term1 - term2 + term3;
    }
    return result;
}


double k(double t) {
    double result;
    if (t == 0) {
        result = k0 + a1/b1;
    }
    else {
        double term1 = v0 * (b2*sqrt(a1)) / (b1*sqrt(a2)) * sin(sqrt(a1*a2)*t);
        double term2 = k0 * cos(sqrt(a1*a2)*t);
        double term3 = a1/b1;
        result = term1 + term2 + term3;
    }
    return result;
}


int main()
{
    FILE* pipe = _popen("C:\\gnuplot\\bin\\gnuplot -persist", "w");
    fprintf(pipe, "%s\n" ,"set terminal qt 0");
    fprintf(pipe, "%s\n", "plot '-' title 'victims' with lines, '-' title 'killers' with lines");
    int N, T;
    double t;
    cin>>v0>>k0>>a1>>b1>>a2>>b2>>T>>N;
    v0 = v0 - a2/b2;
    k0 = k0 - a1/b1;

    for(t = 0.0; t <= T; t += double(T)/N){
        fprintf(pipe, "%f\t%f\n", k(t), v(t));
    }
    fprintf(pipe, "%s\n", "e");

    fprintf(pipe, "%s\n", "e");
    fprintf(pipe, "%s\n" ,"set terminal qt 1");
    fprintf(pipe, "%s\n", "plot '-' title 'relation' with lines");
    fflush(pipe);
    _pclose(pipe);
}
