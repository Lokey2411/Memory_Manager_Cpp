#include <windows.h>
#include <iostream>
#include <string>
#define NUM_USER 10

using namespace std;

class User
{
public:
    string displayName;
    string username;
    string password;
    User() {}
    User(string displayName, string username, string password)
    {
        this->displayName = displayName;
        this->username = username;
        this->password = password;
    }
    void display()
    {
        cout << "Name: " << this->displayName << ", username: " << this->username << ", pass: " << this->password << endl;
    }
    ~User()
    {
        cout << "Destructor called for " << displayName << endl;
    }
};

int main()
{
    User data[] = {User("Viet beo", "viet2411", "123"), User("Viet xin", "viet2003", "456"), User("Gau truc", "viet24112003", "789"), User("Panda", "gautruc", "123"), User("Panda2", "gautruc2411", "456"), User("Gau truc 2", "gautruc24112003", "789"), User("23 con nai yeu em khong phai", "viet123", "0175"), User("Khong ngo gap phai thang lieu", "viet0175", "123"), User("Cuc chang da", "viet2415", "123"), User("Anh em minh cu phai goi la bung suc di", "mdh_0978****", "123")};
    // Cấp phát một vùng bộ nhớ ảo
    User *arr = (User *)VirtualAlloc(NULL, NUM_USER * sizeof(User), MEM_COMMIT, PAGE_READWRITE);
    if (arr == NULL)
    {
        cout << "Virtual memory allocation failed\n";
        return 1;
    }

    for (int i = 0; i < NUM_USER; i++)
        new (&arr[i]) User(data[i].displayName, data[i].username, data[i].password);
    // cout << arr[0];
    for (int i = 0; i < NUM_USER; i++)
    {
        cout << "User" << i << ": ";
        arr[i].display();
    }
    cout << endl;
    // delete[] arr;

    // Giải phóng bộ nhớ
    VirtualFree(arr, 0, MEM_RELEASE);
    system("pause");

    return 0;
}
