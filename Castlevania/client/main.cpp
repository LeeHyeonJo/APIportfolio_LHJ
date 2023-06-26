// client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
// 0. 데스크톱 마법사 -> 데스크톱 어플리케이션 -> 솔루션 필터를 영어로 변경. 
// 오늘 할거; 1. 주석보며 함수 내용 파악하고, seon 검색해서 winapi 적당히 예습해보기 
//  ㄴ 메세지의 개념, 겟메세지를 픽메세지로 변경하기, wm_paint로 도형 그려보기, 핸들의 역할(HWND,hdc) 
// 1.5. 질문한거 개념 정리 
// 2. 악마성 에클레시아 리소스 nds factory로 추출하기. 

// 윈도우가 돌아가는 원리만 이해하고 넘아가도 OK. (한줄씩 실행하면서, 어떤 작업이 이뤄지는지 확인할 것) 
// peekmassage 변경하기, 도형 그려보기 

#include "framework.h"
#include "client.h"

#define MAX_LOADSTRING 100 // 0. 배열의 크기가 최대 100이라는 뜻. 

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다. 
// 1. 새로운 자료형: WCHAR.
// 영어는 char 형(1바이트)로 전부 표현 가능
// WCHAR은 2바이트 크기의 자료형. 한글,한자 등을 표현할 수 있다 (지금은 이것이 표준) 
// WCHAR 형은 초기화할때 앞에 L을 붙인다. 
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

    // 기본 메시지 루프입니다:
    // **와일문을 돌면서, 메세지를 가져오는 함수 
    // ** 윈도우 안에서 도는 모든 동작은 "메세지" 로 구성되고, 전달된다** 
    // ** 이 "메세지" 들은 큐의 형태로 정리되고 처리된다. 

    // 단점: 메세지가 없을 경우, 게임이 실행되지 않는다
    // 게임은 특정한 동작(메세지) 가 없어도 실행되어야 한다. 
    // 따라서 getmessage 함수는 메세지가 있을때에만 동작하므로, 게임 제작에는 적합하지 않다. 
       // > 이를 위해, 우리는 대신 peekmessage를 사용할거다. 


    // ******* 이 부분을 get message에서 peekmessage로 변경하였음 ******* 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // 메세지의 내용을 번역하는 함수 
        {
            TranslateMessage(&msg); //무한
            DispatchMessage(&msg); //반복
        }
    }

    return (int) msg.wParam;

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
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
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
    //  CW_USEDEFAULT, 0, 윈도우의 좌표계: 좌측 상단이 0이다 (배열과 동일): 이건 운영체제마다 다름. 
    //  ㄴ 게임 창이 윈도우의 어디에서 뜰지, 라는 뜻. 
   //  CW_USEDEFAULT, 0,: 실제 게임 화면의 크기 
   // ex. CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,  :: 0,0,1600,900 : 0,0위치에 1600*900의 크기의 창을 만들어줘. 

   //szWindowClass, szTitle, : 솔루션의 이름, 콘솔창의 이름 

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
            // ** 직사각형을 그려보자!!!! **
            // Rectangle(hdc, 100, 100, 200, 200);

            // 원리: 업데이트 윈도우에서, hdc를 이용해서 부름. 

            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
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
