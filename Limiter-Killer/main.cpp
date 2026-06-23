#include <windows.h>






void press() {
	INPUT input = {0};
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = VK_F12;



	
	input.ki.dwFlags = 0;
	SendInput(1, &input, sizeof(INPUT));

	Sleep(100);


	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}

int main() {
	while (true) {


		press();

		Sleep(540000);

		press();

		Sleep(50);


	}
	

	return 0;
}