#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

long long int volatile GlobalVar = 0;

DWORD WINAPI IncProc(LPVOID arg)
{
    //long long int* p = (long long int*)GlobalVar;
    for (long long int i = 0; i < 100000000; i++)
    {
        GlobalVar++;
    }
    ExitThread(0);
}

DWORD WINAPI DecProc(LPVOID arg)
{
    //long long int* p = (long long int*)GlobalVar;
    for (long long int i = 0; i < 100000000; i++)
    {
        GlobalVar--;
    }
    ExitThread(0);
}

int main()
{
   // volatile long long int var = 0;
   // volatile long long int* pvar = &var;
    HANDLE handles[10] = {};

    printf("var = %d\n", GlobalVar);
    for (int i = 0; i < 10; i++)
    {
        handles[i] = CreateThread(NULL, 0, IncProc, (LPVOID)&GlobalVar, 0, NULL);  //создаем потоки 
        Sleep(200);
    }
    if (WaitForMultipleObjects(10, handles, TRUE, INFINITE) == FALSE)
    {
        printf("var = %d\n", GlobalVar);
    }
    for (int i = 0; i < 10; i++)
    {
        handles[i] = CreateThread(NULL, 0, DecProc, (LPVOID)&GlobalVar, 0, NULL); //вычитающие потоки
        Sleep(200);
    }
    if (WaitForMultipleObjects(10, handles, TRUE, INFINITE) == FALSE)
    {
        printf("var = %d\n", GlobalVar);
    }
    return 0;
}