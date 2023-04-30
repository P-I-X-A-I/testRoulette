// Spla-roulette.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Spla-roulette.h"

#define MAX_LOADSTRING 100

// グローバル変数:
HINSTANCE hInst;                                // 現在のインターフェイス
WCHAR szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト
WCHAR szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名

// このコード モジュールに含まれる関数の宣言を転送します:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);




// ****** draw timer **********
// actually unused
VOID CALLBACK drawTimer(HWND, UINT, UINT, DWORD);
VOID CALLBACK drawTimer(HWND hWnd, UINT msg, UINT idEvent, DWORD dwTime)
{
	main_controller_obj->drawGL();
}



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ここにコードを挿入してください。









    // グローバル文字列を初期化する
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SPLAROULETTE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // アプリケーション初期化の実行:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SPLAROULETTE));

    MSG msg;

    // メイン メッセージ ループ:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SPLAROULETTE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	//wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_SPLAROULETTE);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   関数: InitInstance(HINSTANCE, int)
//
//   目的: インスタンス ハンドルを保存して、メイン ウィンドウを作成します
//
//   コメント:
//
//        この関数で、グローバル変数でインスタンス ハンドルを保存し、
//        メイン プログラム ウィンドウを作成および表示します。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // グローバル変数にインスタンス ハンドルを格納する


   // log console
   /*
   AllocConsole();
   FILE* fp = NULL;
   freopen_s(&fp, "CONOUT$", "w", stdout); // stdio.h
   printf("Console window alloced time %d.\n", time(NULL));
   */

   // create object ******************************
   main_controller_obj = new mainController();
   //*******************************************************


   // test resource read
   main_controller_obj->mainInst = hInst;
   printf("hInst %d\n", hInst);

   
  


   // get screen size
   int screenX = GetSystemMetrics(SM_CXSCREEN);
   int screenY = GetSystemMetrics(SM_CYSCREEN);
   printf("main screen %d %d\n", screenX, screenY);


   // calc main window size
   int mainHeight = (int)((float)screenY * 0.9);
   int mainWidth;

   if (mainHeight > 980) { mainHeight = 980; }

   mainWidth = (int)((float)mainHeight * (3.0 / 4.0));

   printf("mainWindow %d %d\n", mainWidth, mainHeight);


   // set window start corner
   int mainCornerX;
   int mainCornerY;

   mainCornerY = 10;
   mainCornerX = (screenX / 2) - (mainWidth / 2);


   // GUI size
   int GUI_width = 220;


   // set to mainController
   main_controller_obj->winWidth = mainWidth;
   main_controller_obj->winHeight = mainHeight;
   main_controller_obj->guiWidth = GUI_width;


   HWND hWnd = CreateWindowW(
					szWindowClass,
					szTitle,
					WS_OVERLAPPED | WS_SYSMENU, // WS_POPUP = fullscreen
					mainCornerX - (GUI_width/2),
					mainCornerY,
					mainWidth + GUI_width,
					mainHeight,
					nullptr,
					nullptr,
					hInstance,
					nullptr);



   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);



   // set opengl view to main window
   main_controller_obj->main_window_obj = hWnd;
   main_controller_obj->setup();
   main_controller_obj->setup_gui();

 

   


   // set draw timer
   SetTimer(hWnd,
	   111,
	   1000 / 60,
	   (TIMERPROC)drawTimer
   );


   return TRUE;
}

//
//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: メイン ウィンドウのメッセージを処理します。
//
//  WM_COMMAND  - アプリケーション メニューの処理
//  WM_PAINT    - メイン ウィンドウを描画する
//  WM_DESTROY  - 中止メッセージを表示して戻る
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int GUI_ID, EVENT_CODE;
	GUI_ID = LOWORD(wParam);
	EVENT_CODE = HIWORD(wParam);

	main_controller_obj->message_from_GUI(message, GUI_ID, EVENT_CODE, lParam);


    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 選択されたメニューの解析:
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: HDC を使用する描画コードをここに追加してください...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

	// this is importtant to change textfield's background color
	case WM_CTLCOLORSTATIC:
		SetBkMode((HDC)wParam, TRANSPARENT);
		return (LRESULT)GetStockObject(WHITE_BRUSH);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
			printf("RETURN KEY");
		//main_controller_obj->roulette_button();
		break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// バージョン情報ボックスのメッセージ ハンドラーです。
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
