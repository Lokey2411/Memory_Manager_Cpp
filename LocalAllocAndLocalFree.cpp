#include <windows.h>
#include <iostream>

int main() {
    // Cấp phát một khối bộ nhớ địa phương
    HLOCAL hMem = LocalAlloc(LMEM_FIXED, 100 * sizeof(int));
    if (hMem == NULL) {
        std::cout << "Local memory allocation failed\n";
        return 1;
    }

    // Sử dụng bộ nhớ
    int* arr = (int*)hMem;
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Giải phóng bộ nhớ
    LocalFree(hMem);
    system("pause");

    return 0;
}
