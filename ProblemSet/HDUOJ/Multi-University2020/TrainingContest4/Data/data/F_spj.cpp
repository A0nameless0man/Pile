const double eps = 1.010000e-06;
const double ans[] = {
  179.96153846153845279332,
  178.64999999999997726263,
  178.24615384615384527933,
  178.48461538461532427391,
  178.55384615384610924593,
  178.45000000000001705303,
  178.56923076923072812860,
  178.56923076923078497202,
  177.79999999999998294697,
  178.73076923076922639666,
  178.64999999999997726263,
  178.41538461538459614530,
  178.55000000000003979039,
  178.47692307692310009770,
  178.54999999999998294697,
  178.78461538461536406430,
  178.40000000000000568434,
  178.49999999999997157829,
  178.48750000000001136868,
  178.00000000000000000000,
  178.52307692307692832401,
  178.49230769230766213695,
  178.49999999999997157829,
  178.69999999999998863132,
  178.64999999999997726263,
  178.60769230769224691358,
  178.34999999999999431566,
  178.41538461538453930189,
  178.74999999999997157829,
  178.45000000000001705303,
  178.54999999999998294697,
  178.57692307692306599165,
  178.33846153846153015365,
  178.54615384615379980460,
  178.26153846153843574029,
  178.34999999999999431566,
  178.54615384615385664802,
  178.34999999999996589395,
  178.70000000000001705303,
  178.43076923076921502798,
  178.04999999999995452526,
  177.92307692307687716493,
  178.46153846153845279332,
  178.58461538461537543299,
  178.25000000000000000000,
  178.79999999999998294697,
  178.47692307692310009770,
  178.34615384615383959499,
  178.39583333333334280724,
  178.45000000000001705303,
  178.65000000000000568434,
  177.89230769230772466472,
  178.30000000000001136868,
  178.53846153846149036326,
  178.09999999999999431566,
  178.57692307692306599165,
  178.48461538461532427391,
  178.30000000000001136868,
  178.24999999999997157829,
  178.50000000000000000000,
  178.29999999999998294697,
  178.43076923076924344969,
  176.89999999999994884092,
  178.41538461538459614530,
  178.43846153846149604760,
  178.66923076923077928768,
  178.26153846153843574029,
  178.25000000000000000000,
  178.19999999999998863132,
  178.29999999999998294697,
  178.55000000000001136868,
  178.42307692307690558664,
  178.58461538461537543299,
  178.75000000000002842171,
  178.65000000000000568434,
  178.26153846153840731859,
  178.25384615384618314238,
  178.24999999999997157829,
  178.16923076923077928768,
  178.34999999999999431566,
  178.33846153846155857536,
  177.98461538461529585220,
  178.59999999999999431566,
  178.04999999999998294697,
  178.53076923076923776534,
  178.49999999999997157829,
  178.29999999999998294697,
  178.00000000000000000000,
  178.54999999999998294697,
  178.53333333333330301684,
  178.40769230769234354739,
  178.50769230769225259792,
  177.50000000000000000000,
  178.31666666666663445540,
  178.22307692307688853361,
  178.24999999999997157829,
  178.19999999999998863132,
  178.45000000000001705303,
  178.44999999999998863132,
  178.55000000000001136868,
};
const int T = sizeof(ans) / sizeof(ans[0]);

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

const int maxn = 3e5;
typedef double real;

int n;
char s[maxn + 1];
int m;
int head[maxn];

void WrongAnswer(void) {
  puts("WA");
  exit(0);
}

void Accepted(void) {
  puts("AC");
  exit(0);
}

int main(void) {
  n = fread(s, 1, maxn, stdin);
  s[n] = '\0';
  m = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && s[j] != '\n') ++j;
    int k = j;
    while (k > i && isspace(s[k - 1])) --k;
    s[k] = '\0';
    head[m++] = i;
    i = j + 1;
  }
  while (m > 0 && s[head[m - 1]] == '\0') --m;

  if (m != T) {
    WrongAnswer();
  }
  for (int i = 0; i < T; ++i) {
    real x, y = ans[i];
    sscanf(s + head[i], "%lf", &x);
    if (!isfinite(x)) {
      WrongAnswer();
    }
    if (abs(x - y) > max(1.0, abs(y)) * eps) {
      WrongAnswer();
    }
  }
  Accepted();
}