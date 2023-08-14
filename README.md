# building-dynamiclibrary


## Create Nuget Package


- Running from Developer Command Prompt vs2022:
```
msbuild .\building-dynamiclibrary.sln -p:Configuration=Release -p:Platform=x64 -t:Build
msbuild .\building-dynamiclibrary.sln -p:Configuration=Release -p:Platform=x86 -t:Build

msbuild .\building-dynamiclibrary.sln -p:Configuration=Debug -p:Platform=x64 -t:Build
msbuild .\building-dynamiclibrary.sln -p:Configuration=Debug -p:Platform=x86 -t:Build
```

## Build Nuget.

```
.\nuget.exe pack .\building-dynamiclibrary\dynamiclibrary.nuspec
```