#include <Windows.h>
#include <stdio.h>

const LPCSTR clsName = "qiniu888";
const LPCSTR msgName = "��ţѧԺ";
const LPCSTR msgUrl = "https://ke.qq.com/course/388295?tuin=96d038f";

//���ڽ�����Ӧ����(�ص�����)
LRESULT CALLBACK WinSunProc(
	HWND  handle,
	UINT  uMsg,
	WPARAM wParam,
	LPARAM lParam
);

// �������
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE prevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
) {
	// ��ƴ�����ۺͽ�����Ӧ
	WNDCLASS wndcls;
	wndcls.cbClsExtra = NULL;
	wndcls.cbWndExtra = NULL;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hInstance = hInstance;
	// ���彻����Ӧ
	wndcls.lpfnWndProc = WinSunProc;
	// ���崰�ڴ���
	wndcls.lpszClassName = clsName;
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	// ע�ᴰ��
	RegisterClass(&wndcls);

	// ��������
	HWND hwnd;
	hwnd = CreateWindow(clsName, "��ţ����", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	// ��ʾ��ˢ�´���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	// ������Ϣ�ṹ�壬��ʼ��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

// ���ڽ�����Ӧ����
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
		sprintf_s(szChar, "���հ�����????: %c", wParam);
		MessageBox(hwnd, szChar, "char", NULL);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "��⵽������������", "message", NULL);
		break;
	case WM_PAINT:
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, msgUrl, strlen(msgUrl));
		EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:
		ret = MessageBox(hwnd, "�Ƿ���Ľ�����", "message", MB_YESNO);
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
