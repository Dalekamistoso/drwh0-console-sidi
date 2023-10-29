#include "config.h"
#include "statusword.h"
#include "ps2.h"
#include "keyboard.h"
#include "uart.h"
#include "interrupts.h"
#include "configstring.h"
#include "diskimg.h"

#include <stdio.h>
#include <string.h>

#include "c64keys.c"

int LoadROM(const char *fn);

int UpdateKeys(int blockkeys)
{
	handlec64keys();
	return(HandlePS2RawCodes(blockkeys));
}


char *autoboot()
{
	char *result=0;

	if(!LoadROM(ROM_FILENAME))
		result="ROM loading failed";

	initc64keys();

	return(result);
}

