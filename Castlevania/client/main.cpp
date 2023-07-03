// client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
// HWND는 윈도우를 만든 후 리턴되는 그의 주소값. HDC는 화면에 그려지는 리소스 (도형들). 이미지가 아님!!

// 윈도우가 돌아가는 원리만 이해하고 넘아가도 OK. (한줄씩 실행하면서, 어떤 작업이 이뤄지는지 확인할 것) 
// peekmassage 변경하기 (* 이게 핵심 *) , 도형 그려보기
// 핸들의 역할(HWND,hdc) 기억하기 
// 리소스 뷰는 컨트롤 시프트 e
// ㄴ 윈도우 창의 이름은 여기서 변경함. 

// 비주얼 스튜디오 자체에서 리포지토리 만드는 법 배웠음. 우측 하단에서 클릭하고 만들기. 

// ++ 오늘 구현할거: 키보드 입력에 따라서 공이 움직이고, 움직이는 구간에 따라서 검정색으로 그려지는것 

#include "framework.h"
#include "client.h"
#include "console.h" // 게임 엔진 - 하이레벨 인터베이스의 헤더 


#define MAX_LOADSTRING 100 // 0. 배열의 크기가 최대 100이라는 뜻. 

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다. 
// 1. 새로운 자료형: WCHAR.
// 영어는 char 형(1바이트)로 전부 표현 가능
// WCHAR은 2바이트 크기의 자료형. 한글,한자 등을 표현할 수 있다 (지금은 이것이 표준) 
// WCHAR 형은 초기화할때 앞에 L을 붙인다. 

game::Application application;  
// console::Application 이 크기를 가진 메모리를 할당. 그 이름은 어플리케이션 
// ㄴ 클래스의 객체를 전역변수로 선언한 것.

WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM); // WndProc: 함수 자체를 가리키는 포인터. 
// **wndproc 는 메세지를 처리해주는 함수 
// **윈도우는 최소 한개 이상의 wndproc 함수를 가지고 있어야 한다. (그래야 메세지들이 처리되니까 ) 
// ** "윈도우의 메세지 종류, 처리과정 seon 검색해서 읽어보기" 
// 함수 포인터란? : 말 그대로 함수를 가리키는 포인터 
// 사용법: int (*ptrsum)(int a, int b); 
//       반환값  함수의 주소를 받을 변수 함수에 들어가는 인자들 
// ptrsum = sum; (전제: sum 이라는 함수를 구현해두었음) 
// 사용시: 평범하게 함수처럼 사용하면 된다. ptrsum(2,3) = 5가 리턴된다. 
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); // 리소스뷰에서 불러와서 여기에 저장1
    LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING); // 여기에서 저장2
        // 3. 문자열을 불러오는 함수. 불러올 크기(바이트)는 내가 정할 수 있다.
        // IDS_APP_TITLE: 클라이언트의 이름을 불러옴.
        // "리소스 뷰"에서 변경 가능 
    MyRegisterClass(hInstance);
    // 윈도우의 정보가 등록되는 함수.
    // ㄴ 윈도우마다 등록되어야 한다. 
    // 즉, 윈도우의 정보 등록 & 윈도우 생성 & 윈도우 런(run)이 된다. 

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));

    MSG msg; // **메세지!
    // queue<MSG>.msg 이 형태인 것. 

    // 기본 메시지 루프입니다:
    // **와일문을 돌면서, 메세지를 가져오는 함수 
    // ** 윈도우 안에서 도는 모든 동작은 "메세지" 로 구성되고, 전달된다** 
    // ** 이 "메세지" 들은 큐의 형태로 정리되고 처리된다. 

    // 단점: 메세지가 없을 경우, 게임이 실행되지 않는다
    // 게임은 특정한 동작(메세지) 가 없어도 실행되어야 한다. 
    // 따라서 getmessage 함수는 메세지가 있을때에만 동작하므로, 게임 제작에는 적합하지 않다. 
       // > 이를 위해, 우리는 대신 peekmessage를 사용할거다. 


    // ******* 이 부분을 get message에서 peekmessage로 변경하였음 ******* 
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // 메세지의 내용을 번역하는 함수 
    //    {
    //        TranslateMessage(&msg); //무한
    //        DispatchMessage(&msg); //반복
    //    }
    //}
    // return (int) msg.wParam; 

    //  ** peekmessage로 변경하였음 **
    // 메세지에서 걸리므로 f5여기에 걸고 넘기셈 
    while (true)
    {

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            // ★게임 로직을 여기서 돌림
            // Run 안에 렌더와 업데이트 함수가 들어있기에 돌 수 있는 것. 
            application.Run(); 
        }

    }

    // 메세지가 있는 동안에는 무한으로 돌고있음 
    // 프로그램을 "끝내는 메세지" 도 있어야 함 ( == WM_QUIT) 
    
    if (msg.message == WM_QUIT)
    {
        // WM_QUIT라는 메세지를 받을 시, 
        // 프로그램을 멈추고 종료하라는 기능을 여기에 구현할 것. 
    }

    return (int) msg.wParam;  // 메인 함수의 메세지를 받아주는 부분. 

    // get message: 메세지큐에 메세지가 있어야만 발생한다. 
    // peek message: 메세지큐에 메세지가 없어도 진행된다. 
}

//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_CROSS); // IDC_ARROW (드래그 ->f12-> 원하는 명령어 찾기) 
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CLIENT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   // ★윈도우 창을 만드는 함수: 윈도우 클래스, 이름...
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, 
            CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   // ☆초기화는 프로그램이 실행될때 맨 처음 한번만.
   // Initialize가 받는 인자는, 윈도우가 실행될때 생성되는 hWnd값. 
   application.Initialize(hWnd, {900,600});

     //윈도우 창에서의 위지 / 콘솔창의 크기    

  //  오리지널 코드: HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
  //   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

     //szWindowClass, szTitle, : 솔루션의 이름, 콘솔창의 이름 
    // 첫 CW_USEDEFAULT, 0 : 윈도우의 좌표 = 좌측 상단이 0이다 (배열과 동일) !!이건 운영체제마다 다름. 
    //  ㄴ 게임 창이 윈도우의 어디에서 뜰지, 라는 뜻.  
    // 두 CW_USEDEFAULT, 0,: 실제 게임 화면의 크기 
   // ex. CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,  :: 0,0,1600,900 : 0,0위치에 1600*900의 크기의 창을 만들어줘. 

   // **: 대부분의 API는 사용자가 직접적으로 데이터에 접근해서 수정할 수 있는 권한을 주지 않는다. 
   // **: 설계구조 자체가, 메모리 자체를 만지는게 아니라. 이미 만들어진 함수를 통해 인자만 바꾸면 OK인 식으로.
   // ** >> 데이터에 직접 접근 불가능. 

   // 이 함수는 반환되면서 HWND 라는 무언가를 던져준다. 
   //HWND 란?: 윈도우 화면 자체를 가리키는 포인터 변수. 이게 클라이언트에 간접적으로 접근하는 리모컨같은것. 
   // ㄴ 핸들이라고 부른다. 

   if (!hWnd) // ★null을 뱉었다면, 프로그램이 실패한 것임. 
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow); // 윈도우 창을 화면에 띄워주는 함수 
   UpdateWindow(hWnd); // 윈도우창이 "돌아가게" 끔하는 함수  

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
// 여기로 들어온 이유: 윈도우 만드는 함수 "도중" 에 , 내부에 프로시저가 들어있어서 여기로 들어옴.
// 그러면서 빙빙빙 돈 것. 그 후 intilaize 함수로 들어가서 초기화, 윈도우 화면을 띄워주게 된다. 
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

    case WM_PAINT: // ** 화면에 새로운것을 띄워야 할 필요가 있을 때, 사용되는 함수 
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps); // **hdc: 그림과 관련된 영역을 다루는 핸들. 

            // (TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...)
            // 원리: 업데이트 윈도우에서, hdc를 이용해서 부름. 
            
            // Rectangle(hdc, 200, 200, 100, 100); // 직사각형
            // Ellipse(hdc, 100, 100 , 200, 200); // 동그라미 

            // >> main이 아니라, console에서 그리도록 할 것임. 

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
