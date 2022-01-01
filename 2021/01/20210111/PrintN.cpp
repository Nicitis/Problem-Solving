#include <cstdio> // C++에서 C언어 헤더 파일은 c...의 형식

using namespace std;

int main()
{
    // buffer[]를 지정하고, setvbuf(stdout, buffer, _IOFBF, sizeof(buffer))를 사용하여 성능을 향상시킬 수 있다.
    // setvbuf는 스트림 버퍼링 방식을 변경한다. Java의 BufferedStream과 유사하게, 스트림이 읽은 데이터는 바로 쓰여지지 않는다.
    // 버퍼에 잠깐 저장되었다가 일정한 블록 이상 쌓이게 되면 장비에 쓰이게 된다. fflush, fclose의 호출, 프로그램 종료 시에 남은
    // 비퍼를 지울 수 있다.
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n",i);
    }

    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
int main()
{
    int n;
    stringstream ss;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        ss << i << '\n';
    }
    printf("%s", ss.str().c_str());
}
*/


