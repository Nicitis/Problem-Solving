// 백준 11662 민호와 강호(CPP) (못품)
// https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=221432986308&proxyReferer=https:%2F%2Fwww.google.com%2F
#include <iostream>
#include <cmath>

#define SIMULATE_NUMBER 35
#define Square(X) ((X)*(X))

using namespace std;

double CalculateDistance(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy, int t)
{
    return sqrt(Square(cx - ax + (dx + ax - bx - cx) * t) + 
        Square(cy - ay + (dy + ay - by - cy) * t));
}

int main()
{
    int ax, ay, bx, by, cx, cy, dx, dy;

    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    double low = 0, high = 1, t, minDist;

    // 최초 dist 계산
    minDist = CalculateDistance(ax, ay, bx, by, cx, cy, dx, dy, 0.5);

    // t 값을 근사하여 계산(35번)
    for (int i = 0; i < 35; i++)
    {
        double left = (low + t) >> 1; // 다음 왼쪽 근사점
        double right = (t + high) >> 1; // 다음 오른쪽 근사점
        double leftDistance = CalculateDistance(ax, ay, bx, by, cx, cy, dx, dy, left);
        double rightDistance = CalculateDistance(ax, ay, bx, by, cx, cy, dx, dy, right);

        if (leftDistance <= rightDistance)
        {

        }
        
    }
}