#include <windows.h>
#include <iostream>
using namespace std;


void SendMouseClick(int button) {
    INPUT input = {0};
    input.type = INPUT_MOUSE;

    if (button == 0){
        input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
    }
    else {
        input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
    }

    SendInput(1, &input, sizeof(INPUT));
}

int main() {

	bool lmbHeld = false;
    bool rmbHeld = false;

	POINT p;

	while (true){
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
            if (!lmbHeld) {
                SendMouseClick(0);
                lmbHeld = true;
            }
        } else {
            lmbHeld = false;
        }

        if (GetAsyncKeyState(VK_OEM_5) & 0x8000) {
            if (!rmbHeld) {
                SendMouseClick(1);
                rmbHeld = true;
            }
        } else {
            rmbHeld = false;
        }

		if (GetAsyncKeyState(VK_UP) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000) {
			GetCursorPos(&p);
			SetCursorPos(p.x - 1, p.y - 1);
			Sleep(2);
			continue;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000) {
			GetCursorPos(&p);
			SetCursorPos(p.x - 1, p.y + 1);
			Sleep(2);
			continue;
		}
		else if (GetAsyncKeyState(VK_UP) & 0x8000 && GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			GetCursorPos(&p);
			SetCursorPos(p.x + 1, p.y - 1);
			Sleep(2);
			continue;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			GetCursorPos(&p);
			SetCursorPos(p.x + 1, p.y + 1);
			Sleep(2);
			continue;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			GetCursorPos(&p);
			SetCursorPos(p.x + 1, p.y);
			Sleep(2);
			continue;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			GetCursorPos(&p);
			SetCursorPos(p.x - 1, p.y);
			Sleep(2);
			continue;
		}
		else if (GetAsyncKeyState(VK_UP) & 0x8000) {
			GetCursorPos(&p);
			SetCursorPos(p.x, p.y - 1);
			Sleep(2);
			continue;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			GetCursorPos(&p);
			SetCursorPos(p.x , p.y + 1);
			Sleep(2);
			continue;
		}

		Sleep(2);
	}

	return 0;
}