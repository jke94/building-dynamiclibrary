# building-dynamiclibrary

A proof of concept about:

1. ✅ How create a C++ cross-platform (linux and windows) dynamic library.
2. ✅ How to delivey a NuGet Package (for windows) to consume dynamic library as third party code, exposing a API.
3. ✅ How to load and consume dynamic library in a cross-platform (linux and windows) client.
4. ✅ How to use the beneficts of docker images, docker-compose and GitHub actions as a system to build and running a client that consumes the dynamic library.

## A. Create Nuget Package (windows delivery)


1. From Developer Command Prompt vs2022, running the following commands:
```
msbuild .\building-dynamiclibrary.sln -p:Configuration=Release -p:Platform=x64 -t:Build
```
```
msbuild .\building-dynamiclibrary.sln -p:Configuration=Release -p:Platform=x86 -t:Build
```
```
msbuild .\building-dynamiclibrary.sln -p:Configuration=Debug -p:Platform=x64 -t:Build
```
```
msbuild .\building-dynamiclibrary.sln -p:Configuration=Debug -p:Platform=x86 -t:Build
```
Also you can build with Visual Studio 2022 using the different compilation targets with all platform and configurations.

2. Building Nuget package, running the following command:

```
.\packages\NuGet.CommandLine.6.6.1\tools\NuGet.exe pack .\dynamiclibrary.nuspec
```

## B. Docker compose (as linux builder and dynamic library client)

- Linux:

```
sudo docker compose -f ./docker-compose.yml -p building-dynamic-lib up --build
```

- Windows:

```
docker-compose -f ./docker-compose.yml -p building-dynamic-lib up --build
```

## C. Useful information.

- [MSDN - What is a DLL](https://learn.microsoft.com/en-us/troubleshoot/windows-client/deployment/dynamic-link-library)

## D. Author

- [Javier Carracedo](https://github.com/jke94)