#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <croutine.h>

int main() {
	printf("hello");
	vTaskStartScheduler();
	return 0;
}

