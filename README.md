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