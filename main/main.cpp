#include <Windows.h>
#include <stdio.h>

const LPCSTR clsName = "qiniu888";
const LPCSTR msgName = "奇牛学院";
const LPCSTR msgUrl = "https://ke.qq.com/course/388295?tuin=96d038f";

//窗口交互响应处理(回调函数)
LRESULT CALLBACK WinSunProc(
	HWND  handle,
	UINT  uMsg,
	WPARAM wParam,
	LPARAM lParam
);

// 程序入口
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE prevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
) {
	// 设计窗口外观和交互响应
	WNDCLASS wndcls;
	wndcls.cbClsExtra = NULL;
	wndcls.cbWndExtra = NULL;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hInstance = hInstance;
	// 定义交互响应
	wndcls.lpfnWndProc = WinSunProc;
	// 定义窗口代号
	wndcls.lpszClassName = clsName;
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	// 注册窗口
	RegisterClass(&wndcls);

	// 创建窗口
	HWND hwnd;
	hwnd = CreateWindow(clsName, "奇牛威武", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	// 显示及刷新窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	// 定义消息结构体，开始消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

// 窗口交互响应处理
LRESULT CALLBACK WinSunProc(
	HWND  hwnd,
	UINT  uMsg,
	WPARAM wParam,
	LPARAM lParam
) {
	HDC hdc;
	int ret;
	switch (uMsg)
	{
	case WM_CHAR:
		char szChar[20];
		sprintf_s(szChar, "您刚按下了????: %c", wParam);
		MessageBox(hwnd, szChar, "char", NULL);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "检测到鼠标左键被按下", "message", NULL);
		break;
	case WM_PAINT:
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, msgUrl, strlen(msgUrl));
		EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:
		ret = MessageBox(hwnd, "是否真的结束？", "message", MB_YESNO);
		if (ret == IDYES)
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}
