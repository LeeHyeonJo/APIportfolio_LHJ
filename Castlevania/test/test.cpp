#include <iostream>
using namespace std;

class Parent

{
public:
    virtual void print()
    { //virtual함수 선언
        cout << "이곳은 Parent입니다." << endl;
    }
};

class Child : public Parent // child가 parent를 상속받음. 

{
public:

    void print() override 
        // 오버라이드는 명시적 표시 
        // virtual은 기본적으로 여러번 쓸 함수 (대체로 부모) 
        // 에 걸어주는 것이다. 
    {
        cout << "이곳은 Child입니다." << endl;
    }
};

void main()

{
    Parent* p = new Parent;
    Child* c = new Child;

    p->print();
    p = c;
    p->print();
}