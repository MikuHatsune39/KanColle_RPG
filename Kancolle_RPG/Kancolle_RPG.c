// KanColle RPG

/*
This program was created by MikuHatsune39 on 2018-03-06
It is a simple attempt to rewrite a python program in c.
*/

//Setting up for compiler
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
PSP_MODULE_INFO("KanColle RPG", 0, 1, 1);
#define printf pspDebugScreenPrintf

//Setting up the program
/* Exit callback */
int exit_callback(int arg1, int arg2, void *common)
{
	sceKernelExitGame();
	return 0;
}

/* Callback thread */
int CallbackThread(SceSize args, void *argp)
{
	int cbid;

	cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
	sceKernelRegisterExitCallback(cbid);

	sceKernelSleepThreadCB();

	return 0;
}

/* Sets up the callback thread and returns its thread id */
int SetupCallbacks(void)
{
	int thid = 0;

	thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
	if (thid >= 0) {
		sceKernelStartThread(thid, 0, 0);
	}

	return thid;
}

//The main body on the code
int main()
{
	//More setup
	pspDebugScreenInit();
	SetupCallbacks();
	//The Start of the main program
	printf("Story: You have just arived at the navel district after being\n");
	printf("recruted to join the fleet.\n");
	nextLine();

	printf("\n");
	printf("???: Hello and welcome to the fleet my name is Shimakaze,\n");
	printf("I'm the fastest ship around!\n");
	nextLine();
	//printf("I'm the fastest ship around, what's your name?");
	
	printf("\n");
	printf("Shimakaze: Wan'na race?\n");
	//nextLine();

	printf("\n");
	wannaRace();

	//Wait until "Home" button is pressed 
	sceKernelSleepThread();
	//The int return
	return 0;
}

void wannaRace(void)
{
	//wait?
	int i = 0;
	for (i = 0; i<5; i++)
	{
		sceDisplayWaitVblankStart();
	}
	printf("Press [X] for Yes, [O] for No.\n");
	printf("\n");
	
	//int i = 0;
	//Buttons
	SceCtrlData pad;
	while (1)
	{
		sceCtrlReadBufferPositive(&pad, 1);
		if (pad.Buttons & PSP_CTRL_CROSS)
		{
			printf("Sure, your on!\n");
			break;
		}
		if (pad.Buttons & PSP_CTRL_CIRCLE)
		{
			printf("You: Mabye another time.\n");
			break;
		}
		//Lets the "HOME" button work
		for (i = 0; i<5; i++)
		{
			sceDisplayWaitVblankStart();
		}
	}
}

void nextLine(void)
{
	//wait?
	int i = 0;
	for (i = 0; i<5; i++)
	{
		sceDisplayWaitVblankStart();
	}
	//Buttons
	SceCtrlData pad;
	while (1)
	{
		sceCtrlReadBufferPositive(&pad, 1);
		if (pad.Buttons & PSP_CTRL_CROSS)
		{
			break;
		}
		if (pad.Buttons & PSP_CTRL_CIRCLE)
		{
			break;
		}
		//Lets the "HOME" button work
		//int i = 0;
		for (i = 0; i<5; i++)
		{
			sceDisplayWaitVblankStart();
		}
	}
}
