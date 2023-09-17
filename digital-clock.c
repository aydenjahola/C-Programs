#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"  // Define clear screen command for Windows
#define SLEEP_MS(ms) Sleep(ms)  // Define sleep function for Windows in milliseconds
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"  // Define clear screen command for non-Windows systems (e.g., Linux)
#define SLEEP_MS(ms) usleep(ms * 1000)  // Define sleep function for non-Windows systems in microseconds
#endif

int main()
{
    int h, m, s;
    int d = 1000; // Add delay of 1000ms
    printf("Set Time: \n");
    scanf("%d%d%d", &h, &m, &s);

    // Check if the input time values are valid
    if (h > 12 || m > 60 || s > 60)
    {
        printf("Error! \n");
        return 1;
    }

    while (1)
    {
        s++;
        if (s > 59)
        {
            m++;
            s = 0;
        }
        if (m > 59)
        {
            h++;
            m = 0;
        }
        if (h > 12)
        {
            h = 1;  // Reset hours to 1 if it exceeds 12 (assuming a 12-hour clock)
        }

        printf("\n Clock: ");
        printf("\n %02d:%02d:%02d", h, m, s);
        SLEEP_MS(d);  // Add a delay of 1000ms
        system(CLEAR_SCREEN); // Clear the screen to update the displayed time
    }
}
