#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>

template <typename GT>
struct CG2D
{
    template <typename T>
    struct Point
    {
        T x;
        T y;
        T length(void) const
        {
            return sqrt(x * x + y * y);
        }
        Point<T> normal() const
        {
            T len = this->length();
            return { this->x / len, this->y / len };
        }
        Point<T> turn90() const
        {
            return { this->y, -(this->x) };
        }
        Point<T> rturn90() const
        {
            return { -(this->y), (this->x) };
        }
        Point<T> mul(const T &rop) const
        {
            return { this->x * rop, this->y * rop };
        }
        Point<T> sub(const Point<T> &rop) const
        {
            return { this->x - rop.x, this->y - rop.y };
        }
        Point<T> add(const Point<T> &rop) const
        {
            return { this->x + rop.x, this->y + rop.y };
        }
        T dot(const Point<T> &rop) const
        {
            return this->x * rop.x + this->y * rop.y;
        }
        T det(const Point<T> &rop) const
        {
            return this->x * rop.y - this->y * rop.x;
        }
    };
    template <typename T>
    struct PVLine
    {
        Point<T>         a;
        Point<T>         v;
        static PVLine<T> makeLine(const Point<T> &a,
                                  const Point<T> &b)
        {
            return { a, b.sub(a) };
        }
        bool isOnline(const Point<T> &p,
                      const T         exp = T(0)) const
        {
            Point<T> ap = p.sub(a);
            return std::abs(ap.det(v)) <= exp;
        }
        static bool isInterect(const PVLine &lop,
                               const PVLine &rop,
                               const T       exp = T(0))
        {
            return !(std::abs(lop.v.det(rop.v)) <= exp);
        }
        static Point<T> interect(const PVLine &lop,
                                 const PVLine &rop)
        {
            T n = (lop.a.sub(rop.a)).det(lop.v)
                  / rop.v.det(lop.v);
            return rop.a.add(rop.v.mul(n));
        }
        PVLine<T> move(const Point<T> &dir)
        {
            return { this->a.add(dir), this->v };
        }
    };
};

using LB = long double;

using L      = CG2D<LB>::PVLine<LB>;
using P      = CG2D<LB>::Point<LB>;
const LB EXP = 1e-8;
const LB PI  = acos(-1);
int      main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int caseid = 0; caseid < T; ++caseid)
        {
            int            n;
            int            A, B;
            LB             r;
            LB             area;
            LB             innerarea;
            LB             innerc;
            std::vector<P> pvec;
            std::vector<P> innerpvec;
            std::vector<L> lvec;
            {
                std::cin >> n >> r;
                std::cin >> A >> B;
                for(int i = 0; i < n; ++i)
                {
                    LB x, y;
                    std::cin >> x >> y;
                    pvec.push_back({ x, y });
                }
            }
#ifdef DEBUG
            {
                std::cout << "testcase: " << caseid
                          << std::endl;
                std::cout << n << " " << r << std::endl;
                std::cout << A << " " << B << std::endl;
                for(int i = 0; i < n; ++i)
                {
                    std::cout << pvec[i].x << " "
                              << pvec[i].y << std::endl;
                }
            }
#endif  // debug
            {
                area = 0.0;
                for(int i = 0; i < n; ++i)
                {
                    area += pvec[i].det(pvec[(i + 1) % n]);
                }
                if(area < 0)
                {
                    std::reverse(pvec.begin(), pvec.end());
                    area = -area;
                }
                area /= 2;
#ifdef DEBUG
                for(int i = 0;
                    i < static_cast<int>(pvec.size());
                    ++i)
                {
                    std::cout << "pvec[" << i << "]=("
                              << pvec[i].x << ","
                              << pvec[i].y << ")"
                              << std::endl;
                }
                for(int i = 0; i < n; ++i)
                {
                    std::cout
                      << "area[" << i << "]="
                      << pvec[i].det(pvec[(i + 1) % n])
                           / 2.0
                      << std::endl;
                }
                std::cout << "area=" << area << std::endl;
#endif  // DEBUG
            }
            {
                for(int i = 0; i < n; ++i)
                {
                    lvec.push_back(
                      L::makeLine(pvec[i],
                                  pvec[(i + 1) % n]));
                }
                for(int i = 0; i < n; ++i)
                {
                    lvec[i] = lvec[i].move(
                      lvec[i].v.rturn90().normal().mul(r));
                }
#ifdef DEBUG
                for(int i = 0; i < n; ++i)
                {
                    std::cout
                      << "lvec[" << i << "]={a:("
                      << lvec[i].a.x << "," << lvec[i].a.y
                      << "),\tv:(" << lvec[i].v.x << ","
                      << lvec[i].v.y << ")}" << std::endl;
                }
#endif  // DEBUG
            }
            {
                std::deque<size_t> que;
                for(int i = 0; i < 2 * n; ++i)
                {
                    while(que.size() > 1)
                    {
                        auto interect12 =

                          L::interect(
                            lvec[que[que.size() - 2]],
                            lvec[que[que.size() - 1]]);
                        auto interecto1 = L::interect(
                          lvec[i % n],
                          lvec[que[que.size() - 1]]);
                        auto dirvec =
                          interecto1.sub(interect12);
                        auto dotret = dirvec.dot(
                          lvec[que[que.size() - 1]].v);
                        if(dotret > EXP)
                        {
                            break;
                        }
                        else
                        {
                            que.pop_back();
                        }
                    }
                    que.push_back(i % n);
                }
                // while(que.size() > 2)
                // {
                //     auto il0 = L::interect(
                //       lvec[que[0]],
                //       lvec[que[que.size() - 1]]);
                //     auto i01    =
                //     L::interect(lvec[que[0]],
                //                            lvec[que[1]]);
                //     auto dirvec = i01.sub(il0);
                //     auto dotret =
                //       dirvec.dot(lvec[que[0]].v);
                //     if(dotret > EXP)
                //     {
                //         break;
                //     }
                //     else
                //     {
                //         que.pop_front();
                //     }
                // }
                {
                    std::vector<char> vis(n, 0);
                    int               i = 0;
                    for(;
                        static_cast<size_t>(i) < que.size();
                        ++i)
                    {
                        if(vis[que[i]])
                        {
                            break;
                        }
                        else
                        {
                            vis[que[i]] = true;
                        }
                    }
                    for(int j = 0; que[j] != que[i]; ++j)
                    {
                        que.pop_front();
                    }
                    for(i = 1;
                        static_cast<size_t>(i) < que.size();
                        ++i)
                    {
                        if(que[i] == que[0])
                        {
                            break;
                        }
                    }
                    while(static_cast<int>(que.size()) > i)
                    {
                        que.pop_back();
                    }
                }
#ifdef DEBUG
                for(int i = 0;
                    static_cast<size_t>(i) < que.size();
                    ++i)
                {
                    std::cout
                      << "que[" << i << "]=" << que[i]
                      << ",lvec[que[" << i << "]]={a:("
                      << lvec[que[i]].a.x << ","
                      << lvec[que[i]].a.y << "),v:("
                      << lvec[que[i]].v.x << ","
                      << lvec[que[i]].v.y << ")}"
                      << std::endl;
                }
#endif  // DEBUG
                {
                    for(int i = 0;
                        static_cast<size_t>(i) < que.size();
                        ++i)
                    {
                        innerpvec.push_back(L::interect(
                          lvec[que[i]],
                          lvec[que[(i + 1)
                                   % static_cast<int>(
                                     que.size())]]));
                    }
                }
            }
            {
                innerarea = 0.0;
                innerc    = 0.0;
                for(int i = 0;
                    i < static_cast<int>(innerpvec.size());
                    ++i)
                {
                    innerarea += innerpvec[i].det(
                      innerpvec[(i + 1)
                                % static_cast<int>(
                                  innerpvec.size())]);
                    innerc +=
                      innerpvec[i]
                        .sub(innerpvec[(i + 1)
                                       % static_cast<int>(
                                         innerpvec.size())])
                        .length();
                }
                innerarea /= 2.0;
#ifdef DEBUG
                for(int i = 0;
                    i < static_cast<int>(innerpvec.size());
                    ++i)
                {
                    std::cout << "innerpvec[" << i << "]=("
                              << innerpvec[i].x << ","
                              << innerpvec[i].y << ")"
                              << std::endl;
                }
                for(int i = 0;
                    i < static_cast<int>(innerpvec.size());
                    ++i)
                {
                    std::cout
                      << "innerarea[" << i << "]="
                      << innerpvec[i].det(
                           innerpvec[(i + 1)
                                     % static_cast<int>(
                                       innerpvec.size())])
                           / 2.0
                      << ","
                      << "innerc[" << i << "]="
                      << innerpvec[i]
                           .sub(
                             innerpvec[(i + 1)
                                       % static_cast<int>(
                                         innerpvec.size())])
                           .length()
                      << std::endl;
                }
                std::cout << "innerarea=" << innerarea
                          << ",innerc=" << innerc
                          << std::endl;
#endif  // DEBUG
            }
            if(A <= B || innerpvec.size() < 3)
            {
                std::cout << area * static_cast<LB>(A)
                          << std::endl;
            }
            else
            {
                LB machinearea =
                  innerarea + innerc * r + r * r * PI;
                LB handarea = area - machinearea;
#ifdef DEBUG
                std::cout << "PI=" << PI << std::endl;
                std::cout << "machinearea=" << machinearea
                          << std::endl;
                std::cout << "handarea=" << handarea
                          << std::endl;
#endif  // DEBUG
                std::cout << std::setprecision(
                  std::numeric_limits<LB>::digits10 + 1)
                          << handarea * static_cast<LB>(A)
                               + machinearea
                                   * static_cast<LB>(B)
                          << std::endl;
            }
        }
    }
}
/*
1
116 9312
713 568
-257 -9994
439 -9986
1475 -9888
2069 -9777
2673 -9634
3085 -9497
4095 -9122
4753 -8778
4865 -8718
5277 -8489
5560 -8295
6214 -7823
6362 -7709
6742 -7382
6900 -7236
7407 -6716
7811 -6240
8159 -5774
8405 -5413
8907 -4536
8962 -4415
9204 -3866
9490 -3147
9610 -2745
9747 -2219
9832 -1763
9929 -1181
9953 -946
9975 -222
9960 717
9941 962
9906 1288
9850 1711
9800 1979
9529 3027
9427 3325
9182 3942
8614 5073
8388 5431
7872 6152
7623 6444
7214 6894
6555 7549
6227 7806
5836 8096
5580 8280
5235 8511
4835 8741
4759 8781
4535 8895
4458 8933
3953 9159
3560 9326
2757 9606
2388 9706
2016 9791
1560 9875
656 9977
-531 9978
-945 9949
-1558 9875
-2202 9753
-2604 9650
-3134 9475
-3780 9244
-4377 8981
-4653 8849
-5058 8624
-5178 8550
-5857 8101
-6142 7880
-6429 7633
-7133 6983
-7625 6467
-8036 5945
-8221 5675
-8484 5268
-8900 4554
-9188 3917
-9329 3596
-9527 3006
-9614 2738
-9827 1839
-9925 1169
-9972 570
-9999 63
-9945 -861
-9883 -1484
-9817 -1831
-9704 -2393
-9665 -2555
-9627 -2695
-9425 -3277
-9232 -3798
-9202 -3878
-8925 -4509
-8520 -5211
-8340 -5510
-8160 -5776
-7935 -6071
-7284 -6824
-6973 -7163
-6545 -7553
-6277 -7775
-5950 -8036
-5366 -8437
-4708 -8809
-4087 -9106
-3834 -9223
-3755 -9254
-3281 -9436
-3010 -9524
-2550 -9651
-1972 -9803
-1079 -9937
-773 -9965
*/