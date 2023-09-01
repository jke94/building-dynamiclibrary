# building-dynamiclibrary


## Create Nuget Package


- Running from Developer Command Prompt vs2022:
```
msbuild .\building-dynamiclibrary.sln -p:Configuration=Release -p:Platform=x64 -t:Build
msbuild .\building-dynamiclibrary.sln -p:Configuration=Release -p:Platform=x86 -t:Build

msbuild .\building-dynamiclibrary.sln -p:Configuration=Debug -p:Platform=x64 -t:Build
msbuild .\building-dynamiclibrary.sln -p:Configuration=Debug -p:Platform=x86 -t:Build
```
or running with Visual Studio 2022.

## Building Nuget package.

```
.\packages\NuGet.CommandLine.6.6.1\tools\NuGet.exe pack .\dynamiclibrary.nuspec
```

## Docker compose

- Linux:

```
sudo docker compose -f ./docker-compose.yml -p building-dynamic-lib up --build
```

- Windows:

```
docker-compose -f ./docker-compose.yml -p building-dynamic-lib up --build
```

## Useful information.

- [MSDN - What is a DLL](https://learn.microsoft.com/en-us/troubleshoot/windows-client/deployment/dynamic-link-library)