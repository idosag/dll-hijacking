#include<windows.h>
#include<iostream>
using namespace std;

void MagicNumber()
{
	unsigned int vm_flag = 1;

	__asm
	{
		MOV EAX, 0x564D5868; 'VMXh'
		MOV EDX, 0x5658; 'VX(port)'
		in EAX, DX; 'Read input from that port'
		CMP EBX, 0x564D5868
		SETZ ECX; 'if successful -> flag = 0'
		MOV vm_flag, ECX
	}

	if (vm_flag == 0)
		printf("VMware Detected.");
	else
		printf("VMware NOT detected\n");
}





int main()
{
	MagicNumber();
	int n;
	std::cin >> n;
	return 0;
}