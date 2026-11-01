# Loader

A simple educational C++ implementation of a web downloader utility that fetches a remote executable via HTTP/HTTPS and executes it locally using native Windows APIs.

## Overview

This project demonstrates the core mechanics of network asset delivery in Windows environments. It mirrors the fundamental architecture used by lightweight **web installers, software updaters, and stagers**, which minimize initial download sizes by pulling main payloads dynamically from a remote server.

## How It Works

The program executes a simple linear routine within the `WinMain` entry point:

1.  **Path Resolution:** It queries the shell system via `SHGetFolderPathW` to securely locate the current user's local application data directory (`CSIDL_LOCAL_APPDATA` / `\AppData\Local`). This path is chosen to ensure the application has write permissions without requiring administrative privileges.
2.  **Path Construction:** It safely appends the target filename using `PathCombineW` to form a fully qualified destination path.
3.  **Network Fetch:** It invokes the Windows URL Moniker library function `URLDownloadToFileW` to download the remote binary file over HTTP/HTTPS from a specified URL.
4.  **Process Execution:** Upon a successful `S_OK` response, it utilizes `ShellExecuteW` with the `open` verb to launch the newly downloaded executable in a standard window.

## Specifications & Dependencies

*   **Language:** C++11 / C++17
*   **Subsystem:** Windows (`WinMain`)
*   **Libraries Linked:** `urlmon.lib`, `shlwapi.lib`
*   **Key APIs Used:** `URLDownloadToFile`, `SHGetFolderPathW`, `PathCombineW`, `ShellExecuteW`

## Educational Disclaimer

This repository is strictly for **educational, testing, and defensive research purposes**. Studying how native OS components handle remote file downloads helps software developers build reliable auto-update mechanisms and allows security analysts to understand and monitor unexpected network-to-execution behavior in corporate networks.
