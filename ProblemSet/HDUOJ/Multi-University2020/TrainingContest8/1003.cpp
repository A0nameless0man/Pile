#include <iostream>

int main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {

            long long ax, ay, bx, by, cx, cy;
            std::cin >> ax >> ay >> bx >> by >> cx >> cy;
            cx -= ax;
            cy -= ay;
            bx -= ax;
            by -= ay;
            long long det = cx * by - bx * cy;
#ifdef DEBUG
            std::cout << det << std::endl;
#endif  // DEBUG
            if(det > 0)
            {
                std::cout << "Clockwise\n";
            }
            else
            {
                std::cout << "Counterclockwise\n";
            }
        }
    }
}
// 1623 524 535 646 151 26